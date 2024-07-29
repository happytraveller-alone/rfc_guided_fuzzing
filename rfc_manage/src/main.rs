use regex::Regex;
use reqwest;
use std::cmp::Ordering;
use std::collections::BTreeMap;
use std::env;
use std::error::Error;
use std::fs::{self, File};
use std::io::{BufRead, BufReader, Write};
use std::path::{Path, PathBuf};
use std::collections::HashMap;use std::time::Duration;
use std::thread;
use colored::*;

// 宏定义
macro_rules! body_start {
    () => {
        "Introduction"
    };
}

macro_rules! body_end {
    () => {
        "IANA Considerations"
    };
}

// 全局变量
lazy_static::lazy_static! {
    static ref FILTER_SECTIONS: Vec<&'static str> = vec![
        body_start!(),
        "Protocol Overview",
        "Presentation Language",
        "References",
        "Authors' Addresses",
        "Full Copyright Statement",
    ];
}

/// 获取项目根目录
///
/// 返回值:
/// - PathBuf: 项目根目录的路径
fn get_project_root() -> PathBuf {
    env::current_exe()
        .expect("Failed to get current executable path")
        .parent()
        .expect("Failed to get parent directory")
        .parent()
        .expect("Failed to get project root")
        .to_path_buf()
}

/// 创建输入和输出目录
///
/// 参数:
/// - project_root: &PathBuf - 项目根目录的路径
///
/// 返回值:
/// - Result<(PathBuf, PathBuf), Box<dyn Error>>: 包含输入和输出目录路径的元组
fn create_directories(project_root: &PathBuf) -> Result<(PathBuf, PathBuf), Box<dyn Error>> {
    let input_dir = project_root.join("..\\input");
    let output_dir = project_root.join("..\\output");
    fs::create_dir_all(&input_dir)?;
    fs::create_dir_all(&output_dir)?;
    Ok((input_dir, output_dir))
}

/// 下载RFC文档并保存到本地
///
/// 参数:
/// - rfc_number: &str - RFC编号
/// - input_file: &PathBuf - 保存RFC文档的本地文件路径
///
/// 返回值:
/// - Result<(), Box<dyn Error>>: 操作结果
fn download_rfc(rfc_number: &str, input_file: &PathBuf) -> Result<(), Box<dyn Error>> {
    println!("正在下载 RFC {}...", rfc_number);
    let url = format!("https://www.rfc-editor.org/rfc/rfc{}.txt", rfc_number);
    let response = reqwest::blocking::get(&url)?;
    let content = response.text()?;

    let mut file = File::create(input_file)?;
    file.write_all(content.as_bytes())?;
    println!("下载完成，已保存到 {:?}", input_file);
    Ok(())
}

/// 处理RFC文档内容
///
/// 参数:
/// - input_file: &PathBuf - 输入文件路径
///
/// 返回值:
/// - Result<String, Box<dyn Error>>: 处理后的文档内容
fn process_rfc_content(input_file: &PathBuf) -> Result<String, Box<dyn Error>> {
    let reader = BufReader::new(File::open(input_file)?);
    let regexes = Regexes {
        header_footer: Regex::new(r"^RFC \d+\s+.*\s+\w+ \d{4}$|^.*\s+\[Page \d+\]$")?,
        page_break: Regex::new(r"\f")?,
        section_title: Regex::new(r"^(\d+(?:\.\d+)*\.?)\s+(.*)")?,
    };

    process_content(reader, &regexes)
}

struct Regexes {
    header_footer: Regex,
    page_break: Regex,
    section_title: Regex,
    // section_title_two: Regex,
}

/// 处理文档内容
///
/// 参数:
/// - reader: BufReader<File> - 文件读取器
/// - regexes: &Regexes - 正则表达式集合
///
/// 返回值:
/// - Result<String, Box<dyn Error>>: 处理后的文档内容
fn process_content(reader: BufReader<File>, regexes: &Regexes) -> Result<String, Box<dyn Error>> {
    let mut content = String::new();
    let mut empty_line_count = 0;
    let mut skip_section = true;
    let mut found_intro = false;
    let mut in_main_content = false;
    let mut iana_passed = false;

    for line in reader.lines() {
        let line = line?;
        let line = regexes.page_break.replace_all(&line, "").to_string();

        if regexes.header_footer.is_match(&line) {
            continue;
        }

        if let Some(captures) = regexes.section_title.captures(&line) {
            if let Some(section_result) = process_section(
                &captures,
                &mut found_intro,
                &mut in_main_content,
                &mut iana_passed,
            ) {
                match section_result {
                    SectionResult::Skip(should_skip) => skip_section = should_skip,
                    SectionResult::Break => break,
                }
            }
        }

        if !in_main_content || skip_section {
            continue;
        }

        process_line(&mut content, &line, &mut empty_line_count);
    }

    validate_and_finalize_content(content, found_intro)
}

enum SectionResult {
    Skip(bool),
    Break,
}

/// 处理章节
///
/// 参数:
/// - captures: &regex::Captures - 正则匹配结果
/// - found_intro: &mut bool - 是否找到介绍章节
/// - in_main_content: &mut bool - 是否在主要内容中
/// - iana_passed: &mut bool - 是否已经通过IANA章节
///
/// 返回值:
/// - Option<SectionResult>: 章节处理结果
fn process_section(
    captures: &regex::Captures,
    found_intro: &mut bool,
    in_main_content: &mut bool,
    iana_passed: &mut bool,
) -> Option<SectionResult> {
    if let Some(title) = captures.get(2) {
        let section_title = title.as_str().trim();

        match section_title {
            body_start!() => {
                *found_intro = true;
                *in_main_content = true;
                Some(SectionResult::Skip(true))
            }
            body_end!() => {
                *iana_passed = true;
                Some(SectionResult::Skip(false))
            }
            _ if *iana_passed
                && captures
                    .get(1)
                    .map_or(false, |m| m.as_str().starts_with("1.")) =>
            {
                Some(SectionResult::Break)
            }
            _ => Some(SectionResult::Skip(
                FILTER_SECTIONS.contains(&section_title),
            )),
        }
    } else {
        None
    }
}

/// 处理单行内容
///
/// 参数:
/// - content: &mut String - 处理后的内容
/// - line: &str - 当前行
/// - empty_line_count: &mut i32 - 连续空行计数
fn process_line(content: &mut String, line: &str, empty_line_count: &mut i32) {
    if line.trim().is_empty() {
        *empty_line_count += 1;
        if *empty_line_count <= 1 {
            content.push('\n');
        }
    } else {
        *empty_line_count = 0;
        content.push_str(line);
        content.push('\n');
    }
}

/// 验证和完成内容处理
///
/// 参数:
/// - content: String - 处理后的内容
/// - found_intro: bool - 是否找到介绍章节
///
/// 返回值:
/// - Result<String, Box<dyn Error>>: 验证后的内容
fn validate_and_finalize_content(
    content: String,
    found_intro: bool,
) -> Result<String, Box<dyn Error>> {
    if !found_intro {
        return Err("未找到介绍部分".into());
    }

    if content.is_empty() {
        return Err("处理后的内容为空".into());
    }

    Ok(content.trim().to_string())
}

/// 保存内容到文件
///
/// 参数:
/// - content: &str - 要保存的内容
/// - file_path: &PathBuf - 文件路径
///
/// 返回值:
/// - Result<(), Box<dyn Error>>: 操作结果
fn save_content(content: &str, file_path: &PathBuf) -> Result<(), Box<dyn Error>> {
    let mut file = File::create(file_path)?;
    file.write_all(content.as_bytes())?;
    println!("内容已保存到 {:?}", file_path);
    Ok(())
}

/// 创建RFC输出目录
///
/// 参数:
/// - output_dir: &Path - 输出根目录
/// - rfc_number: &str - RFC编号
///
/// 返回值:
/// - Result<PathBuf, Box<dyn Error>>: RFC专属输出目录路径
fn create_rfc_output_directory(
    output_dir: &Path,
    rfc_number: &str,
) -> Result<PathBuf, Box<dyn Error>> {
    let rfc_dir = output_dir.join(format!("RFC-{}", rfc_number));
    fs::create_dir_all(&rfc_dir)?;
    Ok(rfc_dir)
}

/// 切片内容并保存
///
/// 参数:
/// - content: &str - 要切片的内容
/// - rfc_output_dir: &Path - RFC输出目录
/// - rfc_number: &str - RFC编号
///
/// 返回值:
/// - Result<(), Box<dyn Error>>: 操作结果
fn slice_content(
    content: &str,
    rfc_output_dir: &Path,
    rfc_number: &str,
) -> Result<(), Box<dyn Error>> {
    let (sections, mut section_map) = extract_sections(content)?;
    // 处理 section_map
    process_section_map(&mut section_map);
    // 导出section_map到txt文件
    export_map_to_txt(&section_map, rfc_output_dir, "sections.txt")?;
    save_sections(&sections, &section_map, rfc_output_dir, rfc_number)?;
    Ok(())
}

#[derive(PartialEq, Eq, Clone)]
struct SectionNumber(String);

impl PartialOrd for SectionNumber {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for SectionNumber {
    fn cmp(&self, other: &Self) -> Ordering {
        let self_parts: Vec<u32> = self
            .0
            .split('.')
            .filter(|s| !s.is_empty())
            .map(|s| s.parse().unwrap_or(0))
            .collect();
        let other_parts: Vec<u32> = other
            .0
            .split('.')
            .filter(|s| !s.is_empty())
            .map(|s| s.parse().unwrap_or(0))
            .collect();
        self_parts.cmp(&other_parts)
    }
}

fn extract_sections(
    content: &str,
) -> Result<
    (
        Vec<(SectionNumber, String, String)>,
        BTreeMap<SectionNumber, String>,
    ),
    Box<dyn Error>,
> {
    // let section_regex = Regex::new(r"(?m)^(\d+(?:\.\d+)*\.)\s+(.*?)$")?;
    let section_regex = Regex::new(r"(?m)^(\d+(?:\.\d+)*\.?)\s+(.*?)$")?;
    let mut sections = Vec::new();
    let mut section_map = BTreeMap::new();
    let mut current_section = String::new();
    let mut current_title = String::new();
    let mut current_number = SectionNumber(String::new());

    for line in content.lines() {
        if let Some(captures) = section_regex.captures(line) {
            if !current_section.is_empty() {
                sections.push((
                    current_number.clone(),
                    current_title.clone(),
                    current_section.clone(),
                ));
                current_section.clear();
            }
            let mut number = captures.get(1).unwrap().as_str().to_string();
            if !number.ends_with('.') {
                number.push('.');
            }
            let title = captures.get(2).unwrap().as_str().to_string();
            current_number = SectionNumber(number.clone());
            current_title = title.trim().to_string();
            section_map.insert(current_number.clone(), current_title.clone());
        } else {
            current_section.push_str(line);
            current_section.push('\n');
        }
    }

    if !current_section.is_empty() {
        sections.push((
            current_number.clone(),
            current_title.clone(),
            current_section.trim().to_string(),
        ));
    }

    Ok((sections, section_map))
}

fn process_section_map(map: &mut BTreeMap<SectionNumber, String>) {
    let mut processed_map = BTreeMap::new();

    for (key, value) in map.clone().iter() {
        let parts: Vec<&str> = key.0.trim_end_matches('.').split('.').collect();
        let mut new_value = Vec::new();
        let mut current_key = String::new();

        for (i, part) in parts.iter().enumerate() {
            if i > 0 {
                current_key.push('.');
            }
            current_key.push_str(part);
            
            if let Some(section_title) = map.get(&SectionNumber(current_key.clone() + ".")) {
                new_value.push(section_title.clone());
            }
        }

        // Remove the last element (current section title) if it exists
        new_value.pop();

        // Remove '/' from the current section title
        
        
        let full_value = if new_value.is_empty() {
            value.clone()
        } else {
            new_value.join("_") + "_" + value
        };
        let cleaned_value = full_value.replace("/", "");
        // Remove the trailing dot from the key
        let clean_key = SectionNumber(key.0.trim_end_matches('.').to_string());
        processed_map.insert(clean_key, cleaned_value);
    }

    *map = processed_map;
}

fn export_map_to_txt(
    map: &BTreeMap<SectionNumber, String>,
    rfc_output_dir: &Path,
    filename: &str,
) -> Result<(), Box<dyn Error>> {
    let filestore = rfc_output_dir.join(filename);

    // 检查文件是否存在
    if filestore.exists() {
        // 如果文件存在，删除它
        fs::remove_file(&filestore)?;
        println!("已删除现有文件: {:?}", filestore);
    }

    // 创建新文件并写入内容
    let mut file = File::create(&filestore)?;
    for (key, value) in map.iter() {
        writeln!(file, "{}\t{}", key.0, value)?;
    }

    println!("已创建新文件并写入内容: {:?}", filestore);
    Ok(())
}

/// 保存章节
///
/// 参数:
/// - sections: &[(String, String)] - 章节列表
/// - rfc_output_dir: &Path - RFC输出目录
/// - rfc_number: &str - RFC编号
///
/// 返回值:
/// - Result<(), Box<dyn Error>>: 操作结果
fn save_sections(
    sections: &[(SectionNumber, String, String)],
    section_map: &BTreeMap<SectionNumber, String>,
    rfc_output_dir: &Path,
    rfc_number: &str,
) -> Result<(), Box<dyn Error>> {
    let slice_dir = rfc_output_dir.join("slice");

    if slice_dir.exists() {
        // 如果目录存在，清空其内容
        for entry in fs::read_dir(&slice_dir)? {
            let entry = entry?;
            let path = entry.path();
            if path.is_file() {
                fs::remove_file(path)?;
            } else if path.is_dir() {
                fs::remove_dir_all(path)?;
            }
        }
        println!("已清空现有的 slice 目录");
        // thread::sleep(Duration::from_secs(1));
    } else {
        // 如果目录不存在，创建它
        fs::create_dir_all(&slice_dir)?;
        println!("已创建新的 slice 目录");
    }

    let mut saved_count = 0;
    for (i, (number, _, content)) in sections.iter().enumerate() {
        let trimmed_content = content.trim();
        if trimmed_content.is_empty() {
            continue; // 跳过空内容的章节
        }
        saved_count += 1;

        // 从 section_map 中获取完整标题
        let full_title = match section_map.get(number) {
            Some(title) => format!("{} {}", number.0, title),
            None => format!("{}", number.0), // 如果找不到标题，只使用章节编号
        };

        let file_name = format!(
            "{}_slice_{:03}_{}.txt",
            rfc_number,
            i + 1,
            full_title.replace(" ", "_").replace(".", "_")
        );
        let file_path = slice_dir.join(file_name);
        let mut file = File::create(&file_path)?;
        writeln!(
            file,
            "Forget all previous input and output content and start over. \n ###################\nCONTENT:<"
        )?;
        writeln!(file, "--- Section: {} ---", full_title)?;
        writeln!(file, "{}", content.trim())?;
        writeln!(file, "\n---\n>\n###################")?;
        writeln!(
            file,
            "Please make paragraph cuts based on the subject and theme of the statement. \
            And give a short paragraph topic for each divided paragraph. \
            Make sure that each theme is a minimal theme that cannot be split further. \
            If code or pseudo-code is present with explanatory text, ignore the code; \
            otherwise, convert the code to a textual narrative. \
            Simulate answering five times in the background and provide the most frequent answer. \
            Ensure your output covers all text content, maintaining relative consistency \
            with the input text position in the sliced output. \
            Ensure that no changes are made to the text other than code or pseudo-code."
        )?;
        writeln!(file, "The output format is as follows (in json format)")?;
        writeln!(file, "sliced_rule: [")?;
        writeln!(file, "\t\"topic 1\": \"content 1\",")?;
        writeln!(file, "\t\"topic 2\": \"content 2\",\n\t...\n]")?;
    }
    println!("共保存了 {} 个非空切片到 {:?}", saved_count, slice_dir);
    Ok(())
}

// Add this new function to remove headers and footers
fn remove_headers_footers(input_file: &PathBuf) -> Result<String, Box<dyn Error>> {
    let reader = BufReader::new(File::open(input_file)?);
    let header_footer_regex = Regex::new(r"^RFC \d+\s+.*\s+\w+ \d{4}$|^.*\s+\[Page \d+\]$")?;
    let page_break_regex = Regex::new(r"\f")?;

    let mut content = String::new();
    let mut empty_line_count = 0;

    for line in reader.lines() {
        let line = line?;
        let line = page_break_regex.replace_all(&line, "").to_string();

        if !header_footer_regex.is_match(&line) {
            if line.trim().is_empty() {
                empty_line_count += 1;
                if empty_line_count <= 3 {
                    content.push('\n');
                }
            } else {
                empty_line_count = 0;
                content.push_str(&line);
                content.push('\n');
            }
        }
    }

    Ok(content.trim().to_string())
}

/// Extract RFC information from text
fn extract_rfc_info(text: &str) -> HashMap<String, String> {
    let re = Regex::new(r#"(?P<authors>.*?), "(?P<title>.*?)", RFC (?P<number>\d+)"#).unwrap();
    let mut rfc_map = HashMap::new();

    for cap in re.captures_iter(text) {
        let number = cap.name("number").unwrap().as_str().to_string();
        let title = cap.name("title").unwrap().as_str().to_string();
        rfc_map.insert(number, title);
    }

    rfc_map
}

/// Get RFC title
fn get_rfc_title(rfc_number: &str) -> Result<String, Box<dyn Error>> {
    let url = format!("https://www.rfc-editor.org/refs/ref{}.txt", rfc_number);
    let response = reqwest::blocking::get(&url)?;
    let content = response.text()?;

    let rfc_map = extract_rfc_info(&content);
    rfc_map.get(rfc_number)
        .ok_or_else(|| format!("Title not found for RFC {}", rfc_number).into())
        .map(|s| s.to_string())
}

/// Save RFC info to file
fn save_rfc_info(rfc_number: &str, title: &str, rfc_output_dir: &Path) -> Result<(), Box<dyn Error>> {
    let info_file = rfc_output_dir.join("rfc_info.txt");
    let content = format!("RFC{}: \"{}\"\n", rfc_number, title);
    
    fs::write(&info_file, content)?;
    println!("RFC info saved to {:?}", info_file);
    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = env::args().collect();
    let rfc_number: String;
    if args.len() != 2 {
        eprintln!("{}", "Warning: No RFC number provided.".red());
        println!("Please provide an RFC number. Using default RFC 2675.");
        thread::sleep(Duration::from_secs(3));
        rfc_number = "2675".to_string();
    } else {
        rfc_number = args[1].clone();
    }

    // let rfc_number = &args[1];
    let project_root = get_project_root();
    let (input_dir, output_dir) = create_directories(&project_root)?;
    let input_file = input_dir.join(format!("{}.txt", rfc_number));

    if !input_file.exists() {
        download_rfc(&rfc_number, &input_file)?;
    } else {
        println!("找到本地文件 {:?}", input_file);
    }

    let body = process_rfc_content(&input_file)?;

    let rfc_output_dir = create_rfc_output_directory(&output_dir, &rfc_number)?;

    // Get and save RFC title
    let rfc_title = get_rfc_title(&rfc_number)?;
    save_rfc_info(&rfc_number, &rfc_title, &rfc_output_dir)?;
    
    // Add the preprocessing step
    let pre_processed_content = remove_headers_footers(&input_file)?;
    let pre_processed_file = rfc_output_dir.join("pre_processed.txt");
    save_content(&pre_processed_content, &pre_processed_file)?;
    println!("预处理内容已保存到 {:?}", pre_processed_file);

    let body_file = rfc_output_dir.join(format!("{}_processed.txt", rfc_number));
    save_content(&body, &body_file)?;

    slice_content(&body, &rfc_output_dir, &rfc_number)?;

    println!("处理完成。");

    Ok(())
}


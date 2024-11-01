// use crate::{
//     INSTRUCTION_FOOTER, INSTRUCTION_HEADER, OUTPUT_FORMAT, PROCESSING_INSTRUCTIONS, TARGET_SECTIONS,
// };
use crate::TARGET_SECTIONS;
use rayon::prelude::*;
use regex::Regex;
use serde_json::json;
use std::cmp::Ordering;
use std::collections::{BTreeMap, HashSet};
use std::error::Error;
use std::fs::{self, File};
use std::io::BufWriter;
use std::io::{Result as IoResult, Write};
use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicUsize, Ordering as AtomicOrdering};
/// 表示 RFC 章节编号的结构体
#[derive(PartialEq, Eq, Clone)]
pub struct SectionNumber(pub String);

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

/// 切分 RFC 内容
///
/// 功能说明：
/// - 将 RFC 内容按章节切分
/// - 处理章节映射
/// - 导出章节信息到文本文件
/// - 保存切分后的章节内容
///
/// 参数：
/// - content: &str - RFC 内容
/// - rfc_output_dir: &Path - 输出目录路径
/// - rfc_number: &str - RFC 编号
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn slice_content(
    content: &str,
    rfc_output_dir: &Path,
    rfc_number: &str,
    // target_sections: &[&str],
) -> Result<(), Box<dyn Error>> {
    let (sections, mut section_map) = extract_sections(content)?;
    process_section_map(&mut section_map);
    export_map_to_txt(&section_map, rfc_output_dir, "sections.txt")?;
    save_sections(
        &sections,
        &section_map,
        rfc_output_dir,
        rfc_number,
        TARGET_SECTIONS,
    )?;
    Ok(())
}

/// 提取 RFC 章节
///
/// 功能说明：
/// - 使用正则表达式从 RFC 内容中提取章节信息
/// - 创建章节列表和章节映射
///
/// 参数：
/// - content: &str - RFC 内容
///
/// 返回：
/// - Result<(Vec<(SectionNumber, String, String)>, BTreeMap<SectionNumber, String>), Box<dyn Error>>
///   成功时返回章节列表和章节映射，失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/10/06
fn extract_sections(
    content: &str,
) -> Result<
    (
        Vec<(SectionNumber, String, String)>,
        BTreeMap<SectionNumber, String>,
    ),
    Box<dyn Error>,
> {
    let section_regex = Regex::new(r"(?m)^(\d+(?:\.\d+)*\.?)\s+(.*?)$")?;
    let mut sections = Vec::new();
    let mut section_map = BTreeMap::new();
    let mut current_section = String::with_capacity(1024);
    let mut current_title = String::new();
    let mut current_number = SectionNumber(String::new());

    for line in content.lines() {
        if let Some(captures) = section_regex.captures(line) {
            if !current_section.is_empty() {
                sections.push((
                    current_number.clone(),
                    current_title.clone(),
                    std::mem::take(&mut current_section),
                ));
            }
            let number = captures.get(1).unwrap().as_str().to_owned() + ".";
            let title = captures.get(2).unwrap().as_str().to_owned();
            current_number = SectionNumber(number);
            current_title = title.trim().to_owned();
            section_map.insert(current_number.clone(), current_title.clone());
        } else {
            current_section.push_str(line);
            current_section.push('\n');
        }
    }

    if !current_section.is_empty() {
        sections.push((current_number, current_title, current_section));
    }

    Ok((sections, section_map))
}

/// 处理章节映射
///
/// 功能说明：
/// - 处理章节映射，生成完整的章节标题
///
/// 参数：
/// - map: &mut BTreeMap<SectionNumber, String> - 章节映射
///
/// 作者：yuanfeng xie
/// 日期：2024/10/06
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

        new_value.pop();

        let full_value = if new_value.is_empty() {
            value.clone()
        } else {
            new_value.join("_") + "_" + value
        };
        let cleaned_value = full_value.replace("/", "");
        let clean_key = SectionNumber(key.0.trim_end_matches('.').to_string());
        processed_map.insert(clean_key, cleaned_value);
    }

    *map = processed_map;
}

/// 导出章节映射到文本文件
///
/// 功能说明：
/// - 将处理后的章节映射导出到指定的文本文件
///
/// 参数：
/// - map: &BTreeMap<SectionNumber, String> - 处理后的章节映射
/// - rfc_output_dir: &Path - 输出目录路径
/// - filename: &str - 输出文件名
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn export_map_to_txt(
    map: &BTreeMap<SectionNumber, String>,
    rfc_output_dir: &Path,
    filename: &str,
) -> Result<(), Box<dyn Error>> {
    let filestore = rfc_output_dir.join(filename);

    if filestore.exists() {
        fs::remove_file(&filestore)?;
        println!("delete existed files: {:?}", filestore);
    }

    let mut file = File::create(&filestore)?;
    for (key, value) in map.iter() {
        writeln!(file, "{}\t{}", key.0, value)?;
    }

    println!("create new file and write: {:?}", filestore);
    Ok(())
}

/// 保存切分后的章节
///
/// 功能说明：
/// - 准备切片目录
/// - 保存每个章节到单独的文件
///
/// 参数：
/// - sections: &[(SectionNumber, String, String)] - 章节列表
/// - section_map: &BTreeMap<SectionNumber, String> - 章节映射
/// - rfc_output_dir: &Path - 输出目录路径
/// - rfc_number: &str - RFC 编号
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn save_sections(
    sections: &[(SectionNumber, String, String)],
    section_map: &BTreeMap<SectionNumber, String>,
    rfc_output_dir: &Path,
    rfc_number: &str,
    target_sections: &[&str],
) -> Result<(), Box<dyn Error>> {
    let slice_dir = prepare_slice_directory(rfc_output_dir)?;
    let target_set: HashSet<&&str> = target_sections.iter().collect();
    let saved_count = AtomicUsize::new(0);

    // 首先在文件开头创建 CSV writer
    let csv_path = rfc_output_dir.join(format!(
        "../../agent_input_source/rfc_original_description_1.csv",
    ));
    let mut csv_writer = csv::Writer::from_path(&csv_path)?;
    // 写入 CSV 表头
    csv_writer.write_record(&["index", "section", "content"])?;

    // 先收集需要处理的章节
    let filtered_sections: Vec<_> = sections
        .iter()
        .enumerate()
        .filter(|(_, (number, _, content))| {
            (target_set.is_empty()
                || target_set
                    .iter()
                    .any(|&prefix| number.0.starts_with(prefix)))
                && !content.trim().is_empty()
        })
        .collect();

    // 并行处理 txt 文件
    filtered_sections
        .par_iter()
        .for_each(|&(i, (number, _, content))| {
            let full_title = get_full_title(number, section_map);
            let file_name = generate_file_name(rfc_number, i);
            let file_path = slice_dir.join(file_name);
            if let Ok(()) = save_section_file(&file_path, &full_title, content.trim()) {
                saved_count.fetch_add(1, AtomicOrdering::Relaxed);
            }
        });

    // 顺序写入 CSV
    let mut reorder_num = 1;
    for (_, (number, _, content)) in filtered_sections {
        let full_title = get_full_title(number, section_map);
        csv_writer.write_record(&[
            reorder_num.to_string(),
            full_title,
            content.trim().to_string(),
        ])?;
        reorder_num += 1;
    }

    // 刷新 CSV writer
    csv_writer.flush()?;
    println!(
        "共保存了 {} 个非空切片到 {:?}",
        saved_count.load(AtomicOrdering::Relaxed),
        slice_dir
    );
    Ok(())
}

/// 准备切片目录
///
/// 功能说明：
/// - 创建或清空切片目录
///
/// 参数：
/// - rfc_output_dir: &Path - RFC 输出目录路径
///
/// 返回：
/// - Result<PathBuf, Box<dyn Error>> - 成功时返回切片目录路径，失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn prepare_slice_directory(rfc_output_dir: &Path) -> Result<PathBuf, Box<dyn Error>> {
    let slice_dir = rfc_output_dir.join("slice");
    if slice_dir.exists() {
        clear_directory(&slice_dir)?;
        println!("已清空现有的 slice 目录");
    } else {
        fs::create_dir_all(&slice_dir)?;
        println!("已创建新的 slice 目录");
    }
    Ok(slice_dir)
}

/// 清空目录
///
/// 功能说明：
/// - 删除指定目录下的所有文件和子目录
///
/// 参数：
/// - dir: &Path - 要清空的目录路径
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn clear_directory(dir: &Path) -> Result<(), Box<dyn Error>> {
    for entry in fs::read_dir(dir)? {
        let entry = entry?;
        let path = entry.path();
        if path.is_file() {
            fs::remove_file(path)?;
        } else if path.is_dir() {
            fs::remove_dir_all(path)?;
        }
    }
    Ok(())
}

/// 获取完整章节标题
///
/// 功能说明：
/// - 根据章节编号从章节映射中获取完整标题
///
/// 参数：
/// - number: &SectionNumber - 章节编号
/// - section_map: &BTreeMap<SectionNumber, String> - 章节映射
///
/// 返回：
/// - String - 完整的章节标题
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn get_full_title(number: &SectionNumber, section_map: &BTreeMap<SectionNumber, String>) -> String {
    match section_map.get(number) {
        Some(title) => format!("{} {}", number.0, title),
        None => format!("{}", number.0),
    }
}

/// 生成文件名
///
/// 功能说明：
/// - 根据 RFC 编号、索引和完整标题生成文件名
///
/// 参数：
/// - rfc_number: &str - RFC 编号
/// - index: usize - 章节索引
/// - full_title: &str - 完整章节标题
///
/// 返回：
/// - String - 生成的文件名
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn generate_file_name(rfc_number: &str, index: usize) -> String {
    format!("{}_slice_{:03}.txt", rfc_number, index + 1,)
}

/// 保存章节文件
///
/// 功能说明：
/// - 将章节内容写入文件，包括指令头部和尾部
///
/// 参数：
/// - file_path: &Path - 文件路径
/// - full_title: &str - 完整章节标题
/// - content: &str - 章节内容
///
/// 返回：
/// - IoResult<()> - 成功时返回 Ok(()), 失败时返回 IO 错误
///
/// 作者：yuanfeng xie
/// 日期：2024/10/06
fn save_section_file(file_path: &Path, full_title: &str, content: &str) -> IoResult<()> {
    let file = File::create(file_path)?;

    let mut writer = BufWriter::new(file);

    write_section(&mut writer, full_title, content)?;
    // write_instructions(&mut writer)?;

    writer.flush()?;

    Ok(())
}

/// 写入章节内容
///
/// 功能说明：
/// - 将章节标题和内容写入文件，包括指令头部和尾部
///
/// 参数：
/// - file: &mut File - 文件句柄
/// - full_title: &str - 完整章节标题
/// - content: &str - 章节内容
///
/// 返回：
/// - IoResult<()> - 成功时返回 Ok(()), 失败时返回 IO 错误
///
/// 作者：yuanfeng xie
/// 日期：2024/10/06
fn write_section<W: Write>(writer: &mut W, full_title: &str, content: &str) -> IoResult<()> {
    let json_obj = json!({
        "section": full_title,
        "content": content
    });

    writeln!(
        writer,
        "{}",
        serde_json::to_string_pretty(&json_obj).unwrap()
    )?;

    Ok(())
}

use regex::Regex;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::error::Error;
use crate::{BODY_START, BODY_END, FILTER_SECTIONS};
use std::path::PathBuf;
/// 正则表达式集合结构体
pub struct Regexes {
    pub header_footer: Regex,
    pub page_break: Regex,
    pub section_title: Regex,
}

/// 处理 RFC 内容
///
/// 功能说明：
/// - 读取输入文件
/// - 使用正则表达式处理 RFC 内容
/// - 移除页眉页脚和页面分隔符
/// - 提取主要内容
///
/// 参数：
/// - input_file: &std::path::PathBuf - 输入文件路径
///
/// 返回：
/// - Result<String, Box<dyn Error>> - 处理后的 RFC 内容或错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn process_rfc_content(input_file: &std::path::PathBuf) -> Result<String, Box<dyn Error>> {
    let reader = BufReader::new(File::open(input_file)?);
    let regexes = Regexes {
        header_footer: Regex::new(r"^RFC \d+\s+.*\s+\w+ \d{4}$|^.*\s+\[Page \d+\]$")?,
        page_break: Regex::new(r"\f")?,
        section_title: Regex::new(r"^(\d+(?:\.\d+)*\.?)\s+(.*)")?,
    };

    process_content(reader, &regexes)
}

/// 处理文件内容
///
/// 功能说明：
/// - 逐行处理文件内容
/// - 移除页眉页脚和页面分隔符
/// - 提取 RFC 的主要内容部分
/// - 处理连续空行
///
/// 参数：
/// - reader: BufReader<File> - 文件读取器
/// - regexes: &Regexes - 正则表达式集合
///
/// 返回：
/// - Result<String, Box<dyn Error>> - 处理后的 RFC 内容或错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn process_content(reader: BufReader<File>, regexes: &Regexes) -> Result<String, Box<dyn Error>> {
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

/// 章节处理结果枚举
enum SectionResult {
    Skip(bool),
    Break,
}

/// 处理章节标题
///
/// 功能说明：
/// - 根据章节标题决定是否跳过该章节或结束处理
/// - 更新处理状态（是否找到介绍、是否在主要内容中、是否通过 IANA 考虑事项）
///
/// 参数：
/// - captures: &regex::Captures - 正则表达式匹配结果
/// - found_intro: &mut bool - 是否找到介绍的标志
/// - in_main_content: &mut bool - 是否在主要内容中的标志
/// - iana_passed: &mut bool - 是否通过 IANA 考虑事项的标志
///
/// 返回：
/// - Option<SectionResult> - 章节处理结果
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn process_section(
    captures: &regex::Captures,
    found_intro: &mut bool,
    in_main_content: &mut bool,
    iana_passed: &mut bool,
) -> Option<SectionResult> {
    if let Some(title) = captures.get(2) {
        let section_title = title.as_str().trim();

        match section_title {
            BODY_START => {
                *found_intro = true;
                *in_main_content = true;
                Some(SectionResult::Skip(true))
            }
            BODY_END => {
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
/// 功能说明：
/// - 处理单行内容，包括空行的处理
/// - 最多保留一个连续的空行
///
/// 参数：
/// - content: &mut String - 累积的内容字符串
/// - line: &str - 当前处理的行
/// - empty_line_count: &mut i32 - 连续空行计数
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
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

/// 验证和最终化内容
///
/// 功能说明：
/// - 验证处理后的内容是否有效
/// - 确保找到了介绍部分
/// - 确保处理后的内容不为空
///
/// 参数：
/// - content: String - 处理后的内容
/// - found_intro: bool - 是否找到介绍的标志
///
/// 返回：
/// - Result<String, Box<dyn Error>> - 验证后的内容或错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
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


/// 移除 RFC 文本中的页眉和页脚
///
/// 功能说明：
/// - 读取输入文件，移除 RFC 格式的页眉和页脚
/// - 处理空行，最多保留三个连续的空行
///
/// 参数：
/// - input_file: &PathBuf - 输入文件路径
///
/// 返回：
/// - Result<String, Box<dyn Error>> - 成功时返回处理后的文本内容，失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn remove_headers_footers(input_file: &PathBuf) -> Result<String, Box<dyn Error>> {
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

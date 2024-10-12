use std::collections::HashMap;
use std::fs::{self, File};
use std::io::{BufRead, BufReader, Write};
use std::path::{Path, PathBuf};
use std::error::Error;
use regex::Regex;
use std::env;

/// 获取项目根目录
///
/// 功能说明：
/// - 获取当前可执行文件的路径
/// - 返回项目根目录的 PathBuf
///
/// 返回：
/// - PathBuf - 项目根目录的路径
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn get_project_root() -> PathBuf {
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
/// 功能说明：
/// - 在项目根目录下创建 input 和 output 目录
///
/// 参数：
/// - project_root: &PathBuf - 项目根目录的路径
///
/// 返回：
/// - Result<(PathBuf, PathBuf), Box<dyn Error>> - 成功时返回输入和输出目录的路径，失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn create_directories(project_root: &PathBuf) -> Result<(PathBuf, PathBuf), Box<dyn Error>> {
    let input_dir = project_root.join("..\\rfc_input");
    let output_dir = project_root.join("..\\output");
    fs::create_dir_all(&input_dir)?;
    fs::create_dir_all(&output_dir)?;
    Ok((input_dir, output_dir))
}

/// 从文本中提取 RFC 信息
///
/// 功能说明：
/// - 使用正则表达式从给定文本中提取 RFC 号码和标题
///
/// 参数：
/// - text: &str - 包含 RFC 信息的文本
///
/// 返回：
/// - HashMap<String, String> - RFC 号码和标题的映射
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn extract_rfc_info(text: &str) -> HashMap<String, String> {
    let re = Regex::new(r#"(?P<authors>.*?), "(?P<title>.*?)", RFC (?P<number>\d+)"#).unwrap();
    let mut rfc_map = HashMap::new();

    for cap in re.captures_iter(text) {
        let number = cap.name("number").unwrap().as_str().to_string();
        let title = cap.name("title").unwrap().as_str().to_string();
        rfc_map.insert(number, title);
    }

    rfc_map
}

/// 保存 RFC 信息到文件
///
/// 功能说明：
/// - 将 RFC 号码和标题保存到指定目录下的 rfc_info.txt 文件中
///
/// 参数：
/// - rfc_number: &str - RFC 号码
/// - title: &str - RFC 标题
/// - rfc_output_dir: &Path - 输出目录路径
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn save_rfc_info(rfc_number: &str, title: &str, rfc_output_dir: &Path) -> Result<(), Box<dyn Error>> {
    let info_file = rfc_output_dir.join("rfc_info.txt");
    let content = format!("RFC{}: \"{}\"\n", rfc_number, title);
    
    fs::write(&info_file, content)?;
    println!("RFC info saved to {:?}", info_file);
    Ok(())
}

/// 创建 RFC 输出目录
///
/// 功能说明：
/// - 在指定的输出目录下创建以 RFC 号码命名的子目录
///
/// 参数：
/// - output_dir: &Path - 主输出目录路径
/// - rfc_number: &str - RFC 号码
///
/// 返回：
/// - Result<PathBuf, Box<dyn Error>> - 成功时返回新创建的目录路径，失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn create_rfc_output_directory(
    output_dir: &Path,
    rfc_number: &str,
) -> Result<PathBuf, Box<dyn Error>> {
    let rfc_dir = output_dir.join(format!("RFC-{}", rfc_number));
    fs::create_dir_all(&rfc_dir)?;
    Ok(rfc_dir)
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

/// 保存内容到文件
///
/// 功能说明：
/// - 将给定的内容写入指定的文件路径
///
/// 参数：
/// - content: &str - 要保存的内容
/// - file_path: &PathBuf - 目标文件路径
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn save_content(content: &str, file_path: &PathBuf) -> Result<(), Box<dyn Error>> {
    let mut file = File::create(file_path)?;
    file.write_all(content.as_bytes())?;
    println!("info saved to{:?}", file_path);
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_extract_rfc_info() {
        let text = r#"Doe, J., "Test RFC", RFC 1234, January 2023.
Smith, A., "Another RFC", RFC 5678, February 2023."#;
        let rfc_map = extract_rfc_info(text);
        assert_eq!(rfc_map.get("1234"), Some(&"Test RFC".to_string()));
        assert_eq!(rfc_map.get("5678"), Some(&"Another RFC".to_string()));
    }

}

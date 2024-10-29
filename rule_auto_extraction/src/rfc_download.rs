use reqwest;
use std::fs::{self,File};
use std::io::Write;
use std::error::Error;
use std::collections::HashMap;
use regex::Regex;
use std::path::{Path, PathBuf};
/// 下载 RFC 文档
///
/// 功能说明：
/// - 从 RFC 编辑器网站下载指定 RFC 编号的文档
/// - 将下载的内容保存到本地文件
///
/// 参数：
/// - rfc_number: &str - RFC 编号
/// - input_file: &PathBuf - 保存下载内容的本地文件路径
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功返回 Ok(()), 失败返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn download_rfc(rfc_number: &str, input_file: &PathBuf) -> Result<(), Box<dyn Error>> {
    println!("downloading RFC {}...", rfc_number);
    let url = format!("https://www.rfc-editor.org/rfc/rfc{}.txt", rfc_number);
    let response = reqwest::blocking::get(&url)?;
    let content = response.text()?;

    let mut file = File::create(input_file)?;
    file.write_all(content.as_bytes())?;
    println!("downloaded，saved to {:?}", input_file);
    Ok(())
}

/// 获取 RFC 标题
///
/// 功能说明：
/// - 从 RFC 引用页面获取指定 RFC 编号的标题
/// - 解析返回的内容以提取标题信息
///
/// 参数：
/// - rfc_number: &str - RFC 编号
///
/// 返回：
/// - Result<String, Box<dyn Error>> - 成功返回 RFC 标题，失败返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
pub fn get_rfc_title(rfc_number: &str) -> Result<String, Box<dyn Error>> {
    let url = format!("https://www.rfc-editor.org/refs/ref{}.txt", rfc_number);
    let response = reqwest::blocking::get(&url)?;
    let content = response.text()?;

    let rfc_map = extract_rfc_info(&content);
    rfc_map.get(rfc_number)
        .ok_or_else(|| format!("Title not found for RFC {}", rfc_number).into())
        .map(|s| s.to_string())
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_extract_rfc_info() {
        let text = r#"Doe, J., "Test RFC", RFC 1234, January 2023. Smith, A., "Another RFC", RFC 5678, February 2023."#;
        let rfc_map = extract_rfc_info(text);
        assert_eq!(rfc_map.get("1234"), Some(&"Test RFC".to_string()));
        assert_eq!(rfc_map.get("5678"), Some(&"Another RFC".to_string()));
    }

}
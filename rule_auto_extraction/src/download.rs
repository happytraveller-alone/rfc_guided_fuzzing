use reqwest;
use std::fs::File;
use std::io::Write;
use std::path::PathBuf;
use std::error::Error;

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

    let rfc_map = crate::utils::extract_rfc_info(&content);
    rfc_map.get(rfc_number)
        .ok_or_else(|| format!("Title not found for RFC {}", rfc_number).into())
        .map(|s| s.to_string())
}

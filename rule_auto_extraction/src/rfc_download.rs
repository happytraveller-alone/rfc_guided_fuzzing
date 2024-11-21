use reqwest;
use std::fs::File;
use std::io::Write;
use std::error::Error;
use std::path::PathBuf;
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

use reqwest;
use std::fs::File;
use std::io::Write;
use std::path::PathBuf;
use std::error::Error;


pub fn download_rfc(rfc_number: &str, input_file: &PathBuf) -> Result<(), Box<dyn Error>> {
    println!("正在下载 RFC {}...", rfc_number);
    let url = format!("https://www.rfc-editor.org/rfc/rfc{}.txt", rfc_number);
    let response = reqwest::blocking::get(&url)?;
    let content = response.text()?;

    let mut file = File::create(input_file)?;
    file.write_all(content.as_bytes())?;
    println!("下载完成，已保存到 {:?}", input_file);
    Ok(())
}

pub fn get_rfc_title(rfc_number: &str) -> Result<String, Box<dyn Error>> {
    let url = format!("https://www.rfc-editor.org/refs/ref{}.txt", rfc_number);
    let response = reqwest::blocking::get(&url)?;
    let content = response.text()?;

    let rfc_map = crate::utils::extract_rfc_info(&content);
    rfc_map.get(rfc_number)
        .ok_or_else(|| format!("Title not found for RFC {}", rfc_number).into())
        .map(|s| s.to_string())
}

use std::fs::{self, File};
use std::io::Write;
use std::path::{Path, PathBuf};
use std::error::Error;
use std::env;
use std::process::{Command, exit};
use std::os::windows::process::CommandExt;
use colored::*;
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



pub fn check_python_version() -> Result<(), Box<dyn Error>> {
    let output = Command::new("cmd").creation_flags(0x08000000).stdout(std::process::Stdio::piped()).stderr(std::process::Stdio::piped())
        .args(&["/C", "python", "--version"])
        .output()
        .expect("Failed to execute Python version check");

    let version_output = String::from_utf8_lossy(&output.stdout);
    let error_output = String::from_utf8_lossy(&output.stderr);

    if !version_output.contains("Python 3.12") {
        eprintln!("Python 3.12 is required but not found.");
        eprintln!("Python version output: {}", version_output);
        eprintln!("Error output: {}", error_output);
        exit(1);
    }
    println!("{}","Python version satisfied".green());
    Ok(())
}

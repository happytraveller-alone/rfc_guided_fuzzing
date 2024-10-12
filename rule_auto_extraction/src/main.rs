// use crate::TARGET_SECTIONS;
use colored::*;
use rule_auto_extraction::{download, process, slice, utils};
use std::{env,thread};
use std::error::Error;
use std::time::Duration;
use std::process::{Command, exit};
use std::path::{Path,PathBuf};
use std::os::windows::process::CommandExt;
use csv::{Reader, WriterBuilder};
use regex::Regex;
/// 运行 RFC 处理程序的主函数
///
/// 功能说明：
/// - 处理命令行参数
/// - 下载或使用本地 RFC 文件
/// - 处理 RFC 内容
/// - 创建输出目录
/// - 获取 RFC 标题
/// - 保存处理后的内容
/// - 切片处理后的内容
///
/// 参数：
/// - args: Vec<String> - 命令行参数
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn run(args: Vec<String>) -> Result<PathBuf, Box<dyn Error>> {
    // 获取 RFC 编号，如果没有提供则使用默认值
    let rfc_number = if args.len() != 2 {
        eprintln!("{}", "Warning: No RFC number provided.".red());
        println!("Please provide an RFC number. Using default RFC 8446.");
        thread::sleep(Duration::from_secs(3));
        "8446".to_string()
    } else {
        args[1].clone()
    };

    // 获取项目根目录并创建输入输出目录
    let project_root = utils::get_project_root();
    let (input_dir, output_dir) = utils::create_directories(&project_root)?;
    let input_file = input_dir.join(format!("{}.txt", rfc_number));
    println!("Starting to process RFC {}", rfc_number);

    // 如果本地文件不存在，则下载 RFC 文件
    if !input_file.exists() {
        println!("Downloading RFC {}", rfc_number);
        download::download_rfc(&rfc_number, &input_file)?;
    } else {
        println!("Found local file {:?}", input_file);
    }

    // 处理 RFC 内容
    println!("Processing RFC content");
    let body = process::process_rfc_content(&input_file)?;

    // 创建输出目录
    println!("Creating output directory");
    let rfc_output_dir = utils::create_rfc_output_directory(&output_dir, &rfc_number)?;

    // 获取 RFC 标题并保存信息
    println!("Getting RFC title");
    let rfc_title = download::get_rfc_title(&rfc_number)?;
    utils::save_rfc_info(&rfc_number, &rfc_title, &rfc_output_dir)?;

    // 移除页眉和页脚
    println!("Removing headers and footers");
    let pre_processed_content = utils::remove_headers_footers(&input_file)?;
    let pre_processed_file = rfc_output_dir.join("pre_processed.txt");
    utils::save_content(&pre_processed_content, &pre_processed_file)?;
    println!("Pre-processed content saved to {:?}", pre_processed_file);

    // 保存处理后的内容
    println!("Saving processed content");
    let body_file = rfc_output_dir.join(format!("{}_processed.txt", rfc_number));
    utils::save_content(&body, &body_file)?;

    // 切片处理内容
    println!("Slicing content");
    slice::slice_content(&body, &rfc_output_dir, &rfc_number)?;

    println!("Processing complete.");

    Ok(rfc_output_dir)
}

fn check_python_version() -> Result<(), Box<dyn Error>> {
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

fn activate_virtual_env() -> Result<(), Box<dyn Error>> {
    let activate_path = Path::new("python_virtual_env/Scripts/activate");
    if !activate_path.exists() {
        eprintln!("Virtual environment activation script not found at {:?}", activate_path);
        exit(1);
    }
    println!("{}","Virtual environment activation script founded".green());
    Ok(())
}

fn run_slice_script(rfc_output_dir: &PathBuf) -> Result<(), Box<dyn Error>> {
    let slice_script_path = Path::new("python_scripts/slice_rfc.py");
    if !slice_script_path.exists() {
        eprintln!("Python script not found at {:?}", slice_script_path);
        exit(1);
    }
    println!("{}","succeed to find slice_rfc.py script".green());
    // 激活虚拟环境并运行 Python 脚本
    let activate_command = Command::new("cmd")
        .creation_flags(0x08000000)
        .args(&["/C", "python_virtual_env\\Scripts\\activate && python"])
        .arg(slice_script_path.to_str().unwrap())
        .arg(rfc_output_dir.join("slice_test").to_str().unwrap())
        .stdout(std::process::Stdio::piped())
        .stderr(std::process::Stdio::piped())
        .spawn() // 非阻塞地启动进程
        .expect("Failed to execute slice_rfc.py script");

    // 等待脚本执行完毕并获取输出
    let slice_output = activate_command
        .wait_with_output()
        .expect("Failed to wait on slice_rfc.py script");

    // 检查脚本执行结果
    if !slice_output.status.success() {
        eprintln!("Failed to run slice_rfc.py script.");
        let slice_error = String::from_utf8_lossy(&slice_output.stderr);
        eprintln!("Error: {}", slice_error);
        exit(1);
    }

    // 打印脚本的标准输出
    let slice_stdout = String::from_utf8_lossy(&slice_output.stdout);
    println!("slice_rfc.py output: {}", slice_stdout);
    // Ok(())
    Ok(())
}

fn judge_rule(rfc_results_path: &PathBuf) -> Result<(), Box<dyn Error>> {
    let mut reader = Reader::from_path(rfc_results_path)?;
    let mut headers = reader.headers()?.clone();
    let content_index = headers.iter().position(|h| h == "Content").ok_or("Content column not found")?;
    let re = Regex::new(r"(?i)\b(MUST|MUST NOT|SHALL|REQUIRED|SHALL NOT)\b")?;

    // 增加新列 "RuleMatch"
    headers.push_field("RuleMatch");

    let output_path = rfc_results_path.with_file_name("rfc_results_update_judge.csv");
    let mut writer = WriterBuilder::new().from_path(&output_path)?;
    writer.write_record(&headers)?;

    let mut total_rules = 0;
    let mut count_ones = 0;
    let mut count_zeros = 0;

    for result in reader.records() {
        let mut record = result?;
        let content = record.get(content_index).unwrap_or("");
        let value = if re.is_match(content) { 1 } else { 0 };
        record.push_field(&value.to_string());
        writer.write_record(&record)?;

        total_rules += 1;
        if value == 1 {
            count_ones += 1;
        } else {
            count_zeros += 1;
        }
    }

    writer.flush()?;
    println!("Updated CSV saved to {:?}", output_path);
    println!("Total rules: {}, Number of 1s: {}, Number of 0s: {}", total_rules, count_ones, count_zeros);
    Ok(())
}


/// 程序入口点
///
/// 功能说明：
/// - 收集命令行参数
/// - 调用 run 函数执行主要逻辑
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/07/29
fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = env::args().collect();
    let rfc_output_dir = run(args)?;
    // 检查 Python 版本
    check_python_version()?;

    // 检查并激活虚拟环境
    activate_virtual_env()?;

    // 检查 agent_input_source 文件夹中是否存在 rfc_results.csv
    let agent_input_source_path = Path::new("agent_input_source");
    let rfc_results_path = agent_input_source_path.join("rfc_results.csv");

    if rfc_results_path.exists() {
        println!("rfc_results.csv found, skipping run_slice_script.");
        judge_rule(&rfc_results_path)?;
    } else {
        // 在虚拟环境中运行 slice_rfc.py 脚本
        run_slice_script(&rfc_output_dir)?;
    }
    
    Ok(())
}

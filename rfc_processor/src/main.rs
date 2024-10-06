// use crate::TARGET_SECTIONS;
use colored::*;
use rfc_processor::{download, process, slice, utils};
use std::env;
use std::error::Error;
use std::thread;
use std::time::Duration;

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
fn run(args: Vec<String>) -> Result<(), Box<dyn Error>> {
    // 获取 RFC 编号，如果没有提供则使用默认值
    let rfc_number = if args.len() != 2 {
        eprintln!("{}", "Warning: No RFC number provided.".red());
        println!("Please provide an RFC number. Using default RFC 2675.");
        thread::sleep(Duration::from_secs(3));
        "2675".to_string()
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
    run(args)
}

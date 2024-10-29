use colored::*;
use rule_auto_extraction::{rfc_download, rfc_section_processor, rfc_section_slice, utils, script};
use std::{env,thread};
use std::error::Error;
use std::time::Duration;
use std::path::{Path,PathBuf};

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
    // let rfc_output_dir = run(args)?;
    run(args)?;
    // 检查 Python 版本
    script::check_python_version()?;

    // // 检查并激活虚拟环境
    script::activate_virtual_env()?;

    let agent_input_source_path = Path::new("agent_input_source");
    // // 脚本执行
    process_rfc_results(agent_input_source_path)?;
    
    Ok(())
}


/// 主处理函数
fn process_rfc_results(agent_input_source_path: &Path) -> Result<(), Box<dyn Error>> {
    let processing_steps = script::get_processing_steps();
    match script::find_first_missing_step(&processing_steps, agent_input_source_path) {
        Some(start_index) => {
            script::execute_steps_from_index(&processing_steps, start_index, agent_input_source_path)?;
        },
        None => {
            println!("All files exist. Nothing to do.");
        }
    }
    Ok(())
}

/// 运行 RFC 处理程序的主函数
///
/// 功能说明：
/// - 处理命令行参数,下载或使用本地 RFC 文件,处理 RFC 内容
/// - 创建输出目录,获取 RFC 标题,保存处理后的内容,切片处理后的内容
///
/// 参数：
/// - args: Vec<String> - 命令行参数
///
/// 返回：
/// - Result<(), Box<dyn Error>> - 成功时返回 Ok(()), 失败时返回错误
///
/// 作者：yuanfeng xie
/// 日期：2024/10/24
struct RfcProcessor {
    rfc_number: String,
    input_dir: PathBuf,
    output_dir: PathBuf,
}

impl RfcProcessor {
    fn new(args: Vec<String>) -> Result<Self, Box<dyn Error>> {
        // 处理 RFC 编号
        let rfc_number = if args.len() != 2 {
            eprintln!("{}", "Warning: No RFC number provided.".red());
            println!("Please provide an RFC number. Using default RFC 8446.");
            thread::sleep(Duration::from_secs(3));
            "8446".to_string()
        } else {
            args[1].clone()
        };

        // 创建必要的目录
        let project_root = utils::get_project_root();
        let (input_dir, output_dir) = utils::create_directories(&project_root)?;

        Ok(RfcProcessor {
            rfc_number,
            input_dir,
            output_dir,
        })
    }

    fn process(&self) -> Result<PathBuf, Box<dyn Error>> {
        println!("Starting to process RFC {}", self.rfc_number);
        
        // 准备输入输出路径
        let input_file = self.input_dir.join(format!("{}.txt", self.rfc_number));
        let rfc_output_dir = utils::create_rfc_output_directory(&self.output_dir, &self.rfc_number)?;

        // 检查所有必需文件是否已存在
        let required_files = [
            "pre_processed.txt",
            &format!("{}_processed.txt", self.rfc_number),
            "rfc_info.txt",
            "sections.txt",
            // &format!("{}_sliced.txt", self.rfc_number),
        ];

        let all_files_exist = input_file.exists() && 
            required_files.iter()
                .all(|file| rfc_output_dir.join(file).exists());

        if all_files_exist {
            println!("Found all processed RFC files. Processing complete.");
            return Ok(rfc_output_dir);
        }

        // 如果文件不完整，重新处理
        if !input_file.exists() {
            println!("Downloading RFC {}", self.rfc_number);
            rfc_download::download_rfc(&self.rfc_number, &input_file)?;
        }

        // 处理 RFC 内容
        println!("Processing RFC content");
        let body = rfc_section_processor::process_rfc_content(&input_file)?;
        
        // 保存 RFC 信息和预处理内容
        let rfc_title = rfc_download::get_rfc_title(&self.rfc_number)?;
        rfc_download::save_rfc_info(&self.rfc_number, &rfc_title, &rfc_output_dir)?;

        let pre_processed_content = rfc_section_processor::remove_headers_footers(&input_file)?;
        let pre_processed_file = rfc_output_dir.join("pre_processed.txt");
        utils::save_content(&pre_processed_content, &pre_processed_file)?;
        
        // 保存处理后的内容
        let body_file = rfc_output_dir.join(format!("{}_processed.txt", self.rfc_number));
        utils::save_content(&body, &body_file)?;

        // 切片处理
        rfc_section_slice::slice_content(&body, &rfc_output_dir, &self.rfc_number)?;

        println!("Processing complete.");
        Ok(rfc_output_dir)
    }
}

fn run(args: Vec<String>) -> Result<PathBuf, Box<dyn Error>> {
    let processor = RfcProcessor::new(args)?;
    processor.process()
}
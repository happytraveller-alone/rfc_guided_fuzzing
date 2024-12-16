use clap::{arg, ArgAction, Command};
// use colored::*;
use rule_auto_extraction::{
    processing_script, rfc_download, rfc_section_processor, rfc_section_slice, utils,
};
use std::{
    // env,
    error::Error,
    path::{Path, PathBuf},
    // thread,
    // time::Duration,
};

const RFC_NUMBER: &str = "8446";

macro_rules! create_option_getter {
    ($fn_name:ident, $arg_name:expr, $default:expr, $t:ty) => {
        pub fn $fn_name(matches: &clap::ArgMatches) -> $t {
            matches
                .get_one::<String>($arg_name)
                .unwrap_or(&$default.to_string())
                .parse::<$t>()
                .unwrap_or($default)
        }
    };
}
// 使用宏来定义函数
create_option_getter!(get_rfc_number, "rfc", RFC_NUMBER.to_string(), String);

macro_rules! create_flag_getter {
    ($fn_name:ident, $flag:expr) => {
        pub fn $fn_name(matches: &clap::ArgMatches) -> bool {
            matches.get_flag($flag)
        }
    };
}

// 使用宏来定义函数
create_flag_getter!(get_parse, "parse");
create_flag_getter!(get_no_parse, "no_parse");
create_flag_getter!(get_extraction, "extract");

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
    // get environment test args
    let matches: clap::ArgMatches = get_command_matches();
    let rfc_number: String = get_rfc_number(&matches);
    if get_parse(&matches) {
        let processor = RfcProcessor::new(rfc_number)?;
        processor.process()?;
    } else if get_no_parse(&matches) {
        println!("No parse");
    } else {
        println!("Please specify a valid option with parse or no_parse");
    }
    if get_extraction(&matches) {
        println!("Extraction");
        // 规定读取文件的位置
        let agent_input_source_path = Path::new("agent_input_source");
        // 脚本执行
        process_rfc_results(agent_input_source_path)?;
    } else {
        println!("Please specify a valid option with extract");
    }

    Ok(())
}

fn get_command_matches() -> clap::ArgMatches {
    Command::new("Rule Extraction Automation Tool")
        .about("A rule extraction automation tool for rfc documents")
        .arg(arg!(-r --rfc <RFC_NUMBER> "Sets the RFC number").required(true))
        .arg(
            arg!(--parse "Enables rfc document parse")
                .default_value("false")
                .action(ArgAction::SetTrue),
        )
        .arg(
            arg!(--no_parse "Enables rfc document parse")
                .default_value("false")
                .action(ArgAction::SetTrue),
        )
        .arg(
            arg!(--extract "Enables rfc document rule extraction")
                .default_value("false")
                .action(ArgAction::SetTrue),
        )
        .get_matches()
}

/// 主处理函数
fn process_rfc_results(agent_input_source_path: &Path) -> Result<(), Box<dyn Error>> {
    let processing_steps = processing_script::get_processing_steps();
    match processing_script::find_first_missing_step(&processing_steps, agent_input_source_path) {
        Some(start_index) => {
            // 检查 Python 版本
            utils::check_python_version()?;
            processing_script::execute_steps_from_index(
                &processing_steps,
                start_index,
                agent_input_source_path,
            )?;
        }
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
    fn new(rfc_number: String) -> Result<Self, Box<dyn Error>> {
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
        let rfc_output_dir =
            utils::create_rfc_output_directory(&self.output_dir, &self.rfc_number)?;

        // 检查所有必需文件是否已存在
        let required_files = [
            "pre_processed.txt",
            &format!("{}_processed.txt", self.rfc_number),
            "sections.txt",
        ];

        let all_files_exist = input_file.exists()
            && required_files
                .iter()
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

        // // 保存 RFC 信息和预处理内容
        // let rfc_title = rfc_download::get_rfc_title(&self.rfc_number)?;
        // rfc_download::save_rfc_info(&self.rfc_number, &rfc_title, &rfc_output_dir)?;

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

// fn run(args: Vec<String>) -> Result<PathBuf, Box<dyn Error>> {
//     let processor = RfcProcessor::new(args)?;
//     processor.process()
// }

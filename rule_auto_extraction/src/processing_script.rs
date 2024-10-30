use std::process::{Command, Child, exit};
use std::{env,error::Error,path::Path};
use colored::*;
use std::sync::{Arc, atomic::{AtomicBool, Ordering}};
use serde::{Deserialize, Serialize};
use crate::{rust_csv_processor,python_csv_processor};

// 定义操作类型枚举
#[derive(Clone)]
pub enum StepAction {
    PythonScript(PythonScriptConfig),
    RustFunction(fn(&Path) -> Result<(), Box<dyn Error>>),
}

// Python脚本的配置
#[derive(Clone, Serialize, Deserialize)]
pub struct PythonScriptConfig {
    script_name: String,
    bot_name: String,
    additional_fields: Vec<String>,
    input_fields: Vec<String>,
}

pub struct ProcessStep {
    input_file: Option<&'static str>,
    output_file: &'static str,
    description: &'static str,
    action: StepAction,
}

// 创建一个函数来获取Python配置
fn get_python_config(script_name: &str) -> PythonScriptConfig {
    match script_name {
        "slice_rfc" => PythonScriptConfig {
            script_name: "slice_rfc.py".to_string(),
            bot_name: "semantic_analysis".to_string(),
            additional_fields: vec![
                "ID".to_string(),
                "Section".to_string(),
                "Title".to_string(),
                "Content".to_string()
            ],
            input_fields: vec!["content".to_string()],
        },
        "extract_rule" => PythonScriptConfig {
            script_name: "extract_rule.py".to_string(),
            bot_name: "TLSRFC_EXTRACT".to_string(),
            additional_fields: vec!["ExtractedRule".to_string()],
            input_fields: vec![
                "Section".to_string(),
                "Title".to_string(),
                "Content".to_string()
            ],
        },
        "classify_rule" => PythonScriptConfig {
            script_name: "classify_rule.py".to_string(),
            bot_name: "rule_classification".to_string(),
            additional_fields: vec![
                "classification_full_result".to_string(),
                "classification_result".to_string(),
                "MQD".to_string(),
                "CRA".to_string()
            ],
            input_fields: vec!["SlicedRule".to_string()],
        },
        "generate_mutation" => PythonScriptConfig {
            script_name: "generate_mutation.py".to_string(),
            bot_name: "generate_mutation".to_string(),
            additional_fields: vec!["mutation_output".to_string()],
            input_fields: vec!["violation_input".to_string()],
        },
        _ => panic!("Unknown script name: {}", script_name),
    }
}

/// 定义处理步骤
pub fn get_processing_steps() -> Vec<ProcessStep> {
    vec![
        ProcessStep {
            input_file: None,
            output_file: "rfc_results.csv",
            description: "Running slice script",
            action: StepAction::PythonScript(get_python_config("slice_rfc")),
        },
        ProcessStep {
            input_file: Some("rfc_results.csv"),
            output_file: "rfc_results_update_judge.csv",
            description: "Running judge rule",
            action: StepAction::RustFunction(|path| rust_csv_processor::judge_rule(&path.join("rfc_results.csv"))),
        },
        ProcessStep {
            input_file: Some("rfc_results_update_judge.csv"),
            output_file: "rfc_results_extracted_rule.csv",
            description: "Running extract rule script",
            action: StepAction::PythonScript(get_python_config("extract_rule")),
        },
        ProcessStep {
            input_file: Some("rfc_results_slice_rule.csv"),
            output_file: "rfc_results_update_slice_rule.csv",
            description: "Running update sliced rules script",
            action: StepAction::RustFunction(|path| rust_csv_processor::run_generate_update_slice_script(
                &path.join("rfc_results_slice_rule.csv"),
                &path.join("rfc_results_update_slice_rule.csv")
            )),
        },
        ProcessStep {
            input_file: Some("rfc_results_update_slice_rule.csv"),
            output_file: "rfc_results_classify_slice_rule.csv",
            description: "Running sliced rule classification script",
            action: StepAction::PythonScript(get_python_config("classify_rule")),
        },
        ProcessStep {
            input_file: Some("rfc_results_classify_slice_rule.csv"),
            output_file: "rfc_results_filter_classify_rule_simple.csv",
            description: "Running rule classify script",
            action: StepAction::RustFunction(|path| rust_csv_processor::run_rule_classify_script(
                &path.join("rfc_results_classify_slice_rule.csv"),
                &path.join("rfc_results_filter_classify_rule_simple.csv"),
                "1",
            )),
        },
        ProcessStep {
            input_file: Some("rfc_results_classify_slice_rule.csv"),
            output_file: "rfc_results_filter_classify_rule_complex.csv",
            description: "Running rule classify script",
            action: StepAction::RustFunction(|path| rust_csv_processor::run_rule_classify_script(
                &path.join("rfc_results_classify_slice_rule.csv"),
                &path.join("rfc_results_filter_classify_rule_complex.csv"),
                "2",
            )),
        },
        ProcessStep {
            input_file: Some("rfc_results_filter_classify_rule_simple.csv"),
            output_file: "rule_simple_violation_input.csv",
            description: "Running rule violation input generation script",
            action: StepAction::RustFunction(|path| rust_csv_processor::run_generate_mutation_descrip_input(
                &path.join("rfc_results_filter_classify_rule_simple.csv"),
                &path.join("rule_simple_violation_input.csv"),
            )),
        },
        ProcessStep {
            input_file: Some("rule_simple_violation_input.csv"),
            output_file: "rule_simple_mutation.csv",
            description: "Running rule violation input generation script",
            action: StepAction::PythonScript(get_python_config("generate_mutation")),
        }
    ]
}

/// 找到第一个需要处理的步骤的索引
pub fn find_first_missing_step(steps: &[ProcessStep], base_path: &Path) -> Option<usize> {
    let mut last_missing_index = None;
    let current_dir = env::current_dir().unwrap();
    let base_path_dir = current_dir.join(base_path);
    
    // 从后向前遍历
    let mut i = steps.len() - 1;
    loop {
        let step = &steps[i];
        let output_path = base_path_dir.join(&step.output_file);
        
        if !output_path.exists() {
            // println!("processing index {}", i);
            
            // 更新最后找到的缺失步骤索引
            last_missing_index = Some(i);
            
            // 检查输入文件
            if let Some(input_file) = &step.input_file {
                let input_path = base_path_dir.join(input_file);
                if !input_path.exists() && i > 0 {
                    i -= 1;
                    continue;
                }
            }
        }
        
        if i == 0 {
            break;
        }
        i -= 1;
    }

    last_missing_index
}

/// 执行从指定索引开始的所有步骤
pub fn execute_steps_from_index(
    steps: &[ProcessStep], 
    start_index: usize, 
    base_path: &Path
) -> Result<(), Box<dyn Error>> {
    let current_dir = env::current_dir()?;
    let base_path_dir = current_dir.join(base_path);

    for step in &steps[start_index..] {
        println!("{}", format!("Executing: {} - {}", step.output_file, step.description).green());
        
        match &step.action {
            StepAction::PythonScript(config) => {
                // 使用配置信息执行Python脚本
                python_csv_processor::run_python_script(
                    &config.script_name,
                    &config.bot_name,
                    step.input_file.map(|f| base_path_dir.join(f)),
                    &base_path_dir.join(step.output_file),
                    &config.additional_fields,
                    &config.input_fields,
                    "csv",
                )?;
            },
            StepAction::RustFunction(func) => {
                // 直接执行Rust函数
                func(&base_path_dir)?;
            }
        }
    }
    Ok(())
}

fn get_package_version_pip(package_name: &str) -> Result<String, Box<dyn std::error::Error>> {
    let output = Command::new("pip")
        .args(&["show", package_name])
        .output()?;
    
    let output_str = String::from_utf8(output.stdout)?;
    
    // 解析输出找到版本
    for line in output_str.lines() {
        if line.starts_with("Version: ") {
            return Ok(line["Version: ".len()..].to_string());
        }
        if line.starts_with("Location: ") {
            return Ok(line["Location: ".len()..].to_string());
        }
    }
    
    Err("Version not found".into())
}





fn setup_ctrlc_handler(child_process: &mut Child) -> Result<(), Box<dyn Error>> {
    // 创建一个标志来追踪是否已经处理过中断信号
    let handled = Arc::new(AtomicBool::new(false));
    let handled_clone = handled.clone();

    // 获取子进程的ID
    let child_id = child_process.id();

    ctrlc::set_handler(move || {
        // 确保处理器只执行一次
        if !handled_clone.swap(true, Ordering::SeqCst) {
            println!("{}","\nReceived Ctrl+C! Terminating child process...".red());
            
            // 在 Windows 上终止进程
            #[cfg(windows)]
            {
                Command::new("taskkill")
                    .args(&["/F", "/T", "/PID", &child_id.to_string()])
                    .output()
                    .expect("Failed to kill child process");
            }

            // 在 Unix 系统上终止进程
            #[cfg(unix)]
            unsafe {
                libc::kill(child_id as i32, libc::SIGTERM);
            }

            // 退出主程序
            exit(0);
        }
    })?;

    Ok(())
}










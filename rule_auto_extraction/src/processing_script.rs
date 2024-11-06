// use std::process::{Command, Child, exit};
use std::{env,error::Error,path::Path};
use colored::*;
// use std::sync::{Arc, atomic::{AtomicBool, Ordering}};
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
                "Section".to_string(),
                "Title".to_string(),
                "Content".to_string()
            ],
            input_fields: vec![
                "section".to_string(),
                "content".to_string()
            ],
        },
        // construction_rule_type, construction_explicitness, construction_base, 
        // processing_rule_type, processing_explicitness, processing_base
        "extract_rule" => PythonScriptConfig {
            script_name: "extract_rule.py".to_string(),
            bot_name: "TLSRFC_EXTRACT".to_string(),
            additional_fields: vec![
                "section".to_string(),
                "title".to_string(),
                "construction_rule_type".to_string(),
                "construction_explicitness".to_string(),
                "construction_base".to_string(),
                "processing_rule_type".to_string(),
                "processing_explicitness".to_string(),
                "processing_base".to_string(),
            ],
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
        // 源文件的section+content作为输入
        // tmp文件：index+section+content+result(包含多个解析后的content)
        // output文件: 解析content, 解析后的内容，按照所属section, 解析为index+<section>+(title+content)
        // 用的struct, semantic_entry, section_name, title, content
        ProcessStep {
            input_file: Some("rfc_original_description_1.csv"),
            output_file: "rfc_sliced_description_2.csv",
            description: "Get Summary Title and Slice RFC description based on Title",
            action: StepAction::PythonScript(get_python_config("slice_rfc")),
        },
        ProcessStep {
            input_file: Some("rfc_sliced_description_2.csv"),
            output_file: "rfc_sliced_description_filter_3.csv",
            description: "Filter Description with Sentiment Rule(MUST,MUST NOT...)",
            action: StepAction::RustFunction(|path| rust_csv_processor::judge_rule(
                &path.join("rfc_sliced_description_2.csv"),
                &path.join("rfc_sliced_description_filter_3.csv")
            )),
        },
        // section+title+content 作为输入
        // tmp文件：index+section+title+content+result(包含多个解析rule)
        // output文件: index+<section+title>+(rule)
        // 用的struct, rule_entry, 
        // section, title, 
        // construction_rule_type, construction_explicitness, construction_base, 
        // processing_rule_type, processing_explicitness, processing_base
        ProcessStep {
            input_file: Some("rfc_sliced_description_filter_3.csv"),
            output_file: "rfc_description_extract_rule_4.csv",
            description: "Running extract rule script",
            action: StepAction::PythonScript(get_python_config("extract_rule")),
        },
        ProcessStep {
            input_file: Some("rfc_description_extract_rule_4.csv"),
            output_file: "rfc_violation_generation_filter_rule_5.csv",
            description: "Running update sliced rules script",
            action: StepAction::RustFunction(|path| rust_csv_processor::run_generate_update_slice_script(
                &path.join("rfc_description_extract_rule_4.csv"),
                &path.join("rfc_violation_generation_filter_rule_5.csv")
            )),
        },
        // ProcessStep {
        //     input_file: Some("rule_simple_violation_input.csv"),
        //     output_file: "rule_simple_mutation.csv",
        //     description: "Running rule violation input generation script",
        //     action: StepAction::PythonScript(get_python_config("generate_mutation")),
        // }
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

// fn get_package_version_pip(package_name: &str) -> Result<String, Box<dyn std::error::Error>> {
//     let output = Command::new("pip")
//         .args(&["show", package_name])
//         .output()?;
    
//     let output_str = String::from_utf8(output.stdout)?;
    
//     // 解析输出找到版本
//     for line in output_str.lines() {
//         if line.starts_with("Version: ") {
//             return Ok(line["Version: ".len()..].to_string());
//         }
//         if line.starts_with("Location: ") {
//             return Ok(line["Location: ".len()..].to_string());
//         }
//     }
    
//     Err("Version not found".into())
// }
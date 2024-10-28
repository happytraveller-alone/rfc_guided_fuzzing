use std::process::{Command, exit};
use std::os::windows::process::CommandExt;
use csv::{Reader, Writer, WriterBuilder};
use regex::Regex;
use std::path::{Path,PathBuf};
use std::error::Error;
use colored::*;
use std::env;
use std::sync::Arc;
use std::sync::atomic::{AtomicBool, Ordering};
use std::process::Child;
use serde::{Deserialize, Serialize};
// use ctrlc::*;
pub struct ProcessStep {
    input_file: Option<&'static str>,
    output_file: &'static str,
    description: &'static str,
    action: fn(&Path) -> Result<(), Box<dyn Error>>,
}

#[derive(Debug, Serialize, Deserialize)]
struct Base {
    first_rule: String,
    second_rule: String,
}

#[derive(Debug, Serialize, Deserialize)]
struct RuleStructure {
    description: String,
    base: Base,
}

/// 定义处理步骤
pub fn get_processing_steps() -> Vec<ProcessStep> {
    vec![
        ProcessStep {
            input_file: None,
            output_file: "rfc_results.csv",
            description: "Running slice script",
            action: |_| run_slice_script(),
        },
        ProcessStep {
            input_file: Some("rfc_results.csv"),
            output_file: "rfc_results_update_judge.csv",
            description: "Running judge rule",
            action: |path| judge_rule(&path.join("rfc_results.csv")),
        },
        ProcessStep {
            input_file: Some("rfc_results_update_judge.csv"),
            output_file: "rfc_results_extracted_rule.csv",
            description: "Running extract rule script",
            action: |_| run_extract_rule_script(),
        },
        ProcessStep {
            input_file: Some("rfc_results_slice_rule.csv"),
            output_file: "rfc_results_update_slice_rule.csv",
            description: "Running update sliced rules script",
            action: |path| run_generate_update_slice_script(
                &path.join("rfc_results_slice_rule.csv"),
                &path.join("rfc_results_update_slice_rule.csv")
            ),
        },
        ProcessStep {
            input_file: Some("rfc_results_update_slice_rule.csv"),
            output_file: "rfc_results_classify_slice_rule.csv",
            description: "Running sliced rule classification script",
            action: |_| run_generate_classification_script(),
        },
        ProcessStep {
            input_file: Some("rfc_results_classify_slice_rule.csv"),
            output_file: "rfc_results_filter_classify_rule_simple.csv",
            description: "Running rule classify script",
            action: |path| run_rule_classify_script(
                &path.join("rfc_results_classify_slice_rule.csv"),
                &path.join("rfc_results_filter_classify_rule_simple.csv"),
                "1",
            ),
        },
        ProcessStep {
            input_file: Some("rfc_results_classify_slice_rule.csv"),
            output_file: "rfc_results_filter_classify_rule_complex.csv",
            description: "Running rule classify script",
            action: |path| run_rule_classify_script(
                &path.join("rfc_results_classify_slice_rule.csv"),
                &path.join("rfc_results_filter_classify_rule_complex.csv"),
                "2",
            ),
        },
        ProcessStep {
            input_file: Some("rfc_results_filter_classify_rule_simple.csv"),
            output_file: "rule_simple_violation_input.csv",
            description: "Running rule violation input generation script",
            action: |path| run_generate_mutation_descrip_input(
                &path.join("rfc_results_filter_classify_rule_simple.csv"),
                &path.join("rule_simple_violation_input.csv"),
            ),
        },
        ProcessStep {
            input_file: Some("rule_simple_violation_input.csv"),
            output_file: "rule_simple_mutation.csv",
            description: "Running rule violation input generation script",
            action: |_| run_generate_mutation(),
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
    let current_dir = env::current_dir().unwrap();
    let base_path_dir = current_dir.join(base_path);
    for step in &steps[start_index..] {
        println!("{} does not exist. {}", step.output_file, step.description);
        (step.action)(&base_path_dir)?;
    }
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

pub fn activate_virtual_env() -> Result<(), Box<dyn Error>> {
    let activate_path = Path::new("python_virtual_env/Scripts/activate");
    if !activate_path.exists() {
        eprintln!("Virtual environment activation script not found at {:?}", activate_path);
        exit(1);
    }
    println!("{}","Virtual environment activation script founded".green());
    Ok(())
}



pub fn run_python_script(script_name: &str) -> Result<(), Box<dyn Error>> {
    let script_path = Path::new("python_scripts").join(format!("{}.py", script_name));
    if !script_path.exists() {
        eprintln!("Python script not found at {:?}", script_path);
        exit(1);
    }
    println!("{}", format!("succeed to find {}.py script", script_name).green());

    // 创建子进程
    let mut child_process = Command::new("cmd")
        .creation_flags(0x08000000)
        .args(&["/C", "python_virtual_env\\Scripts\\activate && python"])
        .arg(script_path.to_str().unwrap())
        .stdout(std::process::Stdio::piped())
        .stderr(std::process::Stdio::piped())
        .spawn()
        .expect(&format!("Failed to execute {}.py script", script_name));

    // 设置 Ctrl+C 处理
    setup_ctrlc_handler(&mut child_process)?;

    // 等待脚本执行完毕并获取输出
    let output = child_process
        .wait_with_output()
        .expect(&format!("Failed to wait on {}.py script", script_name));

    // 检查脚本执行结果
    if !output.status.success() {
        eprintln!("Failed to run {}.py script.", script_name);
        let error = String::from_utf8_lossy(&output.stderr);
        eprintln!("Error: {}", error);
        exit(1);
    }

    // 打印脚本的标准输出
    let stdout = String::from_utf8_lossy(&output.stdout);
    println!("{}.py output: {}", script_name, stdout);
    
    Ok(())
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

// 封装具体的脚本调用函数
pub fn run_slice_script() -> Result<(), Box<dyn Error>> {
    run_python_script("slice_rfc")
}

pub fn run_extract_rule_script() -> Result<(), Box<dyn Error>> {
    run_python_script("extract_rule")
}

pub fn run_generate_violation_script() -> Result<(), Box<dyn Error>> {
    run_python_script("generate_violation")
}

pub fn run_generate_classification_script() -> Result<(), Box<dyn Error>> {
    run_python_script("classify_rule")
}

pub fn run_generate_mutation() -> Result<(), Box<dyn Error>> {
    run_python_script("mutation_output")
}
pub fn judge_rule(rfc_results_path: &PathBuf) -> Result<(), Box<dyn Error>> {
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

pub fn run_rule_slice_script(rfc_results_path: &PathBuf) -> Result<(), Box<dyn Error>> {
    let mut reader = Reader::from_path(rfc_results_path)?;
    let mut headers = reader.headers()?.clone();
    let content_index = headers.iter().position(|h| h == "ExtractedRule").ok_or("Content column not found")?;
    let section_index = headers.iter().position(|h| h == "Section").ok_or("Section column not found")?;
    let title_index = headers.iter().position(|h| h == "Title").ok_or("Title column not found")?;
    let content_rule_index = headers.iter().position(|h| h == "Content").ok_or("Content column not found")?;
    let re = Regex::new(r"<(SRV-MSG-CONST|CLI-MSG-CONST|SRV-MSG-PROC|CLI-MSG-PROC)>\s*<([01])>\s*\((.*?)\)\s*\+\s*<(SRV-MSG-CONST|CLI-MSG-CONST|SRV-MSG-PROC|CLI-MSG-PROC)>\s*<([01])>\s*\((.*?)\)").unwrap();

    // 添加新列 "SlicedRule"
    headers.push_field("SlicedRule");

    let output_path = rfc_results_path.with_file_name("rfc_results_slice_rule.csv");
    let mut writer = WriterBuilder::new().from_path(&output_path)?;
    writer.write_record(&headers)?;

    for result in reader.records() {
        let mut record = result?;
        let content = record.get(content_index).unwrap_or("");
        // 获取需要复制的字段值
        let section = record.get(section_index).unwrap_or("");
        let title = record.get(title_index).unwrap_or("");
        let content_rule = record.get(content_rule_index).unwrap_or("");
        if content == "Skip" {
            record.push_field("Skip");
            writer.write_record(&record)?;
        } else {
            // let matches: Vec<_> = re.captures_iter(content).collect();
            let matches: Vec<_> = re.find_iter(content).collect();
            
            if matches.is_empty() {
                // 如果没有匹配，填充 "Error"
                record.push_field("Error");
                writer.write_record(&record)?;
            } else {
                for (i, m) in matches.iter().enumerate() {
                    if i == 0 {
                        // 第一个匹配：添加到原始记录
                        let mut new_record = record.clone();
                        new_record.push_field(m.as_str());
                        writer.write_record(&new_record)?;
                    } else {
                        // 后续匹配：创建新行，只保留匹配的表达式
                        let mut new_record = csv::StringRecord::new();
                        for (index, _) in record.iter().enumerate() {
                            match index {
                                idx if idx == section_index => new_record.push_field(section),
                                idx if idx == title_index => new_record.push_field(title),
                                idx if idx == content_rule_index => new_record.push_field(content_rule),
                                _ => new_record.push_field(""),
                            }
                        }
                        new_record.push_field(m.as_str());
                        writer.write_record(&new_record)?;
                    }
                }
            }
        }
    }

    writer.flush()?;
    println!("Updated CSV saved to {:?}", output_path);
    Ok(())
}

pub fn run_generate_update_slice_script(input_file: &PathBuf, output_file: &PathBuf) -> Result<(), Box<dyn Error>> {
    // 创建CSV读取器
    let mut reader = Reader::from_path(&input_file)?;
    
    // 获取并克隆标题
    let headers = reader.headers()?.clone();
    
    // 创建CSV写入器
    let mut writer = Writer::from_path(output_file)?;
    
    // 写入标题
    writer.write_record(&headers)?;
    
    // 获取SlicedRule列的索引
    let violation_index = headers.iter().position(|h| h == "SlicedRule")
        .ok_or("SlicedRule column not found")?;
    
    // 定义需要检查的关键词
    const KEYWORDS: [&str; 5] = ["MUST", "MUST NOT", "SHALL", "SHALL NOT", "REQUIRED"];

    // 遍历每一行
    for result in reader.records() {
        let record = result?;
        
        // 获取SlicedRule列的值
        let violation = &record[violation_index];
        
        // 检查是否包含指定的字符串
        if violation.contains("<CLI-MSG-CONST>") 
            && violation.contains("<SRV-MSG-PROC>") 
            && KEYWORDS.iter().any(|&keyword| violation.contains(keyword)) {
            // 写入满足条件的行
            writer.write_record(&record)?;
        }
    }
    
    // 刷新写入器以确保所有数据都被写入
    writer.flush()?;
    
    Ok(())
}

pub fn run_rule_classify_script(input_file: &PathBuf, output_file: &PathBuf, filter_value: &str) -> Result<(), Box<dyn Error>> {
    // 打印路径
    // 检查输入文件是否存在
    if !input_file.exists() {
        eprintln!("Input file not found at: {}", input_file.display());
        return Err(Box::new(std::io::Error::new(
            std::io::ErrorKind::NotFound,
            "Input file does not exist"
        )));
    }
    // 创建CSV读取器
    let mut reader = Reader::from_path(&input_file)?;
    
    // 获取并克隆标题
    let headers = reader.headers()?.clone();
    
    // 创建CSV写入器
    let mut writer = Writer::from_path(output_file)?;
    
    // 写入标题
    writer.write_record(&headers)?;
    
    // 获取SlicedRule列的索引
    let violation_index = headers.iter().position(|h| h == "classification_result")
        .ok_or("classification_result column not found")?;
    
    // 定义需要检查的关键词
    // const KEYWORDS: [&str; 5] = ["MUST", "MUST NOT", "SHALL", "SHALL NOT", "REQUIRED"];

    // 遍历每一行
    for result in reader.records() {
        let record = result?;
        
        // 获取SlicedRule列的值
        let violation = &record[violation_index];
        
        // 检查是否包含指定的字符串
        if violation.contains(filter_value) {
            // 写入满足条件的行
            writer.write_record(&record)?;
        }
    }
    
    // 刷新写入器以确保所有数据都被写入
    writer.flush()?;
    
    Ok(())
}

fn parse_slicedrule(input: &str) -> Result<(String, String), Box<dyn Error>> {
    let parts: Vec<&str> = input.split(" + ").collect();
    if parts.len() != 2 {
        return Err("Invalid slicedrule format".into());
    }

    Ok((parts[0].trim().to_string(), parts[1].trim().to_string()))
}

fn convert_to_json(title: &str, slicedrule: &str) -> Result<String, Box<dyn Error>> {
    let (first_rule, second_rule) = parse_slicedrule(slicedrule)?;

    let rule_structure = RuleStructure {
        description: title.to_string(),
        base: Base {
            first_rule,
            second_rule,
        },
    };

    // 添加Markdown代码块标记
    let json_string = serde_json::to_string_pretty(&rule_structure)?;
    Ok(format!("```json\n{}\n```", json_string))
}

pub fn run_generate_mutation_descrip_input(input_file: &PathBuf, output_file: &PathBuf) -> Result<(), Box<dyn Error>> {
    // 创建CSV读取器
    let mut reader = Reader::from_path(&input_file)?;
    
    // 获取并克隆标题
    let headers = reader.headers()?.clone();
    
    // 创建新的标题，添加violation_input列
    let mut new_headers = headers.iter().map(|s| s.to_string()).collect::<Vec<String>>();
    new_headers.push("violation_input".to_string());
    
    // 创建CSV写入器
    let mut writer = Writer::from_path(output_file)?;
    
    // 写入新的标题
    writer.write_record(&new_headers)?;
    
    // 获取Title和SlicedRule列的索引
    let title_index = headers.iter().position(|h| h == "Title")
        .ok_or("Title column not found")?;
    let rule_index = headers.iter().position(|h| h == "SlicedRule")
        .ok_or("SlicedRule column not found")?;

    // 处理每一行数据
    for result in reader.records() {
        let record = result?;
        
        // 获取Title和SlicedRule的值
        let title = &record[title_index];
        let sliced_rule = &record[rule_index];

        // 转换为JSON格式
        let json_output = convert_to_json(title, sliced_rule)?;

        // 创建新的记录，包含原始数据和JSON输出
        let mut new_record = record.iter().collect::<Vec<_>>();
        new_record.push(&json_output);

        // 写入新记录
        writer.write_record(&new_record)?;
    }

    // 确保写入完成
    writer.flush()?;

    Ok(())
}

pub fn run_generate_mutation(input_file: &PathBuf, output_file: &PathBuf) -> Result<(), Box<dyn Error>> {
    // 创建CSV读取器
    let mut reader = Reader::from_path(&input_file)?;
    
    // 获取并克隆标题
    let headers = reader.headers()?.clone();
    
    // 创建新的标题，添加violation_input列
    let mut new_headers = headers.iter().map(|s| s.to_string()).collect::<Vec<String>>();
    new_headers.push("violation_input".to_string());
    
    // 创建CSV写入器
    let mut writer = Writer::from_path(output_file)?;
    
    // 写入新的标题
    writer.write_record(&new_headers)?;
    
    // 获取Title和SlicedRule列的索引
    let input_index = headers.iter().position(|h| h == "Title")
        .ok_or("Title column not found")?;
    let rule_index = headers.iter().position(|h| h == "SlicedRule")
        .ok_or("SlicedRule column not found")?;

    // 处理每一行数据
    for result in reader.records() {
        let record = result?;
        
        // 获取Title和SlicedRule的值
        let title = &record[title_index];
        let sliced_rule = &record[rule_index];

        // 转换为JSON格式
        let json_output = convert_to_json(title, sliced_rule)?;

        // 创建新的记录，包含原始数据和JSON输出
        let mut new_record = record.iter().collect::<Vec<_>>();
        new_record.push(&json_output);

        // 写入新记录
        writer.write_record(&new_record)?;
    }

    // 确保写入完成
    writer.flush()?;

    Ok(())
}
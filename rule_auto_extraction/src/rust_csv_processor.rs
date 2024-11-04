use csv::{Reader, Writer, WriterBuilder};
use regex::Regex;
use std::path::PathBuf;
use std::error::Error;
use serde::{Deserialize, Serialize};

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

pub fn judge_rule(input: &PathBuf, output: &PathBuf) -> Result<(), Box<dyn Error>> {
    let mut reader = Reader::from_path(input)?;
    let mut headers = reader.headers()?.clone();
    let content_index = headers.iter().position(|h| h == "Content").ok_or("Content column not found")?;
    let re = Regex::new(r"(?i)\b(MUST|must|MUST NOT|must not|SHALL|shall|REQUIRED|required|SHALL NOT|shall not)\b")?;

    
    // 增加新列 "RuleMatch"
    // headers.push_field("RuleMatch");

    // let output_path = rfc_results_path.with_file_name("rfc_results_update_judge.csv");
    let mut writer = WriterBuilder::new().from_path(&output)?;
    writer.write_record(&headers)?;

    let mut total_rules = 0;
    let mut count_ones = 0;
    let mut count_zeros = 0;
    let mut index = 1;

    for result in reader.records() {
        let record = result?;
        let content = record.get(content_index).unwrap_or("");
        let value = if re.is_match(content) { 1 } else { 0 };
        if value != 0 {
            // record.push_field(&value.to_string());
            // writer.write_record(&record)?;
            let record_with_index: Vec<String> = record.iter().enumerate().map(|(i, field)| {
                if i == 0 { index.to_string() } else { field.to_string() }
            }).collect();
            writer.write_record(&record_with_index)?;
            index += 1;
        }

        total_rules += 1;
        if value == 1 {
            count_ones += 1;
        } else {
            count_zeros += 1;
        }
    }

    writer.flush()?;
    println!("Updated CSV saved to {:?}", output);
    println!("Total rules: {}, Number of 1s: {}, Number of 0s: {}", total_rules, count_ones, count_zeros);
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
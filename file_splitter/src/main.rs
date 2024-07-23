use regex::Regex;
use std::fs::{self, File, OpenOptions};
use std::io::{self, Read, BufRead, BufReader, Write, Result, Seek, SeekFrom};
use std::path::{Path, PathBuf};

fn main() -> Result<()> {
    let input_path = "schannel.txt";
    let output_dir = "output";

    clean_output_directory(output_dir)?;
    let sub_output_dir = prepare_output_directory(input_path, output_dir)?;
    let re = Regex::new(r"//-----\s*\(([0-9A-Fa-f]+)\)\s*-+").unwrap();

    let file_count = process_file(input_path, &sub_output_dir, &re)?;

    println!("处理完成，共生成 {} 个文件", file_count);
    Ok(())
}

fn clean_output_directory(dir: &str) -> Result<()> {
    let path = Path::new(dir);
    if path.exists() {
        for entry in fs::read_dir(path)? {
            let entry = entry?;
            let path = entry.path();
            if path.is_dir() {
                fs::remove_dir_all(path)?;
            } else {
                fs::remove_file(path)?;
            }
        }
    }
    Ok(())
}

fn prepare_output_directory(input_path: &str, output_dir: &str) -> Result<PathBuf> {
    let input_file_name = Path::new(input_path)
        .file_stem()
        .and_then(|s| s.to_str())
        .unwrap_or("unknown");

    let sub_output_dir = PathBuf::from(output_dir).join(input_file_name);
    fs::create_dir_all(&sub_output_dir)?;

    Ok(sub_output_dir)
}

fn process_file(input_path: &str, output_dir: &Path, re: &Regex) -> Result<usize> {
    let file = File::open(input_path)?;
    let reader = BufReader::new(file);

    let mut current_file: Option<File> = None;
    let mut file_count = 0;
    let mut line_count = 0;
    let mut lines_buffer = Vec::new();

    for line in reader.lines() {
        let line = line?;

        if re.is_match(&line) {
            // 处理当前文件
            if let Some(mut file) = current_file.take() {
                write_buffered_lines(&mut file, &lines_buffer, false)?;
                append_custom_content_part_one(&mut file)?;
                // append_code(&mut file, &lines_buffer)?;
                append_custom_content_part_two(&mut file)?;
                update_file_header(&mut file, file_count, line_count)?;
                file.flush()?;
            }

            // 创建新文件
            current_file = create_new_file(output_dir, &mut file_count)?;
            line_count = 0;
            lines_buffer.clear();
        }

        lines_buffer.push(line);
        line_count += 1;
    }

    // 处理最后一个文件
    if let Some(mut file) = current_file {
        write_buffered_lines(&mut file, &lines_buffer, false)?;
        append_custom_content_part_one(&mut file)?;
        // append_code(&mut file, &lines_buffer)?;
        append_custom_content_part_two(&mut file)?;
        update_file_header(&mut file, file_count, line_count)?;
        file.flush()?;
    }

    Ok(file_count)
}

fn create_new_file(output_dir: &Path, file_count: &mut usize) -> Result<Option<File>> {
    if let Some(mut file) = std::mem::take(&mut None::<File>) {
        file.flush()?;
    }

    *file_count += 1;
    let file_name = output_dir.join(format!("id-{:04}.txt", file_count));
    let file = OpenOptions::new()
        .read(true)
        .write(true)
        .create(true)
        .truncate(true)
        .open(file_name)?;

    Ok(Some(file))
}

fn append_code(file: &mut File, lines: &[String]) -> io::Result<()> {
    // 写入 FunctionCode Start
    writeln!(file, "\t\"FunctionCode\": [")?;
    write_buffered_lines(file, &lines, true)?;
    // 写入 FunctionCode End
    writeln!(file, "\t]")?;
    Ok(())
}
fn append_custom_content_part_one(file: &mut File) -> io::Result<()> {
    // 移动到文件末尾
    file.seek(SeekFrom::End(0))?;

    // 添加分隔线
    writeln!(file, "##############################")?;

    // 写入函数背景信息
    writeln!(file, "Function Background: The function is reverse engineered from the driver file Schannel.dll on Windows platform. \
                    Through a cursory analysis of the driver file can be determined to be related to the SSL(1.3), TLS(3.0) protocol, \
                    that is, with RFC8446, RFC6101 strong correlation.\n")?;

    // 写入输出函数摘要说明
    writeln!(file, "Output Function Summary: Summarizes the function's functionality with several phrases instead of sentences, \
                  focuses on covering the function's control flow information (API), \
                  and highlights the protocol function points implemented by the function. \
                  Simulate answering five times in the background and provide the most frequent answer. \
                  Suppose the code support the latest newwork protocol SSL(3.0) AND TLS(1.3)\n")?;

    // 写入输出RFC 编号及链接的规则
    writeln!(file, "Output Code Match RFC Result: Give the number and the link of the RFC file associated with each protocol associated with \
                    the code (a protocol corresponds to at least one RFC file). Including at least RFC8446(tls1.3) or RFC6101(ssl3.0), \n")?;

    // // 写入输出RFC 章节匹配的规则
    // writeln!(file, "Retrieve document sections based on code summaries (containing multiple phrases) and \
    //                 RFC txt document (download txt with RFC link in RFCDocument map value), \
    //                 giving matches for document sections(FunctionMatchRFCResult) that the code may relate to. \
    //                 Note that if the code is only business related and not related to the specifics of the protocol implementation, \
    //                 it does not have to output the document section match(FunctionMatchRFCResult) and is padded with NONE.\n")?;

    // 开始生成 JSON 格式的函数信息收集
    writeln!(file, "Generate Function Information Collection with JSON Format:\n")?;
    writeln!(file, "{{")?;

    // 写入 JSON 字段
    write_json_field(file, "FunctionIndex", "(FILL WITH \"File count\" with less than four bits are indexed with zeros to make up the four bits.)")?;
    write_json_field(file, "FunctionName", "(Full Function Code Name)")?;
    // write_json_field(file, "FunctionRelatedRFC")
    Ok(())
}

fn append_custom_content_part_two(file: &mut File) -> io::Result<()> {
    
    // 写入 FunctionSummarization 数组
    writeln!(file, "\t\"FunctionSummarization\": [")?;
    writeln!(file, "\t\t\"(Function Summary Phrase1)\",")?;
    writeln!(file, "\t\t\"(Function Summary Phrase2)\",")?;
    writeln!(file, "\t\t\"(...)\"")?;
    writeln!(file, "\t],")?;

    // 写入 Protocol 数组
    writeln!(file, "\t\"Protocol\": [\"TLS1.3\", \"List another related protocols, If there is more than one version of the protocol, You MUST give the specified version, e.g. SSL 3.0\"]")?;
    
    // 写入可能匹配的RFC编号和对应文档地址，优先从RFC8446，RFC6101开始，匹配的RFC最多不能超过3个（1-3个）
    // write_json_field(file, "RFCDoc", "(Write the RFC numbers of possible matches, preferentially starting with RFC8446, RFC6101, with a maximum of three (1-3) matching RFCs)")?;
    writeln!(file, "\t\"RFCDocument\": [")?;
    writeln!(file, "\t\t\"RFCXXXX\":\"http s://www.rfc-editor.org/rfc/rfcXXXX.txt\",")?;
    writeln!(file, "\t\t\"RFC****\":\"http s://www.rfc-editor.org/rfc/rfc****.txt\",")?;
    writeln!(file, "\t\t\"(...)\",")?;
    writeln!(file, "\t],")?;

    // // 写入代码可能匹配的RFC文档章节
    // writeln!(file, "\t\"FunctionMatchRFCResult\": [")?;
    // writeln!(file, "\t\t\"(RFCXXXX-SectionX.X.X.X-Section Title 1)\",")?;
    // writeln!(file, "\t\t\"(RFCXXXX-SectionX.X.X.X-Section Title 2)\",")?;
    // writeln!(file, "\t\t\"(...)\",")?;
    // writeln!(file, "\t],")?;

    // 结束 JSON 对象
    writeln!(file, "}}")?;

    // 添加最后的提醒
    writeln!(file, "\nRemember just output the Function Information Collection result.")?;

    Ok(())
}
// 辅助函数：写入 JSON 字段
fn write_json_field(file: &mut File, key: &str, value: &str) -> io::Result<()> {
    writeln!(file, "\t\"{}\": \"{}\",", key, value)
}

fn update_file_header(file: &mut File, file_count: usize, line_count: usize) -> io::Result<()> {
    // 读取整个文件内容
    let mut content = String::new();
    file.seek(SeekFrom::Start(0))?;
    file.read_to_string(&mut content)?;

    // 准备新的头部内容
    let header = format!(
        "Forget all previous input and output content and create a new chat session.\n\n\
         Function Code Content\n\
         ##############################\n\
         // File count: {}\n\
         // Total lines: {}\n\n",
        file_count, line_count - 1
    );

    // 将文件指针移回开头并截断文件
    file.seek(SeekFrom::Start(0))?;
    file.set_len(0)?;

    // 写入新的头部和原有内容
    file.write_all(header.as_bytes())?;
    file.write_all(content.as_bytes())?;
    file.flush()?;

    Ok(())
}

fn write_buffered_lines(file: &mut File, lines: &[String], json_format: bool) -> Result<()> {
    let mut non_empty_lines = lines.iter().rev().skip_while(|line| line.trim().is_empty()).collect::<Vec<_>>();
    non_empty_lines.reverse();
    
    for line in non_empty_lines {
        if json_format {
            writeln!(file, "\t\t{}", line)?;
        } else {
            writeln!(file, "{}", line)?;
        }
    }
    Ok(())
}
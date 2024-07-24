use regex::Regex;
use std::fs::{self, File, OpenOptions};
use std::io::{self, BufRead, BufReader, Result, Seek, SeekFrom, Write, ErrorKind};
use std::path::{Path, PathBuf};

fn main() -> Result<()> {
    let input_path = "schannel.txt";
    let output_dir = "output";
    // let result_dir = "result";

    println!("Starting program...");

    match clean_output_directory(output_dir) {
        Ok(_) => println!("Output directory cleaned successfully."),
        Err(e) => eprintln!("Error cleaning output directory: {}", e),
    }
    // clean_output_directory(result_dir)?;

    let sub_output_dir = match prepare_output_directory(input_path, output_dir) {
        Ok(dir) => {
            println!("Output directory prepared: {:?}", dir);
            dir
        },
        Err(e) => {
            eprintln!("Error preparing output directory: {}", e);
            return Err(e);
        }
    };
    // let sub_result_dir = prepare_output_directory(input_path, result_dir)?;

    let re = Regex::new(r"//-----\s*\(([0-9A-Fa-f]+)\)\s*-+").unwrap();

    // let file_count = process_file(input_path, &sub_output_dir, &sub_result_dir, &re)?;
    // let _file_count = process_file(input_path, &sub_output_dir, &re)?;

    match process_file(input_path, &sub_output_dir, &re) {
        Ok(_file_count) => println!("处理完成，共生成 {} 个文件", _file_count),
        Err(e) => eprintln!("Error processing file: {}", e),
    }

    Ok(())
}

fn clean_output_directory(dir: &str) -> Result<()> {
    println!("Cleaning output directory: {}", dir);
    let path = Path::new(dir);
    if path.exists() {
        for entry in fs::read_dir(path)? {
            let entry = entry?;
            let path = entry.path();
            if path.is_dir() {
                fs::remove_dir_all(&path).map_err(|e| {
                    eprintln!("Error removing directory {:?}: {}", path, e);
                    e
                })?;
            } else {
                fs::remove_file(&path).map_err(|e| {
                    eprintln!("Error removing file {:?}: {}", path, e);
                    e
                })?;
            }
        }
    } else {
        println!("Output directory does not exist, creating it.");
        fs::create_dir_all(path).map_err(|e| {
            eprintln!("Error creating output directory: {}", e);
            e
        })?;
    }
    Ok(())
}

fn prepare_output_directory(input_path: &str, output_dir: &str) -> Result<PathBuf> {
    println!("Preparing output directory...");
    let input_file_name = Path::new(input_path)
        .file_stem()
        .and_then(|s| s.to_str())
        .unwrap_or("unknown");

    let sub_output_dir = PathBuf::from(output_dir).join(input_file_name);
    fs::create_dir_all(&sub_output_dir).map_err(|e| {
        eprintln!("Error creating sub output directory {:?}: {}", sub_output_dir, e);
        e
    })?;

    Ok(sub_output_dir)
}


fn process_file(
    input_path: &str,
    output_dir: &Path,
    re: &Regex,
) -> Result<usize> {
    println!("Processing file: {}", input_path);
    let file = File::open(input_path).map_err(|e| {
        eprintln!("Error opening input file {}: {}", input_path, e);
        e
    })?;
    let reader = BufReader::new(file);

    let mut file_count = 0;
    let mut line_count = 0;
    let mut lines_buffer = Vec::new();
    let mut first_match = false;
    // lines_buffer.clear();
    for line in reader.lines() {
        let line = line?;

        if re.is_match(&line) {
            // println!("Matched!!!");
            first_match = true;
            if !lines_buffer.is_empty() {
                let _function_dir = output_dir.join(format!("id-{:04}", file_count));// 
                let prompt_path = _function_dir.join("prompt.txt");
                // 输出
                // println!("{}",prompt_path.display());
                match process_single_file(&_function_dir, &prompt_path, &lines_buffer, file_count, line_count) {
                    Ok(_) => println!("Processed file id-{:04}", file_count),
                    Err(e) => eprintln!("Error processing file id-{:04}: {}", file_count, e),
                }
            }

            file_count += 1;
            let function_dir = output_dir.join(format!("id-{:04}", file_count));
            fs::create_dir_all(&function_dir).map_err(|e| {
                eprintln!("Error creating directory {:?}: {}", function_dir, e);
                e
            })?;

            create_empty_files(&function_dir).map_err(|e| {
                eprintln!("Error creating empty files in {:?}: {}", function_dir, e);
                e
            })?;

            line_count = 0;
            lines_buffer.clear();
        }

        // 只有在第一次匹配正则表达式之后，才开始填充 lines_buffer
        if first_match {
            lines_buffer.push(line);
            line_count += 1;
        }
    }

    if !lines_buffer.is_empty() {
        let function_dir = output_dir.join(format!("id-{:04}", file_count));
        let prompt_path = function_dir.join("prompt.txt");
        
        match process_single_file(&function_dir, &prompt_path, &lines_buffer, file_count, line_count) {
            Ok(_) => println!("Processed final file id-{:04}", file_count),
            Err(e) => eprintln!("Error processing final file id-{:04}: {}", file_count, e),
        }
    }

    Ok(file_count)
}

fn process_single_file(_function_dir: &Path, prompt_path: &Path, lines_buffer: &[String], file_count: usize, line_count: usize) -> Result<()> {
    let mut file = OpenOptions::new()
        .read(true)  // 添加读权限
        .write(true)
        .create(true)
        .truncate(true)
        .open(prompt_path)
        .map_err(|e| {
            eprintln!("Error opening file {:?}: {}", prompt_path, e);
            e
        })?;
    update_file_header(&mut file, file_count, line_count).map_err(|e| {
        eprintln!("Error updating file header of {:?}: {}", prompt_path, e);
        e
    })?;

    write_buffered_lines(&mut file, lines_buffer, false).map_err(|e| {
        eprintln!("Error writing buffered lines to {:?}: {}", prompt_path, e);
        e
    })?;
    append_custom_content_part_one(&mut file).map_err(|e| {
        eprintln!("Error appending custom content part one to {:?}: {}", prompt_path, e);
        e
    })?;
    append_custom_content_part_two(&mut file).map_err(|e| {
        eprintln!("Error appending custom content part two to {:?}: {}", prompt_path, e);
        e
    })?;
    
    
    
    file.flush().map_err(|e| {
        eprintln!("Error flushing file {:?}: {}", prompt_path, e);
        e
    })?;

    Ok(())
}

// fn update_file_header(file: &mut File, file_count: usize, line_count: usize) -> io::Result<()> {
//     // 读取整个文件内容
//     // let mut content = String::new();
//     // file.read_to_string(&mut content)?;

//     // 将文件指针移回到开始位置
//     file.seek(io::SeekFrom::Start(0))?;

//     // Read the content of sectionabstract.txt in the input folder
//     let input_content = fs::read_to_string("input/sectionabstract.txt").map_err(|e| {
//         eprintln!("Error reading input file: {}", e);
//         io::Error::new(ErrorKind::Other, format!("Input file error: {}", e))
//     })?;
//     // Prepare new header content
//     let header = format!(
//         "Forget all previous input and output content and create a new chat session.\n\n\
//          {}\n\n\
//          Function Code Content\n\
//          ##############################\n\
//          // File count: {}\n\
//          // Total lines: {}\n\n",
//         input_content.trim(),
//         file_count,
//         line_count - 1
//     );

//     writeln!(file, "{}", header)?;  // 添加一个空行分隔头部和原内容

//     // 写回原来的内容
//     // file.write_all(content.as_bytes())?;

//     Ok(())
// }

fn update_file_header(file: &mut File, file_count: usize, line_count: usize) -> io::Result<()> {    
    // // 读取整个文件内容
    // let mut content = String::new();
    // file.read_to_string(&mut content)?;

    // 将文件指针移回到开始位置
    file.seek(io::SeekFrom::Start(0))?;

    // Read the content of sectionabstract.txt in the input folder
    let input_content = fs::read_to_string("input/sectionabstract.txt").map_err(|e| {
        eprintln!("Error reading input file: {}", e);
        io::Error::new(ErrorKind::Other, format!("Input file error: {}", e))
    })?;
    
    // Prepare new header content
    let header = format!(
        "Forget all previous input and output content and create a new chat session.\n\n\
         {}\n\n\
         Function Code Content\n\
         ##############################\n\
         // File count: {}\n\
         // Total lines: {}\n",
        input_content.trim(),
        file_count,
        line_count - 1
    );
    writeln!(file, "{}", header)?;  // 添加一个空行分隔头部和原内容
    // file.write_all(content.as_bytes())?;
    // // Combine the new header with the original content
    // let combined_content = format!("{}\n{}", header, content);

    // // Write the combined content back to the file
    // file.set_len(0)?; // 清空文件内容
    // file.write_all(combined_content.as_bytes())?;

    Ok(())
}


fn create_empty_files(function_dir: &Path) -> Result<()> {
    let prompt_path = function_dir.join("prompt.txt");
    let result_path = function_dir.join("result.txt");

    File::create(&prompt_path).map_err(|e| {
        eprintln!("Error creating prompt file {:?}: {}", prompt_path, e);
        e
    })?;
    File::create(&result_path).map_err(|e| {
        eprintln!("Error creating result file {:?}: {}", result_path, e);
        e
    })?;

    Ok(())
}

fn append_custom_content_part_one(file: &mut File) -> io::Result<()> {
    // 移动到文件末尾
    file.seek(SeekFrom::End(0))?;

    // 添加分隔线
    writeln!(file, "##############################")?;

    // 写入角色
    writeln!(file, "Role: Let's assume that you are an advanced reverse engineer and you are reverse engineering a network driver using IDA Pro, \
                    and you are also familiar with the RFC documentation. You need to reverse-engineer a function for a network driver to \
                    correspond to a section of the RFC documentation, which will help you understand the code better. \
                    The driver you're reversing is Schannel.dll, and you've initially determined that the corresponding network protocols \
                    are SSL and TLS, and the documents you need to map are RFC8446 and RFC6101. \
                    You need to get a function summary of the function you're reversing, and then correspond to the potential RFC sections \
                    based on the name of the function and the function summary.\n")?;

    // 写入函数背景信息
    writeln!(file, "Function Background: The function is reverse engineered from the driver file Schannel.dll on Windows platform. \
                    Through a cursory analysis of the driver file can be determined to be related to the SSL(1.3), TLS(3.0) protocol, \
                    that is, with RFC8446, RFC6101 strong correlation.\n")?;

    // 写入输出函数摘要说明
    writeln!(file, "Output Function Summary: Summarizes the function's functionality with several phrases instead of sentences, \
                  focuses on covering the function's control flow information, \
                  and highlights the protocol function points implemented by the function. \
                  Simulate answering five times in the background and provide the most frequent answer.\n")?;
                //   Suppose the code support the latest newwork protocol SSL(3.0) AND TLS(1.3)\n")?;

    // // 写入输出RFC 编号及链接的规则
    // writeln!(file, "Output Code Match RFC Result: Give the number and the link of the RFC file associated with each protocol associated with \
    //                 the code (a protocol corresponds to at least one RFC file). Including at least RFC8446(tls1.3) or RFC6101(ssl3.0), \n")?;

    // 写入输出RFC 章节匹配的规则
    writeln!(file, "Retrieve document sections: \
                    giving matches for document sections(FunctionMatchRFCResult) that the code may related to. \
                    NOTE if the code is only business related(i.e., space opening and releasing involved in programming, \
                    generic call functions (timing and other functions weakly related to network protocols)) and \
                    not related to the specifics of the protocol implementation, \
                    it does not have to output the document section match(FunctionMatchRFCResult) and is filled with \"NONE\".\n")?;

    // 写入匹配的思维链
    writeln!(
        file,
        "Retrieve document sections Thinking Chain: The function code is matched with the RFC document section, \
                    and the thinking chain is provided to help you solve the problem better:"
    )?;
    writeln!(file,"\t1. Function Name: The name of a function describes the general function that the function accomplishes.")?;
    writeln!(file,"\t2. Function Summarization: Function summaries can outline a further breakdown of the function described by the function name.")?;
    writeln!(file,"\t3. Function API Call: The function API of a function call can provide some hint as to the details of the network protocol implementation involved in the function.")?;
    writeln!(file,"\t4. Special Constant Value OR String: Special constant values inside functions, string variable names, and strings may be related to network protocols.")?;
    writeln!(file,"\t5. Function Code: The code of the function can provide a detailed implementation of the network protocol.")?;

    // 开始生成 JSON 格式的函数信息收集
    writeln!(
        file,
        "Generate Function Information Collection with JSON Format:\n"
    )?;
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
    // writeln!(file, "\t\"Protocol\": [\"TLS1.3\", \"List another related protocols, If there is more than one version of the protocol, You MUST give the specified version, e.g. SSL 3.0\"]")?;

    // 写入可能匹配的RFC编号和对应文档地址，优先从RFC8446，RFC6101开始，匹配的RFC最多不能超过3个（1-3个）
    // write_json_field(file, "RFCDoc", "(Write the RFC numbers of possible matches, preferentially starting with RFC8446, RFC6101, with a maximum of three (1-3) matching RFCs)")?;
    // writeln!(file, "\t\"RFCDocument\": [")?;
    // writeln!(file, "\t\t\"RFCXXXX\":\"http s://www.rfc-editor.org/rfc/rfcXXXX.txt\",")?;
    // writeln!(file, "\t\t\"RFC****\":\"http s://www.rfc-editor.org/rfc/rfc****.txt\",")?;
    // writeln!(file, "\t\t\"(...)\",")?;
    // writeln!(file, "\t],")?;

    // 写入代码可能匹配的RFC文档章节
    writeln!(file, "\t\"FunctionMatchRFCResult\": [")?;
    writeln!(file, "\t\t\"(RFCXXXX-SectionX.X.X.X-Section Title 1)\",")?;
    writeln!(file, "\t\t\"(RFCXXXX-SectionX.X.X.X-Section Title 2)\",")?;
    writeln!(file, "\t\t\"(...)\",")?;
    writeln!(file, "\t],")?;

    // 结束 JSON 对象
    writeln!(file, "}}")?;

    // 添加最后的提醒
    writeln!(
        file,
        "\nATTENTION: Remember YOU MUST ONLY output the Function Information Collection result."
    )?;

    Ok(())
}
// 辅助函数：写入 JSON 字段
fn write_json_field(file: &mut File, key: &str, value: &str) -> io::Result<()> {
    writeln!(file, "\t\"{}\": \"{}\",", key, value)
}


fn write_buffered_lines(file: &mut File, lines: &[String], json_format: bool) -> Result<()> {
    let mut non_empty_lines = lines
        .iter()
        .rev()
        .skip_while(|line| line.trim().is_empty())
        .collect::<Vec<_>>();
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


// fn update_file_header(file: &mut File, file_count: usize, line_count: usize) -> io::Result<()> {
//     println!("Updating file header for file count: {}, line count: {}", file_count, line_count);

//     // 读取整个文件内容
//     let mut content = String::new();
//     file.seek(SeekFrom::Start(0)).map_err(|e| {
//         println!("Error seeking to start of file: {}", e);
//         e
//     })?;
//     file.read_to_string(&mut content).map_err(|e| {
//         println!("Error reading file content: {}", e);
//         e
//     })?;

//     // 读取 input 文件夹下的 sectionabstract.txt 的内容
//     let mut input_content = String::new();
//     let input_path = Path::new("input/sectionabstract.txt");
//     File::open(input_path)
//         .and_then(|mut f| f.read_to_string(&mut input_content))
//         .map_err(|e| {
//             println!("Error reading input file: {}", e);
//             e
//         })?;

//     // 准备新的头部内容
//     let header = format!(
//         "Forget all previous input and output content and create a new chat session.\n\n\
//          {}\n\n\
//          Function Code Content\n\
//          ##############################\n\
//          // File count: {}\n\
//          // Total lines: {}\n\n",
//         input_content.trim(),
//         file_count,
//         line_count - 1
//     );

//     // 将文件指针移回开头并截断文件
//     file.seek(SeekFrom::Start(0)).map_err(|e| {
//         println!("Error seeking to start of file: {}", e);
//         e
//     })?;
//     file.set_len(0).map_err(|e| {
//         println!("Error truncating file: {}", e);
//         e
//     })?;

//     // 写入新的头部和原有内容
//     file.write_all(header.as_bytes()).map_err(|e| {
//         println!("Error writing header: {}", e);
//         e
//     })?;
//     file.write_all(content.as_bytes()).map_err(|e| {
//         println!("Error writing original content: {}", e);
//         e
//     })?;
//     file.flush().map_err(|e| {
//         println!("Error flushing file: {}", e);
//         e
//     })?;

//     println!("File header updated successfully");
//     Ok(())
// }

// fn create_new_file(output_dir: &Path, file_count: &mut usize) -> Result<Option<File>> {
//     if let Some(mut file) = std::mem::take(&mut None::<File>) {
//         file.flush()?;
//     }

//     *file_count += 1;
//     let file_name = output_dir.join(format!("id-{:04}.txt", file_count));
//     let file = OpenOptions::new()
//         .read(true)
//         .write(true)
//         .create(true)
//         .truncate(true)
//         .open(file_name)?;

//     Ok(Some(file))
// }

// fn append_code(file: &mut File, lines: &[String]) -> io::Result<()> {
//     // 写入 FunctionCode Start
//     writeln!(file, "\t\"FunctionCode\": [")?;
//     write_buffered_lines(file, &lines, true)?;
//     // 写入 FunctionCode End
//     writeln!(file, "\t]")?;
//     Ok(())
// }

// fn create_empty_file(result_dir: &Path, file_count: usize) -> Result<()> {
//     let file_name = result_dir.join(format!("id-{:04}.txt", file_count));
//     File::create(file_name)?;
//     Ok(())
// }

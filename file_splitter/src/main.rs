use regex::Regex;
use std::env;
use std::fs::{self, File, OpenOptions};
use std::io::{self, BufRead, BufReader, ErrorKind, Seek, SeekFrom, Write};
use std::path::MAIN_SEPARATOR;
use std::path::{Path, PathBuf};
use std::process;
use std::time::Instant;
#[derive(PartialEq, Eq, PartialOrd, Ord)]
enum OutputLevel {
    // Error,
    Info,
    Debug,
}

const CURRENT_OUTPUT_LEVEL: OutputLevel = OutputLevel::Info;

const RED: &str = "\x1b[31m";
const RESET: &str = "\x1b[0m";

fn main() {
    if let Err(e) = run() {
        print_error(&format!("{}", e));
        process::exit(1);
    }
}

fn print_message(message: &str, level: OutputLevel) {
    if level <= CURRENT_OUTPUT_LEVEL {
        println!("{}", message);
    }
}

fn print_error(message: &str) {
    eprintln!("{}Error: {}{}", RED, message, RESET);
}

fn wrap_error<T>(result: io::Result<T>, context: &str) -> io::Result<T> {
    result.map_err(|e| {
        let error_message = format!("{}: {}", context, e);
        print_error(&error_message);
        io::Error::new(ErrorKind::Other, error_message)
    })
}

fn run() -> io::Result<()> {
    let start_time = Instant::now();
    let args: Vec<String> = env::args().collect();
    let (input_file, is_default) = if args.len() > 1 {
        (format!("input/{}", args[1]), false)
    } else {
        (String::from("input/test.txt"), true)
    };

    let input_path = Path::new(&input_file);
    if !input_path.exists() {
        return Err(io::Error::new(
            ErrorKind::NotFound,
            format!("Input file not found: {:?}", input_path),
        ));
    }

    let output_dir = "output";
    let code_dir = "code";

    println!("Starting program...");
    println!("Input file: {:?}", input_path);

    wrap_error(
        clean_output_directory(output_dir),
        "Failed to clean output directory",
    )?;
    wrap_error(
        clean_output_directory(code_dir),
        "Failed to clean code directory",
    )?;

    let sub_output_dir = wrap_error(
        prepare_output_directory(input_path, output_dir),
        "Failed to prepare output directory",
    )?;
    let sub_code_dir = wrap_error(
        prepare_output_directory(input_path, code_dir),
        "Failed to prepare code directory",
    )?;

    let re = Regex::new(r"//-----\s*\(([0-9A-Fa-f]+)\)\s*-+")
        .map_err(|e| io::Error::new(ErrorKind::Other, format!("Regex compilation error: {}", e)))?;

    let file_count = wrap_error(
        process_file(input_path, &sub_output_dir, &sub_code_dir, &re),
        "Failed to process file",
    )?;
    let end_time = Instant::now();
    let duration = end_time.duration_since(start_time);
    println!(
        "处理完成，总处理时间: {}ms，共生成 {} 个文件",
        duration.as_millis(),
        file_count
    );

    if is_default {
        println!("\nThe program is currently using the default parameter.");
        println!("If you want to process your own file, please specify the file name.");
        println!("Usage: cargo run <filename>");
        println!("Example: cargo run schannel.txt");
    }

    Ok(())
}

fn clean_output_directory(dir: &str) -> io::Result<()> {
    println!("Cleaning output directory: {}", dir);
    let path = Path::new(dir);
    if path.exists() {
        for entry in wrap_error(
            fs::read_dir(path),
            &format!("Failed to read directory {}", dir),
        )? {
            let entry = wrap_error(entry, "Failed to read directory entry")?;
            let path = entry.path();
            if path.is_dir() {
                wrap_error(
                    fs::remove_dir_all(&path),
                    &format!("Failed to remove directory {:?}", path),
                )?;
            } else {
                wrap_error(
                    fs::remove_file(&path),
                    &format!("Failed to remove file {:?}", path),
                )?;
            }
        }
    } else {
        println!("Output directory does not exist, creating it.");
        wrap_error(
            fs::create_dir_all(path),
            &format!("Failed to create directory {}", dir),
        )?;
    }
    Ok(())
}

fn prepare_output_directory(input_path: &Path, output_dir: &str) -> io::Result<PathBuf> {
    print_message("Preparing output directory...", OutputLevel::Info);
    let input_file_name = Path::new(input_path)
        .file_stem()
        .and_then(|s| s.to_str())
        .unwrap_or("unknown");

    let sub_output_dir = PathBuf::from(output_dir).join(input_file_name);
    wrap_error(
        fs::create_dir_all(&sub_output_dir),
        &format!("Failed to create output directory {:?}", sub_output_dir),
    )?;

    Ok(sub_output_dir)
}

fn process_file(
    input_path: &Path,
    output_dir: &Path,
    code_dir: &Path,
    re: &Regex,
) -> io::Result<usize> {
    print_message(
        &format!("Processing file: {:?}", input_path),
        OutputLevel::Info,
    );
    let file = wrap_error(
        File::open(input_path),
        &format!("Failed to open input file {:?}", input_path),
    )?;
    let reader = BufReader::new(file);

    let mut file_count = 0;
    let mut line_count = 0;
    let mut lines_buffer = Vec::new();
    let mut first_match = false;

    for line in reader.lines() {
        let line = wrap_error(line, "Failed to read line from input file")?;

        if re.is_match(&line) {
            if first_match {
                wrap_error(
                    process_buffer(output_dir, code_dir, &lines_buffer, file_count, line_count),
                    "Failed to process buffer",
                )?;
            }
            first_match = true;
            file_count += 1;
            // wrap_error(
            //     prepare_new_function_dir(output_dir, &lines_buffer),
            //    "Failed to prepare new function directory",
            // )?;
            line_count = 0;
            lines_buffer.clear();
        }

        if first_match {
            lines_buffer.push(line);
            line_count += 1;

            if lines_buffer.len() == 2 {
                // We have the function declaration, so we can prepare the directory
                wrap_error(
                    prepare_new_function_dir(output_dir, &lines_buffer),
                    "Failed to prepare new function directory",
                )?;
            }
        }
    }

    if !lines_buffer.is_empty() {
        wrap_error(
            process_buffer(output_dir, code_dir, &lines_buffer, file_count, line_count),
            "Failed to process final buffer",
        )?;
    }

    Ok(file_count)
}

fn process_buffer(
    output_dir: &Path,
    code_dir: &Path,
    lines_buffer: &[String],
    file_count: usize,
    line_count: usize,
) -> io::Result<()> {
    // let function_dir = output_dir.join(format!("id-{:04}", file_count));
    let function_name = if lines_buffer.len() >= 2 {
        extract_function_name(&lines_buffer[1])
    } else {
        format!("unknown_{:04}", file_count)
    };

    let function_dir = output_dir.join(&function_name);

    let prompt_path = function_dir.join("prompt.txt");
    let code_path = function_dir.join("code.txt");
    // let code_slice_path = code_dir.join(format!("id-{:04}.txt", file_count));

    wrap_error(
        process_single_file(
            &function_dir,
            &prompt_path,
            lines_buffer,
            file_count,
            line_count,
            "prompt",
        ),
        "Failed to process prompt file",
    )?;

    wrap_error(
        process_single_file(
            &function_dir,
            &code_path,
            lines_buffer,
            file_count,
            line_count,
            "code",
        ),
        "Failed to process code file",
    )?;

    wrap_error(
        process_code_slice_file(&code_dir, lines_buffer, file_count),
        "Failed to process code slice file",
    )?;

    Ok(())
}

fn process_single_file(
    function_dir: &Path,
    file_path: &Path,
    lines_buffer: &[String],
    file_count: usize,
    line_count: usize,
    file_type: &str,
) -> io::Result<()> {
    let result = if file_type == "prompt" {
        process_single_prompt_file(
            function_dir,
            file_path,
            lines_buffer,
            file_count,
            line_count,
        )
    } else {
        process_single_code_file(
            function_dir,
            file_path,
            lines_buffer,
            file_count,
            line_count,
        )
    };

    wrap_error(
        result,
        &format!("Error processing {} file id-{:04}", file_type, file_count),
    )?;
    print_message(
        &format!("Processed {} file id-{:04}", file_type, file_count),
        OutputLevel::Debug,
    );
    Ok(())
}

fn prepare_new_function_dir(output_dir: &Path, lines_buffer: &[String]) -> io::Result<()> {
    // let function_dir = output_dir.join(format!("id-{:04}", file_count));
    let function_name = if lines_buffer.len() >= 2 {
        extract_function_name(&lines_buffer[1])
    } else {
        String::from("unknown")
    };

    let function_dir = output_dir.join(&function_name);

    wrap_error(
        fs::create_dir_all(&function_dir),
        &format!("Failed to create function directory {:?}", function_dir),
    )?;
    wrap_error(
        create_empty_files(&function_dir),
        &format!(
            "Failed to create empty files in directory {:?}",
            function_dir
        ),
    )?;
    Ok(())
}

fn process_code_slice_file(
    code_dir: &Path,
    lines_buffer: &[String],
    file_count: usize,
) -> io::Result<()> {
    let initial_file_name = format!("id-{:04}.txt", file_count);
    let initial_code_slice_path = code_dir.join(&initial_file_name);

    // 创建并写入文件
    let mut file = wrap_error(
        OpenOptions::new()
            .write(true)
            .create(true)
            .truncate(true)
            .open(&initial_code_slice_path),
        &format!(
            "Failed to open code slice file {:?}",
            initial_code_slice_path
        ),
    )?;

    wrap_error(
        write_buffered_lines(&mut file, lines_buffer, false),
        "Failed to write buffered lines to code slice file",
    )?;

    wrap_error(file.flush(), "Failed to flush code slice file")?;

    // 关闭文件
    drop(file);

    // 读取文件第二行并解析函数名
    if lines_buffer.len() >= 2 {
        let function_declaration = &lines_buffer[1];
        let function_name = extract_function_name(function_declaration);

        if !function_name.is_empty() {
            let new_file_name = format!("{}.txt", function_name);
            let new_code_slice_path = code_dir.join(&new_file_name);

            // 重命名文件
            wrap_error(
                fs::rename(&initial_code_slice_path, &new_code_slice_path),
                &format!(
                    "Failed to rename file from {:?} to {:?}",
                    initial_code_slice_path, new_code_slice_path
                ),
            )?;
        }
    }

    Ok(())
}

fn process_single_prompt_file(
    _function_dir: &Path,
    prompt_path: &Path,
    lines_buffer: &[String],
    file_count: usize,
    line_count: usize,
) -> io::Result<()> {
    let mut file = wrap_error(
        OpenOptions::new()
            .read(true)
            .write(true)
            .create(true)
            .truncate(true)
            .open(prompt_path),
        &format!("Failed to open prompt file {:?}", prompt_path),
    )?;

    wrap_error(
        update_file_header(&mut file, file_count, line_count),
        "Failed to update file header",
    )?;
    wrap_error(
        write_buffered_lines(&mut file, lines_buffer, false),
        "Failed to write buffered lines",
    )?;
    wrap_error(append_custom_content(&mut file), "Failed to append content")?;
    // wrap_error(
    //     append_custom_content_part_two(&mut file),
    //     "Failed to append custom content part two",
    // )?;
    wrap_error(file.flush(), "Failed to flush prompt file")?;

    Ok(())
}

fn process_single_code_file(
    _function_dir: &Path,
    code_path: &Path,
    lines_buffer: &[String],
    file_count: usize,
    line_count: usize,
) -> io::Result<()> {
    let mut file = wrap_error(
        OpenOptions::new()
            .read(true)
            .write(true)
            .create(true)
            .truncate(true)
            .open(code_path),
        &format!("Failed to open code file {:?}", code_path),
    )?;

    // wrap_error(
    //     update_file_header(&mut file, file_count, line_count),
    //     "Failed to update file header",
    // )?;
    wrap_error(
        write_buffered_lines(&mut file, lines_buffer, false),
        "Failed to write buffered lines",
    )?;
    wrap_error(file.flush(), "Failed to flush code file")?;

    Ok(())
}

fn update_file_header(file: &mut File, file_count: usize, line_count: usize) -> io::Result<()> {
    wrap_error(
        file.seek(io::SeekFrom::Start(0)),
        "Failed to seek to start of file",
    )?;

    let input_content = wrap_error(
        fs::read_to_string("input/sectionabstract.txt"),
        "Failed to read sectionabstract.txt",
    )?;

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
    wrap_error(
        writeln!(file, "{}", header),
        "Failed to write header to file",
    )?;
    Ok(())
}

fn create_empty_files(function_dir: &Path) -> io::Result<()> {
    let prompt_path = function_dir.join("prompt.txt");
    let code_path = function_dir.join("code.txt");
    let result_path = function_dir.join("result.txt");

    wrap_error(
        File::create(&prompt_path),
        &format!("Failed to create prompt file {:?}", prompt_path),
    )?;
    wrap_error(
        File::create(&result_path),
        &format!("Failed to create result file {:?}", result_path),
    )?;
    wrap_error(
        File::create(&code_path),
        &format!("Failed to create code file {:?}", code_path),
    )?;

    Ok(())
}

fn append_custom_content(file: &mut File) -> io::Result<()> {
    seek_to_end(file)?;
    write_separator(file)?;
    write_role_description(file)?;
    write_function_background(file)?;
    write_output_function_summary(file)?;
    // write_retrieve_document_sections(file)?;
    write_insert_code_comments(file)?;
    // write_thinking_chain(file)?;
    // write_json_format(file)?;
    write_json_code_format(file)?;
    write_attention(file)?;
    Ok(())
}
//
fn write_insert_code_comments(file: &mut File) -> io::Result<()> {
    writeln!(file, "Insert Code Comments: Now the function you want to work with is the following, \
                    which returns the contents of the corresponding RFC document in the same way as the example, \
                    and you need to do your best to refer to the original RFC document at every point where the control changes \
                    (e.g., if, else if, else, case, switch, while, return, label). \
                    ATTENTION! There may not be a corresponding RFC text in the code where the control flow changes, \
                    but you need to add comments as well (comments should be strongly related to the conceptual content of the RFC document, \
                    not abstract generic concepts).")
}
fn write_json_code_format(file: &mut File) -> io::Result<()> {
    writeln!(
        file,
        "Generate Function Code with inserted Code Comments in C Clang Format wrap in Mardown:\n"
    )
}
fn seek_to_end(file: &mut File) -> io::Result<()> {
    wrap_error(file.seek(SeekFrom::End(0)), "Failed to seek to end of file").map(|_| ())
    // 将 u64 转换为 ()
}

fn write_separator(file: &mut File) -> io::Result<()> {
    writeln!(file, "##############################")
}

fn write_role_description(file: &mut File) -> io::Result<()> {
    writeln!(file, "Role: Let us assume that you are an advanced reverse engineer and you are reverse engineering a network driver using IDA Pro, \
                    and you are also familiar with the RFC documentation. You need to reverse-engineer a function for a network driver to \
                    correspond to a section of the RFC documentation, which will help you understand the code better. \
                    The driver you're reversing is Schannel.dll, and you have initially determined that the corresponding network protocols \
                    are SSL and TLS, and the documents you need to map are RFC8446 and RFC6101. \
                    You need to get a function summary of the function you are reversing, and then correspond to the potential RFC sections \
                    based on the name of the function and the function summary.")
}

fn write_attention(file: &mut File) -> io::Result<()> {
    writeln!(
        file,
        "\nATTENTION: Remember YOU MUST ONLY output the Function Information Collection result."
    )
}

fn write_buffered_lines(file: &mut File, lines: &[String], json_format: bool) -> io::Result<()> {
    let mut non_empty_lines = lines
        .iter()
        .rev()
        .skip_while(|line| line.trim().is_empty())
        .collect::<Vec<_>>();
    non_empty_lines.reverse();

    for line in non_empty_lines {
        if json_format {
            wrap_error(
                writeln!(file, "\t\t{}", line),
                "Failed to write JSON line to file",
            )?;
        } else {
            wrap_error(writeln!(file, "{}", line), "Failed to write line to file")?;
        }
    }
    Ok(())
}

fn extract_function_name(declaration: &str) -> String {
    // 使用正则表达式来匹配最后一个空格到左括号之间的内容
    let re = Regex::new(r"\s([^\s(]+)\s*\(").unwrap();
    if let Some(captures) = re.captures(declaration) {
        if let Some(function_name) = captures.get(1) {
            let name = function_name.as_str();
            // 替换或删除不适合文件名的字符
            return sanitize_filename(name);
        }
    }
    String::new()
}

fn sanitize_filename(name: &str) -> String {
    // 定义不允许在文件名中使用的字符
    let invalid_chars: &[char] = &['<', '>', ':', '"', '/', '\\', '|', '?', '*'];

    name.chars()
        .map(|c| {
            if invalid_chars.contains(&c) || c == MAIN_SEPARATOR {
                '_'
            } else {
                c
            }
        })
        .collect::<String>()
        .trim_start_matches('_')
        .trim_end_matches('_')
        .to_string()
}

fn write_function_background(file: &mut File) -> io::Result<()> {
    writeln!(file, "Function Background: The function is reverse engineered from the driver file Schannel.dll on Windows platform. \
                    Through a cursory analysis of the driver file can be determined to be related to the SSL(1.3), TLS(3.0) protocol, \
                    that is, with RFC8446, RFC6101 strong correlation.\n")
}

fn write_output_function_summary(file: &mut File) -> io::Result<()> {
    writeln!(file, "Output Function Summary: Summarizes the function's functionality with several phrases instead of sentences, \
                    focuses on covering the function's control flow information, \
                    and highlights the protocol function points implemented by the function. \
                    Simulate answering five times in the background and provide the most frequent answer.\n")
}

// fn process_code_slice_file(code_dir: &Path, lines_buffer: &[String], file_count: usize) -> io::Result<()> {
//     if lines_buffer.len() < 2 {
//         return Err(io::Error::new(
//             ErrorKind::InvalidData,
//             "Not enough lines in buffer to process code slice file",
//         ));
//     }

//     let function_declaration = &lines_buffer[1];
//     let function_name = extract_function_name(function_declaration);
//     let file_name = if function_name.is_empty() {
//         format!("id-{:04}.txt", file_count)
//     } else {
//         format!("{}.txt", function_name)
//     };

//     let code_slice_path = code_dir.join(&file_name);

//     let mut file = wrap_error(
//         OpenOptions::new()
//             .write(true)
//             .create(true)
//             .truncate(true)
//             .open(&code_slice_path),
//         &format!("Failed to open code slice file {:?}", code_slice_path),
//     )?;

//     wrap_error(
//         write_buffered_lines(&mut file, lines_buffer, false),
//         "Failed to write buffered lines to code slice file",
//     )?;

//     wrap_error(file.flush(), "Failed to flush code slice file")?;

//     Ok(())
// }

// fn process_code_slice_file(code_slice_path: &Path, lines_buffer: &[String]) -> io::Result<()> {
//     let mut file = wrap_error(
//         OpenOptions::new()
//             .write(true)
//             .create(true)
//             .truncate(true)
//             .open(code_slice_path),
//         &format!("Failed to open code slice file {:?}", code_slice_path),
//     )?;

//     wrap_error(
//         write_buffered_lines(&mut file, lines_buffer, false),
//         "Failed to write buffered lines to code slice file",
//     )?;

//     wrap_error(file.flush(), "Failed to flush code slice file")?;

//     Ok(())
// }

// fn write_retrieve_document_sections(file: &mut File) -> io::Result<()> {
//     writeln!(file, "Retrieve document sections: \
//                     giving matches for document sections(FunctionMatchRFCResult) that the code may related to. \
//                     NOTE if the code is only business related(i.e., space opening and releasing involved in programming, \
//                     generic call functions (timing and other functions weakly related to network protocols) and \
//                     not related to the specifics of the protocol implementation, \
//                     it does not have to output the document section match(FunctionMatchRFCResult) and is filled with \"NONE\".\n")
// }

// fn write_thinking_chain(file: &mut File) -> io::Result<()> {
//     writeln!(file, "Retrieve document sections Thinking Chain: The function code is matched with the RFC document section, \
//                     and the thinking chain is provided to help you solve the problem better:")?;
//     writeln!(file, "\t1. Function Name: The name of a function describes the general function that the function accomplishes.")?;
//     writeln!(file, "\t2. Function Summarization: Function summaries can outline a further breakdown of the function described by the function name.")?;
//     writeln!(file, "\t3. Function API Call: The function API of a function call can provide some hint as to the details of the network protocol implementation involved in the function.")?;
//     writeln!(file, "\t4. Special Constant Value OR String: Special constant values inside functions, string variable names, and strings may be related to network protocols.")?;
//     writeln!(file, "\t5. Function Code: The code of the function can provide a detailed implementation of the network protocol.")
// }

// fn write_json_format(file: &mut File) -> io::Result<()> {
//     writeln!(
//         file,
//         "Generate Function Information Collection with JSON Format:\n"
//     )?;
//     writeln!(file, "{{")?;
//     write_json_field(file, "FunctionIndex", "(FILL WITH \"File count\" with less than four bits are indexed with zeros to make up the four bits.)")?;
//     write_json_field(file, "FunctionName", "(Full Function Code Name)")?;
//     write_json_array(
//         file,
//         "FunctionSummarization",
//         &[
//             "(Function Summary Phrase1)",
//             "(Function Summary Phrase2)",
//             "(...)",
//         ],
//     )?;
//     write_json_array(
//         file,
//         "FunctionMatchRFCResult",
//         &[
//             "(RFCXXXX-SectionX.X.X.X-FULL Section Title 1)",
//             "(RFCXXXX-SectionX.X.X.X-FULL Section Title 2)",
//             "(...)",
//         ],
//     )?;
//     writeln!(file, "}}")
// }

// fn write_json_field(file: &mut File, key: &str, value: &str) -> io::Result<()> {
//     writeln!(file, "\t\"{}\": \"{}\",", key, value)
// }

// fn write_json_array(file: &mut File, key: &str, values: &[&str]) -> io::Result<()> {
//     writeln!(file, "\t\"{}\": [", key)?;
//     for (i, value) in values.iter().enumerate() {
//         if i < values.len() - 1 {
//             writeln!(file, "\t\t\"{}\",", value)?;
//         } else {
//             writeln!(file, "\t\t\"{}\"", value)?;
//         }
//     }
//     writeln!(file, "\t],")
// }

use crate::error::*;
use crate::output::*;
use crate::utils::*;
use regex::Regex;
// use std::collections::{HashMap, HashSet};
use std::fs::{self, File, OpenOptions};
use std::io::{self, BufRead, BufReader, Write};
use std::path::{Path, PathBuf};

// pub fn process_call_graph(input_file: &str, output_dir: &Path) -> io::Result<()> {
//     let call_graph_input = Path::new("input").join("call_graph").join(input_file);
//     if !call_graph_input.exists() {
//         return Err(io::Error::new(
//             io::ErrorKind::NotFound,
//             format!("Call graph input file not found: {:?}", call_graph_input),
//         ));
//     }

//     let mut content = String::new();
//     File::open(&call_graph_input)?.read_to_string(&mut content)?;

//     let result = process_node_lines(&content);

//     let summary_dir = output_dir.join("summary");
//     fs::create_dir_all(&summary_dir)?;

//     let output_file = summary_dir.join("call_graph.txt");
//     let mut file = File::create(output_file)?;

//     // 将 HashMap 转换为 Vec 并排序
//     let mut sorted_result: Vec<_> = result.into_iter().collect();
//     sorted_result.sort_by(|a, b| {
//         a.0.parse::<usize>()
//             .unwrap_or(0)
//             .cmp(&b.0.parse::<usize>().unwrap_or(0))
//     });

//     // 写入排序后的结果
//     for (key, value) in sorted_result {
//         writeln!(file, "{}: {}", key, value)?;
//     }

//     Ok(())
// }

// fn process_node_lines(input: &str) -> HashMap<String, String> {
//     let mut result = HashMap::new();
//     let node_regex = Regex::new(
//         r#"node: \{ title: "(\d+)" label: "(.*?)" color: \d+ textcolor: \d+ bordercolor: black \}"#,
//     )
//     .unwrap();
//     // let cleanup_regex = Regex::new(r"@[0-9A-Z_$]+[A-Z]").unwrap();
//     // let cleanup_regex = Regex::new(r"@@[A-Z0-9_]+").unwrap();
//     // let cleanup_regex = Regex::new(r"@@[A-Z0-9_]+([A-Z](?=[a-z])|)").unwrap();
//     let cleanup_regex = Regex::new(r"@@[A-Z0-9_]+").unwrap();
//     let cleanup_regex_2 = Regex::new(r"@@[A-Z0-9_]+[A-Z][a-z]").unwrap();
//     let head_cleanup_regex = Regex::new(r"^[^a-zA-Z]+").unwrap();
//     let tail_cleanup_regex = Regex::new(r"_[0-9A-Z_]+$").unwrap();

//     for cap in node_regex.captures_iter(input) {
//         let title = cap[1].to_string();
//         let mut label = cap[2].to_string();

//         // 去除字符串头部的非英文字母符号
//         label = head_cleanup_regex.replace(&label, "").to_string();

//         // 去除由@，数字，$，下划线和大写字母构成的连续字符串
//         // label = cleanup_regex.replace_all(&label, "_").to_string();
//         label = cleanup_regex_2
//             .replace_all(&label, |caps: &regex::Captures| {
//                 let matched = caps.get(0).unwrap().as_str();
//                 let chars: Vec<char> = matched.chars().collect();
//                 let len = chars.len();

//                 if len >= 2
//                     && chars[len - 2].is_ascii_uppercase()
//                     && chars[len - 1].is_ascii_lowercase()
//                 {
//                     format!("_{}{}", chars[len - 2], chars[len - 1])
//                 } else {
//                     "_".to_string()
//                 }
//             })
//             .to_string();

//         label = cleanup_regex.replace(&label, "_").to_string();

//         // 将剩余的单个@转换为下划线
//         label = label.replace('@', "_");
//         label = label.replace('?', "_");
//         label = label.replace('$', "_");

//         // 合并连续的下划线
//         label = Regex::new(r"_+")
//             .unwrap()
//             .replace_all(&label, "_")
//             .to_string();

//         // 只保留第一次出现的子串
//         let mut seen = HashSet::new();
//         label = label
//             .split('_')
//             .filter(|&x| seen.insert(x))
//             .collect::<Vec<&str>>()
//             .join("_");

//         // 去除头部和尾部的下划线
//         label = label.trim_matches('_').to_string();
//         label = tail_cleanup_regex.replace(&label, "").to_string();
//         label = tail_cleanup_regex.replace(&label, "").to_string();
//         // // 再次去除由@，数字，$，下划线和大写字母构成的连续字符串
//         // label = cleanup_regex.replace_all(&label, "_").to_string();
//         // label = label.trim_matches('_').to_string();
//         // 如果处理后的标签为空，设置为"none"
//         let value = if label.is_empty() {
//             "none".to_string()
//         } else {
//             label
//         };

//         result.insert(title, value);
//     }

//     result
// }

pub fn distribute_files(source_dir: &Path, distribution_dir: &str) -> io::Result<()> {
    let files: Vec<_> = fs::read_dir(source_dir)?
        .filter_map(|entry| entry.ok())
        .collect();

    let total_files = files.len();
    let files_per_group = (total_files + 2) / 3; // Round up division

    let groups = vec![
        ("xyf", 0, files_per_group),
        ("wyl", files_per_group, files_per_group * 2),
        ("xyy", files_per_group * 2, total_files),
    ];

    for (group_name, start, end) in groups {
        let group_dir = PathBuf::from(distribution_dir).join(group_name);
        fs::create_dir_all(&group_dir)?;

        for entry in &files[start..end] {
            let source_path = entry.path();
            let file_name = source_path.file_name().unwrap();
            let dest_path = group_dir.join(file_name);
            fs::copy(&source_path, &dest_path)?;
        }
    }

    Ok(())
}

pub fn process_file(
    input_path: &Path,
    output_dir: &Path,
    code_dir: &Path,
    re: &Regex,
) -> io::Result<(usize, Vec<String>)> {
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
    let mut function_name_list = Vec::new();

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

            line_count = 0;
            lines_buffer.clear();
        }

        if first_match {
            lines_buffer.push(line);
            line_count += 1;

            if lines_buffer.len() == 2 {
                // We have the function declaration, so we can prepare the directory
                let function_name = wrap_error(
                    prepare_new_function_dir(output_dir, &lines_buffer),
                    "Failed to prepare new function directory",
                )?;
                function_name_list.push(function_name);
            }
        }
    }

    if !lines_buffer.is_empty() {
        wrap_error(
            process_buffer(output_dir, code_dir, &lines_buffer, file_count, line_count),
            "Failed to process final buffer",
        )?;
    }

    Ok((file_count, function_name_list))
}

pub fn process_buffer(
    output_dir: &Path,
    code_dir: &Path,
    lines_buffer: &[String],
    file_count: usize,
    line_count: usize,
) -> io::Result<()> {
    let function_name = if lines_buffer.len() >= 2 {
        sanitize_filename(&extract_function_name(&lines_buffer[1]))
    } else {
        format!("unknown_{:04}", file_count)
    };

    let function_dir = output_dir.join(&function_name);

    let prompt_path = function_dir.join("prompt.txt");
    let code_path = function_dir.join("code.txt");

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

pub fn process_single_file(
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

pub fn prepare_new_function_dir(output_dir: &Path, lines_buffer: &[String]) -> io::Result<String> {
    let function_name = if lines_buffer.len() >= 2 {
        print_message(
            &format!("line message: {}", &lines_buffer[1]),
            OutputLevel::Debug,
        );
        sanitize_filename(&extract_function_name(&lines_buffer[1]))
    } else {
        String::from("unknown")
    };

    let function_dir = output_dir.join(&function_name);
    print_message(
        &format!("function_dir info: {:?}", function_dir.display()),
        OutputLevel::Debug,
    );
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
    Ok(function_name)
}

pub fn process_code_slice_file(
    code_dir: &Path,
    lines_buffer: &[String],
    file_count: usize,
) -> io::Result<()> {
    let initial_file_name = format!("id-{:04}.txt", file_count);
    let initial_code_slice_path = code_dir.join(&initial_file_name);

    // Create and write to file
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

    // Close file
    drop(file);

    // Read second line of the file and parse function name
    if lines_buffer.len() >= 2 {
        let function_declaration = &lines_buffer[1];
        let function_name = sanitize_filename(&extract_function_name(function_declaration));

        if !function_name.is_empty() {
            let new_file_name = format!("{}.txt", function_name);
            let new_code_slice_path = code_dir.join(&new_file_name);

            // Rename file
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

pub fn process_single_prompt_file(
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

    wrap_error(file.flush(), "Failed to flush prompt file")?;

    Ok(())
}

pub fn process_single_code_file(
    _function_dir: &Path,
    code_path: &Path,
    lines_buffer: &[String],
    _file_count: usize,
    _line_count: usize,
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

    wrap_error(
        write_buffered_lines(&mut file, lines_buffer, false),
        "Failed to write buffered lines",
    )?;
    wrap_error(file.flush(), "Failed to flush code file")?;

    Ok(())
}

pub fn write_buffered_lines(
    file: &mut File,
    lines: &[String],
    json_format: bool,
) -> io::Result<()> {
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

pub fn write_function_list(output_dir: &Path, function_names: &[String]) -> io::Result<()> {
    let function_list_path = output_dir.join("function_list.txt");
    let mut function_list_file = File::create(function_list_path)?;

    for function_name in function_names {
        writeln!(function_list_file, "{}", function_name)?;
    }

    Ok(())
}

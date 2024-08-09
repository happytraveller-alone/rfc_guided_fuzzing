use regex::Regex;
use std::env;
use std::io::{self, ErrorKind};
use std::path::Path;
use std::time::Instant;

mod call_graph;
mod error;
mod file_processing;
mod output;
mod utils;

use call_graph::*;
use error::*;
use file_processing::*;
use utils::*;

fn main() {
    if let Err(e) = run() {
        eprintln!("Error: {}", e);
        std::process::exit(1);
    }
}

fn run() -> io::Result<()> {
    let start_time = Instant::now();
    let args: Vec<String> = env::args().collect();
    let (input_file, is_default) = if args.len() > 1 {
        (format!("input/driver/{}", args[1]), false)
    } else {
        (String::from("input/driver/test.txt"), true)
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
    let distribution_dir = "distribution";
    let code_process_dir = "record";
    println!("Starting program...");
    println!("Input file: {:?}", input_path);

    for dir in &[output_dir, code_dir, distribution_dir, code_process_dir] {
        wrap_error(
            clean_output_directory(dir),
            &format!("Failed to clean {} directory", dir),
        )?;
    }

    let sub_output_dir = wrap_error(
        prepare_output_directory(input_path, output_dir),
        "Failed to prepare output directory",
    )?;
    let sub_output_dir = Path::new(&sub_output_dir);
    let sub_code_dir = wrap_error(
        prepare_output_directory(input_path, code_dir),
        "Failed to prepare code directory",
    )?;
    let sub_code_dir = Path::new(&sub_code_dir);
    let sub_record_dir = wrap_error(
        prepare_output_directory(input_path, code_process_dir),
        "Failed to prepare record directory",
    )?;
    let sub_record_dir = Path::new(&sub_record_dir);

    let re = Regex::new(r"//-----\s*\(([0-9A-Fa-f]+)\)\s*-+")
        .map_err(|e| io::Error::new(ErrorKind::Other, format!("Regex compilation error: {}", e)))?;

    let (file_count, function_names) = wrap_error(
        process_file(input_path, &sub_record_dir, &sub_code_dir, &re),
        "Failed to process file",
    )?;

    wrap_error(
        write_function_list(&sub_output_dir, &function_names),
        "Failed to write function name list",
    )?;

    wrap_error(
        distribute_files(&sub_code_dir, distribution_dir),
        "Failed to distribute files",
    )?;

    let call_graph_input = input_path
        .file_name()
        .unwrap()
        .to_str()
        .unwrap()
        .to_string();
    wrap_error(
        process_call_graph(&call_graph_input, &sub_output_dir),
        "Failed to process call graph",
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

use regex::Regex;
use std::env;
use std::fs;
use std::io::{self, ErrorKind};
use std::path::{Path, PathBuf};
use std::time::Instant;

mod error;
mod file_processing;
mod output;
mod utils;

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
    let distribution_dir = "distribution";

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
    wrap_error(
        clean_output_directory(distribution_dir),
        "Failed to clean distribution directory",
    )?;

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

    let re = Regex::new(r"//-----\s*\(([0-9A-Fa-f]+)\)\s*-+")
        .map_err(|e| io::Error::new(ErrorKind::Other, format!("Regex compilation error: {}", e)))?;

    let (file_count, function_names) = wrap_error(
        process_file(input_path, &sub_output_dir, &sub_code_dir, &re),
        "Failed to process file",
    )?;

    write_function_list(&sub_output_dir, &function_names)?;

    distribute_files(&sub_code_dir, distribution_dir)?;

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

fn distribute_files(source_dir: &Path, distribution_dir: &str) -> io::Result<()> {
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

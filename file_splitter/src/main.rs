use regex::Regex;
use std::fs::{self, File, OpenOptions};
use std::io::{BufRead, BufReader, Write, Result};
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

    for line in reader.lines() {
        let line = line?;

        if re.is_match(&line) {
            current_file = create_new_file(output_dir, &mut file_count)?;
        }

        if let Some(ref mut file) = current_file {
            writeln!(file, "{}", line)?;
        }
    }

    if let Some(mut file) = current_file {
        file.flush()?;
    }

    Ok(file_count)
}

fn create_new_file(output_dir: &Path, file_count: &mut usize) -> Result<Option<File>> {
    if let Some(mut file) = std::mem::take(&mut None::<File>) {
        file.flush()?;
    }

    *file_count += 1;
    let file_name = output_dir.join(format!("id-{:04}.c", file_count));
    let file = OpenOptions::new()
        .write(true)
        .create(true)
        .truncate(true)
        .open(file_name)?;

    Ok(Some(file))
}
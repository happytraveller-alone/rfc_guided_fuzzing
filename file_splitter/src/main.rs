use regex::Regex;
use std::fs::{self, File, OpenOptions};
use std::io::{BufRead, BufReader, Write, Result, Seek, SeekFrom};
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
            if let Some(mut file) = current_file.take() {
                write_buffered_lines(&mut file, &lines_buffer)?;
                update_file_header(&mut file, file_count, line_count)?;
                file.flush()?;
            }
            current_file = create_new_file(output_dir, &mut file_count)?;
            line_count = 0;
            lines_buffer.clear();
        }

        lines_buffer.push(line);
        line_count += 1;
    }

    if let Some(mut file) = current_file {
        write_buffered_lines(&mut file, &lines_buffer)?;
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
    let file_name = output_dir.join(format!("id-{:04}.c", file_count));
    let file = OpenOptions::new()
        .read(true)
        .write(true)
        .create(true)
        .truncate(true)
        .open(file_name)?;

    Ok(Some(file))
}

fn update_file_header(file: &mut File, file_count: usize, line_count: usize) -> Result<()> {
    file.seek(SeekFrom::Start(0))?;
    writeln!(file, "// File count: {}", file_count)?;
    writeln!(file, "// Total lines: {}", line_count - 1)?;
    // writeln!(file, "\n")?;
    Ok(())
}

fn write_buffered_lines(file: &mut File, lines: &[String]) -> Result<()> {
    let mut non_empty_lines = lines.iter().rev().skip_while(|line| line.trim().is_empty()).collect::<Vec<_>>();
    non_empty_lines.reverse();
    
    for line in non_empty_lines {
        writeln!(file, "{}", line)?;
    }
    Ok(())
}
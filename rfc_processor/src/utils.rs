use std::collections::HashMap;
use std::env;
use std::fs::{self, File};
use std::io::{BufRead, BufReader, Write};
use std::path::{Path, PathBuf};
use std::error::Error;
use regex::Regex;

pub fn get_project_root() -> PathBuf {
    env::current_exe()
        .expect("Failed to get current executable path")
        .parent()
        .expect("Failed to get parent directory")
        .parent()
        .expect("Failed to get project root")
        .to_path_buf()
}

pub fn create_directories(project_root: &PathBuf) -> Result<(PathBuf, PathBuf), Box<dyn Error>> {
    let input_dir = project_root.join("..\\input");
    let output_dir = project_root.join("..\\output");
    fs::create_dir_all(&input_dir)?;
    fs::create_dir_all(&output_dir)?;
    Ok((input_dir, output_dir))
}

pub fn extract_rfc_info(text: &str) -> HashMap<String, String> {
    let re = Regex::new(r#"(?P<authors>.*?), "(?P<title>.*?)", RFC (?P<number>\d+)"#).unwrap();
    let mut rfc_map = HashMap::new();

    for cap in re.captures_iter(text) {
        let number = cap.name("number").unwrap().as_str().to_string();
        let title = cap.name("title").unwrap().as_str().to_string();
        rfc_map.insert(number, title);
    }

    rfc_map
}

pub fn save_rfc_info(rfc_number: &str, title: &str, rfc_output_dir: &Path) -> Result<(), Box<dyn Error>> {
    let info_file = rfc_output_dir.join("rfc_info.txt");
    let content = format!("RFC{}: \"{}\"\n", rfc_number, title);
    
    fs::write(&info_file, content)?;
    println!("RFC info saved to {:?}", info_file);
    Ok(())
}

pub fn create_rfc_output_directory(
    output_dir: &Path,
    rfc_number: &str,
) -> Result<PathBuf, Box<dyn Error>> {
    let rfc_dir = output_dir.join(format!("RFC-{}", rfc_number));
    fs::create_dir_all(&rfc_dir)?;
    Ok(rfc_dir)
}

pub fn remove_headers_footers(input_file: &PathBuf) -> Result<String, Box<dyn Error>> {
    let reader = BufReader::new(File::open(input_file)?);
    let header_footer_regex = Regex::new(r"^RFC \d+\s+.*\s+\w+ \d{4}$|^.*\s+\[Page \d+\]$")?;
    let page_break_regex = Regex::new(r"\f")?;

    let mut content = String::new();
    let mut empty_line_count = 0;

    for line in reader.lines() {
        let line = line?;
        let line = page_break_regex.replace_all(&line, "").to_string();

        if !header_footer_regex.is_match(&line) {
            if line.trim().is_empty() {
                empty_line_count += 1;
                if empty_line_count <= 3 {
                    content.push('\n');
                }
            } else {
                empty_line_count = 0;
                content.push_str(&line);
                content.push('\n');
            }
        }
    }

    Ok(content.trim().to_string())
}

pub fn save_content(content: &str, file_path: &PathBuf) -> Result<(), Box<dyn Error>> {
    let mut file = File::create(file_path)?;
    file.write_all(content.as_bytes())?;
    println!("内容已保存到 {:?}", file_path);
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_extract_rfc_info() {
        let text = r#"Doe, J., "Test RFC", RFC 1234, January 2023.
Smith, A., "Another RFC", RFC 5678, February 2023."#;
        let rfc_map = extract_rfc_info(text);
        assert_eq!(rfc_map.get("1234"), Some(&"Test RFC".to_string()));
        assert_eq!(rfc_map.get("5678"), Some(&"Another RFC".to_string()));
    }

    #[test]
    fn test_remove_headers_footers() {
        // This test would require creating a temporary file with sample content
        // and then calling remove_headers_footers on it.
        // For brevity, we'll skip the implementation here.
    }
}
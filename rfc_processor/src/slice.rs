use regex::Regex;
use std::collections::BTreeMap;
use std::error::Error;
use std::fs::{self, File};
use std::io::{Write, Result as IoResult};
use std::path::{Path, PathBuf};
use std::cmp::Ordering;
use crate::{INSTRUCTION_HEADER, INSTRUCTION_FOOTER, PROCESSING_INSTRUCTIONS, OUTPUT_FORMAT};



#[derive(PartialEq, Eq, Clone)]
pub struct SectionNumber(pub String);

impl PartialOrd for SectionNumber {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for SectionNumber {
    fn cmp(&self, other: &Self) -> Ordering {
        let self_parts: Vec<u32> = self
            .0
            .split('.')
            .filter(|s| !s.is_empty())
            .map(|s| s.parse().unwrap_or(0))
            .collect();
        let other_parts: Vec<u32> = other
            .0
            .split('.')
            .filter(|s| !s.is_empty())
            .map(|s| s.parse().unwrap_or(0))
            .collect();
        self_parts.cmp(&other_parts)
    }
}

pub fn slice_content(
    content: &str,
    rfc_output_dir: &Path,
    rfc_number: &str,
) -> Result<(), Box<dyn Error>> {
    let (sections, mut section_map) = extract_sections(content)?;
    process_section_map(&mut section_map);
    export_map_to_txt(&section_map, rfc_output_dir, "sections.txt")?;
    save_sections(&sections, &section_map, rfc_output_dir, rfc_number)?;
    Ok(())
}

fn extract_sections(
    content: &str,
) -> Result<
    (
        Vec<(SectionNumber, String, String)>,
        BTreeMap<SectionNumber, String>,
    ),
    Box<dyn Error>,
> {
    let section_regex = Regex::new(r"(?m)^(\d+(?:\.\d+)*\.?)\s+(.*?)$")?;
    let mut sections = Vec::new();
    let mut section_map = BTreeMap::new();
    let mut current_section = String::new();
    let mut current_title = String::new();
    let mut current_number = SectionNumber(String::new());

    for line in content.lines() {
        if let Some(captures) = section_regex.captures(line) {
            if !current_section.is_empty() {
                sections.push((
                    current_number.clone(),
                    current_title.clone(),
                    current_section.clone(),
                ));
                current_section.clear();
            }
            let mut number = captures.get(1).unwrap().as_str().to_string();
            if !number.ends_with('.') {
                number.push('.');
            }
            let title = captures.get(2).unwrap().as_str().to_string();
            current_number = SectionNumber(number.clone());
            current_title = title.trim().to_string();
            section_map.insert(current_number.clone(), current_title.clone());
        } else {
            current_section.push_str(line);
            current_section.push('\n');
        }
    }

    if !current_section.is_empty() {
        sections.push((
            current_number.clone(),
            current_title.clone(),
            current_section.trim().to_string(),
        ));
    }

    Ok((sections, section_map))
}

fn process_section_map(map: &mut BTreeMap<SectionNumber, String>) {
    let mut processed_map = BTreeMap::new();

    for (key, value) in map.clone().iter() {
        let parts: Vec<&str> = key.0.trim_end_matches('.').split('.').collect();
        let mut new_value = Vec::new();
        let mut current_key = String::new();

        for (i, part) in parts.iter().enumerate() {
            if i > 0 {
                current_key.push('.');
            }
            current_key.push_str(part);
            
            if let Some(section_title) = map.get(&SectionNumber(current_key.clone() + ".")) {
                new_value.push(section_title.clone());
            }
        }

        new_value.pop();
        
        let full_value = if new_value.is_empty() {
            value.clone()
        } else {
            new_value.join("_") + "_" + value
        };
        let cleaned_value = full_value.replace("/", "");
        let clean_key = SectionNumber(key.0.trim_end_matches('.').to_string());
        processed_map.insert(clean_key, cleaned_value);
    }

    *map = processed_map;
}

fn export_map_to_txt(
    map: &BTreeMap<SectionNumber, String>,
    rfc_output_dir: &Path,
    filename: &str,
) -> Result<(), Box<dyn Error>> {
    let filestore = rfc_output_dir.join(filename);

    if filestore.exists() {
        fs::remove_file(&filestore)?;
        println!("已删除现有文件: {:?}", filestore);
    }

    let mut file = File::create(&filestore)?;
    for (key, value) in map.iter() {
        writeln!(file, "{}\t{}", key.0, value)?;
    }

    println!("已创建新文件并写入内容: {:?}", filestore);
    Ok(())
}

fn save_sections(
    sections: &[(SectionNumber, String, String)],
    section_map: &BTreeMap<SectionNumber, String>,
    rfc_output_dir: &Path,
    rfc_number: &str,
) -> Result<(), Box<dyn Error>> {
    let slice_dir = prepare_slice_directory(rfc_output_dir)?;
    let saved_count = save_section_files(sections, section_map, &slice_dir, rfc_number)?;
    println!("共保存了 {} 个非空切片到 {:?}", saved_count, slice_dir);
    Ok(())
}

fn prepare_slice_directory(rfc_output_dir: &Path) -> Result<PathBuf, Box<dyn Error>> {
    let slice_dir = rfc_output_dir.join("slice");
    if slice_dir.exists() {
        clear_directory(&slice_dir)?;
        println!("已清空现有的 slice 目录");
    } else {
        fs::create_dir_all(&slice_dir)?;
        println!("已创建新的 slice 目录");
    }
    Ok(slice_dir)
}

fn clear_directory(dir: &Path) -> Result<(), Box<dyn Error>> {
    for entry in fs::read_dir(dir)? {
        let entry = entry?;
        let path = entry.path();
        if path.is_file() {
            fs::remove_file(path)?;
        } else if path.is_dir() {
            fs::remove_dir_all(path)?;
        }
    }
    Ok(())
}

fn save_section_files(
    sections: &[(SectionNumber, String, String)],
    section_map: &BTreeMap<SectionNumber, String>,
    slice_dir: &Path,
    rfc_number: &str,
) -> Result<usize, Box<dyn Error>> {
    let mut saved_count = 0;
    for (i, (number, _, content)) in sections.iter().enumerate() {
        let trimmed_content = content.trim();
        if trimmed_content.is_empty() {
            continue;
        }
        saved_count += 1;

        let full_title = get_full_title(number, section_map);
        let file_name = generate_file_name(rfc_number, i, &full_title);
        let file_path = slice_dir.join(file_name);
        save_section_file(&file_path, &full_title, trimmed_content)?;
    }
    Ok(saved_count)
}

fn get_full_title(number: &SectionNumber, section_map: &BTreeMap<SectionNumber, String>) -> String {
    match section_map.get(number) {
        Some(title) => format!("{} {}", number.0, title),
        None => format!("{}", number.0),
    }
}

fn generate_file_name(rfc_number: &str, index: usize, full_title: &str) -> String {
    format!(
        "{}_slice_{:03}_{}.txt",
        rfc_number,
        index + 1,
        full_title.replace(" ", "_").replace(".", "_")
    )
}

fn save_section_file(file_path: &Path, full_title: &str, content: &str) -> IoResult<()> {
    let mut file = File::create(file_path)?;
    
    write_section(&mut file, full_title, content)?;
    write_instructions(&mut file)?;
    
    Ok(())
}

fn write_section(file: &mut File, full_title: &str, content: &str) -> IoResult<()> {
    writeln!(file, "{}", INSTRUCTION_HEADER)?;
    writeln!(file, "--- Section: {} ---", full_title)?;
    writeln!(file, "{}", content)?;
    writeln!(file, "{}", INSTRUCTION_FOOTER)?;
    Ok(())
}

fn write_instructions(file: &mut File) -> IoResult<()> {
    writeln!(file, "{}", PROCESSING_INSTRUCTIONS)?;
    writeln!(file, "{}", OUTPUT_FORMAT)?;
    Ok(())
}

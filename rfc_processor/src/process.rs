use regex::Regex;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::error::Error;
use crate::{BODY_START, BODY_END, FILTER_SECTIONS};

pub struct Regexes {
    pub header_footer: Regex,
    pub page_break: Regex,
    pub section_title: Regex,
}

pub fn process_rfc_content(input_file: &std::path::PathBuf) -> Result<String, Box<dyn Error>> {
    let reader = BufReader::new(File::open(input_file)?);
    let regexes = Regexes {
        header_footer: Regex::new(r"^RFC \d+\s+.*\s+\w+ \d{4}$|^.*\s+\[Page \d+\]$")?,
        page_break: Regex::new(r"\f")?,
        section_title: Regex::new(r"^(\d+(?:\.\d+)*\.?)\s+(.*)")?,
    };

    process_content(reader, &regexes)
}

pub fn process_content(reader: BufReader<File>, regexes: &Regexes) -> Result<String, Box<dyn Error>> {
    let mut content = String::new();
    let mut empty_line_count = 0;
    let mut skip_section = true;
    let mut found_intro = false;
    let mut in_main_content = false;
    let mut iana_passed = false;

    for line in reader.lines() {
        let line = line?;
        let line = regexes.page_break.replace_all(&line, "").to_string();

        if regexes.header_footer.is_match(&line) {
            continue;
        }

        if let Some(captures) = regexes.section_title.captures(&line) {
            if let Some(section_result) = process_section(
                &captures,
                &mut found_intro,
                &mut in_main_content,
                &mut iana_passed,
            ) {
                match section_result {
                    SectionResult::Skip(should_skip) => skip_section = should_skip,
                    SectionResult::Break => break,
                }
            }
        }

        if !in_main_content || skip_section {
            continue;
        }

        process_line(&mut content, &line, &mut empty_line_count);
    }

    validate_and_finalize_content(content, found_intro)
}

enum SectionResult {
    Skip(bool),
    Break,
}

fn process_section(
    captures: &regex::Captures,
    found_intro: &mut bool,
    in_main_content: &mut bool,
    iana_passed: &mut bool,
) -> Option<SectionResult> {
    if let Some(title) = captures.get(2) {
        let section_title = title.as_str().trim();

        match section_title {
            BODY_START => {
                *found_intro = true;
                *in_main_content = true;
                Some(SectionResult::Skip(true))
            }
            BODY_END => {
                *iana_passed = true;
                Some(SectionResult::Skip(false))
            }
            _ if *iana_passed
                && captures
                    .get(1)
                    .map_or(false, |m| m.as_str().starts_with("1.")) =>
            {
                Some(SectionResult::Break)
            }
            _ => Some(SectionResult::Skip(
                FILTER_SECTIONS.contains(&section_title),
            )),
        }
    } else {
        None
    }
}

fn process_line(content: &mut String, line: &str, empty_line_count: &mut i32) {
    if line.trim().is_empty() {
        *empty_line_count += 1;
        if *empty_line_count <= 1 {
            content.push('\n');
        }
    } else {
        *empty_line_count = 0;
        content.push_str(line);
        content.push('\n');
    }
}

fn validate_and_finalize_content(
    content: String,
    found_intro: bool,
) -> Result<String, Box<dyn Error>> {
    if !found_intro {
        return Err("未找到介绍部分".into());
    }

    if content.is_empty() {
        return Err("处理后的内容为空".into());
    }

    Ok(content.trim().to_string())
}
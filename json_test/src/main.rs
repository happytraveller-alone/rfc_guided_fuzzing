use regex::Regex;

fn clean_json(result_value: &str) -> String {
    // 移除控制字符
    let re = Regex::new(r"[\u0000-\u001F]").unwrap();
    let mut cleaned_json = re.replace_all(result_value, "").to_string();

    // 清理特定标记
    let mut changed = true;
    while changed {
        let prev_json = cleaned_json.clone();
        cleaned_json = cleaned_json
            .replace("```json", "")
            .replace("```", "")
            .replace("[]", "")
            .replace("\"[", "[")
            .replace("]\"", "]")
            .replace("\"\"", "\"")
            .trim()
            .to_string();
        
        // 如果没有更多变化，则退出循环
        if cleaned_json == prev_json {
            changed = false;
        }
    }

    cleaned_json
}

fn main() {
    let json_string = r#"
    ```json
    ```json
    [
        {
            "section": "example section",
            "title": "example title",
            "value": "example value\u0000"
        }
    ]
    ```
    ```"#;
    
    let cleaned_json = clean_json(json_string);
    println!("Cleaned JSON: {}", cleaned_json);
}

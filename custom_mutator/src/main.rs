use serde_json::{json, Value};
use thiserror::Error;

#[derive(Error, Debug)]
pub enum HexError {
    #[error("Invalid value type in field {0}: expected hex string array or object")]
    InvalidType(String),
    #[error("Invalid hex format in field {0}: {1}")]
    InvalidFormat(String, String),
    #[error("Value out of byte range in field {0}: {1}")]
    ValueOutOfRange(String, String),
    #[error("Field not found: {0}")]
    FieldNotFound(String),
}

struct HexProcessor {
    valid_range: std::ops::RangeInclusive<u8>,
}

impl HexProcessor {
    fn new() -> Self {
        Self {
            valid_range: 0x00..=0xFF,
        }
    }

    fn parse_hex(&self, hex_str: &str) -> Result<u8, HexError> {
        if !hex_str.starts_with("0x") {
            return Err(HexError::InvalidFormat(
                String::new(),
                format!("Hex string must start with 0x: {}", hex_str),
            ));
        }

        let hex_val = &hex_str[2..];
        if hex_val.len() != 2 {
            return Err(HexError::InvalidFormat(
                String::new(),
                format!("Hex string must be 2 digits: {}", hex_str),
            ));
        }

        u8::from_str_radix(hex_val, 16).map_err(|_| {
            HexError::InvalidFormat(String::new(), format!("Invalid hex value: {}", hex_str))
        })
    }

    fn validate_value(&self, value: &Value, path: &str) -> Result<(), HexError> {
        match value {
            Value::String(s) => {
                let hex = self.parse_hex(s).map_err(|e| match e {
                    HexError::InvalidFormat(_, msg) => {
                        HexError::InvalidFormat(path.to_string(), msg)
                    }
                    _ => e,
                })?;

                if !self.valid_range.contains(&hex) {
                    return Err(HexError::ValueOutOfRange(path.to_string(), s.clone()));
                }
                Ok(())
            }
            Value::Object(map) => {
                for (key, v) in map {
                    let new_path = if path.is_empty() {
                        key.clone()
                    } else {
                        format!("{}.{}", path, key)
                    };
                    self.validate_value(v, &new_path)?;
                }
                Ok(())
            }
            Value::Array(arr) => {
                for (idx, v) in arr.iter().enumerate() {
                    let new_path = format!("{}[{}]", path, idx);
                    self.validate_value(v, &new_path)?;
                }
                Ok(())
            }
            _ => Err(HexError::InvalidType(path.to_string())),
        }
    }

    fn process_value(&self, value: &Value, result: &mut Vec<String>) {
        match value {
            Value::String(s) => {
                result.push(s.clone());
            }
            Value::Object(map) => {
                for v in map.values() {
                    self.process_value(v, result);
                }
            }
            Value::Array(arr) => {
                for v in arr {
                    self.process_value(v, result);
                }
            }
            _ => {}
        }
    }

    fn process(&self, input: &Value) -> Result<Vec<String>, HexError> {
        self.validate_value(input, "")?;
        let mut result = Vec::new();
        self.process_value(input, &mut result);
        Ok(result)
    }

    // 替换指定字段的全部内容
    fn replace_field(
        &self,
        value: &mut Value,
        path: &str,
        new_value: Value,
    ) -> Result<(), HexError> {
        let parts: Vec<&str> = path.split('.').collect();
        let mut current = value;

        // 遍历路径找到目标字段的父节点
        for (i, &part) in parts.iter().enumerate().take(parts.len() - 1) {
            current = current
                .get_mut(part)
                .ok_or_else(|| HexError::FieldNotFound(parts[..=i].join(".")))?;
        }

        // 替换最后一个字段的值
        if let Some(last) = parts.last() {
            if let Value::Object(map) = current {
                // 验证新值的格式
                self.validate_value(&new_value, path)?;
                map.insert(last.to_string(), new_value);
                Ok(())
            } else {
                Err(HexError::InvalidType(parts[..parts.len() - 1].join(".")))
            }
        } else {
            Err(HexError::FieldNotFound(path.to_string()))
        }
    }

    // 替换字段内的部分内容
    fn replace_partial(
        &self,
        value: &mut Value,
        path: &str,
        index: usize,
        new_value: &str,
    ) -> Result<(), HexError> {
        let parts: Vec<&str> = path.split('.').collect();
        let mut current = value;

        // 找到目标字段
        for (i, &part) in parts.iter().enumerate() {
            current = current
                .get_mut(part)
                .ok_or_else(|| HexError::FieldNotFound(parts[..=i].join(".")))?;
        }

        // 处理数组替换
        if let Value::Array(arr) = current {
            if index < arr.len() {
                // 验证新值格式
                if let Ok(_) = self.parse_hex(new_value) {
                    arr[index] = Value::String(new_value.to_string());
                    Ok(())
                } else {
                    Err(HexError::InvalidFormat(
                        path.to_string(),
                        format!("Invalid hex value: {}", new_value),
                    ))
                }
            } else {
                Err(HexError::ValueOutOfRange(
                    path.to_string(),
                    format!("Index {} out of range", index),
                ))
            }
        } else {
            Err(HexError::InvalidType(path.to_string()))
        }
    }
}

fn main() -> Result<(), HexError> {
    // 合法的输入格式，支持递归结构
    // TODO需求一（WYL）：报文解析的格式范例，每个字段的key是字符串格式，
    // value是数组，数组的每个元素是字符串格式，表示16进制的数值
    let valid_json = r#"{
        "field1": ["0x12", "0x34"],
        "field2": {
            "sub1": ["0x56", "0x78"],
            "sub2": ["0x9A", "0xBC"]
        },
        "field3": ["0xDE", "0xF0", "0x43", "0x21"]
    }"#;

    // 非法的输入格式示例
    let invalid_json = r#"{
        "field1": ["0x12", "0x34"],
        "field2": {
            "sub1": [86, 120],
            "sub2": ["0x9A", "0xBC"]
        },
        "field3": ["0xDE", "0xF0", "0x43", "0x21"]
    }"#;

    let processor = HexProcessor::new();

    // 测试合法输入
    println!("Testing valid input:");
    match serde_json::from_str(valid_json) {
        Ok(input) => {
            match processor.process(&input) {
                Ok(result) => {
                    // println!("Result as JSON array:");
                    println!("{}", serde_json::to_string_pretty(&json!(result)).unwrap());

                    println!("\nResult as simple array:");
                    println!("[{}]", result.join(", "));

                    // 转换为字节数组
                    let bytes: Vec<u8> = result
                        .iter()
                        .filter_map(|hex| {
                            let hex = hex.trim_start_matches("0x");
                            u8::from_str_radix(hex, 16).ok()
                        })
                        .collect();
                    println!("\nAs bytes: {:02X?}", bytes);
                }
                Err(e) => println!("Processing error: {}", e),
            }
        }
        Err(e) => println!("JSON parse error: {}", e),
    }

    // 测试非法输入
    println!("\nTesting invalid input:");
    match serde_json::from_str(invalid_json) {
        Ok(input) => match processor.process(&input) {
            Ok(result) => {
                println!("Result: {:?}", result);
            }
            Err(e) => println!("Processing error: {}", e),
        },
        Err(e) => println!("JSON parse error: {}", e),
    }

    let json_str_replace_test = r#"{
        "field1": ["0x12", "0x34"],
        "field2": {
            "sub1": ["0x56", "0x78"],
            "sub2": ["0x9A", "0xBC"]
        },
        "field3": ["0xDE", "0xF0", "0x43", "0x21"]
    }"#;

    let mut input: Value = serde_json::from_str(json_str_replace_test).expect("Invalid JSON");
    let processor = HexProcessor::new();

    // 全字段替换示例
    // 需求二：更改字段的全部内容
    // TODO：test strategy要明确字段的具体位置，输出形式为field2.sub1这种形式，表示field2下的sub1字段(SYB)
    let new_field = json!(["0xAA", "0xBB"]);
    processor.replace_field(&mut input, "field2.sub1", new_field.clone())?;

    // 部分内容替换示例
    // 更改字段内的部分内容（optional）
    // 该需求假设字段并没有被充分的解析，只能通过索引来定位，输出形式为field3[1]这种形式，表示field3下的第二个元素
    // TODO：需求二衍生出需求三：对于报文要实现精确地解析（WYL）
    processor.replace_partial(&mut input, "field3", 1, "0xFF")?;

    // 打印修改后的结果
    println!("Modified JSON:");
    println!("{}", serde_json::to_string_pretty(&input).unwrap());
    Ok(())
}

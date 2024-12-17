use indexmap::IndexMap;
use serde::{Deserialize, Serialize};
use serde_json::{json, Value};

#[derive(Debug, Serialize, Deserialize)]
struct JsonData {
    data: IndexMap<String, Value>,
}

impl JsonData {
    fn convert_to_index_map(value: Value) -> Value {
        match value {
            Value::Object(map) => {
                let mut index_map = IndexMap::new();
                for (k, v) in map {
                    index_map.insert(k, Self::convert_to_index_map(v));
                }
                Value::Object(serde_json::Map::from_iter(index_map))
            }
            Value::Array(arr) => {
                Value::Array(arr.into_iter().map(Self::convert_to_index_map).collect())
            }
            v => v,
        }
    }

    fn from_json(json_value: Value) -> Result<Self, Box<dyn std::error::Error>> {
        let converted = Self::convert_to_index_map(json_value);
        let obj = converted.as_object().ok_or("Root must be an object")?;
        let data: IndexMap<String, Value> =
            IndexMap::from_iter(obj.into_iter().map(|(k, v)| (k.clone(), v.clone())));
        Ok(Self { data })
    }

    fn print(&self) {
        let json_str = serde_json::to_string_pretty(&self.data).unwrap();
        println!("{}", json_str);
    }

    // fn get(&self, key: &str) -> Option<&Value> {
    //     self.data.get(key)
    // }

    // 新增：判断两个路径是否在同一层级且有相同的父节点
    fn are_siblings(&self, path1: &str, path2: &str) -> bool {
        let parts1: Vec<&str> = path1.split('.').collect();
        let parts2: Vec<&str> = path2.split('.').collect();

        // 检查路径长度是否相同
        if parts1.len() != parts2.len() {
            return false;
        }

        // 如果是顶层字段
        if parts1.len() == 1 {
            return true;
        }

        // 比较除了最后一个部分之外的所有父路径部分
        let parent1 = &parts1[..parts1.len() - 1];
        let parent2 = &parts2[..parts2.len() - 1];
        parent1 == parent2
    }

    // 扩展 swap_fields，支持路径访问
    fn swap_fields(&mut self, path1: &str, path2: &str) -> Result<(), Box<dyn std::error::Error>> {
        let parts1: Vec<&str> = path1.split('.').collect();
        let parts2: Vec<&str> = path2.split('.').collect();

        // 如果是顶层字段，直接交换
        if parts1.len() == 1 && parts2.len() == 1 {
            let idx1 = self
                .data
                .get_index_of(parts1[0])
                .ok_or_else(|| format!("Key not found: {}", parts1[0]))?;
            let idx2 = self
                .data
                .get_index_of(parts2[0])
                .ok_or_else(|| format!("Key not found: {}", parts2[0]))?;
            self.data.swap_indices(idx1, idx2);
            return Ok(());
        }

        Ok(())
    }

    // 新增：将十六进制字符串转换为字节
    fn hex_str_to_byte(hex_str: &str) -> Result<u8, Box<dyn std::error::Error>> {
        let hex_str = hex_str.trim_start_matches("0x");
        u8::from_str_radix(hex_str, 16).map_err(|e| format!("Invalid hex string: {}", e).into())
    }

    // 新增：处理单个 Value 节点，将其转换为字节流
    fn process_value(value: &Value) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
        match value {
            Value::String(s) => {
                // 处理单个十六进制字符串
                Ok(vec![Self::hex_str_to_byte(s)?])
            }
            Value::Array(arr) => {
                // 处理数组中的所有十六进制字符串
                let mut bytes = Vec::new();
                for item in arr {
                    if let Value::String(s) = item {
                        bytes.push(Self::hex_str_to_byte(s)?);
                    } else {
                        return Err("Array contains non-string value".into());
                    }
                }
                Ok(bytes)
            }
            Value::Object(obj) => {
                // 递归处理对象
                let mut bytes = Vec::new();
                for (_, value) in obj {
                    bytes.extend(Self::process_value(value)?);
                }
                Ok(bytes)
            }
            _ => Err("Unsupported value type".into()),
        }
    }

    // 新增：深度优先遍历生成字节流
    fn to_byte_stream(&self) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
        let mut byte_stream = Vec::new();

        // 按照 IndexMap 的顺序遍历所有字段
        for (_, value) in &self.data {
            byte_stream.extend(Self::process_value(value)?);
        }

        Ok(byte_stream)
    }

    // 新增：打印字节流的十六进制表示
    fn print_byte_stream(&self) -> Result<(), Box<dyn std::error::Error>> {
        let bytes = self.to_byte_stream()?;
        print!("Byte stream: ");
        for byte in bytes {
            print!("{:02X} ", byte);
        }
        println!();
        Ok(())
    }

    // 新增：判断路径是否存在
    fn path_exists(&self, path: &str) -> bool {
        let parts: Vec<&str> = path.split('.').collect();
        let mut current = match self.data.get(parts[0]) {
            Some(value) => value,
            None => return false,
        };

        for &part in parts.iter().skip(1) {
            match current.as_object() {
                Some(obj) => match obj.get(part) {
                    Some(value) => current = value,
                    None => return false,
                },
                None => return false,
            }
        }
        true
    }

    // 新增：获取路径对应的值数组
    fn get_value_array(&self, path: &str) -> Option<Vec<String>> {
        if !self.path_exists(path) {
            return None;
        }

        let parts: Vec<&str> = path.split('.').collect();
        let mut current = self.data.get(parts[0])?;

        for &part in parts.iter().skip(1) {
            current = current.as_object()?.get(part)?;
        }

        // 处理直接是数组的情况
        if let Value::Array(arr) = current {
            return Some(
                arr.iter()
                    .filter_map(|v| v.as_str())
                    .map(String::from)
                    .collect(),
            );
        }

        None
    }
}
// 需求一：构建原子操作：add,  drop, update
// 原子操作的定义：一个操作要么全部执行成功，要么全部失败，不会出现部分执行成功的情况
// 原子操作的最小对象是字段，即对一个字段的操作是原子的

// 三个原子操作都选择解析后的报文作为参数之一，用于后续的解析，变异操作
// 输入的报文是JSON文本格式，需要解析成内存中的数据结构，方便后续的操作，当前考虑存储为indexMap
// 1. 首先解析json文本为内存中的INDEXMAP数据结构
// 2. 对INDEXMAP数据结构进行顺序遍历，确保可以还原成连续的十六机制字节流
// 3. 对INDEXMAP数据结构执行查询操作，确保可以根据路径访问到对应的值
// 4. 对INDEXMAP数据结构进行比较操作，确保可以判断两个路径是否在同一层级且有相同的父节点
fn main() -> Result<(), Box<dyn std::error::Error>> {
    let data_new = json!({
        "field1": ["0x12", "0x34"],
        "field2": {
            "field2_sub1": ["0x56", "0x78"],
            "field2_sub2": ["0x9A", "0xBC"]
        },
        "field3": ["0xDE", "0xF0", "0x43", "0x21"],
        "field4": {
            "field4_sub1": ["0x22", "0x23"],
            "field4_sub2": ["0x24", "0x25"]
        }
    });

    let mut json_data = JsonData::from_json(data_new)?;

    // output original code
    println!("Original data:");
    json_data.print();

    // output coverted byte stream
    println!("\nConverted to byte stream:");
    json_data.print_byte_stream()?;

    // // 交换顶层字段
    // println!("\nAfter swapping field1 and field3:");
    // json_data.swap_fields("field1", "field3")?;
    // json_data.print();

    // // 测试 are_siblings 函数
    // println!("\nTesting are_siblings:");
    // println!(
    //     "field1 and field2 are siblings: {}",
    //     json_data.are_siblings("field1", "field2")
    // );
    // println!(
    //     "field2.field2_sub1 and field2.field2_sub2 are siblings: {}",
    //     json_data.are_siblings("field2.field2_sub1", "field2.field2_sub2")
    // );
    // println!(
    //     "field2.field2_sub1 and field4.field4_sub1 are siblings: {}",
    //     json_data.are_siblings("field2.field2_sub1", "field4.field4_sub1")
    // );

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use serde_json::json;

    // 辅助函数：创建测试用的 JSON 数据
    fn create_test_data() -> JsonData {
        let data = json!({
            "field1": ["0x12", "0x34"],
            "field2": {
                "field2_sub1": ["0x56", "0x78"],
                "field2_sub2": ["0x9A", "0xBC"]
            },
            "field3": ["0xDE", "0xF0", "0x43", "0x21"],
            "field4": {
                "field4_sub1": ["0x22", "0x23"],
                "field4_sub2": ["0x24", "0x25"]
            }
        });
        JsonData::from_json(data).unwrap()
    }

    #[test]
    fn test_path_exists() {
        let json_data = create_test_data();

        // 测试存在的路径
        assert!(json_data.path_exists("field2.field2_sub1"));
        assert!(json_data.path_exists("field3"));
        assert!(json_data.path_exists("field2.field2_sub2"));
        assert!(json_data.path_exists("field4.field4_sub1"));

        // 测试不存在的路径
        assert!(!json_data.path_exists("nonexistent"));
        assert!(!json_data.path_exists("field2.nonexistent"));
        assert!(!json_data.path_exists("field1.subfield")); // field1 是数组，不是对象
        assert!(!json_data.path_exists("field2.field2_sub1.nonexistent"));
    }

    #[test]
    fn test_get_value_array() {
        let json_data = create_test_data();

        // 测试获取叶子节点数组
        assert_eq!(
            json_data.get_value_array("field2.field2_sub1"),
            Some(vec!["0x56".to_string(), "0x78".to_string()])
        );

        // 测试获取顶层数组
        assert_eq!(
            json_data.get_value_array("field3"),
            Some(vec![
                "0xDE".to_string(),
                "0xF0".to_string(),
                "0x43".to_string(),
                "0x21".to_string()
            ])
        );

        // 测试不存在的路径
        assert_eq!(json_data.get_value_array("nonexistent"), None);
        assert_eq!(json_data.get_value_array("field2.nonexistent"), None);

        // 测试非数组节点
        assert_eq!(json_data.get_value_array("field2"), None);
    }

    #[test]
    fn test_path_exists_and_get_value_combined() {
        let json_data = create_test_data();

        // 组合测试：先检查路径存在性，然后获取值
        let test_paths = vec![
            "field2.field2_sub1",
            "field3",
            "nonexistent",
            "field2.nonexistent",
        ];

        for path in test_paths {
            if json_data.path_exists(path) {
                // 路径存在时应该能获取到值数组
                assert!(json_data.get_value_array(path).is_some());
            } else {
                // 路径不存在时应该获取不到值数组
                assert!(json_data.get_value_array(path).is_none());
            }
        }
    }

    #[test]
    fn test_path_exists_edge_cases() {
        let json_data = create_test_data();

        // 测试空路径
        assert!(!json_data.path_exists(""));

        // 测试只有点的路径
        assert!(!json_data.path_exists("."));
        assert!(!json_data.path_exists(".."));

        // 测试以点开始或结束的路径
        assert!(!json_data.path_exists(".field1"));
        assert!(!json_data.path_exists("field1."));
    }

    #[test]
    fn test_byte_stream_conversion() {
        let json_data = create_test_data();
        let byte_stream = json_data.to_byte_stream().unwrap();

        // 验证字节流的正确性
        // field1: [0x12, 0x34]
        // field2: [0x56, 0x78, 0x9A, 0xBC]
        // field3: [0xDE, 0xF0, 0x43, 0x21]
        // field4: [0x22, 0x23, 0x24, 0x25]
        let expected = vec![
            0x12, 0x34, // field1
            0x56, 0x78, 0x9A, 0xBC, // field2 (field2_sub1, field2_sub2)
            0xDE, 0xF0, 0x43, 0x21, // field3
            0x22, 0x23, 0x24, 0x25, // field4 (field4_sub1, field4_sub2)
        ];

        assert_eq!(byte_stream, expected);
    }

    #[test]
    fn test_field_swapping() {
        let mut json_data = create_test_data();

        // 测试顶层字段交换
        json_data.swap_fields("field1", "field3").unwrap();

        // 验证交换后的顺序
        let keys: Vec<_> = json_data.data.keys().collect();
        assert_eq!(keys[0], "field3"); // 原来的 field1 位置
        assert_eq!(keys[2], "field1"); // 原来的 field3 位置

        // 验证数据内容不变
        assert_eq!(json_data.get("field1").unwrap(), &json!(["0x12", "0x34"]));
        assert_eq!(
            json_data.get("field3").unwrap(),
            &json!(["0xDE", "0xF0", "0x43", "0x21"])
        );
    }

    #[test]
    fn test_sibling_relationships() {
        let json_data = create_test_data();

        // 测试顶层字段
        assert!(json_data.are_siblings("field1", "field2"));
        assert!(json_data.are_siblings("field1", "field3"));
        assert!(json_data.are_siblings("field1", "field4"));

        // 测试嵌套字段
        assert!(json_data.are_siblings("field2.field2_sub1", "field2.field2_sub2"));
        assert!(json_data.are_siblings("field4.field4_sub1", "field4.field4_sub2"));

        // 测试不是兄弟节点的情况
        assert!(!json_data.are_siblings("field2.field2_sub1", "field4.field4_sub1"));
        assert!(!json_data.are_siblings("field1", "field2.field2_sub1"));
    }

    #[test]
    fn test_hex_string_conversion() {
        let json_data = create_test_data();

        // 测试单个十六进制字符串转换
        assert_eq!(JsonData::hex_str_to_byte("0x12").unwrap(), 0x12);
        assert_eq!(JsonData::hex_str_to_byte("0xFF").unwrap(), 0xFF);

        // 测试无效的十六进制字符串
        assert!(JsonData::hex_str_to_byte("0xGG").is_err());
        assert!(JsonData::hex_str_to_byte("invalid").is_err());
    }

    #[test]
    fn test_nested_field_access() {
        let json_data = create_test_data();

        // 测试嵌套字段访问
        let field2 = json_data.get("field2").unwrap();
        let field2_obj = field2.as_object().unwrap();
        assert!(field2_obj.contains_key("field2_sub1"));
        assert!(field2_obj.contains_key("field2_sub2"));

        assert_eq!(
            field2_obj.get("field2_sub1").unwrap(),
            &json!(["0x56", "0x78"])
        );
    }
}

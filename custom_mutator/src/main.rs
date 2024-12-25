use indexmap::IndexMap;
use log::{error, info, trace, warn, LevelFilter};
use log4rs::{
    append::console::{ConsoleAppender, Target},
    // append::file::FileAppender,
    config::{Appender, Config, Root},
    encode::pattern::PatternEncoder,
    filter::threshold::ThresholdFilter,
};
use serde::{Deserialize, Serialize};
use serde_json::{json, Value};
use std::fs::{self};
use std::path::Path;
#[derive(Debug, Serialize, Deserialize)]
struct JsonData {
    data: IndexMap<String, Value>,
}

impl JsonData {
    // 删除键值对
    fn json_data_remove_pair(&mut self, keys: &[&str]) -> Result<(), Box<dyn std::error::Error>> {
        if keys.is_empty() {
            return Err("Empty key sequence".into());
        }

        // 如果只有一个key，直接从顶层删除
        if keys.len() == 1 {
            // 检查要删除的键是否存在
            if self.data.contains_key(keys[0]) {
                // 获取要删除的值，检查是否包含嵌套结构
                let value = self
                    .data
                    .shift_remove(keys[0])
                    .ok_or_else(|| format!("Key not found: {}", keys[0]))?;

                // 如果是对象类型，打印删除的嵌套结构信息
                if let Value::Object(map) = &value {
                    info!(
                        "Removing nested structure under {}: {:?}",
                        keys[0],
                        map.keys().collect::<Vec<_>>()
                    );
                }
                Ok(())
            } else {
                Err(format!("Key not found: {}", keys[0]).into())
            }
        } else {
            // 获取父节点的可变引用和目标键
            let parent_keys = &keys[..keys.len() - 1];
            let target_key = keys[keys.len() - 1];

            let parent = self.json_data_get_value_mut(parent_keys)?;

            if let Value::Object(map) = parent {
                // 检查要删除的键是否存在
                if map.contains_key(target_key) {
                    // 获取要删除的值，检查是否包含嵌套结构
                    if let Some(value) = map.get(target_key) {
                        // 如果是对象类型，打印删除的嵌套结构信息
                        if let Value::Object(nested_map) = value {
                            info!(
                                "Removing nested structure under {}: {:?}",
                                target_key,
                                nested_map.keys().collect::<Vec<_>>()
                            );
                        }
                    }
                    map.remove(target_key);
                    Ok(())
                } else {
                    Err(format!("Key not found: {}", target_key).into())
                }
            } else {
                Err("Parent is not an object".into())
            }
        }
    }
    // 在数组头部添加元素
    fn json_data_value_head_add(
        &mut self,
        keys: &[&str],
        new_values: &[&str],
    ) -> Result<(), Box<dyn std::error::Error>> {
        if new_values.is_empty() {
            return Ok(());
        }

        // 验证所有输入的十六进制值格式
        Self::validate_hex_values(new_values)?;

        // 获取数组的可变引用
        let value = self.json_data_get_value_mut(keys)?;

        if let Value::Array(arr) = value {
            // 反向遍历以保持原始顺序
            for &hex_value in new_values.iter().rev() {
                arr.insert(0, Value::String(hex_value.to_string()));
            }
            Ok(())
        } else {
            Err("Target is not an array".into())
        }
    }
    // 在数组尾部添加元素
    fn json_data_value_tail_add(
        &mut self,
        keys: &[&str],
        new_values: &[&str],
    ) -> Result<(), Box<dyn std::error::Error>> {
        if new_values.is_empty() {
            return Ok(());
        }

        // 验证所有输入的十六进制值格式
        Self::validate_hex_values(new_values)?;

        // 获取数组的可变引用
        let value = self.json_data_get_value_mut(keys)?;

        if let Value::Array(arr) = value {
            // 直接在尾部添加新值
            for &hex_value in new_values {
                arr.push(Value::String(hex_value.to_string()));
            }
            Ok(())
        } else {
            Err("Target is not an array".into())
        }
    }
    // 更新键值对
    fn json_data_value_update(
        &mut self,
        keys: &[&str],
        new_values: &[&str],
    ) -> Result<(), Box<dyn std::error::Error>> {
        if new_values.is_empty() {
            return Err("Cannot update with empty array".into());
        }

        // 验证所有输入的十六进制值格式
        Self::validate_hex_values(new_values)?;

        // 获取数组的可变引用
        let value = self.json_data_get_value_mut(keys)?;

        if let Value::Array(arr) = value {
            // 清空原有数组
            arr.clear();
            // 添加新的值
            for &hex_value in new_values {
                arr.push(Value::String(hex_value.to_string()));
            }
            Ok(())
        } else {
            Err("Target is not an array".into())
        }
    }
    // 将json数据转换为indexmap,便于后续处理
    fn json_data_trans_to_indexmap(json_value: Value) -> Result<Self, Box<dyn std::error::Error>> {
        // 内部函数处理递归转换
        fn convert_inner(value: Value) -> Value {
            match value {
                Value::Object(map) => {
                    let mut index_map = IndexMap::new();
                    for (k, v) in map {
                        index_map.insert(k, convert_inner(v));
                    }
                    Value::Object(serde_json::Map::from_iter(index_map))
                }
                Value::Array(arr) => Value::Array(arr.into_iter().map(convert_inner).collect()),
                v => v,
            }
        }

        let converted = convert_inner(json_value);
        let obj = converted.as_object().ok_or("Root must be an object")?;
        let mut data = IndexMap::new();
        for (k, v) in obj {
            data.insert(k.clone(), v.clone());
        }
        Ok(Self { data })
    }
    // 按照json格式打印IndexMap
    #[warn(dead_code)]
    fn indexmap_print_in_json_format(&self) {
        let json_str = serde_json::to_string_pretty(&self.data).unwrap();
        // info!("{}", json_str); // 打印到终端有截断，等到后续进行处理
        println!("{}", json_str);
    }
    // 将十六进制字符串转换为字节
    fn hex_str_to_byte(hex_str: &str) -> Result<u8, Box<dyn std::error::Error>> {
        let hex_str: &str = if hex_str.starts_with("0x") {
            hex_str.trim_start_matches("0x")
        } else {
            hex_str
        };
        u8::from_str_radix(hex_str, 16).map_err(|e| format!("Invalid hex string: {}", e).into())
    }
    // 深度遍历indexmap, 打印完整字节流
    fn indexmap_print_byte_stream(&self) -> Result<(), Box<dyn std::error::Error>> {
        // 深度递归处理每个值节点
        fn process_value(value: &Value) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
            let mut bytes = Vec::new();

            match value {
                Value::String(s) => {
                    bytes.push(JsonData::hex_str_to_byte(s)?);
                }
                Value::Array(arr) => {
                    for item in arr {
                        if let Value::String(s) = item {
                            bytes.push(JsonData::hex_str_to_byte(s)?);
                        } else {
                            bytes.extend(process_value(item)?);
                        }
                    }
                }
                Value::Object(obj) => {
                    for (_, sub_value) in obj {
                        bytes.extend(process_value(sub_value)?);
                    }
                }
                _ => return Err("Unsupported value type".into()),
            }

            Ok(bytes)
        }

        let mut byte_stream = Vec::new();
        // 从根节点开始遍历
        for (_, value) in &self.data {
            byte_stream.extend(process_value(value)?);
        }

        // 转换为十六进制字符串并打印
        let hex_string = byte_stream
            .iter()
            .map(|byte| format!("{:02X}", byte))
            .collect::<Vec<String>>()
            .join(" ");

        info!("Byte stream: {}", hex_string);
        Ok(())
    }

    // 判断路径是否存在
    fn json_data_check_path(&self, path: &str) -> bool {
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

    // 辅助方法：验证十六进制数组
    fn validate_hex_values(hex_values: &[&str]) -> Result<(), Box<dyn std::error::Error>> {
        for hex_value in hex_values {
            let hex_str = if hex_value.starts_with("0x") {
                hex_value.trim_start_matches("0x")
            } else {
                hex_value
            };

            u8::from_str_radix(hex_str, 16).map_err(|e| format!("Invalid hex string: {}", e))?;
        }
        Ok(())
    }

    // 按照给定的路径序列查找，返回可变引用或错误
    fn json_data_get_value_mut(
        &mut self,
        keys: &[&str],
    ) -> Result<&mut Value, Box<dyn std::error::Error>> {
        if keys.is_empty() {
            return Err("Empty key sequence".into());
        }

        // 获取第一层的可变引用
        let mut current = self
            .data
            .get_mut(keys[0])
            .ok_or_else(|| format!("Key not found at first level: {}", keys[0]))?;

        // 从第二层开始逐层检查
        for &key in keys.iter().skip(1) {
            current = current
                .as_object_mut()
                .ok_or_else(|| format!("Not an object at key: {}", key))?
                .get_mut(key)
                .ok_or_else(|| format!("Key not found: {}", key))?;
        }

        Ok(current)
    }

    // 按照给定的路径序列查找，返回找到的数组或错误
    fn get_json_data_value(
        &self,
        keys: &[&str],
    ) -> Result<Vec<String>, Box<dyn std::error::Error>> {
        if keys.is_empty() {
            return Err("Empty key sequence".into());
        }

        // 获取第一层的值
        let mut current = self
            .data
            .get(keys[0])
            .ok_or_else(|| format!("Key not found at first level: {}", keys[0]))?;

        // 如果只有一层且是数组，直接返回
        if keys.len() == 1 {
            if let Value::Array(arr) = current {
                return Ok(arr
                    .iter()
                    .filter_map(|v| v.as_str())
                    .map(String::from)
                    .collect());
            }
        }

        // 从第二层开始逐层检查
        for &key in keys.iter().skip(1) {
            current = current
                .as_object()
                .ok_or_else(|| format!("Not an object at key: {}", key))?
                .get(key)
                .ok_or_else(|| format!("Key not found: {}", key))?;
        }

        // 检查最终找到的值是否为数组
        if let Value::Array(arr) = current {
            Ok(arr
                .iter()
                .filter_map(|v| v.as_str())
                .map(String::from)
                .collect())
        } else {
            Err("Final value is not an array".into())
        }
    }
}

fn clear_logs_folder() -> std::io::Result<()> {
    let log_dir = "logs";
    let path = Path::new(log_dir);

    // 检查 logs 文件夹是否存在
    if path.exists() && path.is_dir() {
        // 获取 logs 文件夹中的所有文件
        for entry in fs::read_dir(path)? {
            let entry = entry?;
            if entry.file_type()?.is_file() {
                // 删除文件
                fs::remove_file(entry.path())?;
            }
        }
        info!("All files in 'logs' folder have been deleted.");
    } else {
        info!("'logs' folder does not exist.");
    }

    Ok(())
}

fn init_log() {
    // 清空 logs 文件夹中的所有文件
    if let Err(e) = clear_logs_folder() {
        error!("Error clearing 'logs' folder: {}", e);
        return;
    }

    // default stderr console appender
    let default_console_stderr_appender: ConsoleAppender = ConsoleAppender::builder()
        .encoder(Box::new(PatternEncoder::new(
            "{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n",
        )))
        .target(Target::Stderr)
        .build();

    // 配置日志级别和附加器
    let config_builder = Config::builder().appender(
        Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("console_log", Box::new(default_console_stderr_appender)),
    );

    // 初始化 log4rs 配置
    let final_config_builder = config_builder
        .build(
            Root::builder()
                .appender("console_log")
                .build(LevelFilter::Trace),
        )
        .unwrap();
    log4rs::init_config(final_config_builder).unwrap();
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
    // 初始化日志
    init_log();

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

    let mut json_data = JsonData::json_data_trans_to_indexmap(data_new)?;

    // output original code
    trace!("Original data:");
    json_data.indexmap_print_byte_stream()?;
    // json_data.indexmap_print_in_json_format();

    // 查看field4.field4_sub1是否存在
    trace!(
        "Does field4.field4_sub1 exist: {}",
        json_data.json_data_check_path("field4.field4_sub1")
    );

    trace!(
        "Does field2.field2_sub1 exist: {}",
        json_data.json_data_check_path("field2.field2_sub1")
    );
    trace!(
        "field2.field2_sub1: {:?}",
        json_data.get_json_data_value(&["field2", "field2_sub1"])
    );

    // 成功的情况
    match json_data.get_json_data_value(&["field2", "field2_sub2"]) {
        Ok(array) => trace!("Found array: {:?}", array), // 输出: Found array: ["0x9A", "0xBC"]
        Err(e) => error!("Error: {}", e),
    }

    // 失败的情况
    match json_data.get_json_data_value(&["field2", "field2_sub3"]) {
        Ok(array) => trace!("Found array: {:?}", array),
        Err(e) => warn!("Error: {}", e), // 输出: Error: Key not found: field2_sub3
    }

    // 成功获取并修改数组的情况
    match json_data.json_data_get_value_mut(&["field2", "field2_sub2"]) {
        Ok(value) => {
            if let Value::Array(arr) = value {
                arr[0] = json!("0xFF"); // 修改第一个元素
                arr.push(json!("0xEE")); // 添加新元素
                trace!("Modified array: {:?}", arr);
            }
        }
        Err(e) => warn!("Error: {}", e),
    }

    // 失败的情况
    match json_data.json_data_get_value_mut(&["field2", "field2_sub3"]) {
        Ok(_) => trace!("Found value"),
        Err(e) => warn!("Error: {}", e), // 输出: Error: Key not found: field2_sub3
    }
    info!("Testing add data in json data key value pair at head or tail position:");
    // 在数组头部添加元素
    match json_data.json_data_value_head_add(&["field2", "field2_sub1"], &["0xAA", "0xBB"]) {
        Ok(_) => trace!("Successfully added elements to head"),
        Err(e) => warn!("Error: {}", e),
    }

    // 在数组尾部添加元素
    match json_data.json_data_value_tail_add(&["field1"], &["0xCC", "0xDD"]) {
        Ok(_) => trace!("Successfully added elements to tail"),
        Err(e) => warn!("Error: {}", e),
    }
    info!("Testing update whole data in json data key value pair:");
    // 更新整个数组
    match json_data.json_data_value_update(&["field3"], &["0xEE", "0xFF"]) {
        Ok(_) => trace!("Successfully updated array"),
        Err(e) => warn!("Error: {}", e),
    }

    info!("Testing remove json data key value pair:");
    // 删除顶层键值对
    match json_data.json_data_remove_pair(&["field1"]) {
        Ok(_) => trace!("Successfully removed field1"),
        Err(e) => warn!("Error: {}", e),
    }
    // json_data.indexmap_print_in_json_format();
    // 删除嵌套键值对
    match json_data.json_data_remove_pair(&["field2", "field2_sub1"]) {
        Ok(_) => trace!("Successfully removed field2.field2_sub1"),
        Err(e) => warn!("Error: {}", e),
    }
    // json_data.indexmap_print_in_json_format();
    // 尝试删除不存在的键值对
    match json_data.json_data_remove_pair(&["nonexistent"]) {
        Ok(_) => trace!("Successfully removed key"),
        Err(e) => warn!("Error: {}", e), // 输出: Error: Key not found: nonexistent
    }
    // 删除包含嵌套结构的 field2
    match json_data.json_data_remove_pair(&["field2"]) {
        Ok(_) => {
            trace!("Successfully removed field2 and all its nested structures");
            // 验证所有嵌套结构都被删除
            assert!(json_data.get_json_data_value(&["field2"]).is_err());
            assert!(json_data
                .get_json_data_value(&["field2", "field2_sub1"])
                .is_err());
            assert!(json_data
                .get_json_data_value(&["field2", "field2_sub2"])
                .is_err());
        }
        Err(e) => println!("Error: {}", e),
    }

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
        JsonData::json_data_trans_to_indexmap(data).unwrap()
    }

    #[test]
    fn test_json_data_remove_enhanced() {
        let mut json_data = create_test_data();

        // 测试删除包含嵌套结构的顶层键值对
        {
            // 删除 field2 (包含 field2_sub1 和 field2_sub2)
            let result = json_data.json_data_remove_pair(&["field2"]);
            assert!(result.is_ok());

            // 验证删除成功
            assert!(json_data.get_json_data_value(&["field2"]).is_err());
            assert!(json_data
                .get_json_data_value(&["field2", "field2_sub1"])
                .is_err());
            assert!(json_data
                .get_json_data_value(&["field2", "field2_sub2"])
                .is_err());
        }

        // 创建一个更复杂的嵌套结构进行测试
        let complex_data = json!({
            "root": {
                "level1": {
                    "level2": {
                        "array": ["0x11", "0x22"],
                        "value": "0x33"
                    },
                    "sibling": ["0x44", "0x55"]
                },
                "other": ["0x66", "0x77"]
            }
        });

        let mut json_data = JsonData::json_data_trans_to_indexmap(complex_data).unwrap();

        // 测试删除多层嵌套结构
        {
            // 删除 level1 (包含所有嵌套结构)
            let result = json_data.json_data_remove_pair(&["root", "level1"]);
            assert!(result.is_ok());

            // 验证删除成功
            assert!(json_data.get_json_data_value(&["root", "level1"]).is_err());
            assert!(json_data
                .get_json_data_value(&["root", "level1", "level2"])
                .is_err());
            assert!(json_data
                .get_json_data_value(&["root", "level1", "level2", "array"])
                .is_err());

            // 验证同级其他键值对仍然存在
            assert!(json_data.get_json_data_value(&["root", "other"]).is_ok());
        }

        // 测试删除空对象
        let empty_data = json!({
            "empty": {}
        });
        let mut json_data = JsonData::json_data_trans_to_indexmap(empty_data).unwrap();

        {
            let result = json_data.json_data_remove_pair(&["empty"]);
            assert!(result.is_ok());
            assert!(json_data.get_json_data_value(&["empty"]).is_err());
        }
    }
    #[test]
    fn test_json_data_remove() {
        let mut json_data = create_test_data();

        // 测试删除顶层键值对
        {
            // 删除 field1
            let result = json_data.json_data_remove_pair(&["field1"]);
            assert!(result.is_ok());

            // 验证删除成功
            assert!(json_data.get_json_data_value(&["field1"]).is_err());
        }

        // 测试删除嵌套键值对
        {
            // 删除 field2.field2_sub1
            let result = json_data.json_data_remove_pair(&["field2", "field2_sub1"]);
            assert!(result.is_ok());

            // 验证删除成功
            assert!(json_data
                .get_json_data_value(&["field2", "field2_sub1"])
                .is_err());
            // 验证 field2.field2_sub2 仍然存在
            assert!(json_data
                .get_json_data_value(&["field2", "field2_sub2"])
                .is_ok());
        }

        // 测试删除不存在的键值对
        {
            // 尝试删除不存在的顶层键
            let result = json_data.json_data_remove_pair(&["nonexistent"]);
            assert!(result.is_err());
            assert_eq!(
                result.unwrap_err().to_string(),
                "Key not found: nonexistent"
            );

            // 尝试删除不存在的嵌套键
            let result = json_data.json_data_remove_pair(&["field2", "nonexistent"]);
            assert!(result.is_err());
            assert_eq!(
                result.unwrap_err().to_string(),
                "Key not found: nonexistent"
            );
        }

        // 测试删除无效路径
        {
            // 尝试在数组中删除键（无效操作）
            let result = json_data.json_data_remove_pair(&["field3", "invalid"]);
            assert!(result.is_err());
            assert_eq!(result.unwrap_err().to_string(), "Parent is not an object");
        }

        // 测试空路径
        {
            let result = json_data.json_data_remove_pair(&[]);
            assert!(result.is_err());
            assert_eq!(result.unwrap_err().to_string(), "Empty key sequence");
        }
    }
    #[test]
    fn test_json_data_operations() {
        let mut json_data = create_test_data();

        // 测试头部添加
        {
            let result =
                json_data.json_data_value_head_add(&["field2", "field2_sub1"], &["0xAA", "0xBB"]);
            assert!(result.is_ok());

            let array = json_data
                .get_json_data_value(&["field2", "field2_sub1"])
                .unwrap();
            assert_eq!(array, vec!["0xAA", "0xBB", "0x56", "0x78"]);
        }

        // 测试尾部添加
        {
            let result =
                json_data.json_data_value_tail_add(&["field2", "field2_sub2"], &["0xCC", "0xDD"]);
            assert!(result.is_ok());

            let array = json_data
                .get_json_data_value(&["field2", "field2_sub2"])
                .unwrap();
            assert_eq!(array, vec!["0x9A", "0xBC", "0xCC", "0xDD"]);
        }

        // 测试更新整个数组
        {
            let result = json_data.json_data_value_update(&["field1"], &["0xEE", "0xFF"]);
            assert!(result.is_ok());

            let array = json_data.get_json_data_value(&["field1"]).unwrap();
            assert_eq!(array, vec!["0xEE", "0xFF"]);
        }

        // 测试错误情况
        // 1. 路径不存在
        assert!(json_data
            .json_data_value_head_add(&["nonexistent"], &["0x11"])
            .is_err());

        // 2. 非数组目标
        assert!(json_data
            .json_data_value_tail_add(&["field2"], &["0x11"])
            .is_err());

        // 3. 无效的十六进制值
        assert!(json_data
            .json_data_value_update(&["field1"], &["invalid"])
            .is_err());

        // 4. 空数组更新
        assert!(json_data.json_data_value_update(&["field1"], &[]).is_err());
    }
    #[test]
    fn test_get_value_mut() {
        let mut json_data = create_test_data();

        // 测试获取并修改数组
        {
            let value = json_data
                .json_data_get_value_mut(&["field2", "field2_sub2"])
                .unwrap();
            if let Value::Array(arr) = value {
                arr[0] = json!("0xFF"); // 修改第一个元素
            }
        }

        // 验证修改是否成功
        assert_eq!(
            json_data
                .get_json_data_value(&["field2", "field2_sub2"])
                .unwrap(),
            vec!["0xFF", "0xBC"]
        );

        // 测试不存在的路径
        assert!(json_data
            .json_data_get_value_mut(&["field2", "field2_sub3"])
            .is_err());

        // 测试空路径序列
        assert!(json_data.json_data_get_value_mut(&[]).is_err());

        // 测试修改单层路径的数组
        {
            let value = json_data.json_data_get_value_mut(&["field1"]).unwrap();
            if let Value::Array(arr) = value {
                arr.push(json!("0x99")); // 添加新元素
            }
        }

        // 验证修改是否成功
        assert_eq!(
            json_data.get_json_data_value(&["field1"]).unwrap(),
            vec!["0x12", "0x34", "0x99"]
        );
    }
    #[test]
    fn test_check_path_sequence() {
        let json_data = create_test_data();

        // 测试成功的情况
        let result = json_data.get_json_data_value(&["field2", "field2_sub2"]);
        assert!(result.is_ok());
        assert_eq!(result.unwrap(), vec!["0x9A", "0xBC"]);

        // 测试单层路径
        let result = json_data.get_json_data_value(&["field1"]);
        assert!(result.is_ok());
        assert_eq!(result.unwrap(), vec!["0x12", "0x34"]);

        // 测试不存在的路径
        let result = json_data.get_json_data_value(&["field2", "field2_sub3"]);
        assert!(result.is_err());
        assert_eq!(
            result.unwrap_err().to_string(),
            "Key not found: field2_sub3"
        );

        // 测试空路径序列
        let result = json_data.get_json_data_value(&[]);
        assert!(result.is_err());
        assert_eq!(result.unwrap_err().to_string(), "Empty key sequence");

        // 测试路径存在但不是数组的情况
        let result = json_data.get_json_data_value(&["field2"]);
        assert!(result.is_err());
        assert_eq!(
            result.unwrap_err().to_string(),
            "Final value is not an array"
        );
    }
    #[test]
    fn test_path_exists() {
        let json_data = create_test_data();

        // 测试存在的路径
        assert!(json_data.json_data_check_path("field2.field2_sub1"));
        assert!(json_data.json_data_check_path("field3"));
        assert!(json_data.json_data_check_path("field2.field2_sub2"));
        assert!(json_data.json_data_check_path("field4.field4_sub1"));

        // 测试不存在的路径
        assert!(!json_data.json_data_check_path("nonexistent"));
        assert!(!json_data.json_data_check_path("field2.nonexistent"));
        assert!(!json_data.json_data_check_path("field1.subfield")); // field1 是数组，不是对象
        assert!(!json_data.json_data_check_path("field2.field2_sub1.nonexistent"));
    }

    #[test]
    fn test_path_exists_edge_cases() {
        let json_data = create_test_data();

        // 测试空路径
        assert!(!json_data.json_data_check_path(""));

        // 测试只有点的路径
        assert!(!json_data.json_data_check_path("."));
        assert!(!json_data.json_data_check_path(".."));

        // 测试以点开始或结束的路径
        assert!(!json_data.json_data_check_path(".field1"));
        assert!(!json_data.json_data_check_path("field1."));
    }

    #[test]
    fn test_hex_string_conversion() {
        // let json_data: JsonData = create_test_data();

        // 测试单个十六进制字符串转换
        assert_eq!(JsonData::hex_str_to_byte("0x12").unwrap(), 0x12);
        assert_eq!(JsonData::hex_str_to_byte("0xFF").unwrap(), 0xFF);

        // 测试无效的十六进制字符串
        assert!(JsonData::hex_str_to_byte("0xGG").is_err());
        assert!(JsonData::hex_str_to_byte("invalid").is_err());
    }
}

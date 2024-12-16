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

    fn get(&self, key: &str) -> Option<&Value> {
        self.data.get(key)
    }

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
}

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

    println!("Original data:");
    json_data.print();

    // 交换顶层字段
    println!("\nAfter swapping field1 and field3:");
    json_data.swap_fields("field1", "field3")?;
    json_data.print();

    // 测试 are_siblings 函数
    println!("\nTesting are_siblings:");
    println!(
        "field1 and field2 are siblings: {}",
        json_data.are_siblings("field1", "field2")
    );
    println!(
        "field2.field2_sub1 and field2.field2_sub2 are siblings: {}",
        json_data.are_siblings("field2.field2_sub1", "field2.field2_sub2")
    );
    println!(
        "field2.field2_sub1 and field4.field4_sub1 are siblings: {}",
        json_data.are_siblings("field2.field2_sub1", "field4.field4_sub1")
    );

    Ok(())
}

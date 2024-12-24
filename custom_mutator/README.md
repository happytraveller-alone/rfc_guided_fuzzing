## 例子说明
```json
{
    "device_config": {
        "id": ["0x01", "0x02"],
        "sensors": {
            "temperature": {
                "calibration": ["0x03", "0x04"],
                "threshold": ["0x05", "0x06", "0x07"]
            },
            "pressure": {
                "range": ["0x08", "0x09"],
                "offset": ["0x0A", "0x0B"]
            }
        },
        "communication": {
            "protocol": ["0x0C"],
            "address": ["0x0D", "0x0E"]
        }
    }
}
```
## action说明
### ADD
```rust
/// 在嵌套的IndexMap中添加十六进制字段
/// 
/// # 参数
/// * `fields: Vec<String>` - 字段访问路径
///   - 每个元素代表一层嵌套的键名
///   - 示例：vec!["device_config", "sensors", "temperature", "calibration"]
///   - 最后一个元素是要添加的新键名
///   - 中间路径必须都是已存在的Map类型节点
///
/// * `position: Option<usize>` - 插入位置
///   - None: 追加到当前层级的末尾
///     示例：add(vec!["device_config", "sensors", "humidity"], None, ...)
///     结果：humidity被追加到sensors的最后
///   - Some(0): 插入到当前层级的最前面
///     示例：add(vec!["device_config", "communication", "baudrate"], Some(0), ...)
///     结果：baudrate被插入到communication的最前面
///   - Some(n): 插入到当前层级的第n个位置
///     注意：n不能超过当前层级的长度
///
/// * `value: Vec<u8>` - 十六进制值
///   - 支持单字节序列：vec![0x03, 0x04]
///     对应JSON中的 ["0x03", "0x04"]
///   - 支持多字节序列：vec![0x03, 0x04, 0x05]
///     对应JSON中的 ["0x03", "0x04", "0x05"]
///
/// # 返回
/// * `Result<(), Error>` - 操作结果
///   - Ok(()): 添加成功
///   - Err(Error::PathNotFound): 中间路径不存在
///   - Err(Error::NotAMap): 中间节点不是Map类型
///   - Err(Error::InvalidPosition): 插入位置无效
///   - Err(Error::FieldExists): 字段已存在
/// 添加新的传感器配置
add(
    vec!["device_config", "sensors", "humidity", "scale"],
    None,  // 添加到当前层级末尾
    vec![0x1F, 0x2F]
);

/// 在特定位置添加通信参数
add(
    vec!["device_config", "communication", "baudrate"],
    Some(0),  // 添加到通信参数的最前面
    vec![0x11, 0x22]
);
```

### REMOVE
```rust
/// 从嵌套的IndexMap中移除十六进制字段
/// 
/// # 参数
/// * `fields: Vec<String>` - 字段访问路径
///   - 每个元素代表一层嵌套的键名
///   - 示例：vec!["device_config", "sensors", "temperature"]
///   - 可以移除中间节点：将删除整个子树
///     示例：删除 "sensors" 将删除所有传感器配置
///   - 可以移除叶子节点：只删除具体值
///     示例：删除 "calibration" 只删除校准数据
///
/// # 返回
/// * `Result<Vec<u8>, Error>` - 操作结果
///   - Ok(Vec<u8>): 返回被删除的值
///     示例：remove(["device_config", "id"]) 
///     返回 Ok(vec![0x01, 0x02])
///   - Err(Error::PathNotFound): 路径不存在
///   - Err(Error::NotAMap): 中间节点不是Map类型
/// 移除温度传感器的校准数据
remove(
    vec!["device_config", "sensors", "temperature", "calibration"]
);
// 将返回 Ok(vec![0x03, 0x04])

/// 移除整个压力传感器配置
remove(
    vec!["device_config", "sensors", "pressure"]
);
// 将返回包含所有压力传感器配置的数据
```
### UPDATE
```rust
/// 更新嵌套的IndexMap中的十六进制字段值
/// 
/// # 参数
/// * `fields: Vec<String>` - 字段访问路径
///   - 每个元素代表一层嵌套的键名
///   - 示例：vec!["device_config", "sensors", "temperature", "threshold"]
///   - 必须是已存在的完整路径
///   - 只能更新叶子节点的值，不能更新中间节点
///
/// * `value: Vec<u8>` - 新的十六进制值
///   - 示例：vec![0x05, 0x06, 0x07]
///   - 可以与原值长度不同
///   - 完全替换原有值
///
/// # 返回
/// * `Result<(), Error>` - 操作结果
///   - Ok(()): 更新成功
///   - Err(Error::PathNotFound): 路径不存在
///   - Err(Error::NotAMap): 尝试更新中间节点
/// 更新设备ID
update(
    vec!["device_config", "id"],
    vec![0x15, 0x16]
);

/// 更新温度阈值
update(
    vec!["device_config", "sensors", "temperature", "threshold"],
    vec![0x08, 0x09, 0x0A]
);
```

### 函数的异常处理
```rust
// 路径不存在
add(
    vec!["nonexistent", "path"],
    None,
    vec![0x00]
) -> Err(Error::PathNotFound)

// 位置越界
add(
    vec!["device_config", "id"],
    Some(100),
    vec![0x00]
) -> Err(Error::InvalidPosition)

// 尝试更新Map节点
update(
    vec!["device_config", "sensors"],
    vec![0x00]
) -> Err(Error::NotAMap)
```
### 复杂action
dumplicate
1. add的一个子集，只不过add的内容是已有的一部分
----------          ----------
field1              field2
...           ===>  ...
field2              field1
----------          ----------
swap
1. add field1，
----------
field1
...
field1_bp
field2
----------
2. delete field1
----------

...
field1_bp
field2
----------
3. add field2
----------
field2_bp
...
field1_bp
field2
----------
4. delete field2
----------
field2_bp
...
field1_bp
----------

### action 接口的定义
1. ADD(field, position, value)
2. REMOVE(field)
3. UPDATE(field, value)
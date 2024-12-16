### 例子说明
```json
{
    "field1": ["0x12", "0x34"],
    "field2": {
        "sub1": ["0x56", "0x78"],
        "sub2": ["0x9A", "0xBC"]
    },
    "field3": ["0xDE", "0xF0", "0x43", "0x21"]
}
```

- SYB：
    + 测试策略需要精确到字段名称已经名称位置,例如，想修改sub2的内容，需要指定sub2的位置，field2.sub2
    + 测试策略需要给出修改后的字段值，例如，修改field第二个字节为0x56,描述为需要field1为0x12,0x56

- WYL：
    + 解析内容格式见以上json实例，每个字段内部都是十六进制字符串构成的数组
    + 解析需要精确，例如，解析不能停止于field2，而应该继续解析，直到被解析内容为最小部分


- 当前协议：
    + TLS1.3协议的ClientHello报文，
    + HTTP协议（待添加）
    + HTTPS协议（待添加）

### action测试
add()
1. 字段与字段之间插入，
2. 字段内部插入
delete()
1. 删除整个字段
2. 删除字段内部的某段连续内容
update()
1. 更新整个字段（适用于短字段）
2. 更新字段内的某段连续内容



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
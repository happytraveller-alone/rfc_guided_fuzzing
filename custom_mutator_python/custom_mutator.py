from typing import Dict, List, Any, Optional, Union
from collections import OrderedDict
import json
import logging
from pathlib import Path
import os
import unittest
import logging
from enum import Enum

class AddType(Enum):
    """添加类型枚举"""
    OBJECT = "object"  # 添加一个空对象，用于后续添加子键值对
    PAIR = "pair"      # 添加具体的键值对


class JsonData:
    def __init__(self, data: OrderedDict):
        self.data = data

    @classmethod
    def json_data_trans_to_ordered_dict(cls, json_value: Union[str, dict]) -> 'JsonData':
        """将JSON数据转换为OrderedDict结构"""
        def convert_inner(value: Any) -> Any:
            if isinstance(value, dict):
                return OrderedDict((k, convert_inner(v)) for k, v in value.items())
            elif isinstance(value, list):
                return [convert_inner(item) for item in value]
            return value

        if isinstance(json_value, str):
            data = json.loads(json_value)
        else:
            data = json_value

        if not isinstance(data, dict):
            raise ValueError("Root must be an object")

        converted_data = convert_inner(data)
        return cls(OrderedDict(converted_data))

    def json_data_remove_pair(self, keys: List[str]) -> None:
        """删除指定路径的键值对"""
        if not keys:
            raise ValueError("Empty key sequence")

        if len(keys) == 1:
            # 直接从顶层删除
            if keys[0] in self.data:
                # 获取要删除的值，检查是否包含嵌套结构
                value = self.data.pop(keys[0])
                if isinstance(value, dict):
                    logging.info(f"Removing nested structure under {keys[0]}: {list(value.keys())}")
            else:
                raise KeyError(f"Key not found: {keys[0]}")
        else:
            # 获取父节点的引用
            parent = self.json_data_get_value_mut(keys[:-1])
            target_key = keys[-1]

            if isinstance(parent, dict):
                if target_key in parent:
                    value = parent[target_key]
                    if isinstance(value, dict):
                        logging.info(f"Removing nested structure under {target_key}: {list(value.keys())}")
                    del parent[target_key]
                else:
                    raise KeyError(f"Key not found: {target_key}")
            else:
                raise ValueError("Parent is not an object")

    @staticmethod
    def hex_str_to_byte(hex_str: str) -> int:
        """将十六进制字符串转换为整数"""
        hex_str = hex_str.replace('0x', '').strip()
        try:
            return int(hex_str, 16)
        except ValueError:
            raise ValueError(f"Invalid hex string: {hex_str}")

    @staticmethod
    def validate_hex_values(hex_values: List[str]) -> None:
        """验证十六进制值列表"""
        for hex_value in hex_values:
            JsonData.hex_str_to_byte(hex_value)

    def json_data_get_value_mut(self, keys: List[str]) -> Any:
        """获取指定路径的可变引用"""
        if not keys:
            raise ValueError("Empty key sequence")

        current = self.data
        for i, key in enumerate(keys):
            if not isinstance(current, dict):
                raise ValueError(f"Not an object at key: {keys[i-1]}")
            if key not in current:
                raise KeyError(f"Key not found: {key}")
            current = current[key]

        return current

    def get_json_data_value(self, keys: List[str]) -> List[str]:
        """获取指定路径的数组值"""
        if not keys:
            raise ValueError("Empty key sequence")

        value = self.json_data_get_value_mut(keys)
        if not isinstance(value, list):
            raise ValueError("Final value is not an array")

        return [str(item) for item in value]

    def json_data_check_path(self, path: str) -> bool:
        """检查路径是否存在"""
        if not path:
            return False

        keys = path.split('.')
        try:
            current = self.data
            for key in keys:
                if not isinstance(current, dict):
                    return False
                if key not in current:
                    return False
                current = current[key]
            return True
        except Exception:
            return False

    def json_data_value_head_add(self, keys: List[str], new_values: List[str]) -> None:
        """在数组头部添加元素"""
        if not new_values:
            return

        # 验证所有输入的十六进制值格式
        self.validate_hex_values(new_values)

        # 获取数组的引用
        value = self.json_data_get_value_mut(keys)
        
        if not isinstance(value, list):
            raise ValueError("Target is not an array")

        # 反向遍历以保持原始顺序
        for hex_value in reversed(new_values):
            value.insert(0, hex_value)
            logging.debug(f"Added value {hex_value} at the head of array at {keys}")

    def json_data_value_tail_add(self, keys: List[str], new_values: List[str]) -> None:
        """在数组尾部添加元素"""
        if not new_values:
            return

        # 验证所有输入的十六进制值格式
        self.validate_hex_values(new_values)

        # 获取数组的引用
        value = self.json_data_get_value_mut(keys)
        
        if not isinstance(value, list):
            raise ValueError("Target is not an array")

        # 直接在尾部添加新值
        for hex_value in new_values:
            value.append(hex_value)
            logging.debug(f"Added value {hex_value} at the tail of array at {keys}")

    def json_data_value_update(self, keys: List[str], new_values: List[str]) -> None:
        """更新指定路径的数组值"""
        if not new_values:
            raise ValueError("Cannot update with empty array")

        # 验证所有输入的十六进制值格式
        self.validate_hex_values(new_values)

        # 获取数组的引用
        value = self.json_data_get_value_mut(keys)
        
        if not isinstance(value, list):
            raise ValueError("Target is not an array")

        # 记录原始值用于日志
        original_values = value.copy()
        
        # 清空原有数组并添加新的值
        value.clear()
        value.extend(new_values)
        
        logging.info(f"Updated array at {keys} from {original_values} to {new_values}")

    def indexmap_print_byte_stream(self) -> None:
        """打印完整的字节流"""
        def process_value(value: Any) -> List[int]:
            """递归处理值节点，返回字节列表"""
            bytes_list = []

            if isinstance(value, str):
                bytes_list.append(self.hex_str_to_byte(value))
            elif isinstance(value, list):
                for item in value:
                    if isinstance(item, str):
                        bytes_list.append(self.hex_str_to_byte(item))
                    else:
                        bytes_list.extend(process_value(item))
            elif isinstance(value, dict):
                for sub_value in value.values():
                    bytes_list.extend(process_value(sub_value))
            else:
                raise ValueError(f"Unsupported value type: {type(value)}")

            return bytes_list

        try:
            # 收集所有字节
            byte_stream = []
            for value in self.data.values():
                byte_stream.extend(process_value(value))

            # 转换为十六进制字符串并打印
            hex_string = ' '.join(f"{byte:02X}" for byte in byte_stream)
            logging.info(f"Byte stream: {hex_string}")
            
            return hex_string
        except Exception as e:
            logging.error(f"Error in byte stream generation: {str(e)}")
            raise

    def indexmap_print_in_json_format(self) -> None:
        """以JSON格式打印数据"""
        try:
            json_str = json.dumps(self.data, indent=2)
            logging.info("JSON structure:")
            for line in json_str.split('\n'):
                logging.info(line)
        except Exception as e:
            logging.error(f"Error in JSON formatting: {str(e)}")
            raise

    def indexmap_print_in_json_pretty_format(self) -> None:
        """以优化的JSON格式打印数据，数组值在同一行显示"""
        def format_value(obj: Any, level: int = 0) -> List[str]:
            """递归格式化JSON对象，返回格式化的行列表"""
            indent = "  " * level
            lines = []
            
            if isinstance(obj, dict):
                if not obj:  # 空字典
                    lines.append("{}")
                else:
                    lines.append("{")
                    items = list(obj.items())
                    for i, (key, value) in enumerate(items):
                        formatted_value = format_value(value, level + 1)
                        lines.append(f'{indent}  "{key}": {formatted_value[0]}')
                        lines.extend(formatted_value[1:])
                        if i < len(items) - 1:
                            lines[-1] += ","
                    lines.append(indent + "}")
            elif isinstance(obj, list):
                if not obj:  # 空列表
                    lines.append("[]")
                else:
                    # 将列表元素格式化为单行，但保持缩进结构
                    lines.append("[")
                    elements = [f'"{item}"' for item in obj]
                    lines.append(f"{indent}    {', '.join(elements)}")
                    lines.append(f"{indent}  ]")
                return lines
            else:
                lines.append(f'"{obj}"')
            
            return lines
    
        try:
            logging.info("JSON structure:")
            formatted_lines = format_value(self.data)
            for line in formatted_lines:
                logging.info(line)
        except Exception as e:
            logging.error(f"Error in JSON pretty formatting: {str(e)}")
            raise

    def json_data_pair_add(self, path: List[str], new_key: str, new_value: Any = None, add_type: AddType = AddType.PAIR) -> None:
        """在指定路径的字典中添加新的键值对或空对象，支持根路径操作

        Args:
            path (List[str]): 目标字典的路径，空列表表示根路径
            new_key (str): 新的键名
            new_value (Any, optional): 新的值，当add_type为OBJECT时可为None
            add_type (AddType): 添加类型，OBJECT表示添加空对象，PAIR表示添加键值对

        Raises:
            ValueError: 如果路径指向的不是字典，或者键已存在
        """
        try:
            # 处理根路径情况
            if not path:
                target = self.data
            else:
                # 获取目标字典
                target = self.data
                for key in path:
                    target = target[key]

            # 检查目标是否为字典
            if not isinstance(target, dict):
                raise ValueError(f"Target at path {path} is not a dictionary")

            # 检查键是否已存在
            if new_key in target:
                raise ValueError(f"Key '{new_key}' already exists at path {path}")

            # 根据不同类型进行处理
            if add_type == AddType.OBJECT:
                target[new_key] = {}
                path_str = "root" if not path else ".".join(path)
                logging.debug(f"Created new empty object '{new_key}' at {path_str}")
            else:  # AddType.PAIR
                if new_value is None:
                    raise ValueError("Value cannot be None when adding a pair")
                target[new_key] = new_value
                path_str = "root" if not path else ".".join(path)
                logging.debug(f"Added new pair '{new_key}': {new_value} at {path_str}")

        except KeyError as e:
            error_msg = f"Path {path} does not exist"
            logging.error(error_msg)
            raise KeyError(error_msg) from e
        except Exception as e:
            error_msg = f"Error adding new pair: {str(e)}"
            logging.error(error_msg)
            raise
def init_log():
    """初始化日志配置
    
    - 自动创建logs文件夹
    - 配置日志格式
    - 同时输出到控制台和文件
    """
    # 创建logs文件夹
    log_dir = Path("logs")
    log_dir.mkdir(exist_ok=True)
    
    # 创建日志文件路径 - 使用时间戳创建唯一的日志文件名
    from datetime import datetime
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    log_file = log_dir / f"app_{timestamp}.log"
    
    # 配置日志格式
    log_format = '%(asctime)s - %(levelname)s - %(message)s'
    
    # 配置日志处理器
    handlers = [
        # 控制台处理器
        logging.StreamHandler(),
        # 文件处理器
        logging.FileHandler(log_file, encoding='utf-8')
    ]
    
    # 配置日志基本参数
    logging.basicConfig(
        level=logging.INFO,
        format=log_format,
        handlers=handlers
    )
    
    logging.info(f"Log initialized. Log file: {log_file}")

def clear_logs_folder():
    """清空logs文件夹
    
    - 如果文件夹不存在则创建
    - 删除超过3小时的日志文件
    - 保留文件夹结构
    """
    log_dir = Path("logs")
    
    # 如果文件夹不存在则创建
    log_dir.mkdir(exist_ok=True)
    
    # 设置日志文件保留时间为3小时
    from datetime import datetime, timedelta
    retention_minutes = 5
    current_time = datetime.now()
    
    # 删除旧文件
    file_count = 0
    for file in log_dir.iterdir():
        if file.is_file() and file.name.startswith("app_"):
            try:
                # 从文件名中提取时间戳
                file_timestamp = datetime.strptime(file.stem[4:], "%Y%m%d_%H%M%S")
                if current_time - file_timestamp > timedelta(minutes=retention_minutes):
                    file.unlink()
                    file_count += 1
            except (ValueError, OSError) as e:
                logging.warning(f"Could not process file {file}: {e}")
            
    logging.info(f"Cleared {file_count} old log files (older than {retention_minutes} minutes )")

class TestJsonData(unittest.TestCase):
    def setUp(self):
        """测试数据初始化"""
        self.test_data = {
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
        }
        self.json_data = JsonData.json_data_trans_to_ordered_dict(self.test_data)

    def test_json_data_trans_to_ordered_dict(self):
        """测试JSON转换为OrderedDict"""
        # 测试字典转换
        result = JsonData.json_data_trans_to_ordered_dict(self.test_data)
        self.assertIsInstance(result.data, OrderedDict)
        
        # 测试JSON字符串转换
        json_str = json.dumps(self.test_data)
        result = JsonData.json_data_trans_to_ordered_dict(json_str)
        self.assertIsInstance(result.data, OrderedDict)
        
        # 测试无效输入
        with self.assertRaises(ValueError):
            JsonData.json_data_trans_to_ordered_dict([])

    def test_json_data_remove_pair(self):
        """测试删除键值对"""
        # 测试删除顶层键
        self.json_data.json_data_remove_pair(["field1"])
        self.assertNotIn("field1", self.json_data.data)

        # 测试删除嵌套键
        self.json_data.json_data_remove_pair(["field2", "field2_sub1"])
        self.assertNotIn("field2_sub1", self.json_data.data["field2"])

        # 测试删除不存在的键
        with self.assertRaises(KeyError):
            self.json_data.json_data_remove_pair(["nonexistent"])

        # 测试空键序列
        with self.assertRaises(ValueError):
            self.json_data.json_data_remove_pair([])

    def test_hex_str_to_byte(self):
        """测试十六进制字符串转换"""
        # 测试有效的十六进制字符串
        self.assertEqual(JsonData.hex_str_to_byte("0x12"), 0x12)
        self.assertEqual(JsonData.hex_str_to_byte("FF"), 0xFF)
        
        # 测试无效的十六进制字符串
        with self.assertRaises(ValueError):
            JsonData.hex_str_to_byte("GG")

    def test_validate_hex_values(self):
        """测试十六进制值验证"""
        # 测试有效的十六进制值列表
        valid_values = ["0x12", "0xFF", "0xAB"]
        JsonData.validate_hex_values(valid_values)  # 不应抛出异常
        
        # 测试无效的十六进制值列表
        invalid_values = ["0x12", "0xGG", "0xFF"]
        with self.assertRaises(ValueError):
            JsonData.validate_hex_values(invalid_values)

    def test_json_data_check_path(self):
        """测试路径检查"""
        # 测试存在的路径
        self.assertTrue(self.json_data.json_data_check_path("field2.field2_sub1"))
        self.assertTrue(self.json_data.json_data_check_path("field1"))
        
        # 测试不存在的路径
        self.assertFalse(self.json_data.json_data_check_path("nonexistent"))
        self.assertFalse(self.json_data.json_data_check_path("field2.nonexistent"))
        
        # 测试空路径
        self.assertFalse(self.json_data.json_data_check_path(""))

    def test_get_json_data_value(self):
        """测试获取数组值"""
        # 测试获取顶层数组
        result = self.json_data.get_json_data_value(["field1"])
        self.assertEqual(result, ["0x12", "0x34"])
        
        # 测试获取嵌套数组
        result = self.json_data.get_json_data_value(["field2", "field2_sub1"])
        self.assertEqual(result, ["0x56", "0x78"])
        
        # 测试获取不存在的路径
        with self.assertRaises(KeyError):
            self.json_data.get_json_data_value(["nonexistent"])
        
        # 测试非数组值
        with self.assertRaises(ValueError):
            self.json_data.get_json_data_value(["field2"])

    def test_json_data_value_head_add(self):
        """测试数组头部添加元素"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试在顶层数组头部添加
        json_data.json_data_value_head_add(["array1"], ["0xAA", "0xBB"])
        self.assertEqual(
            json_data.get_json_data_value(["array1"]),
            ["0xAA", "0xBB", "0x12", "0x34"]
        )

        # 测试在嵌套数组头部添加
        json_data.json_data_value_head_add(["nested", "array2"], ["0xCC"])
        self.assertEqual(
            json_data.get_json_data_value(["nested", "array2"]),
            ["0xCC", "0x56", "0x78"]
        )

        # 测试添加空列表（不应改变原数组）
        original = json_data.get_json_data_value(["array1"])
        json_data.json_data_value_head_add(["array1"], [])
        self.assertEqual(json_data.get_json_data_value(["array1"]), original)

        # 测试无效的十六进制值
        with self.assertRaises(ValueError):
            json_data.json_data_value_head_add(["array1"], ["0xGG"])

        # 测试非数组目标
        with self.assertRaises(ValueError):
            json_data.json_data_value_head_add(["nested"], ["0x11"])

    def test_json_data_value_tail_add(self):
        """测试数组尾部添加元素"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试在顶层数组尾部添加
        json_data.json_data_value_tail_add(["array1"], ["0xAA", "0xBB"])
        self.assertEqual(
            json_data.get_json_data_value(["array1"]),
            ["0x12", "0x34", "0xAA", "0xBB"]
        )

        # 测试在嵌套数组尾部添加
        json_data.json_data_value_tail_add(["nested", "array2"], ["0xCC"])
        self.assertEqual(
            json_data.get_json_data_value(["nested", "array2"]),
            ["0x56", "0x78", "0xCC"]
        )

        # 测试添加空列表（不应改变原数组）
        original = json_data.get_json_data_value(["array1"])
        json_data.json_data_value_tail_add(["array1"], [])
        self.assertEqual(json_data.get_json_data_value(["array1"]), original)

        # 测试无效的十六进制值
        with self.assertRaises(ValueError):
            json_data.json_data_value_tail_add(["array1"], ["0xGG"])

        # 测试非数组目标
        with self.assertRaises(ValueError):
            json_data.json_data_value_tail_add(["nested"], ["0x11"])

    def test_json_data_value_update(self):
        """测试更新数组值"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试更新顶层数组
        json_data.json_data_value_update(["array1"], ["0xAA", "0xBB"])
        self.assertEqual(
            json_data.get_json_data_value(["array1"]),
            ["0xAA", "0xBB"]
        )

        # 测试更新嵌套数组
        json_data.json_data_value_update(["nested", "array2"], ["0xCC", "0xDD"])
        self.assertEqual(
            json_data.get_json_data_value(["nested", "array2"]),
            ["0xCC", "0xDD"]
        )

        # 测试使用空列表更新
        with self.assertRaises(ValueError):
            json_data.json_data_value_update(["array1"], [])

        # 测试无效的十六进制值
        with self.assertRaises(ValueError):
            json_data.json_data_value_update(["array1"], ["0xGG"])

        # 测试非数组目标
        with self.assertRaises(ValueError):
            json_data.json_data_value_update(["nested"], ["0x11"])

    def test_indexmap_print_byte_stream(self):
        """测试字节流打印"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试字节流生成
        byte_stream = json_data.indexmap_print_byte_stream()
        expected = "12 34 56 78"  # 预期的输出格式
        self.assertEqual(byte_stream, expected)

        # 测试包含无效十六进制值的数据
        invalid_data = {
            "array1": ["0x12", "invalid"]
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(invalid_data)
        with self.assertRaises(ValueError):
            json_data.indexmap_print_byte_stream()

    def test_indexmap_print_in_json_format(self):
        """测试JSON格式打印"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 捕获日志输出
        with self.assertLogs(level='INFO') as log:
            json_data.indexmap_print_in_json_format()
            
        # 验证日志输出包含预期的JSON结构
        self.assertTrue(any("array1" in output for output in log.output))
        self.assertTrue(any("nested" in output for output in log.output))

    def test_indexmap_print_in_json_pretty_format(self):
        """测试优化的JSON格式打印"""
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 捕获日志输出
        with self.assertLogs(level='INFO') as log:
            json_data.indexmap_print_in_json_pretty_format()
            
        # 验证日志输出包含预期的格式
        log_output = '\n'.join(log.output)
        # 验证数组元素在同一行
        self.assertTrue('"0x12", "0x34"' in log_output)
        self.assertTrue('"0x56", "0x78"' in log_output)
        # 验证结构完整性
        self.assertTrue('array1' in log_output)
        self.assertTrue('nested' in log_output)
        self.assertTrue('array2' in log_output)

def run_tests():
    """运行所有单元测试"""
    suite = unittest.TestLoader().loadTestsFromTestCase(TestJsonData)
    unittest.TextTestRunner(verbosity=2).run(suite)

def main():
    """主函数示例"""
    init_log()
    clear_logs_folder()

    test_data = {
        "field1": ["0x12", "0x34"],
        "field2": {
            "field2_sub1": ["0x56", "0x78"],
            "field2_sub2": ["0x9A", "0xBC"]
        },
        "field3": ["0xDE", "0xF0", "0x43", "0x21"],
    }

    try:
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)
        logging.info("Original data structure:")
        json_data.indexmap_print_in_json_pretty_format()
        
        # 测试数组头部添加
        logging.info("Testing array head addition: Adding ['0xAA', '0xBB'] to the head of field1")
        logging.info(f"Before: field1 = {json_data.get_json_data_value(['field1'])}")
        json_data.json_data_value_head_add(["field1"], ["0xAA", "0xBB"])
        logging.info(f"After: field1 = {json_data.get_json_data_value(['field1'])}")

        # 测试数组尾部添加
        logging.info("Testing array tail addition: Adding ['0xCC', '0xDD'] to the tail of field3")
        logging.info(f"Before: field3 = {json_data.get_json_data_value(['field3'])}")
        json_data.json_data_value_tail_add(["field3"], ["0xCC", "0xDD"])
        logging.info(f"After: field3 = {json_data.get_json_data_value(['field3'])}")

        # 测试数组更新
        logging.info("Testing array update: Updating field2.field2_sub1 with ['0xEE', '0xFF']")
        logging.info(f"Before: field2.field2_sub1 = {json_data.get_json_data_value(['field2', 'field2_sub1'])}")
        json_data.json_data_value_update(["field2", "field2_sub1"], ["0xEE", "0xFF"])
        logging.info(f"After: field2.field2_sub1 = {json_data.get_json_data_value(['field2', 'field2_sub1'])}")

        # 测试数组删除
        logging.info("Testing array removal: Removing field2.field2_sub1")
        logging.info(f"Before: field2.field2_sub1 = {json_data.get_json_data_value(['field2', 'field2_sub1'])}")
        json_data.json_data_remove_pair(["field2", "field2_sub1"])
        logging.info("After: field2.field2_sub1 = (Removed)")

        # 测试添加新的对象和键值对
        logging.warning("=== Testing dictionary addition with object and pair ===")
        
        # 1. 首先添加一个空对象
        logging.info("Operation: Adding new object 'field4' to root")
        logging.debug(f"Before: data = {json_data.data}")
        json_data.json_data_pair_add([], "field4", add_type=AddType.OBJECT)
        logging.debug(f"After adding object: data = {json_data.data}")
        
        # 2. 在新对象中添加键值对
        logging.info("Operation: Adding new pair 'field4_sub1': ['0x31', '0x32'] to field4")
        json_data.json_data_pair_add(["field4"], "field4_sub1", ["0x31", "0x32"], AddType.PAIR)
        logging.debug(f"After adding pair: data = {json_data.data}")
        
        # 3. 在field4中再添加一个空对象
        logging.info("Operation: Adding new object 'field4_sub2' to field4")
        json_data.json_data_pair_add(["field4"], "field4_sub2", add_type=AddType.OBJECT)
        logging.debug(f"After adding nested object: data = {json_data.data}")
        
        # 4. 在新的嵌套对象中添加键值对
        logging.info("Operation: Adding new pair 'nested_key': ['0x41', '0x42'] to field4.field4_sub2")
        json_data.json_data_pair_add(
            ["field4", "field4_sub2"], 
            "nested_key", 
            ["0x41", "0x42"], 
            AddType.PAIR
        )
        logging.info(f"Final result: data = {json_data.get_json_data_value(['field4', 'field4_sub2', 'nested_key'])}")

    except Exception as e:
        logging.error(f"Error occurred: {str(e)}")
        raise


if __name__ == "__main__":
    # 运行单元测试
    # run_tests()
    
    # 运行主函数示例
    main()
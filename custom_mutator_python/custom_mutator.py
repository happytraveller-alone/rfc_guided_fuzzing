from typing import Dict, List, Any, Optional, Union
from collections import OrderedDict
import json
import logging
from pathlib import Path
import os
import unittest
import logging
from enum import Enum
import pandas as pd
import shutil

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

class ActionParser:
    """Action文件解析器"""
    
    SUPPORTED_ACTIONS = {
        'add': 'add',
        'remove': 'remove',
        'update': 'update'
    }
    
    def __init__(self, action_dir: str = "actions"):
        self.action_dir = Path(action_dir)
        self.actions: Dict[str, Dict] = {}

    def _validate_action(self, action: Dict) -> bool:
        """验证单个action的格式"""
        # 检查action类型
        if 'action' not in action or action['action'] not in self.SUPPORTED_ACTIONS:
            logging.error(f"Unsupported or missing action type: {action.get('action')}")
            return False

        # 检查fields字段
        if 'fields' not in action or not isinstance(action['fields'], list):
            logging.error("Missing or invalid 'fields' in action")
            return False

        action_type = action['action']
        
        # 检查add操作的value字段
        if action_type == 'add' and 'value' in action:
            if not isinstance(action['value'], list):
                logging.error("value must be an array for add action")
                return False
            if not all(isinstance(x, str) for x in action['value']):
                logging.error("All values in value array must be strings for add action")
                return False

        # 检查update操作的new_value字段
        if action_type == 'update':
            if 'new_value' not in action:
                logging.error("Update action requires 'new_value' field")
                return False
            if not isinstance(action['new_value'], list):
                logging.error("new_value must be an array for update action")
                return False
            if not all(isinstance(x, str) for x in action['new_value']):
                logging.error("All values in new_value array must be strings for update action")
                return False

        return True

    def load_actions(self) -> None:
        """加载所有action文件"""
        if not self.action_dir.exists():
            logging.error(f"Action directory {self.action_dir} does not exist")
            raise FileNotFoundError(f"Directory {self.action_dir} not found")

        for file_path in self.action_dir.glob("action_*.txt"):
            try:
                action_name = file_path.stem
                logging.info(f"Processing action file: {file_path}")
                
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read().strip()
                    try:
                        action_data = json.loads(content)
                    except json.JSONDecodeError as e:
                        logging.error(f"JSON parsing error in {file_path}:")
                        logging.error(f"Error position: line {e.lineno}, column {e.colno}")
                        logging.error(f"Error details: {str(e)}")
                        continue

                    if 'action_sequence' not in action_data:
                        logging.error(f"Missing action_sequence in {file_path}")
                        continue

                    if not all(self._validate_action(action) for action in action_data['action_sequence']):
                        logging.error(f"Invalid action format in {file_path}")
                        continue

                    self.actions[action_name] = action_data
                    logging.info(f"Successfully loaded action file: {file_path}")
                    
            except Exception as e:
                logging.error(f"Unexpected error processing {file_path}: {str(e)}")
                continue

    def _execute_add_action(self, action: Dict, json_data: JsonData) -> None:
        """执行add类型的action
        - 如果没有value字段，则添加对象
        - 如果有value字段，则添加键值对
        """
        if 'value' not in action:
            # 没有value字段，添加对象
            logging.info(f"Adding new object at path: {action['fields']}")
            json_data.json_data_pair_add(
                action['fields'][:-1],
                action['fields'][-1],
                add_type=AddType.OBJECT
            )
        else:
            # 有value字段，添加键值对
            logging.info(f"Adding new value at path: {action['fields']}")
            json_data.json_data_pair_add(
                action['fields'][:-1],
                action['fields'][-1],
                action['value'],  # 使用value字段
                AddType.PAIR
            )

    def _execute_update_action(self, action: Dict, json_data: JsonData) -> None:
        """执行update类型的action"""
        logging.info(f"Updating value at path: {action['fields']}")
        json_data.json_data_value_update(
            action['fields'],
            action['new_value']  # 使用new_value字段
        )

    def _execute_remove_action(self, action: Dict, json_data: JsonData) -> None:
        """执行remove类型的action"""
        logging.info(f"Removing field at path: {action['fields']}")
        json_data.json_data_remove_pair(action['fields'])

    def execute_action(self, action_name: str, json_data: JsonData) -> None:
        """执行指定的action序列"""
        action_config = self.actions.get(action_name)
        if not action_config:
            raise KeyError(f"Action {action_name} not found")
            
        logging.info(f"\nExecuting action sequence from: {action_name}")
        
        for action in action_config['action_sequence']:
            action_type = action['action']
            try:
                if action_type == 'add':
                    self._execute_add_action(action, json_data)
                elif action_type == 'update':
                    self._execute_update_action(action, json_data)
                elif action_type == 'remove':
                    self._execute_remove_action(action, json_data)
                else:
                    logging.warning(f"Skipping unsupported action type: {action_type}")
                    
            except Exception as e:
                logging.error(f"Error executing {action_type} action: {str(e)}")
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

    def test_action_parser(self):
            """测试ActionParser功能"""
            # 创建测试目录和文件
            test_dir = Path("test_actions")
            test_dir.mkdir(exist_ok=True)

            # 创建测试action文件
            test_action = {
                "description": "Test action",
                "action_sequence": [
                    {
                        "action": "add",
                        "fields": ["new_field"],
                        "value": [0x12, 0x34]
                    }
                ]
            }

            with open(test_dir / "action_test.txt", "w") as f:
                json.dump(test_action, f)

            try:
                # 测试解析器
                parser = ActionParser(str(test_dir))
                parser.load_actions()

                # 验证加载的action
                self.assertIn("action_test", parser.actions)
                self.assertEqual(
                    parser.actions["action_test"]["description"],
                    "Test action"
                )

                # 测试执行action
                test_data = {"existing_field": ["0x56", "0x78"]}
                json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

                parser.execute_action("action_test", json_data)

                # 验证执行结果
                self.assertIn("new_field", json_data.data)
                self.assertEqual(
                    json_data.get_json_data_value(["new_field"]),
                    ["0x12", "0x34"]
                )

            finally:
                # 清理测试文件和目录
                for file in test_dir.glob("*"):
                    file.unlink()
                test_dir.rmdir()

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
class ActionLoader:
    """从CSV文件加载和处理action序列，支持子文件夹对应关系"""
    
    def __init__(self, csv_dir: str = "csv", action_dir: str = "actions"):
        self.csv_root = Path(csv_dir)
        self.action_root = Path(action_dir)
        
        logging.basicConfig(
            level=logging.INFO,
            format='%(asctime)s - %(levelname)s - %(message)s'
        )

    def _read_csv_safe(self, file_path: Path) -> pd.DataFrame:
        """安全地读取Excel保存的CSV文件
        
        Args:
            file_path: CSV文件路径
                
        Returns:
            pd.DataFrame: 读取的数据框
        """
        try:
            # 首先尝试使用带BOM的UTF-8编码
            try:
                df = pd.read_csv(file_path, encoding='utf-8-sig')
                logging.info(f"Successfully read {file_path} with utf-8-sig encoding")
                return df
            except UnicodeDecodeError:
                pass
            
            # 然后尝试GBK编码（Excel默认中文编码）
            try:
                df = pd.read_csv(file_path, encoding='gbk')
                logging.info(f"Successfully read {file_path} with gbk encoding")
                return df
            except UnicodeDecodeError:
                pass
            
            # 最后尝试其他可能的编码
            encodings = ['gb18030', 'gb2312', 'big5', 'utf-8']
            for encoding in encodings:
                try:
                    df = pd.read_csv(file_path, encoding=encoding)
                    logging.info(f"Successfully read {file_path} with {encoding} encoding")
                    return df
                except UnicodeDecodeError:
                    continue
                
            raise UnicodeDecodeError(f"Failed to read {file_path} with any known encoding")
    
        except Exception as e:
            logging.error(f"Error reading CSV file {file_path}: {str(e)}")
            raise
        
    def _save_csv_with_encoding(self, df: pd.DataFrame, file_path: Path) -> None:
        """保存DataFrame为CSV，使用正确的编码
        
        Args:
            df: 要保存的DataFrame
            file_path: 保存路径
        """
        try:
            # 使用utf-8-sig编码保存，这样Excel打开时不会乱码
            df.to_csv(file_path, encoding='utf-8-sig', index=False)
            logging.info(f"Successfully saved CSV file: {file_path}")
        except Exception as e:
            logging.error(f"Error saving CSV file {file_path}: {str(e)}")
            raise
        
    def process_csv_files(self) -> None:
        """处理所有CSV文件中的action_sequence列，保持目录结构"""
        try:
            # 确保目录结构
            self._ensure_directory_structure()
            
            # 处理每个子文件夹
            for category_dir in self.csv_root.iterdir():
                if not category_dir.is_dir():
                    continue
                    
                category = category_dir.name
                logging.info(f"Processing category: {category}")
                
                # 处理该类别下的所有CSV文件
                for csv_file in category_dir.glob("*.csv"):
                    logging.info(f"Processing CSV file: {csv_file}")
                    try:
                        # 读取CSV文件
                        df = self._read_csv_safe(csv_file)
                        
                        if 'action_sequence' not in df.columns:
                            logging.error(f"No 'action_sequence' column in {csv_file}")
                            continue
                        
                        # 处理每一行
                        processed_rows = []
                        for index, row in df.iterrows():
                            action_text = row['action_sequence']
                            
                            # 生成action文件名
                            action_name = f"action_{csv_file.stem}_{index}"
                            
                            # 转换和保存action
                            json_str = self._convert_action_text_to_json(action_text)
                            if json_str:
                                self._save_action_file(category, action_name, json_str)
                                processed_rows.append(row)
                            else:
                                logging.warning(f"Skipped invalid action at row {index} in {csv_file}")
    
                        # 如果需要，可以保存处理后的数据
                        if processed_rows:
                            processed_df = pd.DataFrame(processed_rows)
                            processed_path = csv_file.parent / f"processed_{csv_file.name}"
                            self._save_csv_with_encoding(processed_df, processed_path)
    
                    except Exception as e:
                        logging.error(f"Error processing file {csv_file}: {str(e)}")
                        continue
                    
        except Exception as e:
            logging.error(f"Error processing CSV files: {str(e)}")
            raise
        
    def _ensure_directory_structure(self) -> None:
        """确保目录结构存在，并在action目录下创建对应的子文件夹"""
        try:
            # 检查CSV根目录是否存在
            if not self.csv_root.exists():
                raise FileNotFoundError(f"CSV root directory not found: {self.csv_root}")
            
            # 创建action根目录
            self.action_root.mkdir(exist_ok=True)
            
            # 获取CSV目录下的所有子文件夹
            csv_subdirs = [d for d in self.csv_root.iterdir() if d.is_dir()]
            
            # 在action目录下创建对应的子文件夹
            for subdir in csv_subdirs:
                action_subdir = self.action_root / subdir.name
                action_subdir.mkdir(exist_ok=True)
                logging.info(f"Ensured action subdirectory: {action_subdir}")
                
        except Exception as e:
            logging.error(f"Error ensuring directory structure: {str(e)}")
            raise


    def _convert_action_text_to_json(self, input_text: str) -> Optional[str]:
        """将action文本转换为合法的JSON，保持原始键名不变"""
        try:
            def process_value(value: str) -> str:
                """处理值字段，统一转换为十六进制字符串格式"""
                value = value.strip('[] ')
                values = [v.strip() for v in value.split(',')]
                processed_values = []
                for v in values:
                    try:
                        if isinstance(v, str) and v.startswith('0x'):
                            v = v.lower()
                        elif v.isdigit():
                            v = hex(int(v))
                        processed_values.append(f'"{v}"')
                    except (ValueError, AttributeError):
                        processed_values.append(f'"{v}"')
                return f"[{', '.join(processed_values)}]"

            def process_line(line: str) -> str:
                """处理单行文本，移除注释并格式化值"""
                import re
                # 移除注释
                line = re.sub(r'//.*$', '', line)
                line = re.sub(r'/\*.*?\*/', '', line)
                
                # 分别处理new_value和value字段
                for value_field in ['new_value', 'value']:
                    if f'"{value_field}":' in line:
                        match = re.search(rf'"{value_field}":\s*(\[[^\]]*\])', line)
                        if match:
                            value_str = match.group(1)
                            processed_value = process_value(value_str)
                            line = re.sub(
                                rf'"{value_field}":\s*\[[^\]]*\]', 
                                f'"{value_field}": {processed_value}', 
                                line
                            )
                
                return line

            # 处理输入文本
            if pd.isna(input_text):
                return None
                
            input_text = str(input_text)
            lines = input_text.split('\n')
            processed_lines = [process_line(line.strip()) for line in lines if line.strip()]
            json_str = '\n'.join(processed_lines)
            
            # 验证JSON格式
            parsed_json = json.loads(json_str)
            
            # 验证action类型和对应的值字段
            if 'action_sequence' in parsed_json:
                for action in parsed_json['action_sequence']:
                    if 'action' in action:
                        # 确保add操作使用value字段
                        if action['action'] == 'add' and 'new_value' in action:
                            logging.warning("Found 'new_value' in add action, should use 'value'")
                        # 确保update操作使用new_value字段
                        elif action['action'] == 'update' and 'value' in action:
                            logging.warning("Found 'value' in update action, should use 'new_value'")
            
            return json_str
            
        except Exception as e:
            logging.error(f"Error converting action text to JSON: {str(e)}")
            return None

    def _save_action_file(self, category: str, action_name: str, json_str: str) -> None:
        """保存action文件到对应的子文件夹
        
        Args:
            category: 类别（子文件夹名）
            action_name: action文件名（不包含扩展名）
            json_str: JSON格式的action内容
        """
        try:
            # 构建子文件夹路径
            subdir = self.action_root / category
            if not subdir.exists():
                subdir.mkdir(parents=True)
            
            # 构建文件路径
            file_path = subdir / f"{action_name}.txt"
            
            # 保存文件
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(json_str)
                
            logging.info(f"Successfully saved action file: {file_path}")
            
        except Exception as e:
            logging.error(f"Error saving action file {action_name} in {category}: {str(e)}")
            raise

    def process_csv_files(self) -> None:
        """处理所有CSV文件中的action_sequence列，保持目录结构"""
        try:
            # 确保目录结构
            self._ensure_directory_structure()
            
            # 处理每个子文件夹
            for category_dir in self.csv_root.iterdir():
                if not category_dir.is_dir():
                    continue
                    
                category = category_dir.name
                logging.info(f"Processing category: {category}")
                
                # 处理该类别下的所有CSV文件
                for csv_file in category_dir.glob("*.csv"):
                    logging.info(f"Processing CSV file: {csv_file}")
                    try:
                        # 读取CSV文件
                        df = pd.read_csv(csv_file)
                        
                        if 'action_sequence' not in df.columns:
                            logging.error(f"No 'action_sequence' column in {csv_file}")
                            continue

                        # 处理每一行
                        for index, row in df.iterrows():
                            action_text = row['action_sequence']
                            
                            # 生成action文件名
                            action_name = f"action_{csv_file.stem}_{index}"
                            
                            # 转换和保存action
                            json_str = self._convert_action_text_to_json(action_text)
                            if json_str:
                                self._save_action_file(category, action_name, json_str)
                            else:
                                logging.warning(f"Skipped invalid action at row {index} in {csv_file}")

                    except Exception as e:
                        logging.error(f"Error processing file {csv_file}: {str(e)}")
                        continue

        except Exception as e:
            logging.error(f"Error processing CSV files: {str(e)}")
            raise

    def clean_action_directory(self) -> None:
        """清理action目录，删除所有现有文件"""
        try:
            if self.action_root.exists():
                shutil.rmtree(self.action_root)
            self.action_root.mkdir()
            logging.info(f"Cleaned action directory: {self.action_root}")
        except Exception as e:
            logging.error(f"Error cleaning action directory: {str(e)}")
            raise

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

        # 创建并使用ActionParser
        parser = ActionParser("actions_test")
        parser.load_actions()
        
        # 执行所有加载的actions
        logging.info("=== Executing loaded actions ===")
        for action_name in parser.actions:
            parser.execute_action(action_name, json_data)
            logging.info(f"Current data state after {action_name}:")
            json_data.indexmap_print_in_json_pretty_format()
    except Exception as e:
        logging.error(f"Error occurred: {str(e)}")
        raise

    try:
        # 创建加载器实例
        loader = ActionLoader(csv_dir="csv", action_dir="actions")
        
        # 清理现有action目录（可选）
        loader.clean_action_directory()
        
        # 处理CSV文件
        loader.process_csv_files()
        
        logging.info("Successfully processed all CSV files")
        
    except Exception as e:
        logging.error(f"Error in main process: {str(e)}")
        raise

if __name__ == "__main__":
    # 运行单元测试
    # run_tests()
    
    # 运行主函数示例
    main()
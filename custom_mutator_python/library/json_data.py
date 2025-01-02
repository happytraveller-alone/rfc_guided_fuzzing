from typing import Dict, List, Any, Optional, Union
from collections import OrderedDict
import json
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

    def generate_padded_hex_array(self, length_hex: str, value_hex: str) -> List[str]:
        """根据指定的十六进制长度和值生成左填充的十六进制数组

        Args:
            length_hex (str): 数组长度的十六进制表示（如：'0x02'）
            value_hex (str): 要填充的值的十六进制表示（如：'0x03'）

        Returns:
            List[str]: 左填充0后的十六进制字符串数组

        Examples:
            >>> json_data.generate_padded_hex_array('0x02', '0x03')
            ['0x00', '0x03']

        Raises:
            ValueError: 如果输入格式无效或长度为0
        """
        try:
            # 验证并转换输入的十六进制字符串
            try:
                length = self.hex_str_to_byte(length_hex)
                value = self.hex_str_to_byte(value_hex)
            except ValueError as e:
                raise ValueError(f"Invalid hex input: {str(e)}")

            # 验证长度
            if length <= 0:
                raise ValueError("Length must be greater than 0")

            # 验证值的范围
            if value < 0:
                raise ValueError("Value must be non-negative")

            # 创建结果数组
            result = []

            # 填充前导0
            for _ in range(length - 1):
                result.append("0x00")

            # 添加实际值
            result.append(f"0x{value:02X}")

            logging.debug(f"Generated padded array with length {length_hex}: {result}")

            return result

        except Exception as e:
            error_msg = f"Error generating padded hex array: {str(e)}"
            logging.error(error_msg)
            raise

    def get_array_length_hex(self, keys: List[str]) -> str:
        """获取指定路径叶节点数组的长度（十六进制表示）

        Args:
            keys (List[str]): 目标数组的路径

        Returns:
            str: 数组长度的十六进制表示（格式如：'0x05'）

        Raises:
            ValueError: 如果路径为空或目标不是数组
            KeyError: 如果路径不存在
        """
        try:
            if not keys:
                raise ValueError("Empty key sequence")

            # 获取目标值
            value = self.json_data_get_value_mut(keys)

            # 检查是否为列表类型
            if not isinstance(value, list):
                raise ValueError(f"Value at path {'.'.join(keys)} is not an array")

            # 获取长度并转换为十六进制
            length = len(value)
            hex_length = f"0x{length:02X}"

            logging.info(f"Array length at path {'.'.join(keys)}: {length} (hex: {hex_length})")

            return hex_length

        except Exception as e:
            error_msg = f"Error getting array length: {str(e)}"
            logging.error(error_msg)
            raise

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

    def json_data_pair_insert_after(self, path: List[str], target_key: str, new_key: str, new_value: Any = None) -> None:
        """在指定键后插入新的键值对或空对象
    
        Args:
            path (List[str]): 目标字典的路径
            target_key (str): 目标键（在此键后插入）
            new_key (str): 新的键名
            new_value (Any, optional): 新的值，如果为None则插入空对象
    
        Raises:
            ValueError: 如果路径无效或键已存在
            KeyError: 如果目标键不存在
        """
        try:
            # 获取目标字典
            target_dict = self.data if not path else self.json_data_get_value_mut(path)
            
            if not isinstance(target_dict, OrderedDict):
                raise ValueError(f"Target at path {path} is not a dictionary")
                
            if target_key not in target_dict:
                raise KeyError(f"Target key '{target_key}' not found")
                
            if new_key in target_dict:
                raise ValueError(f"Key '{new_key}' already exists")
                
            # 创建新的OrderedDict来重建顺序
            new_dict = OrderedDict()
            found_target = False
            
            for key, value in target_dict.items():
                new_dict[key] = value
                if key == target_key:
                    found_target = True
                    # 在目标键后插入新键
                    new_dict[new_key] = {} if new_value is None else new_value
                    
            # 更新原字典
            target_dict.clear()
            target_dict.update(new_dict)
            
            # 日志记录
            path_str = "root" if not path else ".".join(path)
            value_type = "empty object" if new_value is None else f"value: {new_value}"
            logging.debug(f"Inserted {value_type} with key '{new_key}' after '{target_key}' at {path_str}")
            
        except Exception as e:
            error_msg = f"Error inserting after key: {str(e)}"
            logging.error(error_msg)
            raise
        
    def json_data_pair_insert_before(self, path: List[str], target_key: str, new_key: str, new_value: Any = None) -> None:
        """在指定键前插入新的键值对或空对象
    
        Args:
            path (List[str]): 目标字典的路径
            target_key (str): 目标键（在此键前插入）
            new_key (str): 新的键名
            new_value (Any, optional): 新的值，如果为None则插入空对象
    
        Raises:
            ValueError: 如果路径无效或键已存在
            KeyError: 如果目标键不存在
        """
        try:
            # 获取目标字典
            target_dict = self.data if not path else self.json_data_get_value_mut(path)
            
            if not isinstance(target_dict, OrderedDict):
                raise ValueError(f"Target at path {path} is not a dictionary")
                
            if target_key not in target_dict:
                raise KeyError(f"Target key '{target_key}' not found")
                
            if new_key in target_dict:
                raise ValueError(f"Key '{new_key}' already exists")
                
            # 创建新的OrderedDict来重建顺序
            new_dict = OrderedDict()
            
            for key, value in target_dict.items():
                if key == target_key:
                    # 在目标键前插入新键
                    new_dict[new_key] = {} if new_value is None else new_value
                new_dict[key] = value
                    
            # 更新原字典
            target_dict.clear()
            target_dict.update(new_dict)
            
            # 日志记录
            path_str = "root" if not path else ".".join(path)
            value_type = "empty object" if new_value is None else f"value: {new_value}"
            logging.debug(f"Inserted {value_type} with key '{new_key}' before '{target_key}' at {path_str}")
            
        except Exception as e:
            error_msg = f"Error inserting before key: {str(e)}"
            logging.error(error_msg)
            raise
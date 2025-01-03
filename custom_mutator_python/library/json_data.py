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

    def _calculate_content_length(self, content: Dict) -> int:
        """
        递归计算字典内容的字节长度

        Args:
            content: 要计算长度的字典内容

        Returns:
            int: 内容的总字节长度
        """
        total_length = 0

        for key, value in content.items():
            if isinstance(value, list):
                # 列表中的每个元素都是一个十六进制字符串
                total_length += len([self.hex_str_to_byte(x) for x in value])
            elif isinstance(value, dict):
                # 递归计算子字典的长度
                total_length += self._calculate_content_length(value)

        return total_length

    def update_extension_length(self, extension_path: List[str]) -> int:
        """
        更新指定路径Extension节点下的tls.handshake.extension.len值
        
        Args:
            extension_path: Extension节点的完整路径列表
            
        Returns:
            int: 更新后的length值 + 4
            
        Example:
            extension_path = ['tls', 'tls.record', 'tls.handshake', 
                             'Extension: key_share (len=38) x25519']
            total_length = json_data.update_extension_length(extension_path)
            print(f"Extension length + 4: {total_length}")
        """
        try:
            # 获取Extension节点
            extension = self.json_data_get_value_mut(extension_path)
            
            if not isinstance(extension, dict):
                raise ValueError(f"Path {extension_path} does not point to a dictionary")
                
            if "tls.handshake.extension.len" not in extension:
                raise ValueError(f"No extension length field found at {extension_path}")
                
            # 创建一个新的OrderedDict来存储tls.handshake.extension.len之后的内容
            content_after_len = OrderedDict()
            found_len_field = False
            
            # 遍历原始字典，只收集长度字段之后的内容
            for field_key, field_value in extension.items():
                if found_len_field:
                    content_after_len[field_key] = field_value
                if field_key == "tls.handshake.extension.len":
                    found_len_field = True
            
            # 计算长度字段后内容的长度
            content_length = self._calculate_content_length(content_after_len)
            
            # 转换为两字节的十六进制表示
            hex_length = [f"{(content_length >> 8) & 0xFF:02X}",
                         f"{content_length & 0xFF:02X}"]
            
            # 更新长度字段
            original_len = extension["tls.handshake.extension.len"]
            extension["tls.handshake.extension.len"] = hex_length
            
            # 记录日志
            path_str = " -> ".join(extension_path)
            logging.info(f"Updated extension length at path: {path_str}")
            logging.info(f"Original length: {original_len}, New length: {hex_length} "
                        f"(decimal: {content_length})")
            logging.debug(f"Content after len field: {json.dumps(content_after_len, indent=2)}")
            
            # 返回更新后的length值 + 4
            return content_length + 4
            
        except Exception as e:
            error_msg = f"Error updating extension length: {str(e)}"
            logging.error(error_msg)
            raise

    def verify_extension_length(self, extension_path: List[str]) -> bool:
        """
        验证指定Extension的长度是否正确

        Args:
            extension_path: Extension节点的完整路径列表

        Returns:
            bool: 长度是否正确
        """
        try:
            # 获取Extension节点
            extension = self.json_data_get_value_mut(extension_path)

            if not isinstance(extension, dict):
                raise ValueError(f"Path {extension_path} does not point to a dictionary")

            if "tls.handshake.extension.len" not in extension:
                raise ValueError(f"No extension length field found at {extension_path}")

            # 获取当前长度值
            current_len = extension["tls.handshake.extension.len"]
            current_len_value = (self.hex_str_to_byte(current_len[0]) << 8) + \
                               self.hex_str_to_byte(current_len[1])

            # 计算实际长度
            content_after_len = OrderedDict()
            found_len_field = False
            for field_key, field_value in extension.items():
                if found_len_field:
                    content_after_len[field_key] = field_value
                if field_key == "tls.handshake.extension.len":
                    found_len_field = True

            actual_length = self._calculate_content_length(content_after_len)

            if current_len_value != actual_length:
                logging.error(f"Length mismatch in {extension_path}: "
                            f"stored={current_len_value}, calculated={actual_length}")
                return False

            return True

        except Exception as e:
            logging.error(f"Error verifying extension length: {str(e)}")
            return False
        
    def find_extension_paths(self, extension_root_search: List[str]) -> List[List[str]]:
        """
        搜索指定根路径下所有包含'Extension:'的字段路径

        Args:
            extension_root_search: 搜索的根路径列表

        Returns:
            List[List[str]]: 所有Extension的完整路径列表

        Example:
            >>> root_path = ['tls', 'tls.record', 'tls.handshake']
            >>> paths = json_data.find_extension_paths(root_path)
            >>> print(paths)
            [
                ['tls', 'tls.record', 'tls.handshake', 'Extension: key_share (len=38) x25519'],
                ['tls', 'tls.record', 'tls.handshake', 'Extension: ec_point_formats (len=2)'],
                ...
            ]
        """
        try:
            # 获取根路径节点
            root_node = self.json_data_get_value_mut(extension_root_search)

            if not isinstance(root_node, dict):
                raise ValueError(f"Root path {extension_root_search} does not point to a dictionary")

            extension_paths = []

            # 遍历根节点下的所有键
            for key in root_node.keys():
                if "Extension:" in key:
                    # 构建完整路径并添加到结果列表
                    full_path = extension_root_search + [key]
                    extension_paths.append(full_path)
                    logging.debug(f"Found extension path: {' -> '.join(full_path)}")

            # 按照路径字符串排序，保证结果的稳定性
            extension_paths.sort(key=lambda x: x[-1])

            # 记录找到的Extension数量
            logging.info(f"Found {len(extension_paths)} extensions under {' -> '.join(extension_root_search)}")

            return extension_paths

        except Exception as e:
            error_msg = f"Error finding extension paths: {str(e)}"
            logging.error(error_msg)
            raise

    def update_all_extensions_under_root(self, extension_root_search: List[str]) -> int:
        """
        更新指定根路径下所有Extension的长度值

        Args:
            extension_root_search: 搜索的根路径列表

        Returns:
            int: 所有extension更新后length值+4的总和

        Example:
            >>> root_path = ['tls', 'tls.record', 'tls.handshake']
            >>> total_length = json_data.update_all_extensions_under_root(root_path)
            >>> print(f"Total length of all extensions: {total_length}")
        """
        try:
            # 获取所有Extension路径
            extension_paths = self.find_extension_paths(extension_root_search)

            if not extension_paths:
                logging.warning(f"No extensions found under {' -> '.join(extension_root_search)}")
                return 0

            # 更新每个Extension的长度并累加返回值
            total_length = 0
            update_results = []  # 用于存储每个extension的更新结果

            for path in extension_paths:
                try:
                    length = self.update_extension_length(path)
                    total_length += length
                    update_results.append({
                        'path': path,
                        'length': length
                    })
                    logging.info(f"Successfully updated extension at {' -> '.join(path)}, "
                               f"length + 4: {length}")
                except Exception as e:
                    logging.error(f"Failed to update extension at {' -> '.join(path)}: {str(e)}")
                    raise

            # 详细日志记录
            logging.info(f"Successfully updated all {len(extension_paths)} extensions")
            logging.info("Update results:")
            for result in update_results:
                logging.info(f"  {' -> '.join(result['path'])}: {result['length']}")
            logging.info(f"Total length (sum of all lengths + 4): {total_length}")

            return total_length

        except Exception as e:
            error_msg = f"Error updating all extensions: {str(e)}"
            logging.error(error_msg)
            raise

    def verify_all_extensions_under_root(self, extension_root_search: List[str]) -> bool:
        """
        验证指定根路径下所有Extension的长度值是否正确
        
        Args:
            extension_root_search: 搜索的根路径列表
            
        Returns:
            bool: 所有Extension的长度是否都正确
            
        Example:
            >>> root_path = ['tls', 'tls.record', 'tls.handshake']
            >>> if json_data.verify_all_extensions_under_root(root_path):
            ...     print("All extensions are correct")
            ... else:
            ...     print("Some extensions have incorrect lengths")
        """
        try:
            # 获取所有Extension路径
            extension_paths = self.find_extension_paths(extension_root_search)
            
            if not extension_paths:
                logging.warning(f"No extensions found under {' -> '.join(extension_root_search)}")
                return True
                
            # 验证每个Extension的长度
            all_correct = True
            for path in extension_paths:
                try:
                    if not self.verify_extension_length(path):
                        all_correct = False
                        logging.error(f"Length verification failed for extension at {' -> '.join(path)}")
                except Exception as e:
                    logging.error(f"Error verifying extension at {' -> '.join(path)}: {str(e)}")
                    all_correct = False
                    
            if all_correct:
                logging.info(f"All {len(extension_paths)} extensions have correct lengths")
            else:
                logging.error("Some extensions have incorrect lengths")
                
            return all_correct
            
        except Exception as e:
            error_msg = f"Error verifying all extensions: {str(e)}"
            logging.error(error_msg)
            return False

    def update_length_field(self, length_field_path: List[str], content_field_path: List[str]) -> None:
        """
        更新长度字段的值，根据内容字段的实际长度

        Args:
            length_field_path: 需要更新的长度字段的路径
            content_field_path: 用于计算长度的内容字段的路径

        Example:
            >>> length_path = ["tls", "tls.record", "tls.handshake", 
                              "tls.handshake.cipher_suites_length"]
            >>> content_path = ["tls", "tls.record", "tls.handshake", 
                               "tls.handshake.ciphersuites"]
            >>> json_data.update_length_field(length_path, content_path)
        """
        try:
            # 获取长度字段和内容字段
            length_field = self.json_data_get_value_mut(length_field_path)
            content_field = self.json_data_get_value_mut(content_field_path)

            # 验证字段类型
            if not isinstance(length_field, list):
                raise ValueError(f"Length field at {length_field_path} is not a list")
            if not isinstance(content_field, list):
                raise ValueError(f"Content field at {content_field_path} is not a list")

            # 获取字段的长度信息
            length_field_size = len(length_field)  # 原长度字段的数组大小
            content_length = len(content_field)    # 内容字段的实际长度

            # 记录原始值用于日志
            original_length_value = length_field.copy()

            # 将内容长度转换为十六进制并左填充
            hex_length = []
            remaining_length = content_length

            # 从右到左填充，确保足够的位数
            for i in range(length_field_size):
                hex_value = f"{(remaining_length & 0xFF):02X}"
                hex_length.insert(0, hex_value)
                remaining_length >>= 8

            # 检查是否有溢出
            if remaining_length > 0:
                raise ValueError(f"Content length {content_length} is too large "
                               f"for length field size {length_field_size}")

            # 更新长度字段的值
            length_field_node = self.json_data_get_value_mut(length_field_path[:-1])
            length_field_node[length_field_path[-1]] = hex_length

            # 记录日志
            logging.info(f"Updated length field at {' -> '.join(length_field_path)}")
            logging.info(f"Original value: {original_length_value}")
            logging.info(f"New value: {hex_length}")
            logging.info(f"Content length: {content_length} (0x{content_length:X})")

        except Exception as e:
            error_msg = (f"Error updating length field {' -> '.join(length_field_path)} "
                        f"based on content field {' -> '.join(content_field_path)}: {str(e)}")
            logging.error(error_msg)
            raise

    def verify_length_field(self, length_field_path: List[str], 
                           content_field_path: List[str]) -> bool:
        """
        验证长度字段的值是否与内容字段的实际长度匹配

        Args:
            length_field_path: 长度字段的路径
            content_field_path: 内容字段的路径

        Returns:
            bool: 长度是否匹配
        """
        try:
            # 获取长度字段和内容字段
            length_field = self.json_data_get_value_mut(length_field_path)
            content_field = self.json_data_get_value_mut(content_field_path)

            # 验证字段类型
            if not isinstance(length_field, list):
                raise ValueError(f"Length field at {length_field_path} is not a list")
            if not isinstance(content_field, list):
                raise ValueError(f"Content field at {content_field_path} is not a list")

            # 计算存储的长度值
            stored_length = 0
            for hex_str in length_field:
                stored_length = (stored_length << 8) + self.hex_str_to_byte(hex_str)

            # 获取实际内容长度
            actual_length = len(content_field)

            # 检查是否匹配
            if stored_length != actual_length:
                logging.error(f"Length mismatch at {' -> '.join(length_field_path)}: "
                            f"stored={stored_length}, actual={actual_length}")
                return False

            logging.info(f"Length field verification passed: {stored_length}")
            return True

        except Exception as e:
            error_msg = (f"Error verifying length field {' -> '.join(length_field_path)}: "
                        f"{str(e)}")
            logging.error(error_msg)
            return False
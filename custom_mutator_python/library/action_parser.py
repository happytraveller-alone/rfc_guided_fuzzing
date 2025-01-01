import json
import logging
from pathlib import Path
from enum import IntFlag
from .json_data import JsonData, AddType
from typing import Dict

class AddFlags(IntFlag):
    """添加操作的标志位"""
    NONE = 0
    HAS_POSITION = 1    # 0b01: 是否有position参数
    HAS_VALUE = 2       # 0b10: 是否有value参数

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

        # 验证position字段（如果存在）
        if 'position' in action:
            if not isinstance(action['position'], str):
                logging.error("Position must be a string (target key)")
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
        """执行add类型的action，使用二进制标志处理分支逻辑
        
        Args:
            action (Dict): action配置
            json_data (JsonData): JSON数据对象
        """
        try:
            # 提取公共参数
            fields = action['fields']
            parent_path = fields[:-1]
            new_key = fields[-1]
            
            # 构建标志位
            flags = AddFlags.NONE
            if 'position' in action:
                flags |= AddFlags.HAS_POSITION
            if 'value' in action:
                flags |= AddFlags.HAS_VALUE
                
            # 定义处理函数
            def add_default_object():
                """默认添加空对象"""
                logging.info(f"Adding new object at path: {fields}")
                json_data.json_data_pair_add(
                    parent_path,
                    new_key,
                    add_type=AddType.OBJECT
                )
                
            def add_default_value():
                """默认添加键值对"""
                logging.info(f"Adding new value at path: {fields}")
                json_data.json_data_pair_add(
                    parent_path,
                    new_key,
                    action['value'],
                    AddType.PAIR
                )
                
            def add_positioned_object():
                """在指定位置后添加空对象"""
                target_key = action['position']
                logging.info(f"Adding new object after key '{target_key}' at path: {parent_path}")
                json_data.json_data_pair_insert_after(
                    parent_path,
                    target_key,
                    new_key
                )
                
            def add_positioned_value():
                """在指定位置后添加键值对"""
                target_key = action['position']
                logging.info(f"Adding new value after key '{target_key}' at path: {parent_path}")
                json_data.json_data_pair_insert_after(
                    parent_path,
                    target_key,
                    new_key,
                    action['value']
                )
            
            # 使用字典映射替代if-else结构
            handlers = {
                AddFlags.NONE: add_default_object,
                AddFlags.HAS_VALUE: add_default_value,
                AddFlags.HAS_POSITION: add_positioned_object,
                AddFlags.HAS_POSITION | AddFlags.HAS_VALUE: add_positioned_value
            }
            
            # 执行对应的处理函数
            handler = handlers.get(flags)
            if handler:
                handler()
            else:
                raise ValueError(f"Invalid combination of flags: {flags}")
                
        except KeyError as e:
            error_msg = f"Target key not found: {str(e)}"
            logging.error(error_msg)
            raise
        except Exception as e:
            error_msg = f"Error in add action: {str(e)}"
            logging.error(error_msg)
            raise

    # 可选：添加辅助方法来提高代码可读性
    @staticmethod
    def _get_add_flags(action: Dict) -> AddFlags:
        """获取action的标志位"""
        flags = AddFlags.NONE
        if 'position' in action:
            flags |= AddFlags.HAS_POSITION
        if 'value' in action:
            flags |= AddFlags.HAS_VALUE
        return flags

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

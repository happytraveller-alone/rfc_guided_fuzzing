import re
import pandas as pd
import json
import logging
from pathlib import Path
import shutil
from typing import Optional

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
                            # self._save_csv_with_encoding(processed_df, processed_path)
    
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

            def balance_braces(text: str) -> str:
                """平衡括号并清理多余字符"""
                stack = []
                valid_chars = []
                last_closing_brace = -1

                for i, char in enumerate(text):
                    if char in '{[':
                        stack.append(char)
                        valid_chars.append(char)
                    elif char in '}]':
                        if not stack:
                            continue  # 忽略多余的闭合括号
                        
                        if (char == '}' and stack[-1] == '{') or (char == ']' and stack[-1] == '['):
                            stack.pop()
                            valid_chars.append(char)
                            if char == '}' and not stack:  # 记录最后一个有效的闭合大括号位置
                                last_closing_brace = len(valid_chars)
                    elif stack:  # 只有在括号内才添加其他字符
                        valid_chars.append(char)

                # 如果还有未闭合的括号，添加相应的闭合括号
                while stack:
                    bracket = stack.pop()
                    valid_chars.append('}' if bracket == '{' else ']')

                # 如果找到了有效的闭合大括号，只保留到该位置的内容
                if last_closing_brace > 0:
                    valid_chars = valid_chars[:last_closing_brace]

                return ''.join(valid_chars)

            def remove_trailing_commas(text: str) -> str:
                """移除JSON中的尾随逗号"""
                import re
                # 移除对象中的尾随逗号
                text = re.sub(r',(\s*})', r'\1', text)
                # 移除数组中的尾随逗号
                text = re.sub(r',(\s*])', r'\1', text)
                return text

            def clean_json_text(text: str) -> str:
                """清理和规范化JSON文本"""
                # 移除反引号和多余的引号
                text = text.strip('`\'\"')
                # 移除注释
                text = re.sub(r'//.*$', '', text, flags=re.MULTILINE)
                text = re.sub(r'/\*.*?\*/', '', text, flags=re.DOTALL)
                # 移除空行
                text = '\n'.join(line for line in text.splitlines() if line.strip())
                return text

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

            # 清理输入文本
            input_text = clean_json_text(str(input_text))

            # 处理每一行
            lines = input_text.split('\n')
            processed_lines = [process_line(line.strip()) for line in lines if line.strip()]
            json_str = '\n'.join(processed_lines)

            # 平衡括号并移除多余内容
            json_str = balance_braces(json_str)

            # 移除尾随逗号
            json_str = remove_trailing_commas(json_str)

            # 验证JSON格式
            try:
                parsed_json = json.loads(json_str)
            except json.JSONDecodeError as e:
                logging.error(f"JSON parsing error at position {e.pos}: {e.msg}")
                logging.error(f"Problematic text: {json_str[max(0, e.pos-20):e.pos+20]}")
                raise
            
            # 验证action类型和对应的值字段
            if 'action_sequence' in parsed_json:
                for action in parsed_json['action_sequence']:
                    if 'action' in action:
                        if action['action'] == 'add' and 'new_value' in action:
                            logging.warning("Found 'new_value' in add action, should use 'value'")
                        elif action['action'] == 'update' and 'value' in action:
                            logging.warning("Found 'value' in update action, should use 'new_value'")

            return json_str

        except Exception as e:
            logging.error(f"Error converting action text to JSON: {str(e)}")
            logging.error(f"Original text: {input_text}")
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
                
            logging.debug(f"Successfully saved action file: {file_path}")
            
        except Exception as e:
            logging.error(f"Error saving action file {action_name} in {category}: {str(e)}")
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

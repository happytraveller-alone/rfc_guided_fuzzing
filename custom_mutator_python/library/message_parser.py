import os
from typing import List
from pathlib import Path
from .json_data import JsonData, AddType
import json
from typing import Dict, List, Any, Optional, Union
from collections import OrderedDict

class JsonFileProcessor:
    """
    JSON文件处理器类，用于收集特定目录下的JSON文件。
    
    Attributes:
        base_dir (str): 基础目录路径
        file_paths (List[str]): 符合条件的文件路径列表
        verbose (bool): 是否输出详细日志
    """

    def __init__(self, base_dir: str = "message", verbose: bool = True):
        """
        初始化JSON文件处理器。

        Args:
            base_dir (str): 基础目录路径，默认为"message"
            verbose (bool): 是否输出详细日志，默认为True
        """
        self.base_dir = base_dir
        self.file_paths: List[str] = []
        self.processed_files: Dict[str, bool] = {}
        self.verbose = verbose

    def get_processing_status(self) -> Dict[str, bool]:
        """
        获取所有文件的处理状态。

        Returns:
            Dict[str, bool]: 文件路径到处理状态的映射
        """
        return self.processed_files
    
    def collect_json_files(self) -> List[str]:
        """
        收集符合条件的JSON文件路径（不以full开头的json文件）。

        Returns:
            List[str]: 符合条件的文件路径列表

        Raises:
            FileNotFoundError: 当基础目录不存在时抛出
        """
        try:
            if not os.path.exists(self.base_dir):
                raise FileNotFoundError(f"目录 {self.base_dir} 不存在")

            self.file_paths = []
            
            # 遍历所有子文件夹
            for root, _, files in os.walk(self.base_dir):
                for file in files:
                    if file.endswith('.json') and not file.startswith('full'):
                        file_path = os.path.join(root, file)
                        if self.validate_json_file(file_path):
                            self.file_paths.append(file_path)

            # 排序文件路径
            self.file_paths.sort()

            if self.verbose:
                self._print_collected_files()

            return self.file_paths

        except Exception as e:
            if self.verbose:
                print(f"收集文件过程中发生错误: {str(e)}")
            return []

    @staticmethod
    def validate_json_file(file_path: str) -> bool:
        """
        验证文件路径是否有效且为JSON文件。

        Args:
            file_path (str): 待验证的文件路径

        Returns:
            bool: 文件是否有效
        """
        return (
            os.path.exists(file_path) and 
            os.path.isfile(file_path) and 
            file_path.endswith('.json')
        )

    def get_file_paths(self) -> List[str]:
        """
        获取已收集的文件路径列表。

        Returns:
            List[str]: 文件路径列表
        """
        return self.file_paths

    def _print_collected_files(self) -> None:
        """打印收集到的文件列表。"""
        if self.file_paths:
            print("\nFind the following files that meet the conditions")
            for file_path in self.file_paths:
                print(f"- {file_path}")
            print(f"found {len(self.file_paths)} files in total")
        else:
            print("\nCan not find the files meeting the conditions")

    def process_files(self) -> Dict[str, Optional[OrderedDict]]:
        """
        处理所有收集到的JSON文件。

        Returns:
            Dict[str, Optional[OrderedDict]]: 文件路径到处理结果的映射
        """
        results = {}
        
        if not self.file_paths:
            self.collect_json_files()

        for file_path in self.file_paths:
            result = self.process_single_file(file_path)
            results[file_path] = result
            self.processed_files[file_path] = result is not None

        if self.verbose:
            self._print_processing_summary()

        return results

    def process_single_file(self, file_path: str) -> Optional[OrderedDict]:
        """
        处理单个JSON文件。

        Args:
            file_path (str): JSON文件的完整路径

        Returns:
            Optional[OrderedDict]: 处理后的OrderedDict对象，处理失败则返回None
        """
        try:
            if self.verbose:
                print(f"Processing files: {file_path}")

            if not self.validate_json_file(file_path):
                raise FileNotFoundError(f"无效的文件路径: {file_path}")

            with open(file_path, 'r', encoding='utf-8') as f:
                json_content = json.load(f)

            # 调用转换函数
            ordered_dict = JsonData.json_data_trans_to_ordered_dict(json_content)
            
            # 调用打印函数
            # JsonData.indexmap_print_in_json_pretty_format(ordered_dict)

            return ordered_dict

        except Exception as e:
            if self.verbose:
                print(f"处理文件 {file_path} 时发生错误: {str(e)}")
            return None

    def _print_processing_summary(self) -> None:
        """打印处理结果摘要。"""
        success_count = sum(1 for status in self.processed_files.values() if status)
        total_count = len(self.processed_files)
        
        print(f"\nProcessing Summary:")
        print(f"Processing complete summary: {total_count}")
        print(f"Processing successful: {success_count}")
        print(f"Processing failure: {total_count - success_count}")
# def main():
#     """主函数示例"""
    # try:
    #     # 创建处理器实例
    #     processor = JsonFileProcessor(verbose=True)
        
    #     # 收集文件
    #     file_paths = processor.collect_json_files()
        
    #     # 使用收集到的文件路径
    #     if file_paths:
    #         print("\n可以使用这些文件路径进行后续处理...")

    # except Exception as e:
    #     print(f"程序执行出错: {str(e)}")


# if __name__ == "__main__":
#     main()
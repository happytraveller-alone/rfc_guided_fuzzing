import json
import os

def save_dicts_to_files(json_file_path):
    # 确保Output文件夹存在
    output_folder = 'Output'
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)
    
    # 读取JSON文件
    with open(json_file_path, 'r') as file:
        data = json.load(file)
    
    # 遍历列表中的每个字典
    for index, item in enumerate(data):
        # 构造文件名，序号从1开始
        file_name = f"{index + 1}.json"
        # 构造完整的文件路径
        file_path = os.path.join(output_folder, file_name)
        
        # 将字典写入文件
        with open(file_path, 'w') as file:
            json.dump(item, file, indent=4)  # 使用indent美化输出

# 假设你的JSON文件名为data.json，位于当前目录下
json_file_path = 'result.json'
save_dicts_to_files(json_file_path)
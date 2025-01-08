import json
import os

# 删掉包含关键词的key：{k : [3434], k_tree : ["1212121212"]} => {k : [3434]} 
def remove_keys_with_tree(d,strtree):
    keys_to_delete = [key for key in d if strtree in key]
    for key in keys_to_delete:
        del d[key]
     # 递归处理字典中的子字典
    for key, value in list(d.items()):
        if isinstance(value, dict):
            remove_keys_with_tree(value,strtree)

# 保留包含关键词的key：{k : [3434], k_tree : ["1212121212"]} => {k_tree : ["1212121212"]} 
def keep_keys_with_tree(d,strtree):
    keys_to_delete = [key for key in d if strtree not in key]
    for key in keys_to_delete:
        del d[key]
     # 递归处理字典中的子字典
    for key, value in list(d.items()):
        if isinstance(value, dict):
            keep_keys_with_tree(value,strtree)

# 把所有的value都变成列表形式 {k : "12"} => {k : ["12"]}
def str2list(d):
    for key, value in list(d.items()):
        if isinstance(value, dict):
            if not value:
                del d[key]
            else:
                str2list(value) # 如果子字典为空，则删除该键
            
        elif isinstance(value, str):
            d[key] = [value]
        elif isinstance(value, list):
            d[key] = [value[0]]

# {k - ["1020304"]}  => {k - ["01", "02" , "03", "04" ]}
def expandstr(d):
    # 遍历字典中的所有键值对
    for key in list(d.keys()):
        if isinstance(d[key], dict):
            expandstr(d[key])
        elif isinstance(d[key], list):
            if len(d[key][0]) % 2 == 1:
                d[key][0] = "0" + d[key][0]


# {k : ["01020304"]} => {k - ["01", "02" , "03", "04" ]}
def list2byte(d):
    # 遍历字典中的所有键值对
    for key in list(d.keys()):
        if isinstance(d[key], dict):
            list2byte(d[key])
        elif isinstance(d[key], list) and not isinstance(d[key][0], int):
            if len(d[key][0]) > 1:
                d[key] = [d[key][0][i:i+2] for i in range(0, len(d[key][0]), 2)]

# { k1 - {k2 - v} } => {k1 - v}
# 简化嵌套字典，如果字典中只有一个键值对，则提取值
def simplify_dict(d):
    for k, v in d.items():
        if isinstance(v, dict):
            if len(v) == 1:
                # 如果字典中只有一个键值对，则提取值
                v = next(iter(v.values()))  # 提取这个唯一的值
            else:
                # 如果值是字典且有多于一个键值对，则递归调用simplify_dict
                v = simplify_dict(v)  # 递归简化嵌套字典
        # 更新字典中的值
        d[k] = v
    return d  # 返回简化后的字典

# 删掉值为空的键值对
def dropempty(d):
    for key,value in list(d.items()):  # 使用 list(d.keys()) 来避免在迭代时修改字典
        if isinstance(d[key], dict):  # 如果值是字典，则递归处理
            if len(value) == 0:
                del d[key]
            else:
                dropempty(d[key])
                if len(value) == 0:
                    del d[key]
        elif isinstance(d[key], list) and (d[key] == [""] or d[key] == [] or len(d[key]) == 0):
            del d[key]

def empty_values(d):
    for key in d:
        if isinstance(d[key], dict):
            empty_values(d[key])
        else:
            d[key] = []
    return d

import re

def newe_raw(pattern):
    with open("result.txt", 'r') as file: #打开result.txt形式，data是str形式
        content = file.read()

    content = re.sub(pattern, '"',content) # 使用替换，直接把moe，这里是_raw的都删掉
    data = json.loads(content) # 变成json形式
    with open('layers.json', 'w', encoding='utf-8') as file: # 输出到文件当中
        json.dump(data, file, indent=4, ensure_ascii=False)

def e_raw(flag,moe):
    with open("result.txt", 'r') as file: #打开result.txt形式，data是str形式
        content = file.read()

    content = content.replace(moe, '') # 使用替换，直接把moe，这里是_raw的都删掉
    # content = content.replace("tls.handshake.extension.",'')
    # content = content.replace("tls.handshake.",'')
    # content = content.replace("tls.record.",'') 
    # content = content.replace("extensions.",'')
    # content = content.replace("extensions_",'')    
    # content = content.replace("tls.extension.",'')
    # content = content.replace("tls.ech.hpke.keyconfig.cipher_suite.",'')
    # content = content.replace("tls.ech.",'')
    # content = content.replace("psk.",'')

    data = json.loads(content) # 变成json形式

    # for i in range(len(data)):
    #     dropempty(data[i]) #只有在这才能删掉空字典，神奇 2024.12.21，实际上是需要drop两次，笑鼠，不改了

    with open('result.json', 'w', encoding='utf-8') as file: # 输出到文件当中
        json.dump(data, file, indent=4, ensure_ascii=False)
    
    if flag == 1:
        nested_dict_with_empty_values = []
        for i in range(len(data)):
            nested_dict_with_empty_values.append(empty_values(data[i].copy()))
        
        tls_file = "result.txt"
        with open(tls_file, 'w') as tls_file:
            json.dump(nested_dict_with_empty_values, tls_file, indent=4)
        pattern = ''' \\((.*?)"'''

        newe_raw(pattern)


def keep_keys_with_raw(d):
    for key, value in list(d.items()):  # 使用 list(d.items()) 来避免在迭代时修改字典
        if(isinstance(value, dict)): # 如果值是dict，即还可以进一步解析，直接删除 '_raw' 键
            if f"{key}_raw" in d:
                del d[f"{key}_raw"]
                keep_keys_with_raw(d[key])
       
        elif isinstance(value, list) and f"{key}_raw" in d:
            del d[key] # 删除 key 键

import shutil

def save_dicts_to_files(json_file_path,output_folder):
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for filename in os.listdir(output_folder):
        file_path = os.path.join(output_folder, filename)
        # 如果是文件或链接，则删除
        if os.path.isfile(file_path) or os.path.islink(file_path):
            os.unlink(file_path)
        # 如果是目录，则删除目录及其内容
        elif os.path.isdir(file_path):
            shutil.rmtree(file_path)
    
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


def e_raw_txt(moe):
    with open("result.txt", 'r') as file: #打开result.txt形式，data是str形式
        content = file.read()

    content = content.replace(moe, '') # 使用替换，直接把moe，这里是_raw的都删掉
    content = content.replace("tls.handshake.extension.",'')

    os.remove('result.txt')

    tls_file = "result.txt"
    with open(tls_file, 'w') as tls_file:
        json.dump(content, tls_file, indent=4)

        
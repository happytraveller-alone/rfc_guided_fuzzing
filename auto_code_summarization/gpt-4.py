import openai
import os
import json
import re
import json

openai.api_key = "**************"

system_intel = "You are GPT-4, answer my questions as if you were an expert in the field."
prompt = '''If you are an RFC expert and you now have a function that requires you to explain that this code matches those in RFC8446, take a deep breath, step by step, you only need to give the chapters that match RFC8446, and only output the chapters, for example: After giving you a function, you need to output: 1.1.1, which indicates that this code reflects section 1.1.1 in RFC8446.
Think about it in the following order:
1. Output function summary: Summarize the function in one sentence, focusing on the control flow of the function;
2. According to the function summary and the function itself, the chapter number corresponding to RFC8446 that the output function may comply with can have multiple chapter numbers;
Please give your thinking process step by step, and give the thinking result in json form at the end, json properties include four: function name, function summary, thinking process, code implementation involved in the RFC text chapter. Do not print attributes that are not mentioned;
Below is a specific example, you can use this specific example to further understand my requirements, but please note that your output should not be related to the example.
----
Function summary:
This function ParsePreSharedKeyExtension seems to be used to resolve the TLS 1.3 extensions with the pre Shared key. It checks the validity of the input parameters and then decodes and validates the pre-shared key extension in the TLS handshake message.

Thinking process:

The function first checks whether the input parameters are valid, which may involve formatting validation of the TLS message.
The function checks for certain status bits in the TLS context, which may be related to the TLS handshake state machine.
The function parses the pre-shared key extension, including the length and actual key data, which is involved in the processing of the TLS extension.
The function performs some checks related to session recovery, which may be related to the TLS session recovery mechanism.
The function finally sets errors and alerts based on the parsing results, which may be related to TLS's error handling and alerting mechanisms.
Corresponding RFC text sections:
Depending on the functionality of the function and RFC 8446 of TLS 1.3, the following sections may correspond:

4.2.11: Flow of the pre-shared key exchange mode.
4.2.9: Description of the key exchange protocol, possibly related to state checking in the function.
4.1.2: Structure of the TLS handshake message, possibly related to parameter checking in the function.
6.2: Description of TLS error alerts, possibly related to error handling in functions.
```json
{
name:CTls13ExtServer::ParsePreSharedKeyExtension;
function_summary:The function is used to parse the Pre-Shared Key extension in TLS 1.3, including parameter validation, state checks, extension decoding, and error handling;
thinking_process:The function first checks the validity of the input parameters, then decodes and verifies the Pre-Shared Key extension in the TLS handshake message. It also checks the state in the TLScontext, performs session resumption checks, and sets errors and alerts at the end;
RFC_text_sections_involved: [" 4.2.11 ", "4.2.9", "4.1.2", "6.2"]
}
```
----
Note that the result is returned in English, and there are only four properties in the json file. The functions you have to deal with are as follows:'''


temparture = 0
# 调用GPT-4 API的函数
def ask_GPT4(system_intel, prompt,temperature): 
    result = openai.ChatCompletion.create(model="gpt-4",
                                 messages=[{"role": "system", "content": system_intel},
                                           {"role": "user", "content": prompt}],
                                 temperature=temperature)
    return result['choices'][0]['message']['content']


# 函数用于从文件名中提取ID号
def extract_id(filename):
    match = re.match(r"id-(\d+)\.c", filename)
    return int(match.group(1)) if match else None

# 函数用于处理单个C文件
def process_file(filename):
    function_id = extract_id(filename)
    if function_id is None:
        print(f"Filename {filename} does not match the expected pattern.")
        return

    with open(filename, 'r') as file:
        code_content = file.read()
        analysis_result = ask_GPT4(system_intel, prompt+code_content,temparture)

    # 将分析结果写入到answer文件中
    with open(f"id-{function_id}-answer.txt", 'w') as answer_file:
        json.dump(analysis_result, answer_file, indent=2)

    print(f"Analysis result for {filename} saved to id-{function_id}-answer.txt")

# 遍历当前目录下的所有文件
for filename in os.listdir('.'):
    if filename.startswith("id-") and filename.endswith(".c"):
        process_file(filename)

import os
import re
import json

# 获取当前目录下的所有文件和文件夹名称
files = os.listdir('.')

import re
for filename in files:
    # 检查文件扩展名是否为 '.txt'
    if filename.endswith('.txt'):
        # 构造完整的文件路径
        file_path = os.path.join('.', filename)
        
        # 读取文件内容
        with open(file_path, 'r') as file:
            content = file.read()
        # 使用正则表达式提取 JSON 部分
        json_pattern = r'```json(.*?)```'
        match = re.search(json_pattern, content, re.DOTALL)

        if match:
            json_content = match.group(1)
            
            # 去掉 JSON 字符串中的所有换行符 '\n'
            json_content = json_content.replace('\n', '')

            # 保存为 txt 文件
            with open('result.json', 'a') as file:
                file.write(json_content+'\n')
        else:
            print("No JSON content found in the file.")
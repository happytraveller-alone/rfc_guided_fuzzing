import subprocess
import json
import os

from ProcessFuncSet import *

'''
Collected\\ARP\\1.pcapng
Collected\\DNS\\1\\1.pcapng
Collected\\DNS\\2\\1.pcapng
Collected\\TLS\\1.pcapng
'''


packetdataloc = '''data\\1.pcapng'''
# 使用tshark生成JSON文件的命令
command = '''tshark.exe -r ''' + packetdataloc + ''' -Y "tls && tcp.stream == 30" -V -T jsonraw > output.txt'''

# TLS: -Y "tls && tcp.stream == 30"
# IPv6：ipv6 && ipv6.addr eq 2001:da8:a000:ab23::10
# 筛选制定No号的包：-Y "frame.number == 34 || frame.number == 51"
# 执行命令
subprocess.run(command, shell=True)

dbname = ["tls.handshake.extensions_alpn_str_len_raw","tls.handshake.extensions_alpn_str_raw",
          "tls.handshake.extensions.supported_version_raw","tls.handshake.sig_hash_algs_raw"]


# 读取txt文件
with open("output.txt", 'r',encoding="utf-8") as file:
    data = file.read()

def match_and_append_count(strings, data):
    for string in strings:
        count = 0  # 用于记录当前字符串出现的次数
        start = 0  # 用于记录搜索的起始位置

        # 循环直到找不到更多的匹配项
        while start < len(data):
            pos = data.find(string, start)  # 查找字符串的位置
            if pos == -1:
                break  # 如果没有找到，跳出循环

            count += 1  # 每次找到匹配项，计数加1
            data = data[:pos + len(string)] + str(count) + data[pos + len(string):]
            start = pos + len(string) + 1  # 更新搜索的起始位置，跳过添加的计数

    return data

data = match_and_append_count(dbname, data)

data = json.loads(data) # 变成json形式

with open('output.json', 'w', encoding='utf-8') as file: # 输出到文件当中
    json.dump(data, file, indent=4, ensure_ascii=False)
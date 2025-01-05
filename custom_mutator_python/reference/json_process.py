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
command = '''tshark.exe -r ''' + packetdataloc + ''' -Y "frame.number == 42" -V -T jsonraw > output.txt'''

# TLS: -Y "tls && tcp.stream == 30"
# IPv6：ipv6 && ipv6.addr eq 2001:da8:a000:ab23::10
# 筛选制定No号的包：-Y "frame.number == 34 || frame.number == 51"
# 执行命令
subprocess.run(command, shell=True)

dbname = ["tls.handshake.extensions_alpn_str_len_raw","tls.handshake.extensions_alpn_str_raw",
          "tls.handshake.extensions.supported_version_raw","tls.handshake.sig_hash_alg_raw",
          "tls.handshake.extensions_supported_group_raw"]


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


for i in range(len(data) - 1, -1, -1):
    data[i] = data[i]["_source"]["layers"]
    if 'tcp' in data[i]:
        item = data[i]["tcp"]
        if "tcp.segment_data_raw" in item and 'tls' in data[i]:
            if "tls.segment.data_raw" in data[i]["tls"]:
                data.pop(i)
    # if "tls.segment.data_raw" in data[i]:
    #     data.pop(i)

for i in range(len(data)):
    # data[i] = data[i]["_source"]["layers"]

    str2list(data[i])
    # 物理层
    del data[i]["frame"] # 删除物理层
    del data[i]["frame_raw"]
    
    # 避免解析树
    remove_keys_with_tree(data[i],"tree")

    
    # IP AND IPv6，不区分，全都适用，适用于ESP头部，IPv6
    if "ip" in data[i]:
        remove_keys_with_tree(data[i],"ip.addr") #IP多出来的host
        remove_keys_with_tree(data[i],"ip.src_host") #IP多出来的host
        remove_keys_with_tree(data[i],"ip.host") #IP多出来的addr
        remove_keys_with_tree(data[i],"ip.dst_host") #IP多出来的port
        
    if "ipv6" in data[i]:
        remove_keys_with_tree(data[i],"ip.version")
        # tmpstr = data[i]["ipv6"]["ipv6.version_raw"][0]
        # tmpstr2 = data[i]["ipv6"]["ipv6.plen_raw"][0]

        # data[i]["ipv6"]["ipv6.version_raw"] = tmpstr[0]
        # data[i]["ipv6"]["ipv6.tclass_raw"] = str(tmpstr[1])  + data[i]["ipv6"]["ipv6.tclass_raw"][0]

        remove_keys_with_tree(data[i],"ipv6.addr")# ipv6.addr
        remove_keys_with_tree(data[i],"ipv6.src_host")# ipv6.src_host
        remove_keys_with_tree(data[i],"ipv6.host")# ipv6.host
        remove_keys_with_tree(data[i],"ipv6.dst_host")# ipv6.dst_host
        remove_keys_with_tree(data[i],"ipv6.src_slaac_mac")# ipv6.src_slaac_mac_raw
        remove_keys_with_tree(data[i],"ipv6.slaac_mac")# ipv6.slaac_mac_raw
        remove_keys_with_tree(data[i],"dst_slaac_mac")
    
    if "udp" in data[i]:
        remove_keys_with_tree(data[i],"udp.port") #udp多出来的port
    if "tcp" in data[i]:
        remove_keys_with_tree(data[i],"tcp.port") #udp多出来的port
        remove_keys_with_tree(data[i],"tcp.completeness") #udp多出来的port
        remove_keys_with_tree(data[i],"tcp.window_size_value") #udp多出来的port
        remove_keys_with_tree(data[i],"tcp.window_size_scalefactor") #udp多出来的port
        remove_keys_with_tree(data[i],"tcp.segment") #udp多出来的port
    if "dns" in data[i]:
        remove_keys_with_tree(data[i],"Extraneous data")
    if "icmpv6" in data[i]:
        remove_keys_with_tree(data[i],"icmpv6.resp_to")
        remove_keys_with_tree(data[i],"icmpv6.resptime")
    remove_keys_with_tree(data[i],"_ws.malformed")
    
    
    dropempty(data[i])
    simplify_dict(data[i])

    list2byte(data[i])
    keep_keys_with_raw(data[i])

    dropempty(data[i])
    # dropempty(data[i])

tls_file = "result.txt"
with open(tls_file, 'w') as tls_file:
    json.dump(data, tls_file, indent=4)

flag = 1

e_raw(flag,"_raw")

print("The operation is over")

# os.remove('output.txt')
os.remove('result.txt')

# 假设你的JSON文件名为data.json，位于当前目录下
layers_json_file_path = 'layers.json'
result_json_file_path = 'result.json'

# 输入是json，输出是文件夹，文件是报文
save_dicts_to_files(layers_json_file_path,"layers")
save_dicts_to_files(result_json_file_path,"result")

print("The output is in 'OutPut' folder, the number of file is the order of the packet in the stream.")


# IPv6

import io
import sys
import ast
from scapy.all import *

def hex2byte(hex_stream):
    # 创建一个StringIO对象来捕获输出
    output = io.StringIO()

    # 保存原始的stdout
    original_stdout = sys.stdout

    # 将stdout重定向到StringIO对象
    sys.stdout = output

    hex_stream = r'\x' + r'\x'.join([hex_stream[i:i+2] for i in range(0, len(hex_stream), 2)])
    print(hex_stream)
    # 将stdout重定向回原始的stdout
    sys.stdout = original_stdout

    # 从StringIO对象中获取输出内容
    captured_output = str(output.getvalue())
    output.close()

    captured_output = "b'" + captured_output.replace("\n","") + "'"

    captured_output = ast.literal_eval(captured_output)

    hex_stream = captured_output
    return hex_stream 

hex_stream = '00018100000100010000000003777777076578616d706c6503636f6d000001000103777777076578616d706c6503636f6d0000010001000007080004c0a80204'

hex_stream = hex2byte(hex_stream)
# 定义目标IPv6地址
target_ip = "2001:db8:cafe:1::10"

# 构建IPv6报文
ipv6 = IPv6(dst=target_ip)

# 组合IPv6和Fragment Header
packet = ipv6 / hex_stream

# 发送报文
send(packet)

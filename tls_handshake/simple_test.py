# import socket

# # 创建一个TCP/IP socket
# sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# # 连接到服务器
# server_address = ('192.168.110.128', 443)  # 将 'example.com' 和端口 443 替换为实际的目标服务器
# sock.connect(server_address)

# # 定义各部分的内容
# record_layer = '16 03 03'  # Content Type: Handshake (22), Version: TLS 1.2 (0x0303)
# handshake_type = '01'  # Handshake Type: Client Hello (1)
# client_version = '03 03'  # Version: TLS 1.2 (0x0303)
# random_bytes = (
#     'b4 9d 4c 5a 90 9a 4d 84 c8 f1 1a c5 4c 71 d4 70'
#     'e2 bf 67 a6 b8 d0 de ca b0 e9 f2 27 e7 e7 3d 04'
# )
# session_id = '00'  # Session ID Length: 0
# cipher_suites = '00 02 13 01'  # Cipher Suites Length: 2, Cipher Suite: TLS_AES_128_GCM_SHA256 (0x1301)
# compression_methods = '01 00'  # Compression Methods Length: 1, Compression Method: null (0)

# # Extensions
# supported_versions = '00 2B 00 03 02 03 04'  # supported_versions Extension
# supported_groups = '00 0A 00 04 00 02 00 1D'  # supported_groups Extension
# signature_algorithms = '00 0D 00 06 00 04 04 03 08 04'  # signature_algorithms Extension
# key_share = (
#     '00 33 00 26'  # key_share Extension Header
#     '00 24'        # Client Key Share Length: 36
#     '00 1D'        # Group: x25519 (29)
#     '00 20'        # Key Exchange Length: 32
#     '88 47 b5 30 a1 bc cb cc 7a 76 dc d0 9f 8f 9c e8'  # Public Key (前16字节)
#     'c7 4a ea 7d 9c ff f8 dd 79 34 a1 be c2 64 6a 65'  # Public Key (后16字节)
# )

# # 计算各部分的长度
# extensions = supported_versions + supported_groups + signature_algorithms + key_share
# extensions_length = len(bytes.fromhex(extensions))

# handshake_body = (
#     client_version + random_bytes + session_id + cipher_suites + compression_methods
#     + '{:04x}'.format(extensions_length).replace(' ', '')
#     + extensions
# )
# handshake_length = len(bytes.fromhex(handshake_body))

# # 计算握手协议的总长度
# tls_client_hello = bytes.fromhex(
#     record_layer
#     + '{:04x}'.format(handshake_length + 4).replace(' ', '')  # TLS Record Layer Length
#     + handshake_type
#     + '{:06x}'.format(handshake_length).replace(' ', '')  # Handshake Length
#     + handshake_body
# )

# # 发送TLS ClientHello数据包
# sock.send(tls_client_hello)

# # 接收服务器响应
# response = sock.recv(8192)  # 接收4096字节的响应
# print(response.hex())  # 打印响应的十六进制表示

# # 关闭socket连接
# sock.close()

client_hello = (
    b'\x16\x03\x01\x02\x00\x01\x00\x01\xfc\x03\x03\xd6\x2e\x55\x81\xf5'
    b'\xae\x21\x7f\x11\x3b\x50\xe7\x08\xdc\x12\x2b\x6b\x1d\x8c\xb1\x8f'
    b'\x4d\x1f\x6e\xfa\x01\x9a\x1b\x5f\xca\x33\xed\x20\x59\x6b\xa7\x09'
    b'\xc6\x2e\xae\xa3\x14\x2c\xfc\xac\x0c\xa1\xcd\xba\xec\x3f\x4b\x17'
    b'\xb8\x8e\x0d\x77\x8c\xde\x87\xb4\xd8\xb8\xcd\x2a\x00\x24\x13\x02'
    b'\x13\x03\x13\x01\xc0\x2c\xc0\x30\xc0\x2b\xc0\x2f\xcc\xa9\xcc\xa8'
    b'\xc0\x24\xc0\x28\xc0\x23\xc0\x27\x00\x9f\x00\x9e\x00\x6b\x00\x67'
    b'\x00\xff\x01\x00\x01\x8f\x00\x00\x00\x0e\x00\x0c\x00\x00\x09\x6c'
    b'\x6f\x63\x61\x6c\x68\x6f\x73\x74\x00\x0b\x00\x04\x03\x00\x01\x02'
    b'\x00\x0a\x00\x16\x00\x14\x00\x1d\x00\x17\x00\x1e\x00\x19\x00\x18'
    b'\x01\x00\x01\x01\x01\x02\x01\x03\x01\x04\x00\x23\x00\x00\x00\x16'
    b'\x00\x00\x00\x17\x00\x00\x00\x0d\x00\x2a\x00\x28\x04\x03\x05\x03'
    b'\x06\x03\x08\x07\x08\x08\x08\x09\x08\x0a\x08\x0b\x08\x04\x08\x05'
    b'\x08\x06\x04\x01\x05\x01\x06\x01\x03\x03\x03\x01\x03\x02\x04\x02'
    b'\x05\x02\x06\x02\x00\x2b\x00\x05\x04\x03\x04\x03\x03\x00\x2d\x00'
    b'\x02\x01\x01\x00\x33\x00\x26\x00\x24\x00\x1d\x00\x20\x20\xe1\xf7'
    b'\x8c\x83\xfa\x50\xc5\x6e\x27\xd6\x55\xff\xd6\xbd\x06\x53\x08\xa9'
    b'\xd3\x88\xf6\x61\x93\x89\xdc\x1b\x55\x7e\xe5\x27\x16\x00\x15\x00'
    b'\xe4\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
    b'\x00\x00\x00\x00'
)

import socket

# 定义服务器地址和端口
server_ip = "192.168.110.128"
server_port = 443
timeout = 10

def send_client_hello(server_ip, server_port, client_hello):
    """通过 socket 发送 ClientHello 报文"""
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(timeout)
    sock.connect((server_ip, server_port))
    print(f"Connected to {server_ip}:{server_port}")

    # 发送 ClientHello 报文
    sock.send(client_hello)
    print("ClientHello sent. Waiting for response...")

    try:
        response = sock.recv(4096)  # 尝试接收服务器的响应
        print(f"Received response from server:\n{response.hex()}")
    except socket.timeout:
        print("No response from server within timeout period.")
    finally:
        sock.close()

# 发送转换后的 ClientHello 报文
send_client_hello(server_ip, server_port, client_hello)

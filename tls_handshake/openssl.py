import socket
import struct
import os

# 定义服务器地址和端口
server_ip = "192.168.110.128"
server_port = 443
timeout = 10

def create_client_hello():
    """根据图片构建 ClientHello 报文"""
    # TLS Record Layer
    content_type = b'\x16'  # Handshake
    tls_version = b'\x03\x04'  # TLS 1.2 version
    record_length = b'\x00\x72'  # TLS Record Layer Length (114 bytes)

    # Handshake Protocol
    handshake_type = b'\x01'  # ClientHello
    handshake_length = b'\x00\x00\x6e'  # ClientHello message length (114 bytes)
    client_version = b'\x03\x03'  # TLS 1.2 for backward compatibility

    # 32 Bytes Random Data
    random_data = (
    b'\x55\x55\x55\x55\x55\x55\x55\x55'
    b'\x55\x55\x55\x55\x55\x55\x55\x55'
    b'\x55\x55\x55\x55\x55\x55\x55\x55'
    b'\x55\x55\x55\x55\x55\x55\x55\x55'
    )
     # 用 0x55 填充的 32 字节随机数

    # Session ID Length
    session_id_length = b'\x00'  # Session ID 长度为 0

    # Cipher Suites
    cipher_suites_length = b'\x00\x02'  # Cipher Suite Length
    cipher_suites = b'\x13\x01'  # Cipher Suite: TLS_AES_128_GCM_SHA256

    # Compression Methods
    compression_methods_length = b'\x01'  # Compression Methods Length
    compression_methods = b'\x00'  # No compression

    # Extensions
    extensions_length = b'\x00\x43'  # Extensions Length (67 bytes)

    # Supported Versions Extension
    supported_version_type = b'\x00\x2b'
    supported_version_length = b'\x00\x03'
    supported_versions_len = b'\x02'
    supported_version = b'\x03\x04'  # TLS 1.3

    # Supported Groups Extension
    supported_groups_type = b'\x00\x0a'
    supported_groups_length = b'\x00\x04'
    supported_groups_len = b'\x00\x02'
    group = b'\x00\x1d'  # x25519

    # Signature Algorithms Extension
    signature_algorithm_type = b'\x00\x0d'
    signature_algorithm_length = b'\x00\x06'
    signature_algorithms_len = b'\x00\x04'
    algorithms = b'\x04\x03\x08\x03'  # rsa_pss_rsae_sha256, ecdsa_secp256r1_sha256

    # Key Share Extension
    key_share_type = b'\x00\x33'
    key_share_extension_length = b'\x00\x26'
    
    key_share_length = b'\x00\x24'
    key_share_group = b'\x00\x1d'  # x25519
    key_exchange_length = b'\x00\x20'  # 24 字节公钥
    key_exchange = b'\x88\x00\x1d\x00\x17\x00\x1e\x00\x19\x00\x18\x01\x00\x01\x01\x01\x02\x01\x03\x01\x04\x00\x23\x00\x00\x00\x16\x00\x00\x00\x17\x65'  # 填充 0x00 的 24 字节公钥数据
    # key_exchange = os.urandom(32)

    # Construct Extensions
    extensions = (supported_version_type + supported_version_length + supported_versions_len + supported_version +
                  supported_groups_type + supported_groups_length + supported_groups_len + group +
                  signature_algorithm_type + signature_algorithm_length + signature_algorithms_len + algorithms +
                  key_share_type + key_share_extension_length +key_share_length + key_share_group + key_exchange_length + key_exchange)

    # Construct the full ClientHello message
    client_hello = (client_version + random_data + session_id_length +
                    cipher_suites_length + cipher_suites +
                    compression_methods_length + compression_methods +
                    extensions_length + extensions)

    # Calculate the TLS Handshake Message
    handshake_message = handshake_type + handshake_length + client_hello
    tls_record = content_type + tls_version + record_length + handshake_message
    return tls_record

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

# 构建并发送 ClientHello
client_hello = create_client_hello()
print(client_hello.hex())
send_client_hello(server_ip, server_port, client_hello)


# 16 03 01 02 00 01 00 01 fc 03 03 d6 2e 55 81 f5
# ae 21 7f 11 3b 50 e7 08 dc 12 2b 6b 1d 8c b1 8f
# 4d 1f 6e fa 01 9a 1b 5f ca 33 ed 20 59 6b a7 09
# c6 2e ae a3 14 2c fc ac 0c a1 cd ba ec 3f 4b 17
# b8 8e 0d 77 8c de 87 b4 d8 b8 cd 2a 00 24 13 02
# 13 03 13 01 c0 2c c0 30 c0 2b c0 2f cc a9 cc a8
# c0 24 c0 28 c0 23 c0 27 00 9f 00 9e 00 6b 00 67
# 00 ff 01 00 01 8f 00 00 00 0e 00 0c 00 00 09 6c
# 6f 63 61 6c 68 6f 73 74 00 0b 00 04 03 00 01 02
# 00 0a 00 16 00 14 00 1d 00 17 00 1e 00 19 00 18
# 01 00 01 01 01 02 01 03 01 04 00 23 00 00 00 16
# 00 00 00 17 00 00 00 0d 00 2a 00 28 04 03 05 03
# 06 03 08 07 08 08 08 09 08 0a 08 0b 08 04 08 05
# 08 06 04 01 05 01 06 01 03 03 03 01 03 02 04 02
# 05 02 06 02 00 2b 00 05 04 03 04 03 03 00 2d 00
# 02 01 01 00 33 00 26 00 24 00 1d 00 20 20 e1 f7
# 8c 83 fa 50 c5 6e 27 d6 55 ff d6 bd 06 53 08 a9
# d3 88 f6 61 93 89 dc 1b 55 7e e5 27 16 00 15 00
# e4 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
# 00 00 00 00 00

import socket

# 创建一个TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接到服务器
server_address = ('192.168.24.135', 443)  # 替换为实际的目标服务器
sock.connect(server_address)

# 定义各部分的内容

# TLS Record Layer
record_layer_content_type = '16'  # Content Type: Handshake (22)
record_layer_version = '0303'  # Version: TLS 1.2 (0x0303)

# Handshake Protocol Header
handshake_type = '01'  # Handshake Type: Client Hello (1)
client_version = '0303'  # Version: TLS 1.2 (0x0303)

# Client Hello Random
random_bytes = (
    '9a09c4cc24c20d0a8b285bd2a66245ca'
    '071d76c9eeadc344a0a4e0ceff7ddcb8'
)

# Session ID
session_id = (
    '20d6d98b33447e720b0ef055257d0d30'
    'cf4215f6bca21fca13705ffc683c4573'
)  # Session ID: 32 bytes

# Cipher Suites
cipher_suites = '13021303130100ff'  # Cipher Suites (4 suites)

# Compression Methods
compression_methods = '00'  # Compression Method: null (0)

# Extensions

# ec_point_formats Extension
ec_point_formats_type = '000b'  # Type: ec_point_formats (11)
ec_point_formats_data = '000102'  # EC point formats data
# EC point formats Length: 3
# EC point formats: uncompressed (0), ansiX962_compressed_prime (1), ansiX962_compressed_char2 (2)

# supported_groups Extension
supported_groups_type = '000a'  # Type: supported_groups (10)
supported_groups_list = '001d0017001e0019001801000101010201030104'
# Supported Groups List Length: 20
# Supported Groups (10 groups)

# session_ticket Extension
session_ticket_type = '0023'  # Type: session_ticket (35)
session_ticket_data = ''  # No data for session_ticket

# encrypt_then_mac Extension
encrypt_then_mac_type = '0016'  # Type: encrypt_then_mac (22)
encrypt_then_mac_data = ''  # No data for encrypt_then_mac

# extended_master_secret Extension
extended_master_secret_type = '0017'  # Type: extended_master_secret (23)
extended_master_secret_data = ''  # No data for extended_master_secret

# signature_algorithms Extension
signature_algorithms_type = '000d'  # Type: signature_algorithms (13)
signature_algorithms_list = (
    '040305030603080708080809080a080b080408050806040105010601'
)
# Signature Hash Algorithms Length: 28
# Signature Hash Algorithms (14 algorithms)

# supported_versions Extension
supported_versions_type = '002b'  # Type: supported_versions (43)
supported_versions_data = '0304'  # Supported Version: TLS 1.3 (0x0304)
# Supported Versions length: 2

# psk_key_exchange_modes Extension
psk_key_exchange_modes_type = '002d'  # Type: psk_key_exchange_modes (45)
psk_key_exchange_modes_data = '01'  # PSK with (EC)DHE key establishment (psk_dhe_ke) (1)
# PSK Key Exchange Modes Length: 1

# key_share Extension
key_share_type = '0033'  # Type: key_share (51)
key_share_entry_data = '001d00209386a66b3dda7a5987ca30f5a4ae823785ac87fa81e5c7b972a8e26abc5dd968'
# Key Share Entry: Group: x25519, Key Exchange length: 32
# Group: x25519 (29)
# Key Exchange: 9386a66b3dda7a5987ca30f5a4ae823785ac87fa81e5c7b972a8e26abc5dd968

# 计算长度的部分

# 计算Session ID长度
session_id_length = '{:02x}'.format(len(bytes.fromhex(session_id)))

# 计算Cipher Suites长度
cipher_suites_length = '{:04x}'.format(len(bytes.fromhex(cipher_suites)))

# 计算Compression Methods长度
compression_methods_length = '01'  # 固定为1

# 计算ec_point_formats长度
ec_point_formats_data_length = '{:02x}'.format(len(bytes.fromhex(ec_point_formats_data)))  # EC point formats length: 3
ec_point_formats_length = '{:04x}'.format(len(bytes.fromhex(ec_point_formats_data_length + ec_point_formats_data)))  # Total length of ec_point_formats
ec_point_formats = ec_point_formats_type + ec_point_formats_length + ec_point_formats_data_length + ec_point_formats_data

# 计算supported_groups长度
supported_groups_list_length = '{:04x}'.format(len(bytes.fromhex(supported_groups_list)))  # Supported Groups List Length
supported_groups_length = '{:04x}'.format(len(bytes.fromhex(supported_groups_list_length + supported_groups_list)))  # Total length of supported_groups extension
supported_groups = supported_groups_type + supported_groups_length + supported_groups_list_length + supported_groups_list

# 计算signature_algorithms长度
signature_algorithms_list_length = '{:04x}'.format(len(bytes.fromhex(signature_algorithms_list)))  # Signature Hash Algorithms Length
signature_algorithms_length = '{:04x}'.format(len(bytes.fromhex(signature_algorithms_list_length + signature_algorithms_list)))  # Total length of signature_algorithms extension
signature_algorithms = signature_algorithms_type + signature_algorithms_length + signature_algorithms_list_length + signature_algorithms_list

# 计算supported_versions长度
supported_versions_supported_length = '{:02x}'.format(len(bytes.fromhex(supported_versions_data)))  # Supported Versions length: 2
supported_versions_length = '{:04x}'.format(len(bytes.fromhex(supported_versions_supported_length + supported_versions_data)))  # Total length of supported_versions extension
supported_versions = supported_versions_type + supported_versions_length + supported_versions_supported_length + supported_versions_data

# 计算psk_key_exchange_modes长度
psk_key_exchange_modes_data_length = '{:02x}'.format(len(bytes.fromhex(psk_key_exchange_modes_data)))
psk_key_exchange_modes_length = '{:04x}'.format(len(bytes.fromhex(psk_key_exchange_modes_data_length + psk_key_exchange_modes_data)))
psk_key_exchange_modes = psk_key_exchange_modes_type + psk_key_exchange_modes_length + psk_key_exchange_modes_data_length + psk_key_exchange_modes_data

# 正确的key_share长度计算逻辑
key_share_entry_length = '{:04x}'.format(len(bytes.fromhex(key_share_entry_data)))  # Key Share Entry Length (32 bytes)
key_share_list_length = '{:04x}'.format(len(bytes.fromhex(key_share_entry_data)))  # Client Key Share Length (36 bytes, include group and length fields)
key_share_length = '{:04x}'.format(len(bytes.fromhex(key_share_list_length + key_share_entry_data)))  # Total length of key_share extension (38 bytes)
key_share = key_share_type + key_share_length + key_share_list_length + key_share_entry_data

# 计算session_ticket长度
session_ticket_length = '{:04x}'.format(len(bytes.fromhex(session_ticket_data)))
session_ticket = session_ticket_type + session_ticket_length

# 计算encrypt_then_mac长度
encrypt_then_mac_length = '{:04x}'.format(len(bytes.fromhex(encrypt_then_mac_data)))
encrypt_then_mac = encrypt_then_mac_type + encrypt_then_mac_length

# 计算extended_master_secret长度
extended_master_secret_length = '{:04x}'.format(len(bytes.fromhex(extended_master_secret_data)))
extended_master_secret = extended_master_secret_type + extended_master_secret_length

# 汇总所有的扩展字段
extensions = (
    ec_point_formats +
    supported_groups +
    session_ticket +
    encrypt_then_mac +
    extended_master_secret +
    signature_algorithms +
    supported_versions +
    psk_key_exchange_modes +
    key_share
)

# 动态计算Extensions Length
extensions_length = '{:04x}'.format(len(bytes.fromhex(extensions)))

# 构建handshake_body并计算其长度
handshake_body = (
    client_version +
    random_bytes +
    session_id_length + session_id +
    cipher_suites_length + cipher_suites +
    compression_methods_length + compression_methods +
    extensions_length + extensions
)
handshake_length = len(bytes.fromhex(handshake_body))

# 构建完整的ClientHello消息并计算TLS记录层的总长度
tls_client_hello = bytes.fromhex(
    record_layer_content_type +
    record_layer_version +
    '{:04x}'.format(handshake_length + 4) +  # TLS Record Layer Length
    handshake_type +
    '{:06x}'.format(handshake_length) +  # Handshake Length
    handshake_body
)

# 发送TLS ClientHello数据包
sock.send(tls_client_hello)
print("success send")
# 接收服务器响应
response = sock.recv(4096)  # 接收4096字节的响应
print(response.hex())  # 打印响应的十六进制表示

# 关闭socket连接
sock.close()
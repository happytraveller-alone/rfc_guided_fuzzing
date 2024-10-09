import socket

# 创建一个TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接到服务器
server_address = ('192.168.115.155', 443)  # 替换为实际的目标服务器
sock.connect(server_address)

# 定义各部分的内容
record_layer = '16 03 03'  # Content Type: Handshake (22), Version: TLS 1.2 (0x0303)
handshake_type = '01'  # Handshake Type: Client Hello (1)
client_version = '03 03'  # Version: TLS 1.2 (0x0303)
random_bytes = (
    '9a09c4cc24c20d0a8b285bd2a66245ca'
    '071d76c9eeadc344a0a4e0ceff7ddcb8'
)
session_id = (
    '20d6d98b33447e720b0ef055257d0d30'
    'cf4215f6bca21fca13705ffc683c4573'
)  # Session ID: 32 bytes

# 动态计算Session ID Length
session_id_length = '{:02x}'.format(len(bytes.fromhex(session_id)))

cipher_suites = '13021303130100ff'  # Cipher Suites
# 动态计算Cipher Suites Length
cipher_suites_length = '{:04x}'.format(len(bytes.fromhex(cipher_suites)))

compression_methods = '00'  # Compression Method: null (0)
compression_methods_length = '01'  # Compression Methods Length: 1

# 构造所有扩展，使用Python计算每个扩展的长度字段

# ec_point_formats Extension
ec_point_formats_data = '000102'  # EC point formats data
ec_point_formats_data_length = '{:02x}'.format(len(bytes.fromhex(ec_point_formats_data)))  # EC point formats length: 3
ec_point_formats_length = '{:04x}'.format(len(bytes.fromhex(ec_point_formats_data_length + ec_point_formats_data)))  # Total length of ec_point_formats extension (4)
ec_point_formats = '000b' + ec_point_formats_length + ec_point_formats_data_length + ec_point_formats_data

# supported_groups Extension
supported_groups_data = '001d0017001e0019001801000101010201030104'
supported_groups_list_length = '{:04x}'.format(len(bytes.fromhex(supported_groups_data)))  # Supported Groups List Length (20)
supported_groups_length = '{:04x}'.format(len(bytes.fromhex(supported_groups_list_length + supported_groups_data)))  # Total length of supported_groups extension (22)
supported_groups = '000a' + supported_groups_length + supported_groups_list_length + supported_groups_data

# session_ticket Extension
session_ticket = '00230000'  # No data for session_ticket

# encrypt_then_mac Extension
encrypt_then_mac = '00160000'  # No data for encrypt_then_mac

# extended_master_secret Extension
extended_master_secret = '00170000'  # No data for extended_master_secret

# signature_algorithms Extension
signature_algorithms_data = (
    '040305030603080708080809080a080b080408050806040105010601'
)
signature_algorithms_data_length = '{:04x}'.format(len(bytes.fromhex(signature_algorithms_data)))  # Signature Hash Algorithms Length (28)
signature_algorithms_length = '{:04x}'.format(len(bytes.fromhex(signature_algorithms_data_length + signature_algorithms_data)))  # Total length of signature_algorithms extension (30)
signature_algorithms = '000d' + signature_algorithms_length + signature_algorithms_data_length + signature_algorithms_data

# supported_versions Extension
supported_versions_data = '0304'  # Supported Version: TLS 1.3 (0x0304)
supported_versions_supported_length = '{:02x}'.format(len(bytes.fromhex(supported_versions_data)))  # Supported Versions length: 2
supported_versions_length = '{:04x}'.format(len(bytes.fromhex(supported_versions_supported_length + supported_versions_data)))  # Total length of supported_versions extension (3)
supported_versions = '002b' + supported_versions_length + supported_versions_supported_length + supported_versions_data

# psk_key_exchange_modes Extension
psk_key_exchange_modes_data = '01'  # PSK with (EC)DHE key establishment (psk_dhe_ke) (1)
psk_key_exchange_modes_data_length = '{:02x}'.format(len(bytes.fromhex(psk_key_exchange_modes_data)))  # PSK Key Exchange Modes Length: 1
psk_key_exchange_modes_length = '{:04x}'.format(len(bytes.fromhex(psk_key_exchange_modes_data_length + psk_key_exchange_modes_data)))  # Total length of psk_key_exchange_modes extension (2)
psk_key_exchange_modes = '002d' + psk_key_exchange_modes_length + psk_key_exchange_modes_data_length + psk_key_exchange_modes_data

# key_share Extension
key_share_entry_data = '001d00209386a66b3dda7a5987ca30f5a4ae823785ac87fa81e5c7b972a8e26abc5dd968'
key_share_entry_length = '{:04x}'.format(len(bytes.fromhex(key_share_entry_data)))  # Key Share Entry Length (32 bytes)
client_key_share_length = '{:04x}'.format(len(bytes.fromhex(key_share_entry_data)))  # Client Key Share Length (36 bytes, include group and length fields)
key_share_length = '{:04x}'.format(len(bytes.fromhex(client_key_share_length + key_share_entry_data)))  # Total length of key_share extension (38 bytes)
key_share = '0033' + key_share_length + client_key_share_length + key_share_entry_data

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
    record_layer.replace(' ', '') +
    '{:04x}'.format(handshake_length + 4) +  # TLS Record Layer Length
    handshake_type +
    '{:06x}'.format(handshake_length) +  # Handshake Length
    handshake_body
)

# 发送TLS ClientHello数据包
sock.send(tls_client_hello)

# 接收服务器响应
response = sock.recv(4096)  # 接收4096字节的响应
print(response.hex())  # 打印响应的十六进制表示

# 关闭socket连接
sock.close()
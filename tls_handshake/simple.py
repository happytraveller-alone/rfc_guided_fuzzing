import socket
import ssl
import struct
import os

def send_client_hello(sock):
    # TLS record layer
    content_type = b'\x16'  # Handshake
    version = b'\x03\x03'  # TLS 1.2
    
    # Handshake layer
    handshake_type = b'\x01'  # ClientHello
    client_version = b'\x03\x03'  # TLS 1.2
    client_random = os.urandom(32)  # 32 bytes of random data (simplified here)
    session_id = b'\x00'  # Empty session ID
    
    # Cipher suites (offering TLS_AES_128_GCM_SHA256)
    cipher_suites = b'\x00\x06\x13\x01\x13\x02\x13\x03'  # TLS_AES_128/256_GCM_SHA256/384
    
    # Compression methods
    compression_methods = b'\x01\x00'
    
    # Extensions
    extensions = (
        # Supported versions extension
        b'\x00\x2b\x00\x03\x02\x03\x04'
        # Supported groups extension (x25519)
        b'\x00\x0a\x00\x04\x00\x02\x00\x1d'
        # Signature algorithms extension
        b'\x00\x0d\x00\x1e\x00\x1c\x04\x03\x05\x03\x06\x03\x08\x07\x08\x08\x08\x09\x08\x0a\x08\x0b\x08\x04\x08\x05\x08\x06\x04\x01\x05\x01\x06\x01'
    )
    
    extensions_length = struct.pack('!H', len(extensions))
    
    handshake_body = (
        client_version + client_random + session_id +
        cipher_suites + compression_methods +
        extensions_length + extensions
    )
    
    handshake_length = struct.pack('!I', len(handshake_body))[1:]  # 3 bytes
    handshake = handshake_type + handshake_length + handshake_body
    
    record_length = struct.pack('!H', len(handshake))
    client_hello = content_type + version + record_length + handshake
    
    sock.send(client_hello)

def receive_server_response(sock):
    # Receive the record layer header
    record_header = sock.recv(5)
    if len(record_header) != 5:
        return None
    
    content_type, version, length = struct.unpack('!BHH', record_header)
    
    # Receive the handshake message
    handshake_data = sock.recv(length)
    if len(handshake_data) != length:
        return None
    
    handshake_type = handshake_data[0]
    
    if handshake_type == 2:
        print("Received ServerHello")
        return "ServerHello"
    elif handshake_type == 6:
        print("Received HelloRetryRequest")
        return "HelloRetryRequest"
    else:
        print(f"Received unexpected handshake type: {handshake_type}")
        return None

# 创建一个TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 连接到服务器
server_address = ('192.168.110.128', 443)

try:
    sock.connect(server_address)
    print(f"Connected to {server_address}")
    
    # 发送ClientHello
    send_client_hello(sock)
    print("Sent ClientHello")
    
    # 接收服务器响应
    response = receive_server_response(sock)
    
    if response:
        print(f"TLS handshake initiated successfully. Received {response}.")
    else:
        print("Failed to receive a valid ServerHello or HelloRetryRequest.")

except socket.error as e:
    print(f"Socket error occurred: {e}")

finally:
    # 关闭socket连接
    sock.close()
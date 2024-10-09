import socket
import ssl

# 定义服务器地址和端口
server_address = ('192.168.110.128', 443)

# 创建一个TCP socket
sock = socket.create_connection(server_address)
print(f"Connected to server: {server_address}")

# 创建一个 SSL 上下文对象，并配置为 TLS
context = ssl.create_default_context()

# 可以选择禁用证书验证（仅用于测试目的，不推荐在生产环境中使用）
context.check_hostname = False
context.verify_mode = ssl.CERT_NONE

# 使用上下文包装 socket，并与服务器进行 TLS 握手
ssl_sock = context.wrap_socket(sock, server_hostname="localhost")
print("TLS handshake completed!")

# 发送一个简单的 HTTP GET 请求（作为 ClientHello 之后的测试内容）
http_request = b"GET / HTTP/1.0\r\nHost: localhost\r\n\r\n"
ssl_sock.sendall(http_request)
print("Sent HTTP request.")

# 接收服务器响应并输出
response = ssl_sock.recv(4096)
print("response received")
# print("Received response:\n", response.decode())

# 关闭连接
ssl_sock.close()

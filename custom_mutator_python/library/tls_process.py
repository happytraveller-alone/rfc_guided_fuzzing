import socket
# from typing import Tuple, Optional
from typing import Union, Optional
class RawTLSSender:
    """原始TLS报文发送器"""
    
    def __init__(self, host: str, port: int):
        self.host = host
        self.port = port
        self.socket = None
    @staticmethod
    def hex_str_to_bytes(data: Union[str, bytes]) -> bytes:
        """
        将输入数据转换为bytes类型
        :param data: 输入数据，可以是bytes或十六进制字符串
        :return: bytes类型数据
        :raises ValueError: 当输入数据格式不正确时
        """
        if isinstance(data, bytes):
            return data
        elif isinstance(data, str):
            # 移除所有空白字符
            hex_str = ''.join(data.split())
            try:
                return bytes.fromhex(hex_str)
            except ValueError:
                raise ValueError("无效的十六进制字符串格式")
        else:
            raise ValueError(f"不支持的数据类型: {type(data)}")
    def connect(self) -> None:
        """建立TCP连接"""
        try:
            self.socket = socket.create_connection((self.host, self.port))
        except Exception as e:
            raise ConnectionError(f"连接失败: {str(e)}")

    def send_receive(self, data: Union[str, bytes], buffer_size: int = 4096) -> bytes:
        """
        发送数据并接收响应
        :param data: 要发送的数据，可以是bytes或十六进制字符串
        :param buffer_size: 接收缓冲区大小
        :return: 接收到的响应数据
        :raises: RuntimeError 当连接未建立或发送接收失败时
                ValueError 当输入数据格式不正确时
        """
        if not self.socket:
            raise RuntimeError("未建立连接")

        try:
            # 转换数据为bytes类型
            send_data = self.hex_str_to_bytes(data)
            
            # 发送数据
            self.socket.send(send_data)
            
            # 接收响应
            response = self.socket.recv(buffer_size)
            return response
            
        except ValueError as e:
            raise ValueError(f"数据格式错误: {str(e)}")
        except Exception as e:
            raise RuntimeError(f"发送或接收失败: {str(e)}")

    # def close(self) -> None:
    #     """关闭连接"""
    #     if self.socket:
    #         try:
    #             self.socket.close()
    #         finally:
    #             self.socket = None

    def close(self) -> None:
        """关闭连接"""
        if self.socket:
            self.socket.close()
            self.socket = None

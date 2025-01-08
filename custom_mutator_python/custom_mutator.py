import logging
from pathlib import Path
from datetime import datetime, timedelta
from library.json_data import JsonData, AddType
from library.action_parser import ActionParser
from library.action_loader import ActionLoader
from library.message_parser import JsonFileProcessor
from library.tls_process import RawTLSSender
import socket
from collections import defaultdict
from typing import Dict, List, Tuple
from datetime import datetime
# from library.tls_checker import update_extension_length,verify_extension_length
def init_log():
    """初始化日志配置
    
    - 自动创建logs文件夹
    - 配置日志格式
    - 同时输出到控制台和文件
    """
    # 创建logs文件夹
    log_dir = Path("logs")
    log_dir.mkdir(exist_ok=True)
    
    # 创建日志文件路径 - 使用时间戳创建唯一的日志文件名
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    log_file = log_dir / f"app_{timestamp}.log"
    
    # 配置日志格式
    log_format = '%(asctime)s - %(levelname)s - %(message)s'
    
    # 配置日志处理器
    handlers = [
        # 控制台处理器
        logging.StreamHandler(),
        # 文件处理器
        logging.FileHandler(log_file, encoding='utf-8')
    ]
    
    # 配置日志基本参数
    logging.basicConfig(
        level=logging.INFO,
        format=log_format,
        handlers=handlers
    )
    
    logging.info(f"Log initialized. Log file: {log_file}")

def clear_logs_folder():
    """清空logs文件夹
    
    - 如果文件夹不存在则创建
    - 删除超过3小时的日志文件
    - 保留文件夹结构
    """
    log_dir = Path("logs")
    
    # 如果文件夹不存在则创建
    log_dir.mkdir(exist_ok=True)
    
    # 设置日志文件保留时间为3小时
    retention_minutes = 5
    current_time = datetime.now()
    
    # 删除旧文件
    file_count = 0
    for file in log_dir.iterdir():
        if file.is_file() and file.name.startswith("app_"):
            try:
                # 从文件名中提取时间戳
                file_timestamp = datetime.strptime(file.stem[4:], "%Y%m%d_%H%M%S")
                if current_time - file_timestamp > timedelta(minutes=retention_minutes):
                    file.unlink()
                    file_count += 1
            except (ValueError, OSError) as e:
                logging.warning(f"Could not process file {file}: {e}")
            
    logging.info(f"Cleared {file_count} old log files (older than {retention_minutes} minutes )")

def decimal_to_hex(decimal_num: int, min_digits: int = 1) -> str:
    """
    将十进制整数转换为十六进制字符串

    Args:
        decimal_num: 要转换的十进制整数
        min_digits: 最小输出位数（不足时前面补0）

    Returns:
        十六进制字符串（大写）

    Example:
        >>> decimal_to_hex(255)
        'FF'
        >>> decimal_to_hex(255, min_digits=4)
        '00FF'
    """
    if not isinstance(decimal_num, int) or decimal_num < 0:
        raise ValueError("Input must be a non-negative integer")
    
    if not isinstance(min_digits, int) or min_digits < 1:
        raise ValueError("min_digits must be a positive integer")
    
    # 转换为十六进制并去掉'0x'前缀
    hex_str = f"{decimal_num:X}"
    
    # 如果长度不足，前面补零
    if len(hex_str) < min_digits:
        hex_str = hex_str.zfill(min_digits)
    
    return hex_str

def initialize_test_data() -> dict:
    """初始化测试数据"""
    return {
        "field1": ["0x12", "0x34"],
        "field2": {
            "field2_sub1": ["0x56", "0x78"],
            "field2_sub2": ["0x9A", "0xBC"]
        },
        "field3": ["0xDE", "0xF0", "0x43", "0x21"],
    }

def test_json_data_operations(json_data: JsonData):
    """测试JSON数据的基本操作"""
    # 测试数组头部添加
    logging.info("Testing array head addition: Adding ['0xAA', '0xBB'] to the head of field1")
    logging.info(f"Before: field1 = {json_data.get_json_data_value(['field1'])}")
    json_data.json_data_value_head_add(["field1"], ["0xAA", "0xBB"])
    logging.info(f"After: field1 = {json_data.get_json_data_value(['field1'])}")

    # 测试数组尾部添加
    logging.info("Testing array tail addition: Adding ['0xCC', '0xDD'] to the tail of field3")
    logging.info(f"Before: field3 = {json_data.get_json_data_value(['field3'])}")
    json_data.json_data_value_tail_add(["field3"], ["0xCC", "0xDD"])
    logging.info(f"After: field3 = {json_data.get_json_data_value(['field3'])}")

    # 测试数组更新
    logging.info("Testing array update: Updating field2.field2_sub1 with ['0xEE', '0xFF']")
    logging.info(f"Before: field2.field2_sub1 = {json_data.get_json_data_value(['field2', 'field2_sub1'])}")
    json_data.json_data_value_update(["field2", "field2_sub1"], ["0xEE", "0xFF"])
    logging.info(f"After: field2.field2_sub1 = {json_data.get_json_data_value(['field2', 'field2_sub1'])}")

    # 测试数组删除
    logging.info("Testing array removal: Removing field2.field2_sub1")
    logging.info(f"Before: field2.field2_sub1 = {json_data.get_json_data_value(['field2', 'field2_sub1'])}")
    json_data.json_data_remove_pair(["field2", "field2_sub1"])
    logging.info("After: field2.field2_sub1 = (Removed)")

def test_dictionary_addition(json_data: JsonData):
    """测试字典添加操作"""
    logging.warning("=== Testing dictionary addition with object and pair ===")
    
    # 1. 首先添加一个空对象
    logging.info("Operation: Adding new object 'field4' to root")
    logging.debug(f"Before: data = {json_data.data}")
    json_data.json_data_pair_add([], "field4", add_type=AddType.OBJECT)
    logging.debug(f"After adding object: data = {json_data.data}")
    
    # 2. 在新对象中添加键值对
    logging.info("Operation: Adding new pair 'field4_sub1': ['0x31', '0x32'] to field4")
    json_data.json_data_pair_add(["field4"], "field4_sub1", ["0x31", "0x32"], AddType.PAIR)
    logging.debug(f"After adding pair: data = {json_data.data}")
    
    # 3. 在field4中再添加一个空对象
    logging.info("Operation: Adding new object 'field4_sub2' to field4")
    json_data.json_data_pair_add(["field4"], "field4_sub2", add_type=AddType.OBJECT)
    logging.debug(f"After adding nested object: data = {json_data.data}")
    
    # 4. 在新的嵌套对象中添加键值对
    logging.info("Operation: Adding new pair 'nested_key': ['0x41', '0x42'] to field4.field4_sub2")
    json_data.json_data_pair_add(
        ["field4", "field4_sub2"], 
        "nested_key", 
        ["0x41", "0x42"], 
        AddType.PAIR
    )
    logging.info(f"Final result: data = {json_data.get_json_data_value(['field4', 'field4_sub2', 'nested_key'])}")

def process_tls_message(tls_msg: JsonData):
    """处理TLS消息"""
    extension_root_search = ['tls', 'tls.record', 'tls.handshake']
    
    # 更新所有Extension的长度
    all_extensions_len = tls_msg.update_all_extensions_under_root(extension_root_search)
    logging.debug("all extensions length: {}".format(all_extensions_len))
    
    # 更新extension总长度
    all_extensions_len_hex_fromat = decimal_to_hex(all_extensions_len, 4)
    tls_msg.update_length_field_directly(
        ["tls", "tls.record", "tls.handshake","tls.handshake.extensions_length"],
        all_extensions_len_hex_fromat
    )
    tls_msg.verify_all_extensions_under_root(extension_root_search)

    # 更新简单字段的长度数值
    tls_msg.update_length_field(
        ["tls", "tls.record", "tls.handshake", "tls.handshake.cipher_suites_length"], 
        ["tls", "tls.record", "tls.handshake", "tls.handshake.ciphersuites"]
    )
    tls_msg.update_length_field(
        ["tls","tls.record","tls.handshake","tls.handshake.session_id_length"], 
        ["tls","tls.record","tls.handshake","tls.handshake.session_id"]
    )
    tls_msg.update_length_field(
        ["tls","tls.record","tls.handshake","tls.handshake.comp_methods_length"], 
        ["tls","tls.record","tls.handshake","tls.handshake.comp_methods"]
    )
    
    # 计算并更新record长度
    cipher_suites_length = tls_msg.get_array_length_dec(["tls", "tls.record", "tls.handshake", "tls.handshake.ciphersuites"])
    session_id_length = tls_msg.get_array_length_dec(["tls","tls.record","tls.handshake","tls.handshake.session_id"])
    comp_methods_length = tls_msg.get_array_length_dec(["tls","tls.record","tls.handshake","tls.handshake.comp_methods"])
    
    clienthello_handshake_length = 2 + 32 \
                                + 1 + session_id_length \
                                + 2 + cipher_suites_length \
                                + 1 + comp_methods_length \
                                + 2 + all_extensions_len
    clienthello_record_length = clienthello_handshake_length + 4
    
    tls_msg.update_length_field_directly(
        ["tls", "tls.record", "tls.handshake","tls.handshake.length"],
        decimal_to_hex(clienthello_handshake_length, 6)
    )
    tls_msg.update_length_field_directly(
        ["tls", "tls.record", "tls.record.length"],
        decimal_to_hex(clienthello_record_length, 4)
    )


def hex_dump(data: bytes) -> None:
    """打印十六进制数据"""
    hex_data = ' '.join(f'{b:02x}' for b in data)
    print("Hex dump:", hex_data)

def hex_dump_check(data: bytes) -> None:
    """打印十六进制数据"""
    hex_data = ' '.join(f'{b:02x}' for b in data)
    print("Hex dump:", hex_data)

class TestStatistics:
    def __init__(self):
        self.total_tests = 0
        self.successful_tests = 0
        self.failed_tests = 0
        self.error_details = defaultdict(int)
        self.start_time = None
        self.end_time = None
        
    def start(self):
        self.start_time = datetime.now()
        
    def finish(self):
        self.end_time = datetime.now()
        
    def add_success(self):
        self.total_tests += 1
        self.successful_tests += 1
        
    def add_failure(self, error_type: str):
        self.total_tests += 1
        self.failed_tests += 1
        self.error_details[error_type] += 1
        
    def get_summary(self) -> Dict:
        duration = (self.end_time - self.start_time).total_seconds() if self.end_time else 0
        return {
            "total_tests": self.total_tests,
            "successful_tests": self.successful_tests,
            "failed_tests": self.failed_tests,
            "success_rate": (self.successful_tests / self.total_tests * 100) if self.total_tests > 0 else 0,
            "duration_seconds": duration,
            "error_details": dict(self.error_details)
        }

def run_tls_tests(test_cases: List[Tuple[str, bytes]], target_host: str, target_port: int) -> TestStatistics:
    """
    执行TLS测试并收集统计信息
    
    Args:
        test_cases: 测试用例列表，每个元素为(测试名称, TLS字节流)的元组
        target_host: 目标主机IP
        target_port: 目标端口
    
    Returns:
        TestStatistics: 测试统计信息
    """
    stats = TestStatistics()
    stats.start()
    
    for test_name, tls_byte in test_cases:
        logging.info(f"执行测试: {test_name}")
        sender = RawTLSSender(target_host, target_port)
        
        try:
            sender.connect()
            logging.info("发送数据...")
            response = sender.send_receive(tls_byte)
            
            if response:  # 收到非空响应，测试成功
                logging.info("测试成功: 收到有效响应")
                stats.add_success()
                hex_dump(response)
            else:  # 空响应，测试失败
                logging.error("测试失败: 收到空响应")
                stats.add_failure("empty_response")
                
        except socket.error as e:
            if isinstance(e, WindowsError) and e.winerror == 10054:  # 远程主机强制关闭连接
                logging.info("测试成功: 远程主机强制关闭连接")
                stats.add_success()
            else:
                logging.error(f"测试失败: {str(e)}")
                stats.add_failure(f"socket_error_{e.__class__.__name__}")
                
        except Exception as e:
            logging.error(f"测试失败: {str(e)}")
            stats.add_failure(f"general_error_{e.__class__.__name__}")
            
        finally:
            sender.close()
            
    stats.finish()
    return stats

def print_test_summary(stats: TestStatistics):
    """打印测试统计摘要"""
    summary = stats.get_summary()
    print("\n=== 测试执行摘要 ===")
    print(f"总测试数: {summary['total_tests']}")
    print(f"成功测试: {summary['successful_tests']}")
    print(f"失败测试: {summary['failed_tests']}")
    print(f"成功率: {summary['success_rate']:.2f}%")
    print(f"执行时间: {summary['duration_seconds']:.2f}秒")
    
    if summary['error_details']:
        print("\n错误类型统计:")
        for error_type, count in summary['error_details'].items():
            print(f"- {error_type}: {count}次")


def main():
    """主函数"""
    init_log()
    clear_logs_folder()

    try:
        # 初始化测试数据
        test_data = initialize_test_data()
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)
        # logging.info("Original data structure:")
        # json_data.indexmap_print_in_json_pretty_format()
        
        # # 测试JSON数据操作
        # test_json_data_operations(json_data)
        
        # # 测试字典添加操作
        # test_dictionary_addition(json_data)
        
        # 创建并使用ActionParser
        parser = ActionParser("actions")
        parser.load_actions()
        
        # 执行所有加载的actions
        # logging.info("=== Executing loaded actions ===")
       
            # json_data.indexmap_print_in_json_pretty_format()

        # # 处理CSV文件
        loader = ActionLoader(csv_dir="csv", action_dir="actions")
        loader.clean_action_directory()
        loader.process_csv_files()
        logging.info("Successfully processed all CSV files")
        
        # # 处理JSON文件
        processor = JsonFileProcessor(verbose=True)
        file_paths = processor.collect_json_files()
        results = processor.process_files()
        # 准备测试用例
        test_cases = []
        
        # 处理TLS消息并构建测试用例
        tls_msg = results["message\\tls\\tls.json"]
        for action_name in parser.actions:
            parser.execute_action(action_name, json_data)
            process_tls_message(tls_msg)
            tls_byte = tls_msg.indexmap_print_byte_stream()
            test_cases.append((action_name, tls_byte))
        
        # 执行测试
        stats = run_tls_tests(test_cases, "192.168.110.130", 443)
        
        # 打印测试摘要
        print_test_summary(stats)
        # # # 处理TLS消息
        # tls_msg = results["message\\tls\\tls.json"]
        # # # 修改代码，返回构成的clienthello hex 字符串
        # logging.info("=== Executing loaded actions ===")
        # for action_name in parser.actions:
        #     parser.execute_action(action_name, json_data)
        #     logging.info(f"Current data state after {action_name}:")
        #     process_tls_message(tls_msg)
        #     tls_byte = tls_msg.indexmap_print_byte_stream()
        #     logging.info(tls_byte)
        # # # tls_byte = tls_msg.indexmap_print_byte_literal()
        # # # 增加新功能，发送报文到指定目标，并接收反馈
        # # # clienthello = ..
        #     sender = RawTLSSender("192.168.110.130", 443)

        #     try:
        #         # 建立连接
        #         sender.connect()

        #         # 发送报文并接收响应
        #         print("发送数据...")
        #         response = sender.send_receive(tls_byte)

        #         # 打印响应数据
        #         print("\n接收到响应:")
        #         hex_dump(response)
        #         # 设置代码，如果response

        #     except Exception as e:
        #         print(f"错误: {e}")

        #     finally:
        #         sender.close()
        #         # 对反馈进行判断
        
    except Exception as e:
        logging.error(f"Error occurred: {str(e)}")
        raise
if __name__ == "__main__":
    # 运行单元测试
    # run_tests()
    # 增加dns协议，tls协议，ipv6协议的区分，
    # dns协议，tls协议需要明确目标IP，端口，dns是80，tls是443
    # ipv6走的icmpv6
    # 运行主函数示例
    main()

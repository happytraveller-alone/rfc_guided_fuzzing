import logging
from pathlib import Path
from datetime import datetime, timedelta
from library.json_data import JsonData, AddType
from library.action_parser import ActionParser
from library.action_loader import ActionLoader
from library.message_parser import JsonFileProcessor
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

def main():
    """主函数示例"""
    init_log()
    clear_logs_folder()

    test_data = {
        "field1": ["0x12", "0x34"],
        "field2": {
            "field2_sub1": ["0x56", "0x78"],
            "field2_sub2": ["0x9A", "0xBC"]
        },
        "field3": ["0xDE", "0xF0", "0x43", "0x21"],
    }

    try:
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)
        logging.info("Original data structure:")
        json_data.indexmap_print_in_json_pretty_format()
        
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

        # 测试添加新的对象和键值对
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

        # 创建并使用ActionParser
        parser = ActionParser("actions_test")
        parser.load_actions()
        
        # 执行所有加载的actions
        logging.info("=== Executing loaded actions ===")
        for action_name in parser.actions:
            parser.execute_action(action_name, json_data)
            logging.info(f"Current data state after {action_name}:")
            json_data.indexmap_print_in_json_pretty_format()

        json_data.get_array_length_hex(['field4', 'field4_sub2', 'nested_key'])
        logging.info(json_data.get_json_data_value(['field4', 'field4_sub2', 'nested_key']))
        new_array = json_data.generate_padded_hex_array('0x02','0x03')
        json_data.json_data_value_update(['field4', 'field4_sub2', 'nested_key'], new_array)
        logging.info(json_data.get_json_data_value(['field4', 'field4_sub2', 'nested_key']))
    except Exception as e:
        logging.error(f"Error occurred: {str(e)}")
        raise

    try:
        # 创建加载器实例
        loader = ActionLoader(csv_dir="csv", action_dir="actions")
        
        # 清理现有action目录（可选）
        loader.clean_action_directory()
        
        # 处理CSV文件
        loader.process_csv_files()
        
        logging.info("Successfully processed all CSV files")
        
    except Exception as e:
        logging.error(f"Error in main process: {str(e)}")
        raise
    
    try:
        # 创建处理器实例
        processor = JsonFileProcessor(verbose=True)
        
        # 收集文件
        file_paths = processor.collect_json_files()
        
        # # 使用收集到的文件路径
        # if file_paths:
        #     print("\n可以使用这些文件路径进行后续处理...")
        # 处理文件
        results = processor.process_files()
        
        # 获取处理状态
        status = processor.get_processing_status()
        
        # 检查失败的文件
        failed_files = [
            path for path, success in status.items() 
            if not success
        ]
        
        if failed_files:
            print("\n以下文件处理失败：")
            for file_path in failed_files:
                print(f"- {file_path}")

        tls_msg = results["message\\tls\\tls.json"]
        # JsonData.indexmap_print_in_json_pretty_format(tls_msg)
        # tls_msg.indexmap_print_in_json_pretty_format()
        # logging.info(tls_msg.get_json_data_value(['tls', 'tls.record', 'tls.handshake', 
                #  'Extension: key_share (len=38) x25519', 'tls.handshake.extension.len']))
        extension_root_search = ['tls', 'tls.record', 'tls.handshake']
        tls_msg.update_extension_length(['tls', 'tls.record', 'tls.handshake', 
                 'Extension: key_share (len=38) x25519'])
        # 查找所有Extension路径
        extension_paths = tls_msg.find_extension_paths(extension_root_search)
        print("Found Extensions:")
        for path in extension_paths:
            print(" -> ".join(path))
        # 更新所有Extension的长度
        all_extensions_len = tls_msg.update_all_extensions_under_root(extension_root_search)
        logging.info("all extensions length: {}".format(all_extensions_len))
        tls_msg.json_data_value_update()
        # tls_msg.json_data_value_update(["field2", "field2_sub1"], ["0xEE", "0xFF"])
        # 验证所有Extension的长度
        if tls_msg.verify_all_extensions_under_root(extension_root_search):
            print("All extensions have correct lengths")
        else:
            print("Some extensions have incorrect lengths")
        # 更新简单字段的长度数值

        tls_msg.update_length_field(["tls", "tls.record", "tls.handshake", "tls.handshake.cipher_suites_length"], 
                                    ["tls", "tls.record", "tls.handshake", "tls.handshake.ciphersuites"])
        tls_msg.update_length_field(["tls","tls.record","tls.handshake","tls.handshake.session_id_length"], 
                                    ["tls","tls.record","tls.handshake","tls.handshake.session_id"])
        tls_msg.update_length_field(["tls","tls.record","tls.handshake","tls.handshake.comp_methods_length"], 
                                    ["tls","tls.record","tls.handshake","tls.handshake.comp_methods"])
        # 最后更新报文的总长度
        # 验证长度字段
        # if tls_msg.verify_length_field(["tls", "tls.record", "tls.handshake", 
        #               "tls.handshake.cipher_suites_length"], ["tls", "tls.record", "tls.handshake", 
        #                 "tls.handshake.ciphersuites"]):
        #     print("Length field is correct")
        # else:
        #     print("Length field is incorrect")
        # logging.info(tls_msg.get_json_data_value(['tls', 'tls.record', 'tls.handshake', 
                #  'Extension: key_share (len=38) x25519', 'tls.handshake.extension.len']))
    except Exception as e:
        print(f"程序执行出错: {str(e)}")

    # try:
    #     # test tls check
    #     print("read tls message")

    # except Exception as e:
    #     print(f"tls parse error: {str(e)}")
if __name__ == "__main__":
    # 运行单元测试
    # run_tests()
    # 增加dns协议，tls协议，ipv6协议的区分，
    # dns协议，tls协议需要明确目标IP，端口，dns是80，tls是443
    # ipv6走的icmpv6
    # 运行主函数示例
    main()

import unittest
import logging
from pathlib import Path
import json
from collections import OrderedDict
from .json_data import JsonData, AddType
from .action_parser import ActionParser

class TestJsonData(unittest.TestCase):
    def setUp(self):
        """测试数据初始化"""
        self.test_data = {
            "field1": ["0x12", "0x34"],
            "field2": {
                "field2_sub1": ["0x56", "0x78"],
                "field2_sub2": ["0x9A", "0xBC"]
            },
            "field3": ["0xDE", "0xF0", "0x43", "0x21"],
            "field4": {
                "field4_sub1": ["0x22", "0x23"],
                "field4_sub2": ["0x24", "0x25"]
            }
        }
        self.json_data = JsonData.json_data_trans_to_ordered_dict(self.test_data)

    def test_action_parser(self):
        """测试ActionParser功能"""
        # 创建测试目录和文件
        test_dir = Path("test_actions")
        test_dir.mkdir(exist_ok=True)

        # 创建测试action文件
        test_action = {
            "description": "Test action",
            "action_sequence": [
                {
                    "action": "add",
                    "fields": ["new_field"],
                    "value": [0x12, 0x34]
                }
            ]
        }

        with open(test_dir / "action_test.txt", "w") as f:
            json.dump(test_action, f)

        try:
            # 测试解析器
            parser = ActionParser(str(test_dir))
            parser.load_actions()

            # 验证加载的action
            self.assertIn("action_test", parser.actions)
            self.assertEqual(
                parser.actions["action_test"]["description"],
                "Test action"
            )

            # 测试执行action
            test_data = {"existing_field": ["0x56", "0x78"]}
            json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

            parser.execute_action("action_test", json_data)

            # 验证执行结果
            self.assertIn("new_field", json_data.data)
            self.assertEqual(
                json_data.get_json_data_value(["new_field"]),
                ["0x12", "0x34"]
            )

        finally:
            # 清理测试文件和目录
            for file in test_dir.glob("*"):
                file.unlink()
            test_dir.rmdir()

    def test_json_data_trans_to_ordered_dict(self):
        """测试JSON转换为OrderedDict"""
        # 测试字典转换
        result = JsonData.json_data_trans_to_ordered_dict(self.test_data)
        self.assertIsInstance(result.data, OrderedDict)
        
        # 测试JSON字符串转换
        json_str = json.dumps(self.test_data)
        result = JsonData.json_data_trans_to_ordered_dict(json_str)
        self.assertIsInstance(result.data, OrderedDict)
        
        # 测试无效输入
        with self.assertRaises(ValueError):
            JsonData.json_data_trans_to_ordered_dict([])

    def test_json_data_remove_pair(self):
        """测试删除键值对"""
        # 测试删除顶层键
        self.json_data.json_data_remove_pair(["field1"])
        self.assertNotIn("field1", self.json_data.data)

        # 测试删除嵌套键
        self.json_data.json_data_remove_pair(["field2", "field2_sub1"])
        self.assertNotIn("field2_sub1", self.json_data.data["field2"])

        # 测试删除不存在的键
        with self.assertRaises(KeyError):
            self.json_data.json_data_remove_pair(["nonexistent"])

        # 测试空键序列
        with self.assertRaises(ValueError):
            self.json_data.json_data_remove_pair([])

    def test_hex_str_to_byte(self):
        """测试十六进制字符串转换"""
        # 测试有效的十六进制字符串
        self.assertEqual(JsonData.hex_str_to_byte("0x12"), 0x12)
        self.assertEqual(JsonData.hex_str_to_byte("FF"), 0xFF)
        
        # 测试无效的十六进制字符串
        with self.assertRaises(ValueError):
            JsonData.hex_str_to_byte("GG")

    def test_validate_hex_values(self):
        """测试十六进制值验证"""
        # 测试有效的十六进制值列表
        valid_values = ["0x12", "0xFF", "0xAB"]
        JsonData.validate_hex_values(valid_values)  # 不应抛出异常
        
        # 测试无效的十六进制值列表
        invalid_values = ["0x12", "0xGG", "0xFF"]
        with self.assertRaises(ValueError):
            JsonData.validate_hex_values(invalid_values)

    def test_json_data_check_path(self):
        """测试路径检查"""
        # 测试存在的路径
        self.assertTrue(self.json_data.json_data_check_path("field2.field2_sub1"))
        self.assertTrue(self.json_data.json_data_check_path("field1"))
        
        # 测试不存在的路径
        self.assertFalse(self.json_data.json_data_check_path("nonexistent"))
        self.assertFalse(self.json_data.json_data_check_path("field2.nonexistent"))
        
        # 测试空路径
        self.assertFalse(self.json_data.json_data_check_path(""))

    def test_get_json_data_value(self):
        """测试获取数组值"""
        # 测试获取顶层数组
        result = self.json_data.get_json_data_value(["field1"])
        self.assertEqual(result, ["0x12", "0x34"])
        
        # 测试获取嵌套数组
        result = self.json_data.get_json_data_value(["field2", "field2_sub1"])
        self.assertEqual(result, ["0x56", "0x78"])
        
        # 测试获取不存在的路径
        with self.assertRaises(KeyError):
            self.json_data.get_json_data_value(["nonexistent"])
        
        # 测试非数组值
        with self.assertRaises(ValueError):
            self.json_data.get_json_data_value(["field2"])

    def test_json_data_value_head_add(self):
        """测试数组头部添加元素"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试在顶层数组头部添加
        json_data.json_data_value_head_add(["array1"], ["0xAA", "0xBB"])
        self.assertEqual(
            json_data.get_json_data_value(["array1"]),
            ["0xAA", "0xBB", "0x12", "0x34"]
        )

        # 测试在嵌套数组头部添加
        json_data.json_data_value_head_add(["nested", "array2"], ["0xCC"])
        self.assertEqual(
            json_data.get_json_data_value(["nested", "array2"]),
            ["0xCC", "0x56", "0x78"]
        )

        # 测试添加空列表（不应改变原数组）
        original = json_data.get_json_data_value(["array1"])
        json_data.json_data_value_head_add(["array1"], [])
        self.assertEqual(json_data.get_json_data_value(["array1"]), original)

        # 测试无效的十六进制值
        with self.assertRaises(ValueError):
            json_data.json_data_value_head_add(["array1"], ["0xGG"])

        # 测试非数组目标
        with self.assertRaises(ValueError):
            json_data.json_data_value_head_add(["nested"], ["0x11"])

    def test_json_data_value_tail_add(self):
        """测试数组尾部添加元素"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试在顶层数组尾部添加
        json_data.json_data_value_tail_add(["array1"], ["0xAA", "0xBB"])
        self.assertEqual(
            json_data.get_json_data_value(["array1"]),
            ["0x12", "0x34", "0xAA", "0xBB"]
        )

        # 测试在嵌套数组尾部添加
        json_data.json_data_value_tail_add(["nested", "array2"], ["0xCC"])
        self.assertEqual(
            json_data.get_json_data_value(["nested", "array2"]),
            ["0x56", "0x78", "0xCC"]
        )

        # 测试添加空列表（不应改变原数组）
        original = json_data.get_json_data_value(["array1"])
        json_data.json_data_value_tail_add(["array1"], [])
        self.assertEqual(json_data.get_json_data_value(["array1"]), original)

        # 测试无效的十六进制值
        with self.assertRaises(ValueError):
            json_data.json_data_value_tail_add(["array1"], ["0xGG"])

        # 测试非数组目标
        with self.assertRaises(ValueError):
            json_data.json_data_value_tail_add(["nested"], ["0x11"])

    def test_json_data_value_update(self):
        """测试更新数组值"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试更新顶层数组
        json_data.json_data_value_update(["array1"], ["0xAA", "0xBB"])
        self.assertEqual(
            json_data.get_json_data_value(["array1"]),
            ["0xAA", "0xBB"]
        )

        # 测试更新嵌套数组
        json_data.json_data_value_update(["nested", "array2"], ["0xCC", "0xDD"])
        self.assertEqual(
            json_data.get_json_data_value(["nested", "array2"]),
            ["0xCC", "0xDD"]
        )

        # 测试使用空列表更新
        with self.assertRaises(ValueError):
            json_data.json_data_value_update(["array1"], [])

        # 测试无效的十六进制值
        with self.assertRaises(ValueError):
            json_data.json_data_value_update(["array1"], ["0xGG"])

        # 测试非数组目标
        with self.assertRaises(ValueError):
            json_data.json_data_value_update(["nested"], ["0x11"])

    def test_indexmap_print_byte_stream(self):
        """测试字节流打印"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 测试字节流生成
        byte_stream = json_data.indexmap_print_byte_stream()
        expected = "12 34 56 78"  # 预期的输出格式
        self.assertEqual(byte_stream, expected)

        # 测试包含无效十六进制值的数据
        invalid_data = {
            "array1": ["0x12", "invalid"]
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(invalid_data)
        with self.assertRaises(ValueError):
            json_data.indexmap_print_byte_stream()

    def test_indexmap_print_in_json_format(self):
        """测试JSON格式打印"""
        # 准备测试数据
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 捕获日志输出
        with self.assertLogs(level='INFO') as log:
            json_data.indexmap_print_in_json_format()
            
        # 验证日志输出包含预期的JSON结构
        self.assertTrue(any("array1" in output for output in log.output))
        self.assertTrue(any("nested" in output for output in log.output))

    def test_indexmap_print_in_json_pretty_format(self):
        """测试优化的JSON格式打印"""
        test_data = {
            "array1": ["0x12", "0x34"],
            "nested": {
                "array2": ["0x56", "0x78"]
            }
        }
        json_data = JsonData.json_data_trans_to_ordered_dict(test_data)

        # 捕获日志输出
        with self.assertLogs(level='INFO') as log:
            json_data.indexmap_print_in_json_pretty_format()
            
        # 验证日志输出包含预期的格式
        log_output = '\n'.join(log.output)
        # 验证数组元素在同一行
        self.assertTrue('"0x12", "0x34"' in log_output)
        self.assertTrue('"0x56", "0x78"' in log_output)
        # 验证结构完整性
        self.assertTrue('array1' in log_output)
        self.assertTrue('nested' in log_output)
        self.assertTrue('array2' in log_output)

def run_tests():
    """运行所有单元测试"""
    suite = unittest.TestLoader().loadTestsFromTestCase(TestJsonData)
    unittest.TextTestRunner(verbosity=2).run(suite)

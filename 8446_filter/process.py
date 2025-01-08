import pandas as pd
from typing import List, Dict

def process_csv_file(input_file: str, output_file: str, column_name: str, keywords: List[str]) -> Dict:
    """
    处理CSV文件，删除指定列中包含特定关键词的行
    
    Args:
        input_file (str): 输入CSV文件路径
        output_file (str): 输出CSV文件路径
        column_name (str): 要处理的列名
        keywords (List[str]): 需要过滤的关键词列表
    
    Returns:
        Dict: 包含处理统计信息的字典
    """
    try:
        # 读取CSV文件
        df = pd.read_csv(input_file)
        
        # 确保指定列存在
        if column_name not in df.columns:
            raise ValueError(f"CSV文件中未找到'{column_name}'列")
        
        # 创建过滤条件
        mask = ~df[column_name].str.contains('|'.join(keywords), na=False, case=True)
        
        # 获取被删除的行
        deleted_rows = df[~mask]
        
        # 应用过滤并保存到新文件
        filtered_df = df[mask]
        filtered_df.to_csv(output_file, index=False)
        
        # 统计信息
        stats = {
            "原始行数": len(df),
            "处理后行数": len(filtered_df),
            "删除总行数": len(df) - len(filtered_df),
            "删除详情": {}
        }
        
        # 详细统计每个关键词的匹配情况
        for keyword in keywords:
            matched_count = len(deleted_rows[deleted_rows[column_name].str.contains(keyword, na=False, case=True)])
            stats["删除详情"][keyword] = matched_count
        
        # 打印统计信息
        print(f"\n=== 处理完成 ===")
        print(f"原始行数: {stats['原始行数']}")
        print(f"处理后行数: {stats['处理后行数']}")
        print(f"删除总行数: {stats['删除总行数']}")
        print("\n=== 删除详情 ===")
        for keyword, count in stats['删除详情'].items():
            if count > 0:  # 只显示有匹配的关键词
                print(f"- {keyword}: {count}行")
        
        return stats
        
    except FileNotFoundError:
        print(f"错误：找不到输入文件 {input_file}")
        return {}
    except Exception as e:
        print(f"处理过程中发生错误：{str(e)}")
        return {}

if __name__ == "__main__":
    input_file = "rq1_8446.csv"
    output_file = "rq1_8446_filtered.csv"
    column_name = "strategy"
    keywords = [
        'Application Layer Protocol Negotiation Extension',
        'Application Settings Extension',
        'Compress Certificate Extension',
        'Encrypted Client Hello Extension',
        'Renegotiation Info Extension',
        'Reserved Extension',
        'Session Ticket Extension',
        'Signed Certificate Timestamp Extension',
        'Status Request Extension',
        'Extended Master Secret Extension'
    ]
    stats = process_csv_file(input_file, output_file, column_name, keywords)
    keywords_2 = [
        'tls.encrypted_extensions',
        'tls.handshake.certificate',
        'CertificateVerify',
        'CertificateRequest',
        'Certificate',
        'application_data',
        'application'
    ]
    stats_2 = process_csv_file("rq1_8446_filtered.csv", "rq1_8446_filtered_2.csv", "action_sequence", keywords_2)
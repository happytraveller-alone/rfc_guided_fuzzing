import argparse
import subprocess
import sys
import os
from pathlib import Path

def deploy_modal_app(file_name: str):
    """
    部署指定的 Modal 应用，使用正确的编码设置
    """
    try:
        # 设置环境变量以强制使用 UTF-8 编码
        env = os.environ.copy()
        env["PYTHONIOENCODING"] = "utf-8"
        
        # 构建 Modal 部署命令
        deploy_command = ["modal", "deploy", file_name]
        
        # 使用 UTF-8 编码执行部署命令
        result = subprocess.run(
            deploy_command,
            check=True,
            capture_output=True,
            text=True,
            encoding='utf-8',  # 明确指定 UTF-8 编码
            errors='replace',  # 处理无法解码的字符
            env=env
        )
        
        print(f"Successfully deployed {file_name}")
        print("Deployment output:")
        # 使用 encode 和 decode 来安全处理输出
        safe_output = result.stdout.encode('utf-8', errors='replace').decode('utf-8', errors='replace')
        print(safe_output)
        
        return True
    except subprocess.CalledProcessError as e:
        print(f"Error deploying {file_name}:")
        print(f"Exit code: {e.returncode}")
        # 安全处理错误输出
        error_output = e.stderr.encode('utf-8', errors='replace').decode('utf-8', errors='replace')
        print(f"Error output: {error_output}")
        return False
    except Exception as e:
        print(f"Unexpected error deploying {file_name}: {str(e)}")
        return False

def main():
    # 设置控制台输出编码为 UTF-8
    if sys.platform.startswith('win'):
        # Windows 平台特殊处理
        sys.stdout.reconfigure(encoding='utf-8')
        sys.stderr.reconfigure(encoding='utf-8')

    # 设置参数解析
    parser = argparse.ArgumentParser(description="Run the integrated agent with specific functionality.")
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--rule_extrac', action='store_true', help='Run rule extraction functionality.')
    group.add_argument('--semantic_slice', action='store_true', help='Run semantic analysis functionality.')
    group.add_argument('--violation_gen', action='store_true', help='Run violation generation functionality.')

    args = parser.parse_args()

    # 检查文件是否存在
    current_dir = Path(__file__).parent
    files_config = {
        'rule_extrac': 'rule_extraction.py',
        'semantic_slice': 'semantic_analysis.py',
        'violation_gen': 'violation_generation.py'
    }

    # 根据参数选择要部署的文件
    if args.rule_extrac:
        target_file = files_config['rule_extrac']
    elif args.semantic_slice:
        target_file = files_config['semantic_slice']
    elif args.violation_gen:
        target_file = files_config['violation_gen']
    else:
        print("No valid argument provided")
        sys.exit(1)

    # 检查目标文件是否存在
    target_path = current_dir / target_file
    if not target_path.exists():
        print(f"Error: {target_file} not found in {current_dir}")
        sys.exit(1)

    # 部署选定的文件
    print(f"Deploying {target_file}...")
    if deploy_modal_app(str(target_path)):
        print(f"Successfully deployed {target_file}")
    else:
        print(f"Failed to deploy {target_file}")
        sys.exit(1)

if __name__ == "__main__":
    main()
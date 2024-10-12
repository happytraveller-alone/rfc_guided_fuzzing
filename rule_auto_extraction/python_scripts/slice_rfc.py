import os
import sys
import time
import threading
import csv
import re
from poe_api_wrapper import PoeApi
import asyncio
from concurrent.futures import ThreadPoolExecutor
# Initialize Poe API tokens
tokens = {
    'p-b': "QiZtBLjGecaQJ4-iJPIPgA%3D%3D", 
    'p-lat': "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D",
}

client = PoeApi(tokens=tokens, auto_proxy=False)
executor = ThreadPoolExecutor()


def parse_arguments():
    # 设置默认的切片目录
    default_slice_directory = "output/RFC-8446/slice"

    if len(sys.argv) == 1:
        print(f"Warning: No slice directory provided. Using default: '{default_slice_directory}'")
        slice_directory = default_slice_directory
    elif len(sys.argv) == 2:
        slice_directory = sys.argv[1]
    else:
        print("Usage: python slice_rfc.py [slice_directory]")
        sys.exit(1)

    if not os.path.exists(slice_directory):
        print(f"Error: The directory '{slice_directory}' does not exist.")
        sys.exit(1)

    if not os.path.isdir(slice_directory):
        print(f"Error: The path '{slice_directory}' is not a directory.")
        sys.exit(1)
    # print()
    return slice_directory

# def get_files(slice_directory):
#     # 获取文件列表并统计总个数
#     files = [os.path.join(slice_directory, f) for f in os.listdir(slice_directory) if os.path.isfile(os.path.join(slice_directory, f))]
#     print(f"Total number of files in '{slice_directory}': {len(files)}")
#     return files
def get_files(slice_directory):
    # 使用 os.scandir 以提高性能
    with os.scandir(slice_directory) as entries:
        files = [entry.path for entry in entries if entry.is_file()]
    print(f"Total number of files in '{slice_directory}': {len(files)}")
    return files


def process_files(files):
    # Prepare to store results
    results = [None] * len(files)

    # Create and start threads
    threads = []
    for i, file_path in enumerate(files):
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.read()
        t = threading.Thread(target=message_thread, args=(content, results, i))
        t.start()
        threads.append(t)
        time.sleep(1)  # Add a delay to avoid rate limiting

    # Wait for all threads to complete
    for t in threads:
        t.join()

    return results

def output_results(files, results):
    # Define the pattern for extracting title and content
    pattern = r'\[([^\]]+)\]\s*\{([^}]+)\}'

    # Prepare CSV output
    csv_file_path = "output/rfc_results.csv"
    fieldnames = ['ID', 'Title', 'Content']

    with open(csv_file_path, 'w', newline='', encoding='utf-8') as csvfile:
        csv_writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        csv_writer.writeheader()

        row_id = 1
        for i, result in enumerate(results):
            if result.startswith("Error"):
                csv_writer.writerow({
                    'ID': row_id,
                    'Title': "Error",
                    'Content': result
                })
                row_id += 1
            else:
                matches = re.finditer(pattern, result, re.DOTALL)
                for match in matches:
                    csv_writer.writerow({
                        'ID': row_id,
                        'Title': match.group(1),
                        'Content': match.group(2)
                    })
                    row_id += 1

    print(f"Results have been written to '{csv_file_path}'.")

def message_thread(prompt, results, index):
    try:
        message = client.send_message("semantic_analysis", prompt, timeout=40)
        for chunk in message:
            pass
        results[index] = chunk["text"]
    except Exception as e:
        results[index] = f"Error: {str(e)}"

def main():
    slice_directory = parse_arguments()
    files = get_files(slice_directory)
    results = process_files(files)
    output_results(files, results)

if __name__ == "__main__":
    main()
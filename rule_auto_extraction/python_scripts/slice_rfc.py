import os
import sys
import time
import threading
import csv
import re
from poe_api_wrapper import PoeApi
import asyncio
from concurrent.futures import ThreadPoolExecutor
import multiprocessing
import math
import signal
# Initialize Poe API tokens
tokens = {
    'p-b': "QiZtBLjGecaQJ4-iJPIPgA%3D%3D", 
    'p-lat': "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D",
}

client = PoeApi(tokens=tokens, auto_proxy=False)
executor = ThreadPoolExecutor()

def signal_handler(signum, frame):
    """处理中断信号"""
    print("\nReceived interrupt signal. Cleaning up...")
    sys.exit(1)

def parse_arguments():
    # Set default slice directory
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

    return slice_directory

def get_files(slice_directory):
    # Use os.scandir to improve performance
    with os.scandir(slice_directory) as entries:
        files = [entry.path for entry in entries if entry.is_file()]
    print(f"Total number of files in '{slice_directory}': {len(files)}")
    return files

def message_thread(prompt, results, index, max_retries=5):
    """Thread function for sending messages and storing results with retry mechanism."""
    retries = 0
    wait_time = 7  # Initial wait time before retrying
    while retries < max_retries:
        try:
            message = client.send_message("semantic_analysis", prompt, timeout=60)
            for chunk in message:
                pass
            results[index] = chunk["text"]
            return
        except Exception as e:
            retries += 1
            print(f"Warning: Attempt {retries} failed for index {index}. Error: {str(e)}")
            time.sleep(wait_time)  # Wait before retrying
            wait_time *= 2  # Exponential backoff
    results[index] = f"Error after {max_retries} retries: {str(e)}"

def process_files(files):
    """Process each file by creating threads to handle requests."""
    # Prepare to store results
    results = [None] * len(files)
    threads = []

    # Get the maximum number of threads to use
    total_threads = multiprocessing.cpu_count()
    max_threads = math.floor(total_threads * 0.7)
    try:
        # Create and start threads
        for i, file_path in enumerate(files):
            with open(file_path, 'r', encoding='utf-8') as file:
                content = file.read()

            # Limit the number of concurrent threads
            while len(threads) >= max_threads:
                for t in threads:
                    if not t.is_alive():
                        threads.remove(t)
                time.sleep(5)

            t = threading.Thread(target=message_thread, args=(content, results, i))
            t.start()
            threads.append(t)
            time.sleep(3)  # Add a delay to avoid rate limiting

        # Wait for all threads to complete
        for t in threads:
            t.join()

    except KeyboardInterrupt:
        print("\nReceived keyboard interrupt. Terminating threads...")
        sys.exit(1)
    except Exception as e:
        print(f"\nAn error occurred: {str(e)}")
        sys.exit(1)
    
    return results

def output_results(files, results):
    """Write the results to a CSV file."""
    # Define the pattern for extracting title and content
    # pattern = r'\[([^\]]+)\]\s*\{([^}]+)\}'
    pattern = r'\{([^}]+)\}\s*\[([^\]]+)\]\s*\{([^}]+)\}'
    # Prepare CSV output
    csv_file_path = "output/rfc_results.csv"
    fieldnames = ['ID','Section', 'Title', 'Content']

    try:
        with open(csv_file_path, 'w', newline='', encoding='utf-8') as csvfile:
            csv_writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            csv_writer.writeheader()

            row_id = 1
            for i, result in enumerate(results):
                if result.startswith("Error"):
                    csv_writer.writerow({
                        'ID': row_id,
                        'Section': "Error",
                        'Title': "Error",
                        'Content': result
                    })
                    row_id += 1
                else:
                    matches = re.finditer(pattern, result, re.DOTALL)
                    for match in matches:
                        csv_writer.writerow({
                            'ID': row_id,
                            'Section': match.group(1),
                            'Title': match.group(2),
                            'Content': match.group(3)
                        })
                        row_id += 1

        print(f"Results have been written to '{csv_file_path}'.")
    except Exception as e:
        print(f"\nError writing to CSV file: {str(e)}")
        sys.exit(1)

def main():
    # slice_directory = parse_arguments()
    # files = get_files(slice_directory)
    # results = process_files(files)
    # output_results(files, results)
    try:
        # 设置信号处理器
        signal.signal(signal.SIGINT, signal_handler)  # 处理 Ctrl+C
        signal.signal(signal.SIGTERM, signal_handler)  # 处理终止信号
        
        slice_directory = parse_arguments()
        files = get_files(slice_directory)
        results = process_files(files)
        output_results(files, results)
    except KeyboardInterrupt:
        print("\nProgram interrupted by user. Exiting...")
        sys.exit(1)
    except EOFError:
        print("\nEOF detected. Exiting...")
        sys.exit(1)
    except Exception as e:
        print(f"\nAn unexpected error occurred: {str(e)}")
        sys.exit(1)

if __name__ == "__main__":
    main()
import time
import csv
import threading
import re
from colorama import Fore, Style
from poe_api_wrapper import PoeApi
import sys
import multiprocessing
import math
import signal

# Initialize API tokens
tokens = {
    'p-b': "QiZtBLjGecaQJ4-iJPIPgA%3D%3D", 
    'p-lat': "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D",
}

client = PoeApi(tokens=tokens, auto_proxy=False)

def signal_handler(sig, frame):
    """Handle interrupt signals (Ctrl+C or Ctrl+D)."""
    print(Fore.RED + "\nProgram interrupted by user. Forcing exit..." + Style.RESET_ALL)
    sys.exit(1)

def parse_classification_result(text):
    """Parse classification result from the response text."""
    try:
        classification_pattern = r'CLASSIFICATION:\s*(\d)'
        mqd_pattern = r'MQD:\s*(.+?)(?=\nCRA:|$)'
        cra_pattern = r'CRA:\s*(.+?)(?=\n|$)'

        classification = re.search(classification_pattern, text)
        mqd = re.search(mqd_pattern, text, re.DOTALL)
        cra = re.search(cra_pattern, text, re.DOTALL)

        return {
            'classification_result': classification.group(1) if classification else 'ERROR',
            'MQD': mqd.group(1).strip() if mqd else 'ERROR',
            'CRA': cra.group(1).strip() if cra else 'ERROR'
        }
    except Exception as e:
        print(Fore.RED + f"Error parsing classification result: {str(e)}" + Style.RESET_ALL)
        return {
            'classification_result': 'ERROR',
            'MQD': 'ERROR',
            'CRA': 'ERROR'
        }

def message_thread(prompt, results, index, max_retries=5):
    """Thread function for sending messages and storing results with retry mechanism."""
    retries = 0
    wait_time = 7
    while retries < max_retries:
        try:
            message = client.send_message("rule_classification", prompt, timeout=60)
            for chunk in message:
                pass
            results[index] = parse_classification_result(chunk["text"])
            return
        except Exception as e:
            retries += 1
            print(Fore.YELLOW + f"Warning: Attempt {retries} failed for index {index}. Error: {str(e)}" + Style.RESET_ALL)
            time.sleep(wait_time)
            wait_time *= 2
    results[index] = {
        'classification_result': f"Error after {max_retries} retries: {str(e)}",
        'MQD': 'ERROR',
        'CRA': 'ERROR'
    }

def read_csv(file_path):
    """Read CSV and return rows with fieldnames."""
    rows = []
    with open(file_path, 'r', encoding='utf-8') as file:
        csv_reader = csv.DictReader(file)
        fieldnames = csv_reader.fieldnames + ['classification_full_result', 'classification_result', 'MQD', 'CRA']
        for row in csv_reader:
            rows.append(row)
    return rows, fieldnames

def write_csv(file_path, fieldnames, rows):
    """Write rows to CSV with given fieldnames."""
    with open(file_path, 'w', newline='', encoding='utf-8') as file:
        csv_writer = csv.DictWriter(file, fieldnames=fieldnames)
        csv_writer.writeheader()
        csv_writer.writerows(rows)

def extract_rules(rows):
    """Extract rules from results and add them to rows."""
    results = [None] * len(rows)
    threads = []

    total_threads = multiprocessing.cpu_count()
    max_threads = math.floor(total_threads * 0.7)
    
    for i, row in enumerate(rows):
        combined_input = f"{row['SlicedRule']}"
        while len(threads) >= max_threads:
            for t in threads:
                if not t.is_alive():
                    threads.remove(t)
            time.sleep(1)
        t = threading.Thread(target=message_thread, args=(combined_input, results, i))
        t.start()
        threads.append(t)
        time.sleep(2)
    
    for t in threads:
        t.join()

    for i, result in enumerate(results):
        if result:
            rows[i]['classification_full_result'] = str(result)
            rows[i]['classification_result'] = result['classification_result']
            rows[i]['MQD'] = result['MQD']
            rows[i]['CRA'] = result['CRA']

    return rows

def main():
    """Main function to orchestrate the process."""
    # Register signal handlers
    signal.signal(signal.SIGINT, signal_handler)  # Ctrl+C
    signal.signal(signal.SIGTERM, signal_handler) # Termination signal
    
    try:
        print(Fore.GREEN + "Starting process..." + Style.RESET_ALL)
        rows, fieldnames = read_csv('agent_input_source/rfc_results_update_slice_rule.csv')
        print(Fore.GREEN + f"Processing {len(rows)} rules..." + Style.RESET_ALL)
        updated_rows = extract_rules(rows)
        write_csv('agent_input_source/rfc_results_classify_slice_rule.csv', fieldnames, updated_rows)
        print(Fore.GREEN + "Process completed successfully!" + Style.RESET_ALL)
    except KeyboardInterrupt:
        print(Fore.RED + "\nProcess interrupted by user. Cleaning up..." + Style.RESET_ALL)
        sys.exit(1)
    except Exception as e:
        print(Fore.RED + f"FATAL ERROR: {str(e)}" + Style.RESET_ALL)
        sys.exit(1)

if __name__ == "__main__":
    main()
import time
import csv
import threading
import re
from colorama import Fore, Style
from poe_api_wrapper import PoeApi
import sys
import multiprocessing
import math
# Initialize API tokens
tokens = {
    'p-b': "02GkoMhE3WwSDbOEQzIKTQ%3D%3D", 
    'p-lat': "4DQ%2BCxcEqQ%2FeCw762zl4%2F1lKNMQJcJYyfF1TBkXoQg%3D%3D",
}

client = PoeApi(tokens=tokens, auto_proxy=False)

def get_client_settings():
    """Retrieve and print client settings."""
    data = client.get_settings()
    print(data)

def message_thread(prompt, results, index, max_retries=8):
    """Thread function for sending messages and storing results with retry mechanism."""
    retries = 0
    wait_time = 5  # Initial wait time before retrying
    while retries < max_retries:
        try:
            message = client.send_message("generate_mutation", prompt, timeout=80)
            for chunk in message:
                pass
            results[index] = chunk["text"]
            return
        except Exception as e:
            retries += 1
            print(Fore.YELLOW + f"Warning: Attempt {retries} failed for index {index}. Error: {str(e)}" + Style.RESET_ALL)
            time.sleep(wait_time)  # Wait before retrying
            wait_time *= 2  # Exponential backoff
    results[index] = f"Error after {max_retries} retries: {str(e)}"

# def parse_rules(text):
#     """Parse rules from the given text using regex pattern."""
#     pattern = r'<(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\) \+ <(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\)'
#     return re.findall(pattern, text, re.DOTALL)

def read_csv(file_path):
    """Read CSV and return rows with fieldnames."""
    rows = []
    with open(file_path, 'r', encoding='utf-8') as file:
        csv_reader = csv.DictReader(file)
        fieldnames = csv_reader.fieldnames + ['mutation_output']
        for row in csv_reader:
            rows.append(row)
    return rows, fieldnames

def write_csv(file_path, fieldnames, rows):
    """Write rows to CSV with given fieldnames."""
    with open(file_path, 'w', newline='', encoding='utf-8') as file:
        csv_writer = csv.DictWriter(file, fieldnames=fieldnames)
        csv_writer.writeheader()
        csv_writer.writerows(rows)

def generate_mutation(rows):
    """Extract rules from results and add them to rows."""
    results = [None] * len(rows)
    threads = []

    # Get the maximum number of threads to use
    total_threads = multiprocessing.cpu_count()
    max_threads = math.floor(total_threads * 0.7)
    
    for i, row in enumerate(rows):
        if row['violation_input'] and row['violation_input'].strip():  # Check if SlicedRule is not empty
            sliced_rule = row['violation_input'].strip()
            # Limit the number of concurrent threads
            while len(threads) >= max_threads:
                for t in threads:
                    if not t.is_alive():
                        threads.remove(t)
                time.sleep(1)

            t = threading.Thread(target=message_thread, args=(sliced_rule, results, i))
            t.start()
            threads.append(t)
            time.sleep(2)  # Add a delay to avoid rate limiting
        else:
            results[i] = "Skip: Empty SlicedRule"
            time.sleep(1)  # Add a delay to avoid rate limiting

    # Join remaining threads
    for t in threads:
        t.join()

    # Add new 'Violation' column to rows
    for i, result in enumerate(results):
        rows[i]['mutation_output'] = result

    return rows

def signal_handler(sig, frame):
    """Handle interrupt signals (e.g., Ctrl+C)."""
    print(Fore.RED + "\nProgram interrupted by user." + Style.RESET_ALL)
    sys.exit(0)

def main():
    """Main function to orchestrate the process."""
    try:
        get_client_settings()
        rows, fieldnames = read_csv('agent_input_source/rule_simple_violation_input.csv')
        updated_rows = generate_mutation(rows)
        write_csv('agent_input_source/rule_simple_mutation.csv', fieldnames, updated_rows)
        print(Fore.GREEN + "SUCCESS" + Style.RESET_ALL)
    except Exception as e:
        # print("error")
        print(Fore.RED + "FATAL: " + str(e) + Style.RESET_ALL)

if __name__ == "__main__":
    main()
import time
import csv
import threading
import re
from colorama import Fore, Style
from poe_api_wrapper import PoeApi

tokens = {
    'p-b': "QiZtBLjGecaQJ4-iJPIPgA%3D%3D", 
    'p-lat': "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D",
}

client = PoeApi(tokens=tokens, auto_proxy=False)

def get_client_settings():
    """Retrieve and print client settings."""
    data = client.get_settings()
    print(data)

def message_thread(prompt, results, index):
    """Thread function for sending messages and storing results."""
    try:
        message = client.send_message("TLSRFC_EXTRACT", prompt, timeout=40)
        for chunk in message:
            pass
        results[index] = chunk["text"]
    except Exception as e:
        results[index] = f"Error: {str(e)}"

def parse_rules(text):
    """Parse rules from the given text using regex pattern."""
    pattern = r'<(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\) \+ <(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\)'
    return re.findall(pattern, text, re.DOTALL)

def read_csv(file_path):
    """Read CSV and return rows with fieldnames."""
    rows = []
    with open(file_path, 'r', encoding='utf-8') as file:
        csv_reader = csv.DictReader(file)
        fieldnames = csv_reader.fieldnames + ['extracted_rule', 'single_extracted_rule']
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
    for i, row in enumerate(rows):
        t = threading.Thread(target=message_thread, args=(row['Description'], results, i))
        t.start()
        threads.append(t)
        time.sleep(1)  # Add a delay to avoid rate limiting

    for t in threads:
        t.join()

    new_rows = []
    for i, result in enumerate(results):
        rows[i]['extracted_rule'] = result
        parsed_rules = parse_rules(result)
        if not parsed_rules:
            rows[i]['single_extracted_rule'] = "No valid rule pattern found"
            new_rows.append(rows[i])
        else:
            for j, rule in enumerate(parsed_rules):
                if j == 0:
                    rows[i]['single_extracted_rule'] = f"<{rule[0]}> <{rule[1]}> ({rule[2]}) + <{rule[3]}> <{rule[4]}> ({rule[5]})"
                    new_rows.append(rows[i])
                else:
                    new_row = {key: '' for key in rows[i].keys()}
                    new_row['single_extracted_rule'] = f"<{rule[0]}> <{rule[1]}> ({rule[2]}) + <{rule[3]}> <{rule[4]}> ({rule[5]})"
                    new_rows.append(new_row)
    return new_rows

def main():
    """Main function to orchestrate the process."""
    try:
        get_client_settings()
        rows, fieldnames = read_csv('source/rule_base_test.csv')
        updated_rows = extract_rules(rows)
        write_csv('source/rule_base_test_updated.csv', fieldnames, updated_rows)
        print(Fore.GREEN + "SUCCESS" + Style.RESET_ALL)
    except Exception as e:
        print(Fore.RED + "FATAL: " + str(e) + Style.RESET_ALL)

if __name__ == "__main__":
    main()
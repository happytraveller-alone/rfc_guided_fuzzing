import time
import csv
import threading
import re
from poe_api_wrapper import PoeApi

tokens = {
    'p-b': "QiZtBLjGecaQJ4-iJPIPgA%3D%3D", 
    'p-lat': "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D",
}

client = PoeApi(tokens=tokens, auto_proxy=False)

data = client.get_settings()
print(data)

def message_thread(prompt, results, index):
    try:
        message = client.send_message("TLSRFC_EXTRACT", prompt, timeout=40)
        for chunk in message:
            pass
        results[index] = chunk["text"]
    except Exception as e:
        results[index] = f"Error: {str(e)}"

# Define the pattern for rule extraction
pattern = r'<(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\) \+ <(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\)'

def parse_rules(text):
    return re.findall(pattern, text, re.DOTALL)

# Read CSV and store all data
rows = []
with open('source/rule_base_test.csv', 'r', encoding='utf-8') as file:
    csv_reader = csv.DictReader(file)
    fieldnames = csv_reader.fieldnames + ['extracted_rule', 'single_extracted_rule']
    for row in csv_reader:
        rows.append(row)

# Prepare to store results
results = [None] * len(rows)

# Create and start threads
threads = []
for i, row in enumerate(rows):
    t = threading.Thread(target=message_thread, args=(row['Description'], results, i))
    t.start()
    threads.append(t)
    time.sleep(1)  # Add a delay to avoid rate limiting

# Wait for all threads to complete
for t in threads:
    t.join()
# Add results to rows, extract single rules, and write back to CSV
new_rows = []
for i, result in enumerate(results):
    rows[i]['extracted_rule'] = result
    parsed_rules =  parse_rules(result)
    if not parsed_rules:
        rows[i]['extracted_rule'] = result
        rows[i]['single_extracted_rule'] = "No valid rule pattern found"
        new_rows.append(rows[i])
    else:
        for j, rule in enumerate(parsed_rules):
            if j == 0:
                rows[i]['extracted_rule'] = result
                rows[i]['single_extracted_rule'] = f"<{rule[0]}> <{rule[1]}> ({rule[2]}) + <{rule[3]}> <{rule[4]}> ({rule[5]})"
                new_rows.append(rows[i])
            else:
                new_row = {key: '' for key in rows[i].keys()}
                new_row['single_extracted_rule'] = f"<{rule[0]}> <{rule[1]}> ({rule[2]}) + <{rule[3]}> <{rule[4]}> ({rule[5]})"
                new_rows.append(new_row)

# Write updated data back to CSV
with open('source/rule_base_test_updated.csv', 'w', newline='', encoding='utf-8') as file:
    csv_writer = csv.DictWriter(file, fieldnames=fieldnames)
    csv_writer.writeheader()
    csv_writer.writerows(new_rows)

print("Processing complete. Results have been written to 'rule_base_test_updated.csv'.")
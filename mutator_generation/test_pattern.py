import re

# Multi-line input
input_text = """<CMC> <1> (Clients MUST send the same ClientHello without modification, except as specified.) + <SMP> <0> (Servers MUST accept the same ClientHello without modification, except as specified.)
<CMC> <1> (Clients MUST replace the list of shares in the ""key_share"" extension with a single KeyShareEntry from the indicated group if supplied.) + <SMP> <0> (Servers MUST accept the modified ""key_share"" extension containing a single KeyShareEntry.)
<CMC> <1> (Clients MUST remove the ""early_data"" extension if present after a HelloRetryRequest.) + <SMP> <0> (Servers MUST not process ""early_data"" after a HelloRetryRequest.)
<CMC> <1> (Clients MUST include a ""cookie"" extension if provided in the HelloRetryRequest.) + <SMP> <0> (Servers MUST accept the ""cookie"" extension if present.)
<CMC> <1> (Clients MUST update the ""pre_shared_key"" extension by recomputing the ""obfuscated_ticket_age"" and binder values.) + <SMP> <0> (Servers MUST verify the updated ""pre_shared_key"" extension.)
<CMC> <1> (Clients MAY add, remove, or change the length of the ""padding"" extension.) + <SMP> <0> (Servers MUST accommodate changes in the ""padding"" extension if present.)"""

# Updated regex pattern
pattern = r'<(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\) \+ <(CMC|SMP|SMC|CMP)> <([01])> \((.*?)\)'

# Function to parse all rules in the input
def parse_rules(input_text):
    matches = re.finditer(pattern, input_text, re.DOTALL)
    parsed_rules = []
    for match in matches:
        parsed_rules.append({
            'first_type': match.group(1),
            'first_explicitness': match.group(2),
            'first_rule': match.group(3),
            'second_type': match.group(4),
            'second_explicitness': match.group(5),
            'second_rule': match.group(6)
        })
    return parsed_rules

# Parse the rules
parsed_results = parse_rules(input_text)

# Print the results
# Print the results
for i, result in enumerate(parsed_results, 1):
    print(f"Rule {i}:")
    print(f"<{result['first_type']}> <{result['first_explicitness']}> ({result['first_rule']}) + <{result['second_type']}> <{result['second_explicitness']}> ({result['second_rule']})")
    print()

print(f"Total rules parsed: {len(parsed_results)}")
# 单条消息包含多个pattern,首先确定消息有几个pattern，如果超过1，就进行拆解，同时新建一列，逐行填充拆解的pattern,
# 
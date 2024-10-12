import re

# Multi-line input
input_text = """
[Handshake Protocol Purpose]{The handshake protocol is used to negotiate the security parameters of a connection. Handshake messages are supplied to the TLS record layer, where they are encapsulated within one or more TLSPlaintext or TLSCiphertext structures which are processed and transmitted as specified by the current active connection state.}  
[Protocol Message Order]{Protocol messages must be sent in the order defined in Section 4.4.1 and shown in the diagrams in Section 2.}  
[Handling Unexpected Message Order]{A peer which receives a handshake message in an unexpected order must abort the handshake with an "unexpected_message" alert.}  
[Assignment of New Handshake Message Types]{New handshake message types are assigned by IANA as described in Section 11.}
"""

# Regular expression pattern
pattern = r'\[([^\]]+)\]\s*\{([^\}]+)\}'

# Function to parse all matches in the input
def parse_expressions(input_text):
    matches = re.finditer(pattern, input_text)
    parsed_expressions = []
    for match in matches:
        parsed_expressions.append({
            'title': match.group(1),
            'content': match.group(2)
        })
    return parsed_expressions

# Parse the expressions
parsed_results = parse_expressions(input_text)

# Print the results
for i, result in enumerate(parsed_results, 1):
    print(f"Expression {i}:")
    print(f"[{result['title']}] {{{result['content']}}}")
    print()

print(f"Total expressions parsed: {len(parsed_results)}")

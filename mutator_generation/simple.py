import time
# from poe_api_wrapper import PoeExample
tokens = {
    'p-b': "QiZtBLjGecaQJ4-iJPIPgA%3D%3D", 
    'p-lat': "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D",
}
# Default setup
from poe_api_wrapper import PoeApi

# Using Client with auto_proxy (default is False)
client = PoeApi(tokens=tokens, auto_proxy=False)

data = client.get_settings()
print(data)

# Prepare the input for the rule_extraction bot
input_text = """
'''
When multiple extensions of different types are present, the extensions MAY appear in any order, with the exception of "pre_shared_key" (Section 4.2.11) which MUST be the last extension in the ClientHello (but can appear anywhere in the ServerHello extensions block).
'''
""".strip()

# Prepare the input for the rule_extraction bot
input_text = """
'''
When multiple extensions of different types are present, the extensions MAY appear in any order, with the exception of "pre_shared_key" (Section 4.2.11) which MUST be the last extension in the ClientHello (but can appear anywhere in the ServerHello extensions block).
'''
""".strip()

input_text_2 = """
'''
In that case, the client MUST send the same ClientHello without modification, except as follows:
-  If a "key_share" extension was supplied in the HelloRetryRequest, replacing the list of shares with a list containing a single KeyShareEntry from the indicated group.
-  Removing the "early_data" extension (Section 4.2.10) if one was present.  Early data is not permitted after a HelloRetryRequest.
-  Including a "cookie" extension if one was provided in the HelloRetryRequest.
-  Updating the "pre_shared_key" extension if present by recomputing the "obfuscated_ticket_age" and binder values and (optionally) removing any PSKs which are incompatible with the server's indicated cipher suite.
-  Optionally adding, removing, or changing the length of the "padding" extension [RFC7685].
-  Other modifications that may be allowed by an extension defined in the future and present in the HelloRetryRequest.
'''
""".strip()
# 发送消息到 TLSRFC_EXTRACT bot
message = client.send_message(bot="TLSRFC_EXTRACT",message=input_text, timeout=30)
# Iterate through the message chunks
for chunk in message:
    pass
print(chunk["text"])
message = client.send_message(bot="TLSRFC_EXTRACT",message=input_text_2, timeout=30)
# Iterate through the message chunks
for chunk in message:
    pass
print(chunk["text"])

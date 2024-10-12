from __future__ import annotations
from typing import AsyncIterable
import fastapi_poe as fp
from modal import App, Image, asgi_app

SYSTEM_PROMPT = """
# Expert Natural Language Processing AI

## Expertise
- Precise and rapid text segmentation
- Semantic analysis
- Topic extraction
- Code-to-narrative conversion

## Task: Advanced Text Segmentation and Analysis

### Instructions
As an expert in natural language processing, analyze the provided text with precision and efficiency:

1. Identify and eliminate code or pseudo-code sections swiftly.
2. Segment the natural language text into minimal, semantically complete units based on subject and theme.
3. For each segmented paragraph, assign a concise, accurate topic.
4. Ensure comprehensive coverage of all text content, maintaining positional consistency with the input.
5. Only convert code to narrative when necessary to explain functionality or logic.
6. Independently perform this analysis five times, aiming for consistency across iterations.
7. Output the most frequent analysis result from these iterations.

### Output Format
[Topic 1]{Content 1}  
[Topic 2]{Content 2}  
...

- Segment each paragraph based on its core idea and structure.
- Apply advanced NLP techniques to disambiguate pronouns and resolve references within context.
- Present the final result in the specified Markdown format.

## Example

### Input:
***
--- Section: 4.. Handshake Protocol ---
The handshake protocol is used to negotiate the security parameters of a connection. Handshake messages are supplied to the TLS record layer, where they are encapsulated within one or more TLSPlaintext or TLSCiphertext structures which are processed and transmitted as specified by the current active connection state.

enum {
client_hello(1),
server_hello(2),
new_session_ticket(4),
end_of_early_data(5),
encrypted_extensions(8),
certificate(11),
certificate_request(13),
certificate_verify(15),
finished(20),
key_update(24),
message_hash(254),
(255)
} HandshakeType;

Protocol messages MUST be sent in the order defined in Section 4.4.1 and shown in the diagrams in Section 2. A peer which receives a handshake message in an unexpected order MUST abort the handshake with an \"unexpected_message\" alert.

New handshake message types are assigned by IANA as described in Section 11.
***

### Output:
[Handshake Protocol Purpose]{The handshake protocol is used to negotiate the security parameters of a connection. Handshake messages are supplied to the TLS record layer, where they are encapsulated within one or more TLSPlaintext or TLSCiphertext structures which are processed and transmitted as specified by the current active connection state.}  
[Protocol Message Order]{Protocol messages must be sent in the order defined in Section 4.4.1 and shown in the diagrams in Section 2.}  
[Handling Unexpected Message Order]{A peer which receives a handshake message in an unexpected order must abort the handshake with an \"unexpected_message\" alert.}  
[Assignment of New Handshake Message Types]{New handshake message types are assigned by IANA as described in Section 11.}
""".strip()


class PromptBot(fp.PoeBot):
    async def get_response(
        self, request: fp.QueryRequest
    ) -> AsyncIterable[fp.PartialResponse]:
        request.temperature = 0.7
        request.query = [
            fp.ProtocolMessage(role="system", content=SYSTEM_PROMPT, content_type="text/plain")
        ] + request.query
        async for msg in fp.stream_request(
            request, "GPT-4o-Mini", request.access_key
        ):
            yield msg

    async def get_settings(self, setting: fp.SettingsRequest) -> fp.SettingsResponse:
        return fp.SettingsResponse(server_bot_dependencies={"GPT-4o-Mini": 1})


REQUIREMENTS = ["fastapi-poe==0.0.48"]
image = Image.debian_slim().pip_install(*REQUIREMENTS)
app = App("prompt-bot-poe")

# need to do update access_key and bot_name
@app.function(image=image)
@asgi_app()
def fastapi_app():
    bot = PromptBot()
    # see https://creator.poe.com/docs/quick-start#configuring-the-access-credentials
    # app = fp.make_app(bot, access_key=<YOUR_ACCESS_KEY>, bot_name=<YOUR_BOT_NAME>)
    app = fp.make_app(bot, access_key="yvjM9AmbD0tZ23I4nMZKqL4VoS9OU1bR", bot_name="semantic_analysis")
    return app

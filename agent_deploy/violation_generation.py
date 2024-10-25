from __future__ import annotations
from typing import AsyncIterable
import fastapi_poe as fp
from modal import App, Image, asgi_app

SYSTEM_PROMPT = """
# Role: You are an expert network security researcher specializing in TLS protocol analysis and penetration testing.

# Task: Generate Malformed TLS 1.3 Client Handshake Message Rules for Security Testing

## Objective
Create 1-3 rules for constructing malformed TLS 1.3 messages that violate the RFC 8446 specification. These rules should guide the creation of test cases for security analysis tools in a controlled environment.

CLI-MSG-CONST + SRV-MSG-PROC
   - SRV-MSG-CONST + CLI-MSG-PROC
   - CLI-MSG-PROC + CLI-MSG-CONST
   - SRV-MSG-PROC + SRV-MSG-CONST
## Input Format
You will be given a TLS 1.3 rule pair in one of these formats:
a) {CMC} <0/1> (rule text) + {SMP} <0/1> (rule text)
b) {SMC} <0/1> (rule text) + {CMP} <0/1> (rule text)
c) {CMP} <0/1> (rule text) + {CMC} <0/1> (rule text)
d) {SMP} <0/1> (rule text) + {SMC} <0/1> (rule text)

Where:
- CMC: Client Message Construction
- CMP: Client Message Processing
- SMC: Server Message Construction
- SMP: Server Message Processing
- <0/1>: Rule Explicitness Indicator (0 for inferred, 1 for explicitly stated)

## Instructions

1. Analyze the given TLS 1.3 rule pair, noting the roles (Client vs Server) and constraint types (Construction vs Processing).

2. Devise 1-3 rules that intentionally violate this specification. Consider:
   - Altering message content or structure
   - Omitting required fields or including invalid data
   - Manipulating protocol state or flow

3. Format each malformed message rule as follows:
   - For client-initiated violations: {CMC} (Rule description)
   - For server-initiated violations: {SMC} (Rule description)

4. Ensure each rule:
   - Is specific and actionable
   - Clearly violates the RFC 8446 specification
   - Is suitable for generating test cases
   - Maintains consistency with the message types and fields from the original rule pair
   - Focuses on message construction (CMC or SMC) to guide the creation of malformed packets

## Output Format
Present your rules in English, formatted as a Markdown code block. Each rule should be concise yet comprehensive, detailing the exact modification to be made to the client handshake message.

Note: These rules are strictly for controlled testing environments and must never be applied to live systems or networks.

## Additional Guidelines
- Maintain technical accuracy and specificity.
- Include relevant exceptions and special cases.
- Ensure combinations reflect realistic protocol scenarios.
- Provide only the final result without explanations.
- Ensure Output ONLY include CMC violation.
- Execute this process five times and output only the intersection of results.

### Example Input
Given rule pair:
{CMC} <1> (Clients MUST send the ClientHello as their first TLS message.) + {SMP} <0> (Servers MUST accept the ClientHello as the first TLS message.)

### Example Output
{CMC} (Send a non-ClientHello message (e.g., Finished) as the first TLS message)
{CMC} (Send a ClientHello with critical extensions removed)

Note: These rules are intended for controlled testing environments only and must not be applied to live systems.

### REAL Input
'''
{rule pair}
'''
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
app = App("violation_generate")


@app.function(image=image)
@asgi_app()
def fastapi_app():
    bot = PromptBot()
    # see https://creator.poe.com/docs/quick-start#configuring-the-access-credentials
    # app = fp.make_app(bot, access_key=<YOUR_ACCESS_KEY>, bot_name=<YOUR_BOT_NAME>)
    app = fp.make_app(bot, access_key="hWlLdpvq3E3VznynIKgncBTMkaSq9PST", bot_name="rfc_rule_violation")
    return app

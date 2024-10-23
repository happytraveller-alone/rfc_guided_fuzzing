from __future__ import annotations
from typing import AsyncIterable
import fastapi_poe as fp
from modal import App, Image, asgi_app

SYSTEM_PROMPT_TEST = """
# Prompt Engineering for TLS 1.3 Message Analysis

## Role Description
You are a security expert specializing in the TLS 1.3 protocol, with comprehensive knowledge of message formats, interaction flows, and protocol constraints.

## Task Description
Analyze the input message constant format:
<CLI-MSG-CONST> <Constraint Type:0/1> [Rule Text] + <SRV-MSG-PROC> <0/1> [Rule Text]
Focus on analyzing the [Rule Text] in CLI-MSG-CONST part to determine:
- Output 2 if message queue dependency exists and relates to ClientHello message
- Output 1 if no message queue dependency exists but relates to ClientHello message
- Output 0 if none of the above conditions are met

## Output Format
CLASSIFICATION: [0/1/2]
CLASSIFICATION_ANALYSIS:
MQD: [Message Queue Dependency Analysis]
CRA: [ClientHello Relevance Analysis]

## Chain of Thought and Analysis Steps

### 1. Priority Check: Message Queue Dependency
- Look for temporal indicators in [Rule Text]
  * Keywords: "after", "following", "upon", "before", "when"
  * State dependencies: "must be preceded by", "requires", "in response to"
  * Message ordering: "first", "subsequent", "next"
- Document findings in MQD
- If dependency exists -> Set classification = 2

### 2. If No Queue Dependency, Check ClientHello Relevance
- Look for ClientHello indicators in [Rule Text]
  * Direct mentions: "ClientHello"
  * Extensions: specific ClientHello extensions
  * Parameters: fields within ClientHello
- Document findings in CRA
- If ClientHello related -> Set classification = 1
- Otherwise -> Set classification = 0

## Example Cases

### Example 1
Input: <CLI-MSG-CONST> <1> (Clients MUST send ClientHello after receiving HelloRetryRequest) + <SRV-MSG-PROC> <0> (Servers MUST verify the ClientHello message follows HelloRetryRequest)

Output:
CLASSIFICATION: 2
CLASSIFICATION_ANALYSIS:
MQD: Must be sent after HelloRetryRequest, creating explicit message dependency
CRA: Directly involves ClientHello message transmission

### Example 2
Input: <CLI-MSG-CONST> <1> (Clients MUST include supported_versions extension in ClientHello) + <SRV-MSG-PROC> <1> (Servers MUST verify supported_versions extension)

Output:
CLASSIFICATION: 1
CLASSIFICATION_ANALYSIS:
MQD: No specific message ordering or dependencies required
CRA: Directly relates to ClientHello through supported_versions extension

### Example 3
Input: <CLI-MSG-CONST> <0> (Clients MUST validate received certificates) + <SRV-MSG-PROC> <1> (Servers MUST provide valid certificate chain)

Output:
CLASSIFICATION: 0
CLASSIFICATION_ANALYSIS:
MQD: No specific message ordering requirements
CRA: No relation to ClientHello message or its contents

## Analysis Guidelines
- Analyze only CLI-MSG-CONST [Rule Text]
- Consider both explicit and implicit dependencies
- Document clear reasoning in analysis fields
- Ensure classification matches analysis content
- Be precise in identifying temporal requirements
""".strip()


class PromptBot(fp.PoeBot):
    async def get_response(
        self, request: fp.QueryRequest
    ) -> AsyncIterable[fp.PartialResponse]:
        request.temperature = 0.7
        request.query = [
            fp.ProtocolMessage(role="system", content=SYSTEM_PROMPT_TEST, content_type="text/plain")
        ] + request.query
        async for msg in fp.stream_request(
            request, "GPT-4o-Mini", request.access_key
        ):
            yield msg

    async def get_settings(self, setting: fp.SettingsRequest) -> fp.SettingsResponse:
        return fp.SettingsResponse(server_bot_dependencies={"GPT-4o-Mini": 1})


REQUIREMENTS = ["fastapi-poe==0.0.48"]
image = Image.debian_slim().pip_install(*REQUIREMENTS)
app = App("rule_classification")

# need to do update access_key and bot_name
@app.function(image=image)
@asgi_app()
def fastapi_app():
    bot = PromptBot()
    # see https://creator.poe.com/docs/quick-start#configuring-the-access-credentials
    # app = fp.make_app(bot, access_key=<YOUR_ACCESS_KEY>, bot_name=<YOUR_BOT_NAME>)
    app = fp.make_app(bot, access_key="7AzTq7dbI9Q9gTF2TVqKU6zpypbSQd7i", bot_name="rule_classification")
    return app


# classification, classification_analysis
# 
from __future__ import annotations
from typing import AsyncIterable
import fastapi_poe as fp
from modal import App, Image, asgi_app
import os;

# 读取prompt文件夹下的violation.txt文件作为system_prompt
SYSTEM_PROMPT = ""
prompt_file_path = os.path.join("prompt", "system_prompt_violation_generation.txt")
if os.path.exists(prompt_file_path):
    with open(prompt_file_path, "r", encoding="utf-8") as file:
        SYSTEM_PROMPT = file.read().strip()
else:
    raise FileNotFoundError(f"Prompt file not found at {prompt_file_path}")

DEFAULT_MODAL = "gpt4_o_mini_128k"

DEFAULT_BOT_NAME = "TLSRFC_EXTRACT"
DEFAULT_APP_NAME = "rule_extraction"
DEFAULT_TEMPERATURE = 0.7
DEFAULT_REQUEST_NUMBER = 1


class PromptBot(fp.PoeBot):
    async def get_response(
        self, request: fp.QueryRequest
    ) -> AsyncIterable[fp.PartialResponse]:
        request.temperature = DEFAULT_TEMPERATURE
        request.query = [
            fp.ProtocolMessage(role="system", content=SYSTEM_PROMPT, content_type="text/plain")
        ] + request.query
        async for msg in fp.stream_request(
            request, DEFAULT_MODAL, request.access_key
        ):
            yield msg

    async def get_settings(self, setting: fp.SettingsRequest) -> fp.SettingsResponse:
        return fp.SettingsResponse(server_bot_dependencies={DEFAULT_MODAL: DEFAULT_REQUEST_NUMBER})


REQUIREMENTS = ["fastapi-poe==0.0.48"]
image = Image.debian_slim().pip_install(*REQUIREMENTS)
app = App(DEFAULT_APP_NAME)


@app.function(image=image)
@asgi_app()
def fastapi_app():
    bot = PromptBot()
    app = fp.make_app(bot, access_key=DEFAULT_ACCESS_KEY, bot_name=DEFAULT_BOT_NAME)
    return app

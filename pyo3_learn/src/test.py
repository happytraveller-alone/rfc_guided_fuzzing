from poe_api_wrapper import PoeApi
tokens = {
    'p-b': "QiZtBLjGecaQJ4-iJPIPgA%3D%3D", 
    'p-lat': "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D",
}

client = PoeApi(tokens=tokens, auto_proxy=False)
data = client.get_settings()
print(data)
bot_name = "gpt4_o_mini"
response = client.send_message(bot_name, "你好，请介绍一下你自己")
for chunk in response :
    print(chunk)
    print("\n\n")
print(chunk["text"])
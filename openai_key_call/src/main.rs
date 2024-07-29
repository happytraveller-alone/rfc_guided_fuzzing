use openai_api_rs::v1::api::OpenAIClient;
use openai_api_rs::v1::chat_completion::{self, ChatCompletionRequest};
use openai_api_rs::v1::common::GPT4_O;
// use openai_api_rs::v1::common::GPT4;
// use std::env;
use std::fs;
use toml;

fn read_api_key() -> Result<String, Box<dyn std::error::Error>> {
    let config_content = fs::read_to_string("config.toml")?;
    let config: toml::Value = toml::from_str(&config_content)?;
    Ok(config["api_key"].as_str().unwrap().to_string())
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let api_key = read_api_key()?;
    let client = OpenAIClient::new(api_key);
    // let client = OpenAIClient::new(env::var("OPENAI_API_KEY").unwrap().to_string());

    let req = ChatCompletionRequest::new(
        GPT4_O.to_string(),
        vec![chat_completion::ChatCompletionMessage {
            role: chat_completion::MessageRole::user,
            content: chat_completion::Content::Text(String::from("What is bitcoin?")),
            name: None,
            tool_calls: None,
            tool_call_id: None,
        }],
    );

    let result = client.chat_completion(req).await?;
    println!("Content: {:?}", result.choices[0].message.content);
    println!("Response Headers: {:?}", result.headers);

    Ok(())
}
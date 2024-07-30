use colored::*;
use openai_api_rs::v1::api::OpenAIClient;
use openai_api_rs::v1::chat_completion::{self, ChatCompletionRequest};
use openai_api_rs::v1::common::GPT4_O;
use serde_json;
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

    let req = ChatCompletionRequest {
        model: GPT4_O.to_string(),
        messages: vec![
            chat_completion::ChatCompletionMessage {
                role: chat_completion::MessageRole::system,
                content: chat_completion::Content::Text(String::from("When I ask for help to write something, you will reply with a document that contains at least one joke or playful comment in every paragraph.")),
                name: None,
                tool_calls: None,
                tool_call_id: None,
            },
            chat_completion::ChatCompletionMessage {
                role: chat_completion::MessageRole::user,
                content: chat_completion::Content::Text(String::from("Write a thank you note to my steel bolt vendor for getting the delivery in on time and in short notice. This made it possible for us to deliver an important order.")),
                name: None,
                tool_calls: None,
                tool_call_id: None,
            },
        ],
        temperature: Some(0.0),
        top_p: None,
        n: Some(3),
        response_format: Some(serde_json::json!({ "type": "text" })),
        stream: None,
        stop: None,
        max_tokens: Some(256),
        presence_penalty: None,
        frequency_penalty: None,
        logit_bias: None,
        user: None,
        seed: None,
        tools: None,
        parallel_tool_calls: None,
        tool_choice: None,
    };
    let result = client.chat_completion(req).await?;
    println!(
        "{} {:?}",
        "Content:".green(),
        result.choices[0].message.content
    );

    println!("\n{} {:?}", "Response Headers:".green(), result.headers);

    Ok(())
}

# OpenAI API Rust Client

这个项目是一个使用 Rust 语言编写的 OpenAI API 客户端示例。它演示了如何使用 `openai_api_rs` 库来与 OpenAI 的 GPT-4 模型进行交互。

## 功能

- 从配置文件中读取 API 密钥
- 使用 OpenAI 的 GPT-4 模型生成对话回复
- 异步处理 API 请求
- 打印 API 响应内容和头信息

## 依赖

- `openai_api_rs`: OpenAI API 的 Rust 客户端库
- `tokio`: 异步运行时
- `toml`: 用于解析 TOML 配置文件
- `std::fs`: 用于文件系统操作

## 配置

在项目根目录创建一个 `config.toml` 文件，并添加以下内容：

```toml
api_key = "your_openai_api_key_here"
```
将 your_openai_api_key_here 替换为您的实际 OpenAI API 密钥。

## 使用方法

确保您已经安装了 Rust 和 Cargo。克隆此仓库。在项目根目录创建 config.toml 文件并添加您的 API 密钥。

## 代码说明
- read_api_key() 函数从 config.toml 文件中读取 API 密钥。
- main() 函数是程序的入口点，它设置 OpenAI 客户端并发送一个简单的对话请求。
- 当前代码使用 GPT-4 模型（GPT4_O）并询问 "What is bitcoin?"。
- 响应内容和头信息会被打印到控制台。

## 注意事项
代码中包含了一些被注释掉的替代选项，如使用环境变量获取 API 密钥和使用不同的 GPT-4 模型版本。
确保您的 OpenAI 账户有足够的配额来使用 GPT-4 模型。
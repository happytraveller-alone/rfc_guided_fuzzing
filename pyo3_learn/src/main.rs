use pyo3::prelude::*;
use pyo3::types::PyDict;
use std::error::Error;
use std::process::Command;
// 假设这是完整的 PoeClient 实现
struct PoeClient<'py> {
    client: Bound<'py, PyAny>,
    // py: Python<'py>,
}

impl<'py> PoeClient<'py> {
    fn new(py: Python<'py>) -> PyResult<Self> {
        println!("Starting to initialize PoeClient...");
        
        let tokens = PyDict::new_bound(py);
        tokens.set_item("p-b", "QiZtBLjGecaQJ4-iJPIPgA%3D%3D")?;
        tokens.set_item("p-lat", "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D")?;

        // 2. 检查poe_api_wrapper是否可以导入
        println!("Attempting to import poe_api_wrapper...");
        let module = match py.import_bound("poe_api_wrapper") {
            Ok(m) => {
                println!("Successfully imported poe_api_wrapper");
                m
            },
            Err(e) => {
                println!("Error importing poe_api_wrapper: {:?}", e);
                return Err(e);
            }
        };
        let poe_api_class = module.getattr("PoeApi")?;
        let client = poe_api_class.call1((tokens,))?;

        Ok(Self { client})
    }

    // // 发送消息方法
    fn send_message(&self, bot_name: &str, message: &str) -> PyResult<String> {
        println!("Sending message to {}: {}", bot_name, message);
        // https://github.com/snowby666/poe-api-wrapper/blob/58aa4aaff1734f6dce7fb21b234393cdb0f54bf0/poe_api_wrapper/api.py#L664
        let generator = self.client.call_method1("send_message", (bot_name, message))?;
        let py = self.client.py();
        // print!("succeed to get response");
        let builtins = py.import_bound("builtins")?;
        let list_fn = builtins.getattr("list")?;
        let chunks = list_fn.call1((generator,))?;
        // print!("succeed to get list");
        let last_chunk = chunks.get_item(-1)?;
        // print!("succeed to get last chunk");
        let text = last_chunk.get_item("text")?.extract::<String>()?;
        // print!("succeed to get text");
        let chat_id  = last_chunk.get_item("chatId")?.extract::<i128>()?;
        let chat_code = last_chunk.get_item("chatCode")?.extract::<String>()?;
        println!("Chat ID: {}; Chat Code: {}", chat_id, chat_code);
        // https://github.com/snowby666/poe-api-wrapper/blob/58aa4aaff1734f6dce7fb21b234393cdb0f54bf0/poe_api_wrapper/api.py#L897
        self.client.call_method1("purge_conversation", (bot_name, chat_id, chat_code, 0, true))?;
        // https://github.com/snowby666/poe-api-wrapper/blob/58aa4aaff1734f6dce7fb21b234393cdb0f54bf0/poe_api_wrapper/api.py#L940
        self.client.call_method1("delete_chat", (bot_name, chat_id))?;
        Ok(text)
    }

    fn print_settings(&self) -> PyResult<()> {
        let settings = self.client.call_method0("get_settings")?;
        // let settings_str = settings.repr()?.extract::<String>()?;
        // println!("Settings content: {}", settings_str);
        // 尝试将settings转换为PyDict
        if let Ok(settings_dict) = settings.downcast::<PyDict>() {
            println!("\nIterating through settings dictionary:");
            for (key, value) in settings_dict.iter() {
                println!("Key: {:?}, Value: {:?}", key, value);
            }
        } else {
            println!("Settings is not a dictionary");
            // 如果不是字典，尝试获取其类型信息
            println!("Settings type: {:?}", settings.get_type());
        }

        Ok(())
    }

}

fn get_package_version_pip(package_name: &str) -> Result<String, Box<dyn std::error::Error>> {
    let output = Command::new("pip")
        .args(&["show", package_name])
        .output()?;
    
    let output_str = String::from_utf8(output.stdout)?;
    
    // 解析输出找到版本
    for line in output_str.lines() {
        if line.starts_with("Version: ") {
            return Ok(line["Version: ".len()..].to_string());
        }
        if line.starts_with("Location: ") {
            return Ok(line["Location: ".len()..].to_string());
        }
    }
    
    Err("Version not found".into())
}

fn main() -> Result<(), Box<dyn Error>> {
    Python::with_gil(|py| -> PyResult<()> {
        let sys = py.import_bound("sys")?;
        println!("Python version: {}", sys.getattr("version")?);
        println!("Python executable: {}", sys.getattr("executable")?);
        match get_package_version_pip("poe-api-wrapper") {
            Ok(version) => println!("poe-api-wrapper version: {}", version),
            Err(e) => println!("Error getting version: {}", e),
        }
        let path = sys.getattr("path")?;
        path.call_method1("append", ("C:\\Users\\xyf20\\Desktop\\RustDataProcess\\python_virtual_env\\Lib\\site-packages",))?;
        let path_list_store: Vec<String> = path.extract()?;
        println!("PyO3 Python path:");
        for p in path_list_store {
            println!("  {}", p);
        }

        
        match py.import_bound("poe_api_wrapper") {
            Ok(_) => println!("Successfully imported poe-api-wrapper after path addition"),
            Err(e) => println!("Still failed to import: {:?}", e),
        }
       
        // // 1. 创建客户端实例
        let client = PoeClient::new(py)?;
        client.print_settings()?;

        // // 3. 发送消息给指定的bot（这里用"Claude-instant"作为例子）
        let bot_name = "gpt4_o_mini";
        
        // // 4. 发送一条消息并获取响应
        let response = client.send_message(bot_name, "你好，请介绍一下你自己")?;
        println!("Bot response: {}", response);

        // // 5. 继续对话
        // let follow_up_response = client.send_message(bot_name, "你能做些什么？")?;
        // println!("Follow-up response: {}", follow_up_response);

        // // 6. 如果需要清除对话上下文
        // client.clear_context(bot_name)?;

        Ok(())
    })?;

    Ok(())
}
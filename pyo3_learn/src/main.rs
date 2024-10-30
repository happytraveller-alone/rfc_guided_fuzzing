use pyo3::prelude::*;
use pyo3::types::PyDict;
use std::error::Error;
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};
use std::collections::HashMap;

#[derive(Debug)]
enum PoeError {
    Timeout,
    ServerDisconnected,
    Other(String),
}

impl From<PyErr> for PoeError {
    fn from(err: PyErr) -> Self {
        let err_str = err.to_string();
        if err_str.contains("Timed out") {
            PoeError::Timeout
        } else if err_str.contains("Server disconnected") {
            PoeError::ServerDisconnected
        } else {
            PoeError::Other(err_str)
        }
    }
}
struct SharedPoeClient {
    client: PyObject,  // 等同于 Py<PyAny>，可以安全地在线程间共享
    last_request_time: Arc<Mutex<Instant>>,
}

impl SharedPoeClient {
    fn new(py: Python) -> PyResult<Self> {
        let tokens = PyDict::new_bound(py);
        tokens.set_item("p-b", "QiZtBLjGecaQJ4-iJPIPgA%3D%3D")?;
        tokens.set_item("p-lat", "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D")?;

        let module = py.import_bound("poe_api_wrapper")?;
        let poe_api_class = module.getattr("PoeApi")?;
        // 将Python对象转换为PyObject以便在线程间共享
        let client = poe_api_class.call1((tokens,))?.into_py(py);

        Ok(Self { 
            client,
            last_request_time: Arc::new(Mutex::new(Instant::now()))
        })

    }

    fn send_message(&self, bot_name: &str, message: &str) -> PyResult<String> {
        // 确保请求间隔至少500ms
        {
            let mut last_time = self.last_request_time.lock().unwrap();
            let elapsed = last_time.elapsed();
            if elapsed < Duration::from_secs(1) {
                thread::sleep(Duration::from_secs(1) - elapsed);
            }
            *last_time = Instant::now();
        }

        Python::with_gil(|py| {
            // 将PyObject转换为Bound引用
            let client = self.client.bind(py);
            let generator = client.call_method1("send_message", (bot_name, message))?;
            
            let builtins = py.import_bound("builtins")?;
            let list_fn = builtins.getattr("list")?;
            let chunks = list_fn.call1((generator,))?;
            
            let last_chunk = chunks.get_item(-1)?;
            let text = last_chunk.get_item("text")?.extract::<String>()?;
            let chat_id = last_chunk.get_item("chatId")?.extract::<i128>()?;
            let chat_code = last_chunk.get_item("chatCode")?.extract::<String>()?;
            
            // 清理对话
            client.call_method1("purge_conversation", (bot_name, chat_id, chat_code, 0, true))?;
            client.call_method1("delete_chat", (bot_name, chat_id))?;
            
            Ok(text)
        })
    }
}

// 实现线程安全trait
unsafe impl Send for SharedPoeClient {}
unsafe impl Sync for SharedPoeClient {}

fn process_messages(messages: Vec<String>, bot_name: &str) -> Result<(), Box<dyn Error>> {
    let results: Arc<Mutex<HashMap<usize, String>>> = Arc::new(Mutex::new(HashMap::new()));
    let max_threads = (32.0 * 0.7) as usize;
    let active_threads = Arc::new(Mutex::new(0));
    let main_active_threads = Arc::clone(&active_threads); // 为主线程创建一个克隆
    
    // 在主线程中创建共享客户端
    let client = Python::with_gil(|py| SharedPoeClient::new(py))?;
    let client = Arc::new(client);
    
    println!("Starting message processing with {} maximum concurrent threads...", max_threads);
    let start_time = std::time::Instant::now();

    // 渐进式启动策略
    let mut current_max_threads = 1;
    let success_count = Arc::new(Mutex::new(0));
    let failure_streak = Arc::new(Mutex::new(0));

    for (index, message) in messages.iter().enumerate() {
        let message = message.clone();
        let bot_name = bot_name.to_string();
        let results = Arc::clone(&results);
        let client = Arc::clone(&client);
        let active_threads = Arc::clone(&active_threads);
        let success_count = Arc::clone(&success_count);
        let failure_streak = Arc::clone(&failure_streak);
        
        // 等待可用线程
        while *main_active_threads.lock().unwrap() >= current_max_threads {
            thread::sleep(Duration::from_millis(100));
        }

        // 增加活跃线程计数 - 这行很重要！
        {
            let mut count = main_active_threads.lock().unwrap();
            *count += 1;
        }

        // 动态调整线程数
        {
            let current_success = *success_count.lock().unwrap();
            let current_failures = *failure_streak.lock().unwrap();
            
            if current_success >= 5 && current_max_threads < max_threads {
                current_max_threads = (current_max_threads * 2).min(max_threads);
                *success_count.lock().unwrap() = 0;
                println!("Increasing max threads to {}", current_max_threads);
            }
            if current_failures >= 3 && current_max_threads > 1 {
                current_max_threads = (current_max_threads / 2).max(1);
                *failure_streak.lock().unwrap() = 0;
                println!("Decreasing max threads to {}", current_max_threads);
            }
        }
        
        // 调整等待策略
        if index > 0 {
            let wait_time = if index % 10 == 0 {
                // 每10个请求后休息较长时间
                5
            } else {
                // 每个请求之间的间隔
                2
            };
            println!("Waiting for {} seconds before next request...", wait_time);
            thread::sleep(Duration::from_secs(wait_time));
        }

        thread::spawn(move || {
            const MAX_RETRIES: u32 = 8;
            let mut success = false;
            
            for retry in 0..MAX_RETRIES {
                let wait_time = match client.send_message(&bot_name, &message) {
                    Ok(response) => {
                        println!("Thread {} succeeded on attempt {}", index, retry + 1);
                        results.lock().unwrap().insert(index, response);
                        success = true;
                        break;
                    }
                    Err(e) => {
                        // 根据错误类型返回不同的等待时间
                        let base_wait = match PoeError::from(e) {
                            PoeError::Timeout => {
                                eprintln!("Thread {}: Timeout on attempt {}", index, retry + 1);
                                6 // 超时时使用较长的等待时间
                            }
                            PoeError::ServerDisconnected => {
                                eprintln!("Thread {}: Server disconnected on attempt {}", index, retry + 1);
                                9 // 服务器断开时使用更长的等待时间
                            }
                            PoeError::Other(err) => {
                                eprintln!("Thread {}: Other error on attempt {}: {}", index, retry + 1, err);
                                3 // 其他错误使用标准等待时间
                            }
                        };
                        
                        if retry < MAX_RETRIES - 1 {
                            // 使用指数退避，但基于错误类型的等待时间
                            base_wait * (2u64.pow(retry))
                        } else {
                            0 // 最后一次重试不需要等待
                        }
                    }
                };
    
                if wait_time > 0 {
                    thread::sleep(Duration::from_secs(wait_time));
                }
            }
    
            // 更新成功/失败计数
            if success {
                *success_count.lock().unwrap() += 1;
                *failure_streak.lock().unwrap() = 0;
            } else {
                *failure_streak.lock().unwrap() += 1;
                *success_count.lock().unwrap() = 0;
            }
    
            let mut count = active_threads.lock().unwrap();
            *count -= 1;
            println!("Thread {} completed", index);
        });
    
        // 速率限制
        // 速率限制，但添加更多日志
        if index % 10 == 9 {
            println!("Taking a break after {} messages...", index + 1);
            thread::sleep(Duration::from_secs(3));
        }
    }

    // 等待所有线程完成
    println!("Waiting for all threads to complete...");
    while *main_active_threads.lock().unwrap() > 0 {
        let current = *main_active_threads.lock().unwrap();
        println!("Still waiting... {} active threads", current);
        thread::sleep(Duration::from_secs(5));
    }

    // 输出结果统计
    let duration = start_time.elapsed();
    let results = results.lock().unwrap();
    println!("\nProcessing completed in {:?}", duration);
    println!("Successfully processed {} out of {} messages", results.len(), messages.len());
    
    // 按序号打印结果
    let mut sorted_results: Vec<_> = results.iter().collect();
    sorted_results.sort_by_key(|&(k, _)| k);
    for (index, response) in sorted_results {
        println!("\nMessage {}: Response length: {} characters", index, response.len());
        println!("Response preview: {:.100}...", response);
    }

    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    // 生成50条测试消息
    let test_messages: Vec<String> = (0..20)
        .map(|i| format!("Test message {}: Please provide a brief explanation of Rust programming language", i))
        .collect();
    
    println!("Starting to process {} messages...", test_messages.len());
    process_messages(test_messages, "gpt4_o_mini")?;
    
    Ok(())
}
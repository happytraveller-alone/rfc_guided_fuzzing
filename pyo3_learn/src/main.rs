use pyo3::prelude::*;
use pyo3::types::PyDict;
use std::error::Error;
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};
use std::collections::HashMap;
use num_cpus;
use std::process::Command;
use tokio::sync::Semaphore;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::fs::File;
use csv::{Reader,Writer};
use serde_json::Value;
use serde_json::json;
use csv::StringRecord;
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
    request_semaphore: Arc<Semaphore>, // 新增信号量
}

impl SharedPoeClient {
    fn new(py: Python) -> PyResult<Self> {
        let tokens = PyDict::new_bound(py);
        tokens.set_item("p-b", "QiZtBLjGecaQJ4-iJPIPgA%3D%3D")?;
        tokens.set_item("p-lat", "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D")?;

        let output = Command::new("pip")
        .args(&["show", "poe_api_wrapper"])
        .output()?;
    
        let output_str = String::from_utf8(output.stdout)?;
    
        // 解析输出找到版本
        let location = output_str
            .lines()
            .find(|line| line.starts_with("Location: "))
            .map(|line| line["Location: ".len()..].trim().to_string());
        match &location {
            Some(loc) => println!("location: {}", loc),
            None => println!("No location found")
        }
        let path = py.import_bound("sys")?.getattr("path")?;
        path.call_method1("append", (location.unwrap_or_default(),))?;
        let module = py.import_bound("poe_api_wrapper")?;
        let poe_api_class = module.getattr("PoeApi")?;
        // 将Python对象转换为PyObject以便在线程间共享
        let client = poe_api_class.call1((tokens,))?.into_py(py);

        Ok(Self { 
            client,
            last_request_time: Arc::new(Mutex::new(Instant::now())),
            request_semaphore: Arc::new(Semaphore::new(5)) // 初始化为5个并发许可
        })

    }

    async fn send_message(&self, bot_name: &str, message: &str) -> PyResult<String> {
        // 获取信号量许可
        let _permit = self.request_semaphore.acquire().await.unwrap();
        // 确保请求间隔至少2s
        {
            let mut last_time = self.last_request_time.lock().unwrap();
            let elapsed = last_time.elapsed();
            if elapsed < Duration::from_secs(5) {
                thread::sleep(Duration::from_secs(5) - elapsed);
            }
            *last_time = Instant::now();
        }

        let result = Python::with_gil(|py| {
            // let sys = py.import_bound("sys")?;
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
        });

        // permit在作用域结束时自动释放
        result
    }
}

// 实现线程安全trait
unsafe impl Send for SharedPoeClient {}
unsafe impl Sync for SharedPoeClient {}

async fn process_messages(messages: Vec<String>, bot_name: &str, results: Arc<Mutex<HashMap<usize, String>>>) -> Result<(), Box<dyn Error>> {
    // let results: Arc<Mutex<HashMap<usize, String>>> = Arc::new(Mutex::new(HashMap::new()));
    
    let cpu_count = num_cpus::get();
    let cpu_count_physical = num_cpus::get_physical();
    println!("System has {} logical cores ({} physical cores)", cpu_count, cpu_count_physical);

    let max_threads = (cpu_count_physical as f64 * 1.5)
        .min(cpu_count as f64)
        .min(20.0)
        .max(4.0)
        as usize;
    let initial_threads = (max_threads as f64 * 0.5).ceil() as usize;
    let mut current_max_threads = initial_threads;
    
    let active_threads = Arc::new(Mutex::new(0));
    let main_active_threads = Arc::clone(&active_threads);
    
    let client = Python::with_gil(|py| SharedPoeClient::new(py))?;
    let client = Arc::new(client);
    
    println!("Starting message processing with {} maximum concurrent threads...", max_threads);
    let start_time = std::time::Instant::now();

    let success_count = Arc::new(Mutex::new(0));
    let failure_streak = Arc::new(Mutex::new(0));
    let total_processed = Arc::new(Mutex::new(0));
    let completed = Arc::new(AtomicUsize::new(0));
    
    let last_check_time = Arc::new(Mutex::new(Instant::now()));
    let messages_since_last_check = Arc::new(Mutex::new(0));

    let message_len = messages.len();
    let chunk_size = 5;

    // 计算总超时时间
    let calculate_timeout = |chunk_size: usize| {
        let base_time = chunk_size as u64 * 5;
        let buffer_time = (chunk_size as f64).sqrt() as u64 * 10;
        let retry_buffer = (chunk_size as u64 * 10 / 100) * 10;
        let total_timeout = base_time + buffer_time + retry_buffer;
        Duration::from_secs(total_timeout.clamp(120, 600)) // 2-10分钟之间
    };

    println!("Processing messages in chunks of {}", chunk_size);

    for (chunk_index, chunk) in messages.chunks(chunk_size).enumerate() {
        let mut chunk_handles = Vec::new();
        let chunk_start_index = chunk_index * chunk_size;
        let timeout = calculate_timeout(chunk.len());
        
        println!("\nProcessing chunk {} with {} messages", chunk_index + 1, chunk.len());
        println!("Chunk timeout set to {:?}", timeout);

        for (offset, message) in chunk.iter().enumerate() {
            let message = message.clone();
            let bot_name = bot_name.to_string();
            let results = Arc::clone(&results);
            let client = Arc::clone(&client);
            let active_threads = Arc::clone(&active_threads);
            let success_count = Arc::clone(&success_count);
            let failure_streak = Arc::clone(&failure_streak);
            let total_processed = Arc::clone(&total_processed);
            let completed = Arc::clone(&completed);
            let last_check_time = Arc::clone(&last_check_time);
            let messages_since_last_check = Arc::clone(&messages_since_last_check);
            
            let absolute_index = chunk_start_index + offset;

            while *main_active_threads.lock().unwrap() >= current_max_threads {
                let mut last_time = last_check_time.lock().unwrap();
                let mut msgs_count = messages_since_last_check.lock().unwrap();
                let elapsed = last_time.elapsed();
                
                if elapsed >= Duration::from_secs(30) {
                    let throughput = *msgs_count as f64 / elapsed.as_secs_f64();
                    println!("Current throughput: {:.2} messages/second", throughput);
                    *last_time = Instant::now();
                    *msgs_count = 0;
                }
                
                tokio::time::sleep(Duration::from_millis(100)).await;
            }

            {
                let mut count = main_active_threads.lock().unwrap();
                *count += 1;
            }

            // 性能自适应
            {
                let current_success = *success_count.lock().unwrap();
                // let current_failures = *failure_streak.lock().unwrap();
                let total = *total_processed.lock().unwrap();
                
                if total > 0 && total % 5 == 0 {
                    let success_rate = current_success as f64 / total as f64;
                    println!("Current success rate: {:.2}%", success_rate * 100.0);
                    
                    if success_rate > 0.8 && current_max_threads < max_threads {
                        current_max_threads = (current_max_threads * 3 / 2).min(max_threads);
                        println!("Increasing threads to {} based on good performance", current_max_threads);
                    } else if success_rate < 0.5 && current_max_threads > initial_threads {
                        current_max_threads = (current_max_threads * 2 / 3).max(initial_threads);
                        println!("Decreasing threads to {} based on poor performance", current_max_threads);
                    }
                }
            }

            let handle = tokio::spawn(async move {
                const MAX_RETRIES: u32 = 8;
                let mut success = false;
                
                for retry in 0..MAX_RETRIES {
                    match client.send_message(&bot_name, &message).await {
                        Ok(response) => {
                            println!("Message {} succeeded on attempt {}", absolute_index, retry + 1);
                            results.lock().unwrap().insert(absolute_index, response.clone());
                            success = true;
                            completed.fetch_add(1, Ordering::SeqCst);
                            println!("Progress: {}/{}", completed.load(Ordering::SeqCst), message_len);
                            break;
                        }
                        Err(e) => {
                            let wait_time = match PoeError::from(e) {
                                PoeError::Timeout => {
                                    eprintln!("Message {}: Timeout on attempt {}", absolute_index, retry + 1);
                                    4
                                }
                                PoeError::ServerDisconnected => {
                                    eprintln!("Message {}: Server disconnected on attempt {}", absolute_index, retry + 1);
                                    5
                                }
                                PoeError::Other(err) => {
                                    eprintln!("Message {}: Other error on attempt {}: {}", absolute_index, retry + 1, err);
                                    3
                                }
                            };
                            
                            if retry < MAX_RETRIES - 1 {
                                let wait = wait_time * (2u64.pow(retry));
                                tokio::time::sleep(Duration::from_secs(wait)).await;
                            }
                        }
                    }
                }
        
                if success {
                    *success_count.lock().unwrap() += 1;
                    *failure_streak.lock().unwrap() = 0;
                } else {
                    *failure_streak.lock().unwrap() += 1;
                    *success_count.lock().unwrap() = 0;
                }
        
                let mut count = active_threads.lock().unwrap();
                *count -= 1;
                println!("Message {} in chunk {} completed", absolute_index, chunk_index + 1);
            });

            chunk_handles.push(handle);
            *total_processed.lock().unwrap() += 1;
            *messages_since_last_check.lock().unwrap() += 1;
        }

        // 等待当前chunk完成或超时
        println!("Waiting for chunk {} to complete...", chunk_index + 1);
        tokio::select! {
            _ = futures::future::join_all(chunk_handles) => {
                println!("Chunk {} completed successfully", chunk_index + 1);
                // 给一些额外时间让最后的结果写入
                tokio::time::sleep(Duration::from_secs(2)).await;
            }
            _ = tokio::time::sleep(timeout) => {
                println!("Chunk {} timeout reached after {:?}", chunk_index + 1, timeout);
                // 给正在完成的任务一些额外时间
                tokio::time::sleep(Duration::from_secs(5)).await;
            }
        }
    }

    let duration = start_time.elapsed();
    let results = results.lock().unwrap();
    println!("\nProcessing completed in {:?}", duration);
    println!("Successfully processed {} out of {} messages", results.len(), message_len);
    
    // 按序号打印结果
    let mut sorted_results: Vec<_> = results.iter().collect();
    sorted_results.sort_by_key(|&(k, _)| k);
    for (index, response) in sorted_results {
        println!("\nMessage {}: Response length: {} characters", index, response.len());
        // println!("Response preview: {:.100}...", response);
    }
    Ok(())
}

fn build_json_input(record: &csv::StringRecord, field_indices: &[usize], headers: &[String]) -> Value {
    let mut json_input = json!({});
    for &idx in field_indices {
        if idx < headers.len() {
            json_input[&headers[idx]] = Value::String(record[idx].to_string());
        }
    }
    json_input
}

fn build_field_indices(headers: &[String], input_fields: &[String]) -> Vec<usize> {
    input_fields
        .iter()
        .filter_map(|field| headers.iter().position(|h| h == field))
        .collect()
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>> {
    let mut formatted_messages: Vec<String> = Vec::new();
    let input_path = "agent_input_source/rfc8446_sections_test.csv";
    let output_path = "agent_input_source/result_wait_check.csv";

    // 复制原始文件并添加新列
    let file = File::open(input_path)?;
    let mut rdr = Reader::from_reader(file);
    let output_file = File::create(&output_path)?;
    let mut wtr = Writer::from_writer(&output_file);

    // 处理头部
    let mut headers: Vec<String> = rdr.headers()?
        .iter()
        .map(|h| h.to_string())
        .collect();
    headers.push("semantic".to_string());
    wtr.write_record(&headers)?;

    // 复制所有行
    for result in rdr.records() {
        let record = result?;
        let mut row_data: Vec<String> = record.iter().map(|s| s.to_string()).collect();
        row_data.push("default_value".to_string());
        wtr.write_record(&row_data)?;
    }

    wtr.flush()?;

    // 读取文件处理消息
    let file = File::open(input_path)?;
    let mut rdr = Reader::from_reader(file);

    let headers: Vec<String> = rdr.headers()?
        .iter()
        .map(|h| h.to_string())
        .collect();

    let input_fields = vec!["section".to_string(), "content".to_string()];
    let field_indices = build_field_indices(&headers, &input_fields);

    // 处理每条记录
    for (_, result) in rdr.records().enumerate() {
        let record = result?;
        let json_data = build_json_input(&record, &field_indices, &headers);
        formatted_messages.push(json_data.to_string());
    }

    println!("Starting to process {} messages...", formatted_messages.len());

    // 打印样本
    for (i, msg) in formatted_messages.iter().take(2).enumerate() {
        println!("Sample message {}: {}", i, msg);
    }

    // 处理消息
    let results = Arc::new(Mutex::new(HashMap::new()));
    process_messages(formatted_messages, "semantic_analysis", Arc::clone(&results)).await?;

    // 读取所有记录到内存
    let file = File::open(&output_path)?;
    let mut rdr = Reader::from_reader(file);
    let mut records: Vec<StringRecord> = Vec::new();
    for result in rdr.records() {
        records.push(result?);
    }

    // 获取 index 和 semantic 列的索引
    let headers = rdr.headers()?;
    let index_idx = headers.iter().position(|h| h == "index")
        .ok_or("Index column not found")?;
    let semantic_idx = headers.iter().position(|h| h == "semantic")
        .ok_or("Semantic column not found")?;

    // 创建新的写入器
    let output_file = File::create(&output_path)?;
    let mut wtr = Writer::from_writer(output_file);
    
    // 写入表头
    wtr.write_record(headers)?;

    // 获取结果的锁
    let results = results.lock().unwrap();

    // 更新记录并写入
    // 更新记录并写入
    for record in records {
        let mut new_row: Vec<String> = record.iter().map(|field| field.to_string()).collect();
        if let Some(index_value) = record.get(index_idx) {
            if let Ok(index_num) = index_value.parse::<usize>() {
                if let Some(semantic_value) = results.get(&index_num) {  // 使用解析后的数字作为 key
                    new_row[semantic_idx] = semantic_value.clone();
                }
            }
        }
        wtr.write_record(&new_row)?;
    }


    wtr.flush()?;

    println!("Results have been written to {}", output_path);

    Ok(())
}

use csv::{StringRecord,Reader, Writer};
use pyo3::types::{PyDict,IntoPyDict};
// use pyo3::exceptions::PyIOError;
use pyo3::prelude::*;
use std::{collections::HashMap,error::Error,fs::File,process::{Command,exit}, sync::Mutex as SyncMutex};
use std::path::{Path,PathBuf};
use std::io::{self, Error as io_Error, ErrorKind};
use colored::*;
use tokio::signal;
use serde_json::{Value, json};
use serde::{Deserialize, Serialize};
use std::sync::{atomic::{AtomicUsize, Ordering},Arc};
use std::time::{Duration, Instant};
use tokio::sync::Semaphore;
use tokio::time::Duration as tokio_Duration;
use tokio::sync::Mutex;
// use rand::Rng;
use rand::{Rng, SeedableRng};
use rand::rngs::StdRng;
// 假设这是完整的 PoeClient 实现
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
    client: PyObject, // 等同于 Py<PyAny>，可以安全地在线程间共享
    last_request_time: Arc<Mutex<Instant>>,
    request_semaphore: Arc<Semaphore>, // 新增信号量
}

impl SharedPoeClient {
    fn new(py: Python) -> PyResult<Self> {
        let tokens = PyDict::new_bound(py);
        tokens.set_item("p-b", "CU8sNFOTH-2VDpKOVnfG2w%3D%3D")?;
        tokens.set_item(
            "p-lat","wL76wYPSXyCcfQQIO1HGxZNJjNG7pA1AFZn2li%2BFhw%3D%3D",
        )?;
        tokens.set_item("gql_POST", "989de63b517ec9f2a4d53fba838edd0b")?;
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
            None => println!("No location found"),
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
            request_semaphore: Arc::new(Semaphore::new(3)), // 初始化为3个并发许可
        })
    }

    fn clean_message(&self, bot_name: &str, del_all: bool){
        Python::with_gil(|py| {
            // let sys = py.import_bound("sys")?;
            // 将PyObject转换为Bound引用
            let client = self.client.bind(py);
            let _ = client.call_method1("delete_chat", (bot_name, del_all));
        });
    }

    fn print_settings(&self, bot_name: &str,) {
        let result = Python::with_gil(|py| -> PyResult<()> {
            let client = self.client.bind(py);
            let settings = client.call_method0("get_settings")?;
            
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
            let bot_info =client.call_method1("get_botInfo",(bot_name,))?;
            // 尝试将settings转换为PyDict
            if let Ok(bot_info_dict) = bot_info.downcast::<PyDict>() {
                println!("\nIterating through settings dictionary:");
                for (key, value) in bot_info_dict.iter() {
                    println!("Key: {:?}, Value: {:?}", key, value);
                }
            } else {
                println!("Settings is not a dictionary");
                // 如果不是字典，尝试获取其类型信息
                println!("Settings type: {:?}", bot_info.get_type());
            }
            Ok(())
        });
    
        // 处理可能的错误
        if let Err(e) = result {
            eprintln!("Error getting settings: {}", e);
        }
    }

    async fn send_message(&self, index: usize, bot_name: &str, message: &str, max_retry: usize) -> PyResult<String> {
        let mut final_response = String::new();
        let mut success = false;
        let mut retry = 0_usize;
        // let mut rng = rand::thread_rng();
        // 使用 StdRng 而不是 ThreadRng
        let mut rng = StdRng::from_entropy();
        while retry < max_retry {
            // 获取信号量许可，确保请求间隔
            let _permit = self.request_semaphore.acquire().await.unwrap();
            // let random_wait_secs = rng.gen_range(8..=15); // 生成 8 到 15 之间的随机数
            // 确保请求间隔至少8秒

            let mut last_time = self.last_request_time.lock().await;
            let elapsed = last_time.elapsed();
            if elapsed < tokio_Duration::from_secs(5) {
                // 如果请求间隔不足8秒，等待剩余的时间
                // 使用异步等待而不是线程阻塞
                let random_wait_secs = rng.gen_range(5..=110);
                let wait_duration = tokio_Duration::from_secs(random_wait_secs) - elapsed;
                // sleep(wait_duration).await;
                tokio::time::sleep(wait_duration).await;
            }
            // 更新请求时间
            *last_time = Instant::now();
            
            // 执行请求
            match Python::with_gil(|py| {
                let kwargs = [("timeout", 60)].into_py_dict_bound(py);
                let client = self.client.bind(py);
                let generator = client.call_method("send_message", (bot_name, message), Some(&kwargs))?;
                // sleep(Duration::from_secs(3)).await; // 异步等待2秒
                // generator.await // 等待 Python 协程执行完成
                let builtins = py.import_bound("builtins")?;
                let list_fn = builtins.getattr("list")?;
                let chunks = list_fn.call1((generator,))?;
                let last_chunk = chunks.get_item(-1)?;
                // let chat_id = last_chunk.get_item("chatId")?.extract::<i128>()?;
                // let chat_code = last_chunk.get_item("chatCode")?.extract::<String>()?;
                // 清理对话
                // client.call_method1(
                // "purge_conversation",
                // (bot_name, chat_id, chat_code, 0, true),
                // )?;
                // client.call_method1("delete_chat", (bot_name, chat_id))?;
                // let text = last_chunk.get_item("text")?.extract::<String>()?;
                match last_chunk.get_item("text")?.extract::<String>() {
                    Ok(text) => Ok(text),
                    Err(e) => Err(e),
                }
            }) {
                Ok(response) => {
                    // 请求成功
                    success = true;
                    final_response = response.clone();
                    println!(
                        "Message {} succeeded on attempt {}",
                        index,
                        retry + 1
                    );
                    break; // 成功后跳出循环
                }
                Err(e) => {
                    // 请求失败，根据不同错误类型设置等待时间
                    let wait_time = match PoeError::from(e) {
                        PoeError::Timeout => {
                            eprintln!(
                                "Message {}: Timeout on attempt {}",
                                index,
                                retry + 1
                            );
                            3
                        }
                        PoeError::ServerDisconnected => {
                            eprintln!(
                                "Message {}: Server disconnected on attempt {}",
                                index,
                                retry + 1
                            );
                            5
                        }
                        PoeError::Other(err) => {
                            eprintln!(
                                "Message {}: Other error on attempt {}: {}",
                                index,
                                retry + 1,
                                err
                            );
                            3
                        }
                    };

                    if retry < max_retry - 1 {
                        // 在允许的最大重试次数内等待指定时间并重试
                        let wait = wait_time * (2u64.pow(retry as u32));
                        tokio::time::sleep(Duration::from_secs(wait)).await;
                    }
                }
            }

            retry += 1;
        }

        // 如果成功，返回结果；否则返回错误
        if success {
            Ok(final_response)
        } else {
            eprintln!("Message {}: Failed after {} attempts", index, retry + 1);
            Err(PyErr::new::<pyo3::exceptions::PyRuntimeError, _>("Failed to send message after retries"))
        }
    }
}

// 实现线程安全trait
unsafe impl Send for SharedPoeClient {}
unsafe impl Sync for SharedPoeClient {}


async fn process_messages(
    messages: Vec<String>,
    bot_name: &str,
    results: Arc<Mutex<HashMap<usize, String>>>,
) -> Result<(), Box<dyn Error>> {
    let cpu_count = num_cpus::get();
    let cpu_count_physical = num_cpus::get_physical();
    println!(
        "System has {} logical cores ({} physical cores)",
        cpu_count, cpu_count_physical
    );

    let max_threads = (cpu_count_physical as f64 * 1.2)
        .min(cpu_count as f64)
        .min(20.0)
        .max(4.0) as usize;
    let initial_threads = (max_threads as f64 * 0.2).ceil() as usize;
    let mut current_max_threads = initial_threads;

    let active_threads = Arc::new(Mutex::new(0));
    let main_active_threads = Arc::clone(&active_threads);

    let client = Python::with_gil(|py| SharedPoeClient::new(py))?;
    let client = Arc::new(client);
    client.print_settings(bot_name);
    println!(
        "Starting processing with {} maximum concurrent threads, initial {} concurrent threads",
        max_threads,
        initial_threads,
    );
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
        Duration::from_secs(total_timeout.clamp(350, 600)) // 5-10分钟之间
    };

    println!("Processing messages in chunks of {}", chunk_size);

    for (chunk_index, chunk) in messages.chunks(chunk_size).enumerate() {
        let mut chunk_handles = Vec::new();
        let chunk_start_index = chunk_index * chunk_size;
        let timeout = calculate_timeout(chunk.len());

        println!(
            "\nProcessing chunk {} with {} messages",
            chunk_index + 1,
            chunk.len()
        );
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
            // println!("active_threads: {}", *main_active_threads.lock().await);
            while *main_active_threads.lock().await >= current_max_threads {
                let mut last_time = last_check_time.lock().await;
                let mut msgs_count = messages_since_last_check.lock().await;
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
                let mut count = main_active_threads.lock().await;
                *count += 1;
            }

            // 性能自适应
            {
                let current_success = *success_count.lock().await;
                let total = *total_processed.lock().await;

                if total > 0 && total % 5 == 0 {
                    let success_rate = current_success as f64 / total as f64;
                    println!("Current success rate: {:.2}%", success_rate * 100.0);
                    
                    if success_rate < 1.0 {
                        eprintln!("Success rate is below 100%. Exiting program.");
                        std::process::exit(1);
                    }
                    if success_rate == 1.0 && current_max_threads < max_threads {
                        current_max_threads = (current_max_threads + 1).min(max_threads);
                        println!(
                            "Increasing threads to {} based on good performance",
                            current_max_threads
                        );
                    }
                }
            }

            let handle = tokio::spawn(async move {
                const MAX_RETRIES: usize = 8;
                let mut success = false;

                match client.send_message(absolute_index + 1, &bot_name, &message, MAX_RETRIES).await {
                    Ok(response) => {
                        results.lock().await.insert(absolute_index + 1, response.clone());
                        success = true;
                        completed.fetch_add(1, Ordering::SeqCst);
                        println!(
                            "Progress: {}/{}",
                            completed.load(Ordering::SeqCst),
                            message_len
                        );
                    }
                    Err(_) => {
                        eprintln!("Message {}: Failed after retries", absolute_index);
                    }
                }

                if success {
                    *success_count.lock().await += 1;
                    *failure_streak.lock().await = 0;
                } else {
                    *failure_streak.lock().await += 1;
                    *success_count.lock().await = 0;
                }

                let mut count = active_threads.lock().await;
                *count -= 1;
                println!(
                    "Message {} in chunk {} completed",
                    absolute_index + 1,
                    chunk_index + 1
                );
            });

            chunk_handles.push(handle);
            *total_processed.lock().await += 1;
            *messages_since_last_check.lock().await += 1;
        }

        // 等待当前 chunk 完成或超时
        println!("Waiting for chunk {} to complete...", chunk_index + 1);
        tokio::select! {
            _ = futures::future::join_all(chunk_handles) => {
                println!("Chunk {} completed successfully", chunk_index + 1);
                // 给一些额外时间让最后的结果写入
                tokio::time::sleep(Duration::from_secs(10)).await;
            }
            _ = tokio::time::sleep(timeout) => {
                println!("Chunk {} timeout reached after {:?}", chunk_index + 1, timeout);
                // 给正在完成的任务一些额外时间
                tokio::time::sleep(Duration::from_secs(5)).await;
            }
            _ = signal::ctrl_c() => {
                println!("Ctrl+C received, exiting...");
                return Ok(());
            }
        }
    }

    let duration = start_time.elapsed();
    let results = results.lock().await;
    println!("\nProcessing completed in {:?}", duration);
    println!(
        "Successfully processed {} out of {} messages",
        results.len(),
        message_len
    );
    client.clean_message(bot_name, true);
    Ok(())
}



fn read_input_file(input_path: Option<PathBuf>, format: &str) -> io::Result<Reader<File>> {
    // 获取输入路径，如果为 None 则返回错误
    let path = input_path.ok_or_else(|| {
        io_Error::new(ErrorKind::NotFound, "Input path is not provided")
    })?;

    // 打印当前处理的路径
    println!("Processing file: {:?}", path);

    // 检查路径是否存在
    if !path.exists() {
        return Err(io_Error::new(
            ErrorKind::NotFound,
            format!("File does not exist: {:?}", path),
        ));
    }

    // 检查是否为目录
    if path.is_dir() {
        return Err(io_Error::new(
            ErrorKind::InvalidInput,
            format!("Path is a directory, not a file: {:?}", path),
        ));
    }

    // 检查文件扩展名
    let extension = path.extension()
        .and_then(|ext| ext.to_str())
        .ok_or_else(|| {
            io_Error::new(
                ErrorKind::InvalidInput,
                format!("File has no extension: {:?}", path),
            )
        })?;

    // 验证文件格式
    if extension != format {
        return Err(io_Error::new(
            ErrorKind::InvalidInput,
            format!("Invalid file format. Expected {}, got {}", format, extension),
        ));
    }

    // 打开文件并创建 CSV reader
    let file = File::open(&path)?;
    let reader = csv::Reader::from_reader(file);

    Ok(reader)
}

// 1. 验证和初始化
pub fn verify_script_path(script_name: &str) -> Result<(), Box<dyn Error>> {
    let script_path = Path::new("python_scripts").join(format!("{}.py", script_name));
    if !script_path.exists() {
        eprintln!("Python script not found at {:?}", script_path);
        exit(1);
    }
    println!("{}", format!("succeed to find {}.py script", script_name).green());
    Ok(())
}

// 2. 设置Python环境
pub fn setup_python_environment(py: Python) -> PyResult<()> {
    let sys = py.import_bound("sys")?;
    println!("Python version: {}", sys.getattr("version")?);
    println!("Python executable: {}", sys.getattr("executable")?);
    
    // 检查包版本
    // match get_package_version_pip("poe-api-wrapper") {
    //     Ok(version) => println!("poe-api-wrapper version: {}", version),
    //     Err(e) => println!("Error getting version: {}", e),
    // }
    
    // 设置Python路径
    let path = sys.getattr("path")?;
    path.call_method1("append", ("C:\\Users\\xyf20\\Desktop\\RustDataProcess\\python_virtual_env\\Lib\\site-packages",))?;
    
    // 打印Python路径
    let path_list_store: Vec<String> = path.extract()?;
    println!("PyO3 Python path:");
    for p in path_list_store {
        println!("  {}", p);
    }
    
    // 验证导入
    match py.import_bound("poe_api_wrapper") {
        Ok(_) => println!("Successfully imported poe-api-wrapper after path addition"),
        Err(e) => println!("Still failed to import: {:?}", e),
    }
    
    Ok(())
}

// 3. 初始化CSV读写器并处理表头
pub fn initialize_csv(
    input_path: Option<PathBuf>,
    output_path: &Path,
    format: &str,
    // additional_fields: &[String],
) -> Result<(csv::Reader<File>, csv::Writer<File>, Vec<String>, StringRecord), Box<dyn Error>> {
    let mut reader = read_input_file(input_path, format)?;
    let output_file = File::create(output_path)?;
    let mut writer = csv::Writer::from_writer(output_file);
    println!("Processing file: {:?}", output_path);
    // 源文件表头
    let headers: Vec<String> = reader.headers()?
        .iter()
        .map(|h| h.to_string())
        .collect();
    println!("Headers: {:?}", headers);
    let mut new_headers = headers.clone();
    new_headers.extend(["result"].iter().map(|&s| s.to_string()));
    writer.write_record(&new_headers)?;
    println!("New headers: {:?}", new_headers);
    Ok((reader, writer, headers, new_headers.into()))
}

// 4. 构建输入字段索引
pub fn build_field_indices(headers: &[String], input_fields: &[String]) -> Vec<usize> {
    input_fields
        .iter()
        .filter_map(|field| headers.iter().position(|h| h == field))
        .collect()
}

// 5. 构建JSON输入
pub fn build_json_input(record: &csv::StringRecord, field_indices: &[usize], headers: &[String]) -> Value {
    let mut json_input = json!({});
    for &idx in field_indices {
        if idx < headers.len() {
            json_input[&headers[idx]] = Value::String(record[idx].to_string());
        }
    }
    json_input
}


// 6. 处理消息响应
pub fn process_response(
    response: &str,
    additional_fields: &[String],
) -> Vec<String> {
    let mut values = Vec::new();
    match serde_json::from_str::<Value>(response) {
        Ok(response_json) => {
            for field in additional_fields {
                let value = response_json
                    .get(field)
                    .and_then(|v| v.as_str())
                    .unwrap_or("")
                    .to_string();
                values.push(value);
            }
        }
        Err(e) => {
            for _ in additional_fields {
                values.push(String::from(""));
            }
            eprintln!("Error parsing response JSON: {}", e);
        }
    }
    values
}

#[derive(Debug, Serialize, Deserialize)]
struct SemanticEntry {
    section_name: String,
    title: String,
    content: String,
}

#[derive(Serialize, Deserialize, Debug)]
struct Message {
    section: String,
    title: String,
    message_construction: Construction,
    message_processing: Processing,
}

#[derive(Serialize, Deserialize, Debug)]
struct Construction {
    construction_rule_type: String,
    construction_explicitness: u8,
    construction_base: String,
}

#[derive(Serialize, Deserialize, Debug)]
struct Processing {
    processing_rule_type: String,
    processing_explicitness: u8,
    processing_base: String,
}

#[derive(Serialize, Deserialize, Debug)]
struct Rule {
    section: String,
    title: String,
    construction_rule_type: String,
    construction_explicitness: u8,
    construction_base: String,
    processing_rule_type: String,
    processing_explicitness: u8,
    processing_base: String,
}



// 主函数
pub fn run_python_script(
    _script_name: &str,
    bot_name: &str,
    input_path: Option<PathBuf>,
    output_path: &Path,
    additional_fields: &[String],
    input_fields: &[String],
    format: &str,
) -> Result<(), Box<dyn Error>> {
    // 验证脚本路径
    // verify_script_path(script_name)?;

    let mut temp_file_name = output_path.file_stem().unwrap().to_os_string(); 
    temp_file_name.push("_tmp."); 
    temp_file_name.push(output_path.extension().unwrap()); 
    let temp_file_path = output_path.with_file_name(temp_file_name);
    
    if !temp_file_path.exists() {
        // 初始化CSV读写器和表头
        // 获取源文件reader
        // 获取tmp文件的writer
        // 获取源文件表头
        // 获取新文件表头
        let (mut reader, mut writer, original_headers, new_headers) = initialize_csv(
            input_path,
            temp_file_path.as_path(),
            format,
        )?;
        println!("Starting to process input fields indices: {:?}", input_fields);
        // 利用源文件表头构建字段搜索索引
        let field_indices = build_field_indices(&original_headers, input_fields);
        println!("Field indices: {:?}", field_indices);
        // 利用搜索索引,遍历源文件每一行,构建LLM JSON格式化输入
        // 同时对tmp文件新添加列(result)填入默认值
        let mut formatted_messages = Vec::new();
        for result in reader.records() {
            let record = result?;
            // 为输出文件准备行数据
            let mut row_data: Vec<String> = record.iter().map(|s| s.to_string()).collect();
            while row_data.len() < new_headers.len(){
                row_data.push("waiting fill".to_string());
            }
            writer.write_record(&row_data)?;
            // 准备消息数据
            let json_data = build_json_input(&record, &field_indices, &original_headers[..]);
            // println!("{}", json_data);
            formatted_messages.push(json_data.to_string());
        }
        println!("Formatted messages len: {:?}", formatted_messages.len());
        // 写入缓冲区刷新
        writer.flush()?;

        println!(
            "Starting to process {} messages...",
            formatted_messages.len()
        );
        // 构建tokio的异步运行时,调用POE LLM,获取结果
        let results = Arc::new(Mutex::new(HashMap::new()));
        let runtime = tokio::runtime::Runtime::new()?;
        runtime.block_on(async {
            if let Err(e) = process_messages(
                formatted_messages,
                bot_name,
                Arc::clone(&results),
            )
            .await {
                eprintln!("Error processing messages: {}", e);
            }
        });
        // 将结果按照index索引写入到tmp文件中,默认是result列的更新
        // let async_guard = results.lock().await;
        // let results_copy = results.clone(); // 创建数据的拷贝
        // let sync_results = convert_results_for_sync(Arc::clone(&results)).await;
        // 转换为同步锁保护的数据
        update_output_file(temp_file_path.as_path(), &new_headers, &results)?;
    } else {
        println!("Temp file already exists, skipping to construct new header part.");
    }

    // 读取tmp文件,逐行读取result列,根据additional_fields参数进行构建
    // 1. 首先在additional_fields vec前添加index参数,赋值为new_header 
    // 2. 将new_header作为output_path新文件的表头
    // 3. 遍历tmp文件的一行,将result列对应的单元格内容按照additional_fields进行解析,
    // 4. 将解析后的结果,按照表头对应的位置填入.
    // 5. 执行第3步
    // 6. 到达tmp文件尾,结束执行.flush写缓冲区

    // 构建新表头
    let mut new_fields: Vec<String> = vec!["index".to_string()];
    new_fields.extend_from_slice(additional_fields);

    // 直接写对应函数，用if判断调用哪个函数，用bot_name判断调用哪个写入函数
    match bot_name {
        "semantic_analysis" => {
            parse_results_semantic_analysis(temp_file_path.as_path(), output_path, new_fields)?;
        },
        "TLSRFC_EXTRACT" => {
            parse_results_rule_extract(temp_file_path.as_path(), output_path, new_fields)?;
        },
        _ => {
            eprintln!("Invalid bot name: {}", bot_name);
        }
    }
    // 将解析结果写到最终的输出文件中
    // parse_results::<SemanticEntry>(temp_file_path.as_path(), output_path, new_fields, additional_fields)?;

    
    Ok(())
}


fn update_output_file(
    output_path: &Path,
    headers: &StringRecord,
    results: &Arc<Mutex<HashMap<usize, String>>>,  // 使用异步锁类型
) -> Result<(), Box<dyn Error>> {
    // 创建一个运行时
    let rt = tokio::runtime::Runtime::new()?;

    // 使用运行时同步地获取异步锁中的数据
    let results_guard = rt.block_on(results.lock());

    // 将异步锁的数据复制到一个同步的 HashMap 中
    let results_copy = results_guard.clone();
    drop(results_guard);  // 释放异步锁

    // 创建一个同步的 Mutex 保护结果
    let sync_results = Arc::new(SyncMutex::new(results_copy));

    // 读取当前输出文件的所有记录
    let file = File::open(output_path)?;
    let mut rdr = Reader::from_reader(file);
    let records: Vec<StringRecord> = rdr.records().collect::<Result<Vec<_>, _>>()?;

    // 获取列索引
    let index_idx = headers
        .iter()
        .position(|h| h == "index")
        .ok_or("Index column not found")?;
    let result_idx = headers
        .iter()
        .position(|h| h == "result")
        .ok_or("Result column not found")?;

    // 创建新的写入器
    let output_file = File::create(output_path)?;
    let mut wtr = Writer::from_writer(output_file);

    // 写入表头
    wtr.write_record(headers)?;

    // 获取同步的结果锁
    let sync_results_guard = sync_results.lock().map_err(|e| format!("Failed to lock results: {}", e))?;

    // 更新记录并写入
    for record in records {
        let mut new_row: Vec<String> = record.iter().map(|field| field.to_string()).collect();
        if let Some(index_value) = record.get(index_idx) {
            if let Ok(index_num) = index_value.parse::<usize>() {
                if let Some(semantic_value) = sync_results_guard.get(&index_num) {
                    new_row[result_idx] = format!("\"{}\"", semantic_value.clone());
                }
            }
        }
        wtr.write_record(&new_row)?;
    }

    wtr.flush()?;
    Ok(())
}

fn parse_results_semantic_analysis(
    input_path: &Path, 
    output_path: &Path, 
    new_headers: Vec<String>,
    // fields: &[String],
) -> Result<(), Box<dyn Error>> {
    // 读取输入文件
    let file = File::open(input_path)?;
    let mut rdr = Reader::from_reader(file);
    
    // 获取 semantic 列的索引
    let headers = rdr.headers()?;
    let result_idx = headers
        .iter()
        .position(|h| h == "result")
        .ok_or("Semantic column not found")?;

    // 创建输出文件
    let output_file = File::create(output_path)?;
    let mut wtr = Writer::from_writer(output_file);

    // 写入新的表头
    wtr.write_record(&new_headers)?;

    // 用于跟踪全局索引
    let mut global_index = 1;

    // 处理每一行
    for (row_num, result) in rdr.records().enumerate() {
        let record = result?;
        let result_value = record.get(result_idx).unwrap_or("").trim();
        
        // 跳过空值和默认值
        if result_value.is_empty() || result_value == "default_value" {
            continue;
        }
        // 清理和解析 JSON
        let cleaned_json = result_value
                                        .replace("```json", "")  // 移除开始标记
                                        .replace("```", "")      // 移除结束标记
                                        .trim()                  // 移除首尾空白
                                        .to_string();
        // 调试输出
        // println!("Processing row {}, value: {}", row_num + 1, cleaned_json);

        // 尝试解析 JSON 数组
        match serde_json::from_str::<Vec<SemanticEntry>>(&cleaned_json) {
            Ok(entries) => {
                // 为每个解析出的条目写入一行
                for entry in entries {
                    wtr.write_record(&[
                        &global_index.to_string(),
                        &entry.section_name.replace("\"\"", "\""),
                        &entry.title.replace("\"\"", "\""),
                        &entry.content.replace("\"\"", "\""),
                    ])?;
                    global_index += 1;
                }
            },
            Err(e) => {
                eprintln!("Error parsing JSON at row {}: {}", row_num + 1, e);
                eprintln!("Problematic JSON: {}", result_value);
                // 可以选择继续处理或者返回错误
                // return Err(Box::new(e));
                continue;
            }
        }
    }

    wtr.flush()?;
    println!("Total parsed entries: {}", global_index);
    Ok(())
}

fn escape_csv_field(field: &str) -> String {
    let mut escaped = String::new();

    // 检查并添加首部引号
    if !field.starts_with('"') {
        escaped.push('"');
    }

    for c in field.chars() {
        // if c == '"' {
        //     escaped.push('"');
        // }
        escaped.push(c);
    }

    // 检查并添加尾部引号
    if !field.ends_with('"') {
        escaped.push('"');
    }

    escaped
}


fn parse_results_rule_extract(
    input_path: &Path, 
    output_path: &Path, 
    new_headers: Vec<String>,
    // fields: &[String],
) -> Result<(), Box<dyn Error>> {
    // 读取输入文件
    let file = File::open(input_path)?;
    let mut rdr = Reader::from_reader(file);
    
    // 获取 semantic 列的索引
    let headers = rdr.headers()?;
    let result_idx = headers
        .iter()
        .position(|h| h == "result")
        .ok_or("result column not found")?;

    // 创建输出文件
    let output_file = File::create(output_path)?;
    let mut wtr = Writer::from_writer(output_file);

    // 写入新的表头
    wtr.write_record(&new_headers)?;

    // 用于跟踪全局索引
    let mut global_index = 1;

    // 处理每一行
    for (row_num, result) in rdr.records().enumerate() {
        let record = result?;
        let result_value = record.get(result_idx).unwrap_or("").trim();
        
        // 跳过空值和默认值
        if result_value.is_empty() || result_value == "waiting fill" {
            continue;
        }
        // 清理和解析 JSON
        let cleaned_json = result_value
                                        .replace("```json", "")  // 移除开始标记
                                        .replace("```", "")      // 移除结束标记
                                        .replace("[]", "")      // 移除结束标记
                                        .replace("\"[", "[")      // 移除结束标记
                                        .replace("]\"", "]")      // 移除结束标记
                                        .trim()                  // 移除首尾空白
                                        .to_string();
        
        // 跳过空值和默认值
        if cleaned_json.is_empty() || cleaned_json == "waiting fill" {
            continue;
        }
        // 调试输出
        println!("Processing row {}, value: {}", row_num + 1, cleaned_json);

        // 尝试解析 JSON 数组
        // 尝试解析 JSON 数组
        match serde_json::from_str::<Vec<Message>>(&cleaned_json) {
            Ok(messages) => {
                // 为每个解析出的条目写入一行
                for (_index, message) in messages.iter().enumerate() {
                    let rule = Rule {
                        section: message.section.clone(),
                        title: message.title.clone(),
                        construction_rule_type: message.message_construction.construction_rule_type.clone(),
                        construction_explicitness: message.message_construction.construction_explicitness,
                        construction_base: message.message_construction.construction_base.clone(),
                        processing_rule_type: message.message_processing.processing_rule_type.clone(),
                        processing_explicitness: message.message_processing.processing_explicitness,
                        processing_base: message.message_processing.processing_base.clone(),
                    };

                    wtr.write_record(&[
                        &global_index.to_string(),
                        &rule.section,
                        &rule.title,
                        &rule.construction_rule_type,
                        &rule.construction_explicitness.to_string(),
                        &escape_csv_field(&rule.construction_base),
                        &rule.processing_rule_type,
                        &rule.processing_explicitness.to_string(),
                        &escape_csv_field(&rule.processing_base),
                    ])?;
                    global_index += 1;
                }
            },
            Err(e) => {
                eprintln!("Error parsing JSON at row {}: {}", row_num + 1, e);
                eprintln!("Problematic JSON: {}", result_value);
                // 可以选择继续处理或者返回错误
                // return Err(Box::new(e));
                continue;
            }
        }
    }

    wtr.flush()?;
    println!("Total parsed entries: {}", global_index);
    Ok(())
}


// fn parse_results<T: for<'de> Deserialize<'de> + Serialize>(
//     input_path: &Path, 
//     output_path: &Path,                                                                                                                                                                                                 
//     new_headers: Vec<String>,
//     fields: &[String],
// ) -> Result<(), Box<dyn Error>> {
//     // 读取输入文件
//     let file = File::open(input_path)?;
//     let mut rdr = Reader::from_reader(file);
    
//     // 获取 semantic 列的索引
//     let headers = rdr.headers()?;
//     let result_idx = headers
//         .iter()
//         .position(|h| h == "result")
//         .ok_or("Semantic column not found")?;

//     // 创建输出文件
//     let output_file = File::create(output_path)?;
//     let mut wtr = Writer::from_writer(output_file);

//     // 写入新的表头
//     wtr.write_record(&new_headers)?;

//     // 用于跟踪全局索引
//     let mut global_index = 1;

//     // 处理每一行
//     for (row_num, result) in rdr.records().enumerate() {
//         let record = result?;
//         let result_value = record.get(result_idx).unwrap_or("").trim();
        
//         // 跳过空值和默认值
//         if result_value.is_empty() || result_value == "default_value" {
//             continue;
//         }
//         // 清理和解析 JSON
//         let cleaned_json = result_value
//                                         .replace("```json", "")  // 移除开始标记
//                                         .replace("```", "")      // 移除结束标记
//                                         .trim()                  // 移除首尾空白
//                                         .to_string();
//         // 调试输出
//         println!("Processing row {}, value: {}", row_num + 1, cleaned_json);

//         // 尝试解析 JSON 数组
//         match serde_json::from_str::<Vec<T>>(&cleaned_json) {
//             Ok(entries) => {
//                 // 为每个解析出的条目写入一行
//                 for entry in entries {
//                     // wtr.write_record(&[
//                     //     &global_index.to_string(),
//                     //     &entry.section_name.replace("\"\"", "\""),
//                     //     &entry.title.replace("\"\"", "\""),
//                     //     &entry.content.replace("\"\"", "\""),
//                     // ])?;
//                     let mut record = vec![global_index.to_string()]; 
//                     let entry_value = serde_json::to_value(&entry)?; 
//                     for field in fields { 
//                         let value = entry_value.get(field)
//                                                        .and_then(Value::as_str)
//                                                        .unwrap_or("")
//                                                        .replace("\"\"", "\""); 
//                         record.push(value); 
//                     } 
//                     wtr.write_record(&record)?;
//                     global_index += 1;
//                 }
//             },
//             Err(e) => {
//                 eprintln!("Error parsing JSON at row {}: {}", row_num + 1, e);
//                 eprintln!("Problematic JSON: {}", result_value);
//                 // 可以选择继续处理或者返回错误
//                 // return Err(Box::new(e));
//                 continue;
//             }
//         }
//     }

//     wtr.flush()?;
//     println!("Total parsed entries: {}", global_index - 1);
//     Ok(())
// }
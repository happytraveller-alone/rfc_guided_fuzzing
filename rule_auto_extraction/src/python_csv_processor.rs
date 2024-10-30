use csv::{Reader, Writer};
use pyo3::exceptions::PyIOError;
use pyo3::prelude::*;
use pyo3::types::PyDict;
use std::fs::File;
use std::process::exit;
use std::{error::Error, process::Command};
use std::path::{Path,PathBuf};
use std::io::{self, Error as io_Error, ErrorKind};
use colored::*;
use serde_json::{Value, json};
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
    match get_package_version_pip("poe-api-wrapper") {
        Ok(version) => println!("poe-api-wrapper version: {}", version),
        Err(e) => println!("Error getting version: {}", e),
    }
    
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
    additional_fields: &[String],
) -> Result<(csv::Reader<File>, csv::Writer<File>, Vec<String>), Box<dyn Error>> {
    let mut reader = read_input_file(input_path, format)?;
    let output_file = File::create(output_path)?;
    let mut writer = csv::Writer::from_writer(output_file);
    
    let headers: Vec<String> = reader.headers()?
        .iter()
        .map(|h| h.to_string())
        .collect();
        
    let mut new_headers = headers.clone();
    new_headers.extend(additional_fields.iter().cloned());
    writer.write_record(&new_headers)?;
    
    Ok((reader, writer, headers))
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

// 主函数
pub fn run_python_script(
    script_name: &str,
    bot_name: &str,
    input_path: Option<PathBuf>,
    output_path: &Path,
    additional_fields: &[String],
    input_fields: &[String],
    format: &str,
) -> Result<(), Box<dyn Error>> {
    // 验证脚本路径
    verify_script_path(script_name)?;

    // 初始化CSV读写器和表头
    let (mut reader, mut writer, headers) = initialize_csv(
        input_path,
        output_path,
        format,
        additional_fields,
    )?;

    // 构建字段索引
    let field_indices = build_field_indices(&headers, input_fields);

    Python::with_gil(|py| -> PyResult<()> {
        // 设置Python环境
        setup_python_environment(py)?;
        
        // 初始化客户端
        let client = PoeClient::new(py)?;
        client.print_settings()?;
        
        // 处理记录
        loop {
            let mut record = csv::StringRecord::new();
            match reader.read_record(&mut record) {
                Ok(has_record) => {
                    if !has_record {
                        break;
                    }
                    
                    // 准备新记录
                    let mut new_record: Vec<String> = record.iter()
                        .map(|field| field.to_string())
                        .collect();
                    
                    // 构建JSON输入并发送消息
                    let json_input = build_json_input(&record, &field_indices, &headers);
                    let prompt = json_input.to_string();
                    
                    let response = match client.send_message(bot_name, &prompt) {
                        Ok(resp) => resp,
                        Err(e) => {
                            eprintln!("Error sending message: {}", e);
                            String::from("{}")
                        }
                    };
                    
                    // 处理响应
                    let additional_values = process_response(&response, additional_fields);
                    new_record.extend(additional_values);
                    
                    // 写入记录
                    match writer.write_record(&new_record) {
                        Ok(_) => continue,
                        Err(e) => {
                            return Err(PyIOError::new_err(format!("Failed to write record: {}", e)));
                        }
                    }
                }
                Err(e) => {
                    return Err(PyIOError::new_err(format!("Failed to read record: {}", e)));
                }
            }
        }
        
        writer.flush()?;
        Ok(())
    })?;

    Ok(())
}

// pub fn run_python_script(
//     script_name: &str,
//     bot_name: &str,
//     input_path: Option<PathBuf>,
//     output_path: &Path,
//     additional_fields: &[String],
//     input_fields: &[String],
//     format: &str,
// ) -> Result<(), Box<dyn Error>> {
//     let script_path = Path::new("python_scripts").join(format!("{}.py", script_name));
//     if !script_path.exists() {
//         eprintln!("Python script not found at {:?}", script_path);
//         exit(1);
//     }
//     println!("{}", format!("succeed to find {}.py script", script_name).green());

//     // 读取输入文件
//     let mut reader = read_input_file(input_path, format)?;
//     // 创建输出文件的writer
//     let output_file = File::create(output_path)?;
//     let mut writer = csv::Writer::from_writer(output_file);
    
//     // 1. 读取并处理表头
//     let headers: Vec<String> = reader.headers()?
//         .iter()
//         .map(|h| h.to_string())
//         .collect();
    
//     // 2. 创建新的表头（原表头 + additional_fields）
//     let mut new_headers = headers.clone();
//     new_headers.extend(additional_fields.iter().cloned());
    
//     // 写入新表头
//     writer.write_record(&new_headers)?;
    
//     // 创建字段索引映射
//     let field_indices: Vec<usize> = input_fields
//         .iter()
//         .filter_map(|field| headers.iter().position(|h| h == field))
//         .collect();
//     // let mut record = csv::StringRecord::new();
//     Python::with_gil(|py| -> PyResult<()> {
//         let sys = py.import_bound("sys")?;
//         println!("Python version: {}", sys.getattr("version")?);
//         println!("Python executable: {}", sys.getattr("executable")?);
//         match get_package_version_pip("poe-api-wrapper") {
//             Ok(version) => println!("poe-api-wrapper version: {}", version),
//             Err(e) => println!("Error getting version: {}", e),
//         }
//         let path = sys.getattr("path")?;
//         path.call_method1("append", ("C:\\Users\\xyf20\\Desktop\\RustDataProcess\\python_virtual_env\\Lib\\site-packages",))?;
//         let path_list_store: Vec<String> = path.extract()?;
//         println!("PyO3 Python path:");
//         for p in path_list_store {
//             println!("  {}", p);
//         }

        
//         match py.import_bound("poe_api_wrapper") {
//             Ok(_) => println!("Successfully imported poe-api-wrapper after path addition"),
//             Err(e) => println!("Still failed to import: {:?}", e),
//         }
       
//         // // 1. 创建客户端实例
//         let client = PoeClient::new(py)?;
//         client.print_settings()?;
        
//         loop {
//             let mut record = csv::StringRecord::new();
//             match reader.read_record(&mut record) {
//                 Ok(has_record) => {
//                     if !has_record {
//                         break;
//                     }
                    
//                     // 3. 准备写入的新记录
//                     let mut new_record = Vec::new();
                    
//                     // 复制原有数据
//                     for field in record.iter() {
//                         new_record.push(field.to_string());
//                     }
                    
//                     // 4. 构建JSON输入数据
//                     let mut json_input = json!({});
//                     for &idx in &field_indices {
//                         if idx < headers.len() {
//                             json_input[&headers[idx]] = Value::String(record[idx].to_string());
//                         }
//                     }
        
//                     // 5. 调用send_message
//                     let prompt = json_input.to_string();
//                     let response = match client.send_message(bot_name, &prompt) {
//                         Ok(resp) => resp,
//                         Err(e) => {
//                             eprintln!("Error sending message: {}", e);
//                             String::from("{}")  // 返回空JSON对象
//                         }
//                     };
        
//                     // 6. 解析响应并填充additional_fields
//                     match serde_json::from_str::<Value>(&response) {
//                         Ok(response_json) => {
//                             for field in additional_fields {
//                                 let value = response_json
//                                     .get(field)
//                                     .and_then(|v| v.as_str())
//                                     .unwrap_or("")
//                                     .to_string();
//                                 new_record.push(value);
//                             }
//                         }
//                         Err(e) => {
//                             for _ in additional_fields {
//                                 new_record.push(String::from(""));
//                             }
//                             eprintln!("Error parsing response JSON: {}", e);
//                         }
//                     }
                
//                     // 写入该行数据
//                     match writer.write_record(&new_record) {
//                         Ok(_) => continue,
//                         Err(e) => {
//                             return Err(PyIOError::new_err(format!("Failed to write record: {}", e)));
//                         }
//                     }
//                 }
//                 Err(e) => {
//                     return Err(PyIOError::new_err(format!("Failed to read record: {}", e)));
//                 }
//             }
//         }
//         // 确保所有数据都写入文件
//         writer.flush()?;
//         Ok(())
//     })?;

    
//     Ok(())
// }


    
    // // 创建子进程
    // let mut child_process = Command::new("cmd")
    //     .creation_flags(0x08000000)
    //     .args(&["/C", "python_virtual_env\\Scripts\\activate && python"])
    //     .arg(script_path.to_str().unwrap())
    //     .stdout(std::process::Stdio::piped())
    //     .stderr(std::process::Stdio::piped())
    //     .spawn()
    //     .expect(&format!("Failed to execute {}.py script", script_name));

    // // 设置 Ctrl+C 处理
    // setup_ctrlc_handler(&mut child_process)?;

    // // 等待脚本执行完毕并获取输出
    // let output = child_process
    //     .wait_with_output()
    //     .expect(&format!("Failed to wait on {}.py script", script_name));

    // // 检查脚本执行结果
    // if !output.status.success() {
    //     eprintln!("Failed to run {}.py script.", script_name);
    //     let error = String::from_utf8_lossy(&output.stderr);
    //     eprintln!("Error: {}", error);
    //     exit(1);
    // }

    // // 打印脚本的标准输出
    // let stdout = String::from_utf8_lossy(&output.stdout);
    // println!("{}.py output: {}", script_name, stdout);
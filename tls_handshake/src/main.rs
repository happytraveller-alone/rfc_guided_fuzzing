use std::{sync::Arc, thread::sleep, time::Duration, fs::File, error::Error, path::Path};
use tls_handshake::{clienthello_mutator, clienthello_parser, network_connect, server_response, terminal};
use tls_handshake::clienthello::ClientHello;
use tls_handshake::clienthello_parser::ClientHelloParser;
use tls_handshake::clienthello_mutator::TestMutation;
use rustls::{ClientConnection, Stream, ClientConfig};
use mio::{Events, Poll, Token, net::TcpStream as MioTcpStream};
use std::io::{Write, Read, ErrorKind};
use colored::*;
use std::fs::{self};

use log::{debug, error, info, trace, LevelFilter};
use log4rs::{
    append::{file::FileAppender, console::ConsoleAppender},
    config::{Appender, Config, Logger, Root},
    encode::pattern::PatternEncoder,
    filter::threshold::ThresholdFilter,
};


fn main() -> Result<(), Box<dyn std::error::Error>> {
    init_log();
    perform_local_network_test()?;

    let matches = terminal::get_command_matches();

    if matches.get_flag("use_guide") {
        terminal::print_help();
        return Ok(());
    }

    let server_name = terminal::get_server_name(&matches);
    let server_ip = terminal::get_server_ip(&matches);
    let port = terminal::get_port(&matches);
    let easy_read = matches.get_flag("easy_read");

    // Test environment preparation
    terminal::print_configuration_info(&server_name, &server_ip, port, easy_read);
    perform_server_environment_test(&server_ip, port)?;
    
    // read mutation strategy
    let mut mutation_vec_store : Vec<TestMutation> = Vec::new();
    let required_columns = ["message", "field", "action", "relative_to", "position", "value"];
    let file_path = "input_source/mutation_guideline.csv";
    let _ = read_mutation_source(file_path, &required_columns, &mut mutation_vec_store);
    println!("{}","Read mutation source".green());

    // first handshake
    let addr = format!("{}:{}", server_ip, port);
    let config = Arc::new(network_connect::create_tls_config());
    perform_first_handshake(config.clone(), server_name.clone(), addr.clone())?;
    
    // second handshake
    println!("{}","Starting second handshake...\n".green());
    let mut client_hello = Vec::new();
    let mut conn2 = ClientConnection::new(config.clone(), server_name.clone().try_into()?)?;
    conn2.write_tls(&mut client_hello)?;
    // get second client_hello template
    let parsed_clienthello = parse_client_hello_if_enabled(&matches, &client_hello, easy_read);
    // start mutation based on the template
    let mut mutated_clienthello_vec: Vec<ClientHello> = Vec::new();
    mutate_client_hello_if_enabled(&matches, &parsed_clienthello, &mutation_vec_store, &mut mutated_clienthello_vec, easy_read);
    // send mutated client_hello
    send_client_hello_if_test_env(&matches, &server_ip, port, &mut mutated_clienthello_vec, easy_read)?;
    // use guide line
    terminal::print_help();
    Ok(())
}

fn clear_logs_folder() -> std::io::Result<()> {
    let log_dir = "logs";
    let path = Path::new(log_dir);

    // 检查 logs 文件夹是否存在
    if path.exists() && path.is_dir() {
        // 获取 logs 文件夹中的所有文件
        for entry in fs::read_dir(path)? {
            let entry = entry?;
            if entry.file_type()?.is_file() {
                // 删除文件
                fs::remove_file(entry.path())?;
            }
        }
        info!("All files in 'logs' folder have been deleted.");
    } else {
        info!("'logs' folder does not exist.");
    }

    Ok(())
}

fn init_log() {
    // 清空 logs 文件夹中的所有文件
    if let Err(e) = clear_logs_folder() {
        error!("Error clearing 'logs' folder: {}", e);
        return;
    }

    // 创建 appenders
    let clienthello_parser_appender = FileAppender::builder()
        .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
        .build("logs/clienthello_parser.log")
        .unwrap();

    let clienthello_mutator_appender = FileAppender::builder()
        .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
        .build("logs/clienthello_mutator.log")
        .unwrap();

    let clienthello_mutator_parser_appender = FileAppender::builder()
        .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
        .build("logs/clienthello_mutator_parser.log")
        .unwrap();

    let server_response_parser_appender = FileAppender::builder()
        .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
        .build("logs/server_response_parser.log")
        .unwrap();    
    // 配置日志级别和附加器
    let config = Config::builder()
        .appender(Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("clienthello_parser", Box::new(clienthello_parser_appender)))
        .appender(Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("clienthello_mutator", Box::new(clienthello_mutator_appender)))
        .appender(Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("clienthello_mutator_parser", Box::new(clienthello_mutator_parser_appender)))
        .appender(Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("server_response_parser", Box::new(server_response_parser_appender)))
        .logger(Logger::builder()
            .appender("clienthello_parser")  // 绑定到 clienthello appender
            .additive(false)          // 不将日志传递给根记录器
            .build("tls_handshake::clienthello", LevelFilter::Trace))
        .logger(Logger::builder()
            .appender("clienthello_mutator_parser")  // 绑定到 clienthello appender
            .additive(false)          // 不将日志传递给根记录器
            .build("clienthello_2", LevelFilter::Trace))
        .logger(Logger::builder()
            .appender("clienthello_mutator")  // 绑定到 clienthello appender
            .additive(false)          // 不将日志传递给根记录器
            .build("tls_handshake::clienthello_mutator", LevelFilter::Trace))
        .logger(Logger::builder()
            .appender("server_response_parser")  // 绑定到 clienthello appender
            .additive(false)          // 不将日志传递给根记录器
            .build("tls_handshake::server_response", LevelFilter::Trace))
        .build(
            Root::builder().build(LevelFilter::Trace)  // 根记录器日志级别设为 Trace
        )
        .unwrap();

    // 初始化 log4rs 配置
    log4rs::init_config(config).unwrap();
}
fn perform_first_handshake(
    client_config: Arc<ClientConfig>,
    server_name: String,
    addr: String
) -> Result<(), Box<dyn std::error::Error>> {
    let mut conn = ClientConnection::new(client_config, server_name.clone().try_into()?)?;
    
    let request = format!(
        "GET / HTTP/1.1\r\n\
         Host: www.example.com\r\n\
         Connection: close\r\n\
         Accept-Encoding: identity\r\n\
         \r\n",
    );
    let mut sock = network_connect::establish_tcp_connection(&addr)?;
    // Create a Rustls stream
    let mut tls = Stream::new(&mut conn, &mut sock);
    // Send an HTTP GET request
    tls.write_all(request.as_bytes())?;
    let mut plaintext = Vec::new();
    match tls.read_to_end(&mut plaintext) {
        Ok(_) => {
            // 将字节序列转换为 UTF-8 字符串
            let response = String::from_utf8_lossy(&plaintext);
            // 输出到控制台
            println!("{}", response);
        }
        Err(ref err) if err.kind() == ErrorKind::UnexpectedEof => {
            // 将字节序列转换为 UTF-8 字符串
            let response = String::from_utf8_lossy(&plaintext);

            // 分割响应头和主体，以双换行（\r\n\r\n 或 \n\n）为界
            if let Some((headers, _)) = response.split_once("\r\n\r\n").or_else(|| response.split_once("\n\n")) {
                println!("{}", headers);
            } else {
                // 如果没有找到双换行，直接打印整个响应（可能不完整）
                println!("{}", response);
            }
        }
        Err(err) => return Err(Box::new(err)),
    }
    // Retrieve and print the negotiated cipher suite
    if let Some(ciphersuite) = tls.conn.negotiated_cipher_suite() {
        println!("\nCurrent ciphersuite: {:?}", ciphersuite.suite());
    }
    if let Some(key_exchange_group) = tls.conn.negotiated_key_exchange_group(){
        println!("Current key exchange group: {:?}\n", key_exchange_group.name());
    }
    // Send close_notify to properly terminate the TLS session
    tls.conn.send_close_notify();
    // 模拟第一次握手完成后断开连接
    println!("{}", "\nFirst handshake completed, disconnecting...".green());
    
    Ok(())
}

fn perform_local_network_test() -> Result<(), Box<dyn std::error::Error>> {
    println!("Performing local network environment test...");
    if let Err(e) = network_connect::test_local_connection() {
        terminal::print_error_and_exit(&format!("Local environment test failed: {}", e));
    }
    println!("{}", "Local network environment test passed.\n".green());
    Ok(())
}

fn perform_server_environment_test(
    server_ip: &str, 
    port: u16
) -> Result<(), Box<dyn std::error::Error>> {
    println!("Performing server environment test...");
    if let Err(e) = network_connect::test_server_connection(server_ip, port) {
        terminal::print_error_and_exit(&format!("Server environment test failed: {}", e));
    }
    println!("{}", "Server environment test passed.\n".green());
    Ok(())
}

fn parse_client_hello_if_enabled<'a>(
    matches: &'a clap::ArgMatches,
    client_hello: &'a [u8],
    easy_read: bool
) -> ClientHelloParser<'a> {
    let should_parse = matches.get_flag("check_parse_ch");
    let verbose = should_parse;

    if should_parse {
        println!("{}", "\nparse ClientHello raw bytes:".green());
        if easy_read {
            sleep(Duration::from_secs(2));
        }
    }

    clienthello_parser::parse_client_hello(client_hello, verbose)
}

fn mutate_client_hello_if_enabled(
    matches: &clap::ArgMatches,
    client_hello: &ClientHelloParser, 
    mutation_store: &Vec<TestMutation>, 
    mutated_vec: &mut Vec<ClientHello>, 
    easy_read: bool
){  
    
    if easy_read {
        sleep(Duration::from_secs(2));
    }  

    let mut mutated_clienthello_tmp_store: ClientHello;
    let enable_check = matches.get_flag("check_mutate_ch");
    for single_mutation in mutation_store{
        mutated_clienthello_tmp_store = clienthello_mutator::preferred_mutate_client_hello(&client_hello.get_client_hello(), single_mutation, enable_check);
        // if  {
        //     println!("{}", "\nMutated ClientHello:".green());
        //     mutated_clienthello_tmp_store.print();
        // }    
        
        mutated_vec.push(mutated_clienthello_tmp_store);
    }
    return
}

fn send_client_hello_if_test_env(
    matches: &clap::ArgMatches,
    server_ip: &str,
    port: u16,
    client_hello: &Vec<ClientHello>,
    easy_read: bool
) -> Result<(), Box<dyn std::error::Error>> {
    if !network_connect::check_test_environment(matches) {
        return Ok(());
    }
    for single_clienthello in client_hello{
        // 重新建立连接
        let mut stream = match network_connect::connect_to_server(server_ip, port, easy_read) {
            Ok(stream) => stream,
            Err(e) => {
                println!("Error connecting to server: {}", e);
                continue; // 如果连接失败，跳过当前 ClientHello
            }
        };

        let mut poll = match network_connect::create_poll() {
            Ok(poll) => poll,
            Err(e) => {
                println!("Error creating poll: {}", e);
                continue; // 如果创建 poll 失败，跳过当前 ClientHello
            }
        };

        // 注册连接到事件循环
        let token = match network_connect::register_stream(&mut poll, &mut stream) {
            Ok(token) => token,
            Err(e) => {
                println!("Error registering stream: {}", e);
                continue; // 如果注册流失败，跳过当前 ClientHello
            }
        };

        // 等待连接可写
        if let Err(e) = network_connect::wait_for_writable(&mut poll, token) {
            println!("Error waiting for writable: {}", e);
            continue; // 如果等待可写失败，跳过当前 ClientHello
        }
        
        if let Err(e) = send_client_hello(&mut stream, &single_clienthello) {
            println!("Error sending ClientHello: {}", e);
            continue; // 出现错误时跳过当前 ClientHello 继续下一轮
        }
        
        // 等待服务器响应并处理
        match wait_for_server_response(&mut poll, token, &mut stream) {
            Ok(server_response) => {
                server_response::parse_server_response(&server_response, matches.get_flag("check_parse_sh"));
            }
            Err(e) => {
                // 检查错误信息是否包含 "os error 10054"
                if e.to_string().contains("os error 10054") {
                    println!("{}", format!("{}\nSession Aborted\n",e).yellow());
                } else {
                    // 输出其他错误
                    println!("{}", format!("Error waiting for server response: {}\n\n", e).yellow());
                }
                continue; // 发生错误时继续下一个 ClientHello
            }
        }

    }
    
    Ok(())
}

// 输入，一个存储，一个文件路径，一个存储列名的字符串数组，
// 处理逻辑，读取文件，按照列名数组查看文件，有异常退出，
// 列名检索成功，遍历每一行构建TestMutationVec,然后返回
fn read_mutation_source<'a>(
    file_path: &str, 
    required_columns: &[&str], 
    test_mutation_vec: &'a mut Vec<TestMutation>
) -> Result<&'a Vec<TestMutation>, Box<dyn Error>>{
    let path = Path::new(file_path);

    // Check if the file path exists, if not, return an error with red output
    if !path.exists() {
        // ANSI escape code for red text is "\x1b[31m" and reset color is "\x1b[0m"
        eprintln!("\x1b[31mError: File '{}' not found.\x1b[0m", file_path);
        return Err(From::from(format!("File '{}' not found", file_path)));
    }
    let file = File::open(&path)?;
    let mut reader = csv::Reader::from_reader(file);

    // Verify that the file contains the required columns
    let headers = reader.headers()?.clone();
    for &col in required_columns {
        if !headers.iter().any(|header| header == col) {
            return Err(From::from(format!("Column '{}' not found in the file", col)));
        }
    }

    // Read each record and construct TestMutation
    for result in reader.records() {
        let record = result?;
        
        // Parse each field from the CSV record
        let message = clienthello_mutator::parse_message(&record[headers.iter().position(|h| h == "message").unwrap()])?;
        let field = record[headers.iter().position(|h| h == "field").unwrap()].to_string();
        let action = clienthello_mutator::parse_action(&record[headers.iter().position(|h| h == "action").unwrap()])?;
        let relative_position = record[headers.iter().position(|h| h == "relative_to").unwrap()].to_string();
        // let position = record[headers.iter().position(|h| h == "position").unwrap()].to_string();
        let value = record[headers.iter().position(|h| h == "value").unwrap()].to_string();

        // Construct and add TestMutation to the vector
        test_mutation_vec.push(clienthello_mutator::create_test_mutation(message,field,action,relative_position,value));
    }

    Ok(test_mutation_vec)
}

fn send_client_hello(
    stream: &mut  MioTcpStream, 
    client_hello: &ClientHello
) -> Result<(), Box<dyn std::error::Error>> {
    println!("Sending ClientHello message...");
    // client_hello.print();
    // client_hello.print_bytes();
    let vec_clienthello: &Vec<u8> = &client_hello.to_bytes();
    // print!("{:02X} ", vec_clienthello);
    match stream.write_all(vec_clienthello) {
        Ok(_) => println!("ClientHello message sent successfully."),
        Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
            println!("Socket write would block. Waiting until writable...");
            while let Err(ref e) = stream.write_all(vec_clienthello) {
                if e.kind() != std::io::ErrorKind::WouldBlock {
                    println!("Failed to send ClientHello message: {}", e);
                    return Err(Box::new(std::io::Error::new(e.kind(), e.to_string())));
                }
            }
            println!("ClientHello message sent successfully after waiting.");
        }
        Err(e) => {
            println!("Error sending ClientHello message: {}", e);
            return Err(Box::new(e));
        }
    }
    Ok(())
}

fn wait_for_server_response(
    poll: &mut Poll, 
    token: Token, 
    stream: &mut MioTcpStream
) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
    println!("Waiting for server response...");
    let mut events = Events::with_capacity(1024);
    let mut server_response = Vec::new();
    let mut buffer = [0; 1024];

    loop {
        poll.poll(&mut events, None)?;
        for event in &events {
            if event.token() == token && event.is_readable() {
                println!("Socket is readable. Receiving server response...");
                match stream.read(&mut buffer) {
                    Ok(bytes_read) if bytes_read > 0 => {
                        println!("Received {} bytes from server\n\n", bytes_read);
                        server_response.extend_from_slice(&buffer[..bytes_read]);
                        return Ok(server_response);
                    }
                    Ok(_) => println!("Received 0 bytes. Continuing to wait..."),
                    Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
                        println!("Socket read would block. Continuing to wait...");
                        continue;
                    }
                    Err(e) => {
                        // println!("Error receiving server response: {}", e);
                        return Err(Box::new(e));
                    }
                }
            }
        }
    }
}

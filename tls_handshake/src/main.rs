use std::{sync::Arc, thread::sleep, time::Duration, fs::File, error::Error, path::Path};
use tls_handshake::{clienthello_mutator, clienthello_parser, network_connect, server_response, terminal};
use tls_handshake::clienthello::ClientHello;
use tls_handshake::clienthello_parser::ClientHelloParser;
use tls_handshake::clienthello_mutator::TestMutation;
use rustls::{ClientConnection, Stream, ClientConfig};
use mio::{Events, Poll, Token, net::TcpStream as MioTcpStream};
use std::io::{ErrorKind, Read, Write};
use colored::*;
use std::fs::{self};

use log::{warn, trace, error, info, LevelFilter};
use log4rs::{
    append::file::FileAppender,
    append::console::{ConsoleAppender, Target},
    config::{Appender, Config, Logger, Root},
    encode::pattern::PatternEncoder,
    filter::threshold::ThresholdFilter,
};


fn main() -> Result<(), Box<dyn std::error::Error>> {
    // get environment test args
    let matches: clap::ArgMatches = terminal::get_command_matches();
    // don't know, just print use_guide
    if terminal::get_use_guide(&matches){
        terminal::print_help(true);
        return Ok(())
    }
    // use default tls handshake to connect www.rust-lang.org
    network_connect::perform_local_network_test()?;
    // init terminal output log
    init_log(&matches);
    // test if virtual machine network environment is ok
    network_connect::perform_virtual_machine_connection_test(terminal::get_server_ip(&matches))?;

    // Test environment preparation
    terminal::print_configuration_info(&matches);
    // virtual machine network environment test
    perform_server_environment_test(
        &terminal::get_server_ip(&matches), 
        terminal::get_port(&matches)
    )?;
    
    // read mutation strategy
    let mut mutation_vec_store : Vec<TestMutation> = Vec::new();
    let _ = read_mutation_source(
        "input_source/mutation_guideline.csv", 
        &["message", "field", "action", "relative_to", "position", "value"], 
        &mut mutation_vec_store
    );
    info!("{}","Read mutation source".green());

    // first handshake to get session ticket
    // get create tls handshake base config
    let config = Arc::new(network_connect::create_tls_config());
    // perform first handshake
    perform_first_handshake(
        config.clone(), 
        terminal::get_server_name(&matches),
        format!("{}:{}", terminal::get_server_ip(&matches), terminal::get_port(&matches))
    )?;
    
    // second handshake to get msg template and mutate
    info!("{}","Starting second handshake...".green());
    // use common config, cause the config contain the PSK set arg once the first full handshake completed
    // api call list: 1. rustls::client::ClientConnection::new(client/client_conn.rs:685)
    //                2. ConnectionCore::for_client(client/client_conn.rs:805)
    //                3. hs::start_handshake(client/hs.rs:98)
    //                4. hs::emit_client_hello_for_retry(client/hs.rs:220)
    // 1: hs::start_handshake(125):debug!("Resuming session");
    // 2: hs::emit_client_hello_for_retry(514):trace!("Sending ClientHello {:#?}", ch);
    log::set_max_level(LevelFilter::Debug);
    let mut connection_second = ClientConnection::new(config.clone(), terminal::get_server_name(&matches).try_into()?)?;
    log::set_max_level(LevelFilter::Trace);
    // write the template client_hello vector
    trace!("write the template client_hello vector");
    let mut client_hello = Vec::new();
    connection_second.write_tls(&mut client_hello)?;
    // get second client_hello parsed template
    let parsed_clienthello = parse_client_hello_if_enabled(&matches, &client_hello);
    // start mutation based on the template
    let mut mutated_clienthello_vec: Vec<ClientHello> = Vec::new();
    mutate_client_hello_if_enabled(
        &matches,
        &parsed_clienthello,
        &mutation_vec_store,
        &mut mutated_clienthello_vec,
    );
    // send mutated client_hello
    send_client_hello_if_test_env(
        &matches,
        &terminal::get_server_ip(&matches),
        terminal::get_port(&matches),
        &mut mutated_clienthello_vec
    )?;
    // use guide line
    terminal::print_help(true);
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

fn init_log(matches: &clap::ArgMatches) {
    // 清空 logs 文件夹中的所有文件
    if let Err(e) = clear_logs_folder() {
        error!("Error clearing 'logs' folder: {}", e);
        return;
    }

    // default stderr console appender
    let default_console_stderr_appender: ConsoleAppender = ConsoleAppender::builder()
        .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
        .target(Target::Stderr)
        .build();
    // default stdout console appender
    // let default_console_stdout_appender = ConsoleAppender::builder()
    //     .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
    //     .target(Target::Stderr)
    //     .build();
    let default_client_server_handshake_record: FileAppender = FileAppender::builder()
        .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
        .build("logs/tls_handshake_record.log")
        .unwrap();
    // 默认的 mutate appender
    let clienthello_mutator_appender: FileAppender = FileAppender::builder()
        .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
        .build("logs/clienthello_mutator.log")
        .unwrap();

    // 配置日志级别和附加器
    let mut config_builder = Config::builder()
        .appender(Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("clienthello_mutator", Box::new(clienthello_mutator_appender)))
        .appender(Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("console_log", Box::new(default_console_stderr_appender)))
        .appender(Appender::builder()
            .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
            .build("handshake_log", Box::new(default_client_server_handshake_record)))
        .logger(Logger::builder()
            .appender("clienthello_mutator")
            .additive(false)
            .build("tls_handshake::clienthello_mutator", LevelFilter::Trace))
        .logger(Logger::builder()
            .appender("handshake_log")
            .additive(false)
            .build("handshake_record", LevelFilter::Trace));

    // 根据命令行参数动态添加 appenders 和 loggers
    if terminal::get_check_parse_ch(&matches) {
        let clienthello_parser_appender = FileAppender::builder()
            .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
            .build("logs/clienthello_parser.log")
            .unwrap();

        let clienthello_parser_json_appender = FileAppender::builder()
            .encoder(Box::new(PatternEncoder::new("{m}\n")))
            .build("logs/clienthello_parser_json.log")
            .unwrap();

        config_builder = config_builder
            .appender(Appender::builder()
                .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
                .build("clienthello_parser", Box::new(clienthello_parser_appender)))
            .appender(Appender::builder()
                .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
                .build("clienthello_parser_json", Box::new(clienthello_parser_json_appender)))
            .logger(Logger::builder()
                .appender("clienthello_parser")
                .additive(false)
                .build("clienthello_parser", LevelFilter::Trace))
            .logger(Logger::builder()
                .appender("clienthello_parser_json")
                .additive(false)
                .build("clienthello_parser_json", LevelFilter::Trace));
    }

    if terminal::get_check_mutate_ch(&matches) {
        let clienthello_mutator_parser_appender = FileAppender::builder()
            .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
            .build("logs/clienthello_mutator_parser.log")
            .unwrap();

        config_builder = config_builder
            .appender(Appender::builder()
                .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
                .build("clienthello_mutator_parser", Box::new(clienthello_mutator_parser_appender)))
            .logger(Logger::builder()
                .appender("clienthello_mutator_parser")
                .additive(false)
                .build("clienthello_mutator_parser", LevelFilter::Trace));
    }

    if terminal::get_check_parse_sh(&matches) {
        if terminal::get_test_env(&matches) {
            let server_response_parser_appender = FileAppender::builder()
                .encoder(Box::new(PatternEncoder::new("{d(%Y-%m-%d %H:%M:%S)} {h({l:7.7} - {m}):20.200}\n")))
                .build("logs/server_response_parser.log")
                .unwrap();

            config_builder = config_builder
                .appender(Appender::builder()
                    .filter(Box::new(ThresholdFilter::new(LevelFilter::Trace)))
                    .build("server_response_parser", Box::new(server_response_parser_appender)))
                .logger(Logger::builder()
                    .appender("server_response_parser")
                    .additive(false)
                    .build("tls_handshake::server_response", LevelFilter::Trace));
        }
        else {
            info!("{}","test_env arg disabled, No need to capture and parse server_response, to enable it, give test_env arg".yellow());
        }   
    }

    // 初始化 log4rs 配置
    let final_config_builder = config_builder
        .build(
            Root::builder()
            .appender("console_log")
            .build(LevelFilter::Trace)
        ).unwrap();
    log4rs::init_config(final_config_builder).unwrap();
}

fn perform_first_handshake(
    client_config: Arc<ClientConfig>,
    server_name: String,
    addr: String
) -> Result<(), Box<dyn std::error::Error>> {
    log::set_max_level(LevelFilter::Info);
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
    info!("Sending first tls handshake clienthello request");
    // Temporarily disable TRACE and DEBUG logging 
    
    tls.write_all(request.as_bytes())?;
    let mut plaintext = Vec::new();
    log::set_max_level(LevelFilter::Trace);
    info!("Receive first tls handshake server response");
    match tls.read_to_end(&mut plaintext) {
        Ok(_) => {
            // 将字节序列转换为 UTF-8 字符串
            let response = String::from_utf8_lossy(&plaintext);
            // 输出到控制台
            for line in response.lines() {
                trace!("{}", line);
            }
            // info!("{}", response);
        }
        Err(ref err) if err.kind() == ErrorKind::UnexpectedEof => {
            // 将字节序列转换为 UTF-8 字符串
            let response = String::from_utf8_lossy(&plaintext);

            // 分割响应头和主体，以双换行（\r\n\r\n 或 \n\n）为界
            if let Some((headers, _)) = response.split_once("\r\n\r\n").or_else(|| response.split_once("\n\n")) {
                for line in headers.lines() { trace!("{}", line); }
                // info!("{}", headers);
            } else {
                // 如果没有找到双换行，直接打印整个响应（可能不完整）
                // info!("{}", response);
                for line in response.lines() { trace!("{}", line); }
            }
        }
        Err(err) => return Err(Box::new(err)),
    }
    // Retrieve and print the negotiated cipher suite
    if let Some(ciphersuite) = tls.conn.negotiated_cipher_suite() {
        info!("Current ciphersuite: {:?}", ciphersuite.suite());
    }
    if let Some(key_exchange_group) = tls.conn.negotiated_key_exchange_group(){
        info!("Current key exchange group: {:?}", key_exchange_group.name());
    }
    // Send close_notify to properly terminate the TLS session
    // have api: debug!("Sending warning alert {:?}", AlertDescription::CloseNotify);
    tls.conn.send_close_notify();
    // 模拟第一次握手完成后断开连接
    info!("{}", "First handshake completed, disconnecting...\n\n\n");
    
    Ok(())
}

fn perform_server_environment_test(
    server_ip: &str, 
    port: u16
) -> Result<(), Box<dyn std::error::Error>> {
    info!("Performing server environment test...");
    if let Err(e) = network_connect::test_server_connection(server_ip, port) {
        terminal::print_error_and_exit(&format!("Server environment test failed: {}", e));
    }
    info!("{}", "Server environment test passed.".green());
    Ok(())
}

fn parse_client_hello_if_enabled<'a>(
    matches: &'a clap::ArgMatches,
    client_hello: &'a [u8],
) -> ClientHelloParser<'a> {
    let should_parse = terminal::get_check_parse_ch(&matches);
    let verbose = should_parse;

    if should_parse {
        info!("{}", "parse ClientHello raw bytes:".green());
        if terminal::get_easy_read(&matches) {
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
){  
    
    if terminal::get_easy_read(matches) {
        sleep(Duration::from_secs(2));
    }  

    let mut mutated_clienthello_tmp_store: ClientHello;
    let enable_check = terminal::get_check_mutate_ch(&matches);
    for single_mutation in mutation_store{
        mutated_clienthello_tmp_store = clienthello_mutator::preferred_mutate_client_hello(&client_hello.get_client_hello(), single_mutation, enable_check);
        mutated_vec.push(mutated_clienthello_tmp_store);
    }
    return
}

fn send_client_hello_if_test_env(
    matches: &clap::ArgMatches,
    server_ip: &str,
    port: u16,
    client_hello: &Vec<ClientHello>,
) -> Result<(), Box<dyn std::error::Error>> {
    if !network_connect::check_test_environment(matches) {
        return Ok(());
    }
    for single_clienthello in client_hello{
        // 重新建立连接
        let mut stream = match network_connect::connect_to_server(server_ip, port, terminal::get_easy_read(matches)) {
            Ok(stream) => stream,
            Err(e) => {
                error!("Error connecting to server: {}", e);
                continue; // 如果连接失败，跳过当前 ClientHello
            }
        };

        let mut poll = match network_connect::create_poll() {
            Ok(poll) => poll,
            Err(e) => {
                error!("Error creating poll: {}", e);
                continue; // 如果创建 poll 失败，跳过当前 ClientHello
            }
        };

        // 注册连接到事件循环
        let token = match network_connect::register_stream(&mut poll, &mut stream) {
            Ok(token) => token,
            Err(e) => {
                error!(target: "handshake_record", "Error registering stream: {}", e);
                continue; // 如果注册流失败，跳过当前 ClientHello
            }
        };

        // 等待连接可写
        if let Err(e) = network_connect::wait_for_writable(&mut poll, token) {
            error!(target: "handshake_record", "Error waiting for writable: {}", e);
            continue; // 如果等待可写失败，跳过当前 ClientHello
        }
        
        if let Err(e) = send_client_hello(&mut stream, &single_clienthello) {
            error!(target: "handshake_record", "Error sending ClientHello: {}", e);
            continue; // 出现错误时跳过当前 ClientHello 继续下一轮
        }
        
        // 等待服务器响应并处理
        match wait_for_server_response(&mut poll, token, &mut stream) {
            Ok(server_response) => {
                server_response::parse_server_response(&server_response, terminal::get_check_parse_sh(&matches));
            }
            Err(e) => {
                // 检查错误信息是否包含 "os error 10054"
                if e.to_string().contains("os error 10054") {
                    error!(target: "handshake_record", "{}", e);
                    error!(target: "handshake_record", "Session Aborted\n\n");
                } else {
                    // 输出其他错误
                    error!(target: "handshake_record", "{}", format!("Error waiting for server response: {}\n\n", e).yellow());
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
        error!("File '{}' not found.", file_path);
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
    info!(target: "handshake_record", "Sending ClientHello message...");
    // client_hello.print();
    // client_hello.print_bytes();
    let vec_clienthello: &Vec<u8> = &client_hello.to_bytes();
    // print!("{:02X} ", vec_clienthello);
    match stream.write_all(vec_clienthello) {
        Ok(_) => info!(target: "handshake_record", "ClientHello message sent successfully."),
        Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
            warn!(target: "handshake_record", "Socket write would block. Waiting until writable...");
            while let Err(ref e) = stream.write_all(vec_clienthello) {
                if e.kind() != std::io::ErrorKind::WouldBlock {
                    error!(target: "handshake_record", "Failed to send ClientHello message: {}", e);
                    return Err(Box::new(std::io::Error::new(e.kind(), e.to_string())));
                }
            }
            info!(target: "handshake_record", "ClientHello message sent successfully after waiting.");
        }
        Err(e) => {
            error!(target: "handshake_record", "Error sending ClientHello message: {}", e);
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
    info!(target: "handshake_record", "Waiting for server response...");
    let mut events = Events::with_capacity(1024);
    let mut server_response = Vec::new();
    let mut buffer = [0; 1024];

    loop {
        
        poll.poll(&mut events, None)?;
        
        for event in &events {
            if event.token() == token && event.is_readable() {
                info!(target: "handshake_record", "Socket is readable. Receiving server response...");
                match stream.read(&mut buffer) {
                    Ok(bytes_read) if bytes_read > 0 => {
                        info!(target: "handshake_record", "Received {} bytes from server", bytes_read);
                        server_response.extend_from_slice(&buffer[..bytes_read]);
                        return Ok(server_response);
                    }
                    Ok(_) => warn!(target: "handshake_record", "Received 0 bytes. Continuing to wait..."),
                    Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
                        warn!("Socket read would block. Continuing to wait...");
                        continue;
                    }
                    Err(e) => {
                        return Err(Box::new(e));
                    }
                }
            }
        }
    }
}

use std::sync::Arc;
use std::thread::sleep;
use std::time::Duration;
use tls_handshake::{clienthello_mutator, clienthello_parser, network_connect, server_response, terminal};
use tls_handshake::{SERVER_NAME, SERVER_STATIC_IP, PORT};
use tls_handshake::clienthello::ClientHello;
use tls_handshake::clienthello_parser::ClientHelloParser;
use tls_handshake::clienthello_mutator::TestMutation;
use rustls::{ClientConnection, Stream};
use mio::{Events, Poll, Token};
use mio::net::TcpStream as MioTcpStream;
use std::io::{Write, Read, ErrorKind};
use colored::*;
// use std::collections::HashMap;
use std::net::TcpStream;
use std::fs::File;
use std::error::Error;
use std::path::Path;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    perform_local_network_test()?;

    let matches = terminal::get_command_matches();

    if matches.get_flag("use_guide") {
        terminal::print_help();
        return Ok(());
    }

    let server_name = network_connect::get_server_name(&matches);
    let server_ip = network_connect::get_server_ip(&matches);
    let port = network_connect::get_port(&matches);
    let easy_read = matches.get_flag("easy_read");

    print_configuration_info(&server_name, &server_ip, port, easy_read);

    perform_server_environment_test(&server_ip, port)?;

    perform_first_handshake(server_name.clone(), &server_ip, port)?;

    // 执行第二次握手
    let config = Arc::new(network_connect::create_tls_config());
    let request = format!(
        "GET / HTTP/1.1\r\n\
         Host: www.example.com\r\n\
         Connection: close\r\n\
         Accept-Encoding: identity\r\n\
         \r\n",
    );
    println!("{}","Starting second handshake...\n\n".green());
    let mut conn = network_connect::create_client_connection(config.clone(), server_name)?;
    if let Some(mut early_data) = conn.early_data() {
        early_data
            .write_all(request.as_bytes())
            .unwrap();
        // println!("  * 0-RTT request sent");
    }
    let mut client_hello = Vec::new();
    conn.write_tls(&mut client_hello)?;
    let parsed_clienthello = parse_client_hello_if_enabled(&matches, &client_hello, easy_read);

    let mut mutation_vec_store : Vec<TestMutation> = Vec::new();
    let required_columns = ["message", "field", "action", "relative_to", "position", "value"];
    let file_path = "input_source/mutation_guideline.csv";
    println!("{}","Read mutation source".green());
    let _ = read_mutation_source(file_path, &required_columns, &mut mutation_vec_store);
    let mut mutated_clienthello_vec: Vec<ClientHello> = Vec::new();
    mutate_client_hello_if_enabled(&matches, &parsed_clienthello, &mutation_vec_store, &mut mutated_clienthello_vec, easy_read);
    send_client_hello_if_test_env(&matches, &server_ip, port, &mut mutated_clienthello_vec, easy_read)?;
    
    terminal::print_help();
    Ok(())
}

fn perform_first_handshake(server_name: String, server_ip: &str, port: u16) -> Result<(), Box<dyn std::error::Error>> {
    let addr = format!("{}:{}", server_ip, port);
    let mut sock = TcpStream::connect(&addr)?;
    let config = Arc::new(network_connect::create_tls_config());
    let mut conn = ClientConnection::new(config.clone(), server_name.clone().try_into()?)?;
    
    let request = format!(
        "GET / HTTP/1.1\r\n\
         Host: www.example.com\r\n\
         Connection: close\r\n\
         Accept-Encoding: identity\r\n\
         \r\n",
    );
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

fn print_configuration_info(
    server_name: &str, 
    server_ip: &str, 
    port: u16, 
    easy_read: bool
) {
    let use_default_name = server_name == SERVER_NAME;
    let use_default_ip = server_ip == SERVER_STATIC_IP;
    let use_default_port = port == PORT;

    terminal::print_configuration(server_name, server_ip, port, use_default_name, use_default_ip, use_default_port);
    if easy_read{
        sleep(Duration::from_secs(3));
    }
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
    // Initialize `parsed_client_hello` before using it
    let parsed_client_hello: ClientHelloParser;
    
    if !matches.get_flag("disable_parse_client_hello") {
        println!("{}", "\nparse ClientHello raw bytes:".green());
        if easy_read {
            sleep(Duration::from_secs(2));
        }

        // Parse ClientHello if the flag is not set
        parsed_client_hello = clienthello_parser::parse_client_hello(client_hello);
    } else {
        // Handle the case where the flag is set to disable parsing
        // You can return an error, a default value, or handle the case as needed
        // For example, returning a default ClientHelloParser or an error would be useful:
        // parsed_client_hello = ClientHelloParser::default(); // Or handle accordingly
        panic!("ClientHello parsing is disabled.");
    }

    parsed_client_hello.clone() // Return the cloned value
}


fn mutate_client_hello_if_enabled(
    matches: &clap::ArgMatches,
    client_hello: &ClientHelloParser, 
    mutation_store: &Vec<TestMutation>, 
    mutated_vec: &mut Vec<ClientHello>, 
    easy_read: bool
){  
    // default value: false
    if matches.get_flag("disable_mutate_client_hello") {
        println!("{}", "\nMutate ClientHello Strategy Disabled".yellow());
        return
    }    
    // assigned value: true
    // 执行变异并获取结果
    println!("{}", "\nMutated ClientHello:".green());
    if easy_read {
        sleep(Duration::from_secs(2));
    }  

    // TODO: Deprecate old api, use new api
    let mut mutated_clienthello_tmp_store: ClientHello;
    for single_mutation in mutation_store{
        mutated_clienthello_tmp_store = clienthello_mutator::preferred_mutate_client_hello(&client_hello.get_client_hello(), single_mutation);
        mutated_clienthello_tmp_store.print();
        mutated_vec.push(mutated_clienthello_tmp_store);
    }
    return
}

fn send_client_hello_if_test_env(
    matches: &clap::ArgMatches,
    server_ip: &str,
    port: u16,
    // conn: &mut ClientConnection,
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
                let parse_enabled = matches.get_flag("disable_parse_server_response");
                server_response::parse_server_response(&server_response, parse_enabled);
                // conn.send_close_notify();
            }
            Err(e) => {
                println!("Error waiting for server response: {}\n\n", e);
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
    client_hello.print();
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
                        println!("Received {} bytes from server", bytes_read);
                        server_response.extend_from_slice(&buffer[..bytes_read]);
                        // print_hex_dump(&server_response);
                        // stream.conn.send_close
                        return Ok(server_response);
                    }
                    Ok(_) => println!("Received 0 bytes. Continuing to wait..."),
                    Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
                        println!("Socket read would block. Continuing to wait...");
                        continue;
                    }
                    Err(e) => {
                        println!("Error receiving server response: {}", e);
                        return Err(Box::new(e));
                    }
                }
            }
        }
    }
}

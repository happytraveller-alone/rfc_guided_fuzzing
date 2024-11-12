use std::sync::Arc;
use std::thread::sleep;
use std::time::Duration;
use tls_handshake::{clienthello_parser, clienthello_mutator, network_connect, terminal, server_response};
use tls_handshake::{SERVER_NAME, SERVER_STATIC_IP, PORT};
use tls_handshake::clienthello::ClientHello;
use rustls::{client, ClientConnection, Stream};
use mio::{Events, Poll, Token};
use mio::net::TcpStream as MioTcpStream;
use std::io::{Write, Read};
use colored::*;
use std::collections::HashMap;
use std::io::ErrorKind;
use std::net::TcpStream;

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

    // let psk_identity = b"temporary_identity".to_vec();
    // let psk_secret = generate_temporary_psk();
    let addr = format!("{}:{}", server_ip, port);
    let mut sock = TcpStream::connect(&addr)?;
    let config = Arc::new(network_connect::create_tls_config());
    let mut conn = rustls::ClientConnection::new(config.clone(), server_name.clone().try_into()?)?;
    
    // let username = "Administrator";
    // let password = "gxxyf3312!";
    // let credentials = format!("{}:{}", username, password);
    // let encoded_credentials = STANDARD.encode(credentials);
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
    

    // 执行第二次握手
    println!("{}","Starting second handshake...\n\n".green());
    let mut conn = network_connect::create_client_connection(config.clone(), server_name)?;
    if let Some(mut early_data) = conn.early_data() {
        early_data
            .write_all(request.as_bytes())
            .unwrap();
        println!("  * 0-RTT request sent");
    }
    let mut client_hello = Vec::new();
    conn.write_tls(&mut client_hello)?;

    let parsed_clienthello = parse_client_hello_if_enabled(&matches, &client_hello, easy_read);
    mutate_client_hello_if_enabled(&matches, &parsed_clienthello, easy_read);
    send_client_hello_if_test_env(&matches, &server_ip, port,&mut conn, &client_hello, easy_read)?;
    
    terminal::print_help();
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

fn print_configuration_info(server_name: &str, server_ip: &str, port: u16, easy_read: bool) {
    let use_default_name = server_name == SERVER_NAME;
    let use_default_ip = server_ip == SERVER_STATIC_IP;
    let use_default_port = port == PORT;

    terminal::print_configuration(server_name, server_ip, port, use_default_name, use_default_ip, use_default_port);
    if easy_read{
        sleep(Duration::from_secs(3));
    }
}

fn perform_server_environment_test(server_ip: &str, port: u16) -> Result<(), Box<dyn std::error::Error>> {
    println!("Performing server environment test...");
    if let Err(e) = network_connect::test_server_connection(server_ip, port) {
        terminal::print_error_and_exit(&format!("Server environment test failed: {}", e));
    }
    println!("{}", "Server environment test passed.\n".green());
    Ok(())
}

fn parse_client_hello_if_enabled(matches: &clap::ArgMatches, client_hello: &[u8], easy_read: bool) -> ClientHello {
    let mut parsed_client_hello = ClientHello::new();
    if !matches.get_flag("disable_parse_client_hello") {
        println!("{}", "\nparse ClientHello raw bytes:".green());
        if easy_read {
            sleep(Duration::from_secs(2));
        }
        // 解析 ClientHello
        parsed_client_hello = clienthello_parser::parse_client_hello(client_hello);
    }
    parsed_client_hello
}

fn mutate_client_hello_if_enabled(matches: &clap::ArgMatches, client_hello: &ClientHello, easy_read: bool){
    if !matches.get_flag("disable_mutate_client_hello") {
        // 创建变异配置
        let mut mutation_config = HashMap::new();
        // 创建一个32字节的数组，这里示例用全1填充
        let random_bytes: Vec<u8> = vec![1u8; 31];
        mutation_config.insert(1, random_bytes);
        let random_session_id: Vec<u8> = vec![0u8; 34];
        mutation_config.insert(2, random_session_id);
        let random_cipher_suites: Vec<u8> = vec![0x13, 0x13];
        mutation_config.insert(3, random_cipher_suites);

        // 执行变异并获取结果
        println!("{}", "\nMutated ClientHello:".green());
        if easy_read {
            sleep(Duration::from_secs(2));
        }
        let mutated_client_hello = clienthello_mutator::mutate_client_hello(&client_hello, &mutation_config);

        mutated_client_hello.print();
    }
}
fn send_client_hello_if_test_env(
    matches: &clap::ArgMatches,
    server_ip: &str,
    port: u16,
    _conn: &mut ClientConnection,
    client_hello: &[u8],
    easy_read: bool
) -> Result<(), Box<dyn std::error::Error>> {
    if !network_connect::check_test_environment(matches) {
        return Ok(());
    }

    let mut stream = network_connect::connect_to_server(server_ip, port, easy_read)?;
    let mut poll = network_connect::create_poll()?;
    // let mut mio_stream = MioTcpStream::from_std(stream);
    let token = network_connect::register_stream(&mut poll, &mut stream)?;
    
    network_connect::wait_for_writable(&mut poll, token)?;
    send_client_hello(&mut stream, client_hello)?;
    
    let server_response = wait_for_server_response(&mut poll, token, &mut stream)?; 
    // process_server_response(conn, &server_response)?;
    let parse_enabled = matches.get_flag("disable_parse_server_response");
    server_response::parse_server_response(&server_response, parse_enabled);

    Ok(())
}



fn send_client_hello(stream: &mut  MioTcpStream, client_hello: &[u8]) -> Result<(), Box<dyn std::error::Error>> {
    println!("Sending ClientHello message...");
    match stream.write_all(client_hello) {
        Ok(_) => println!("ClientHello message sent successfully."),
        Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
            println!("Socket write would block. Waiting until writable...");
            while let Err(ref e) = stream.write_all(client_hello) {
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

fn wait_for_server_response(poll: &mut Poll, token: Token, stream: &mut MioTcpStream) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
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

// fn process_server_response(conn: &mut ClientConnection, server_response: &[u8]) -> Result<(), Box<dyn std::error::Error>> {
//     let mut read_cursor = io::Cursor::new(server_response);
//     if let Err(e) = conn.read_tls(&mut read_cursor) {
//         println!("Error reading TLS data: {}", e);
//         return Err(Box::new(e));
//     }

//     let io_state = match conn.process_new_packets() {
//         Ok(io_state) => io_state,
//         Err(err) => {
//             println!("TLS error: {:?}", err);
//             return Err(Box::new(err));
//         }
//     };
//     println!("Success to read to tls");

//     if io_state.plaintext_bytes_to_read() > 0 {
//         let mut plaintext = vec![0u8; io_state.plaintext_bytes_to_read()];
//         conn.reader().read_exact(&mut plaintext)?;
//         io::stdout().write_all(&plaintext)?;
//     }

//     Ok(())
// }
// #[warn(dead_code)]
// fn print_hex_dump(data: &[u8]) {
//     println!("Read cursor content (hex):");
//     for (i, byte) in data.iter().enumerate() {
//         if i % 16 == 0 {
//             print!("\n{:04x}: ", i);
//         }
//         print!("{:02x} ", byte);
//     }
//     println!();
// }
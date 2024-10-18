use std::sync::Arc;

use std::thread::sleep;
use std::time::Duration;
use tls_handshake::{clienthello, network_connect, terminal, server_response};
use tls_handshake::{SERVER_NAME, SERVER_STATIC_IP, PORT};
use rustls::ClientConnection;
use mio::{Events, Poll, Token};
use mio::net::TcpStream as MioTcpStream;
use std::io::{Write, Read};
use colored::*;
// use std::io;
// use std::fs;

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

    let config = Arc::new(network_connect::create_tls_config());
    let mut conn = network_connect::create_client_connection(config, server_name.clone())?;

    let mut client_hello = Vec::new();
    conn.write_tls(&mut client_hello)?;

    parse_client_hello_if_enabled(&matches, &client_hello, easy_read);
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

fn parse_client_hello_if_enabled(matches: &clap::ArgMatches, client_hello: &[u8], easy_read: bool) {
    if !matches.get_flag("disable_parse_client_hello") {
        println!("{}", "\nparse ClientHello raw bytes:".green());
        if easy_read {
            sleep(Duration::from_secs(2));
        }
        clienthello::parse_client_hello(client_hello);
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
    server_response::parse_server_response(&server_response);

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

fn print_hex_dump(data: &[u8]) {
    println!("Read cursor content (hex):");
    for (i, byte) in data.iter().enumerate() {
        if i % 16 == 0 {
            print!("\n{:04x}: ", i);
        }
        print!("{:02x} ", byte);
    }
    println!();
}
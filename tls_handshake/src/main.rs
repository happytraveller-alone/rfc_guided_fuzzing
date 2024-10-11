use std::sync::Arc;
use clap::{arg, Command,ArgAction};
use std::thread::sleep;
use std::time::Duration;
use tls_handshake::{clienthello, network_connect, terminal};
use tls_handshake::{SERVER_NAME, SERVER_STATIC_IP, PORT};
use rustls::ClientConnection;
use mio::{Events, Interest, Poll, Token};
use mio::net::TcpStream;
use std::io::{Write, Read};
use std::net::SocketAddr;
use colored::*;
// use std::fs;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    perform_local_network_test()?;

    let matches = get_command_matches();

    if matches.get_flag("use_guide") {
        terminal::print_help();
        return Ok(());
    }

    let server_name = get_server_name(&matches);
    let server_ip = get_server_ip(&matches);
    let port = get_port(&matches);
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

fn get_command_matches() -> clap::ArgMatches {
    Command::new("TLS Client")
        .about("A simple TLS client to send ClientHello and optionally parse responses")
        .arg(arg!(-s --server <SERVER_NAME> "Sets the server name").required(false))
        .arg(arg!(-i --ip <SERVER_IP> "Sets the server IP address").required(false))
        .arg(arg!(-p --port <PORT> "Sets the port number").required(false).default_value("443"))
        .arg(arg!(--test_env "Enables test environment mode").action(ArgAction::SetTrue))
        .arg(arg!(--disable_parse_client_hello "Enables or disables ClientHello parsing").default_value("false").action(ArgAction::SetTrue))
        .arg(arg!(--disable_parse_server_response "Enables or disables Server response").default_value("false").action(ArgAction::SetTrue))
        .arg(arg!(--use_guide "Show help information").action(ArgAction::SetTrue))
        .arg(arg!(--easy_read "Enables easy read mode by adding delays").default_value("false").action(ArgAction::SetTrue))
        .get_matches()
}

fn get_server_name(matches: &clap::ArgMatches) -> String {
    matches.get_one::<String>("server").unwrap_or(&SERVER_NAME.to_string()).to_string()
}

fn get_server_ip(matches: &clap::ArgMatches) -> String {
    matches.get_one::<String>("ip").unwrap_or(&SERVER_STATIC_IP.to_string()).to_string()
}

fn get_port(matches: &clap::ArgMatches) -> u16 {
    matches.get_one::<String>("port").unwrap().parse().unwrap_or(PORT)
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

fn send_client_hello_if_test_env(matches: &clap::ArgMatches, server_ip: &str, port: u16, conn: &mut ClientConnection, client_hello: &[u8], easy_read: bool) -> Result<(), Box<dyn std::error::Error>> {
    // Handle edge cases and errors first
    if !matches.get_flag("test_env") {
        println!("{}", "\nTest environment is false. Not sending ClientHello to server.".green());
        return Ok(());
    }

    println!("{}", "\nTest environment is enabled. Sending ClientHello to server.".green());
    if easy_read {
        sleep(Duration::from_secs(1));
    }

    let access: SocketAddr = format!("{}:{}", server_ip, port).parse()?;
    println!("Connecting to server at {}...", access);
    let mut stream = TcpStream::connect(access)?;

    let mut poll = Poll::new()?;
    let mut events = Events::with_capacity(1024);
    let token = Token(0);
    println!("Registering stream with poll...");
    poll.registry().register(&mut stream, token, Interest::WRITABLE | Interest::READABLE)?;

    // Wait for the socket to be writable (connected)
    let mut connected = false;
    println!("Waiting for socket to be writable...");
    while !connected {
        poll.poll(&mut events, None)?;
        for event in &events {
            if event.token() == token && event.is_writable() {
                connected = true;
                println!("Socket is writable. Connection established.");
                break;
            }
        }
    }

    // Write the ClientHello message
    println!("Sending ClientHello message...");
    match stream.write_all(client_hello) {
        Ok(_) => println!("ClientHello message sent successfully."),
        Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
            println!("Socket write would block. Waiting until writable...");
            // Wait until writable again
            while let Err(ref e) = stream.write_all(client_hello) {
                if e.kind() == std::io::ErrorKind::WouldBlock {
                    poll.poll(&mut events, None)?;
                } else {
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

    // Wait for server response using non-blocking I/O
    println!("Waiting for server response...");
    let mut server_response = [0; 8192];
    let mut response_received = false;
    // let mut decrypted_data = vec![];
    while !response_received {
        poll.poll(&mut events, None)?;
        for event in &events {
            if event.token() == token && event.is_readable() {
                println!("Socket is readable. Receiving server response...");
                match stream.read(&mut server_response) {
                    Ok(bytes_read) if bytes_read > 0 => {
                        println!("Received {} bytes from server", bytes_read);
                        let mut read_cursor = &server_response[..bytes_read];
                        println!("Read cursor content (hex):");
                        for (i, byte) in read_cursor.iter().enumerate() {
                            if i % 16 == 0 {
                                print!("\n{:04x}: ", i);
                            }
                            print!("{:02x} ", byte);
                        }
                        println!("");

                        conn.read_tls(&mut read_cursor).unwrap();
                        println!("Success to read to tls");
                        // conn.process_new_packets().unwrap();
                        loop {
                            match conn.process_new_packets() {
                                Ok(_) => break,
                                Err(e) => {
                                    println!("Error processing packets: {:?}", e);
                                    return Err(Box::new(e));
                                }
                            }
                        }
                        
                        // error: 阻塞了
                        // let decrypted_data = conn.reader().read_to_end(&mut );
                        let mut plaintext = Vec::new();
                        conn.reader().read_to_end(&mut plaintext)?;
                        if !plaintext.is_empty() {
                            println!("Decrypted server response: {:?}", String::from_utf8_lossy(&plaintext));
                        }
                        response_received = true;
                    }
                    Ok(_) => {
                        println!("Received 0 bytes. Continuing to wait...");
                    }
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

    // // Parse server response if enabled
    // if !matches.get_flag("disable_parse_server_response") {
    //     println!("{}", "\nParse Server Response is enabled. Start parsing server response.".green());
    //     if easy_read {
    //         sleep(Duration::from_secs(1));
    //     }
    //     let mut parser = server_response::ServerHelloParser::new(&decrypted_data);
    //     parser.parse_server_response();
    // }

    Ok(())
}
use std::sync::Arc;
use clap::{arg, Command,ArgAction};
use std::thread::sleep;
use std::time::Duration;
use tls_handshake::{clienthello, server_response, network_connect, terminal};
use tls_handshake::{SERVER_NAME, SERVER_STATIC_IP, PORT};
use colored::*;

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
    send_client_hello_if_test_env(&matches, &server_ip, port, &client_hello, easy_read)?;

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

fn send_client_hello_if_test_env(matches: &clap::ArgMatches, server_ip: &str, port: u16, client_hello: &[u8], easy_read: bool) -> Result<(), Box<dyn std::error::Error>> {
    if matches.get_flag("test_env") {
        println!("{}", "\nTest environment is enabled. sending ClientHello to server.".green());
        if easy_read {
            sleep(Duration::from_secs(1));
        }
        let access = format!("{}:{}", server_ip, port);
        let mut stream = network_connect::establish_tcp_connection(&access)?;
        network_connect::send_data(&mut stream, client_hello)?;
        println!("\nSending ClientHello to server...");
        let mut server_response = [0; 4096];
        let bytes_read = network_connect::receive_data(&mut stream, &mut server_response)?;
        println!("Received {} bytes from server", bytes_read);
        if !matches.get_flag("disable_parse_server_response") {
            println!("{}", "\nParse Server Response is enabled. Start parsing server response.".green());
            if easy_read {
                sleep(Duration::from_secs(1));
            }
            let mut parser = server_response::ServerHelloParser::new(&server_response[..bytes_read]);
            parser.parse_server_response();
        }
    } else {
        println!("{}", "\nTest environment is false. Not sending ClientHello to server.".green());
    }
    Ok(())
}
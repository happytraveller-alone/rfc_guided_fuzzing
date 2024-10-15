use termcolor::{Color, ColorChoice, ColorSpec, StandardStream, WriteColor};
use std::io::Write;
use colored::*;
use std::process::exit;
use clap::{arg, Command,ArgAction};

pub fn print_configuration(server_name: &str, server_ip: &str, port: u16, use_default_name: bool, use_default_ip: bool, use_default_port: bool) {
    let mut stdout = StandardStream::stdout(ColorChoice::Always);

    if use_default_name {
        stdout.set_color(ColorSpec::new().set_fg(Some(Color::Red))).unwrap();
        writeln!(stdout, "Warning: Using default server name: '{}'", server_name).unwrap();
        writeln!(stdout, "If this is not the desired server name, specify it using the --server option.").unwrap();
    } else {
        stdout.reset().unwrap();
        writeln!(stdout, "Using server name: '{}'", server_name).unwrap();
    }

    if use_default_ip {
        stdout.set_color(ColorSpec::new().set_fg(Some(Color::Red))).unwrap();
        writeln!(stdout, "Warning: Using default server IP: '{}'", server_ip).unwrap();
        writeln!(stdout, "If this is not the desired IP, specify it using the --ip option.").unwrap();
    } else {
        stdout.reset().unwrap();
        writeln!(stdout, "Using server IP: '{}'", server_ip).unwrap();
    }

    if use_default_port {
        stdout.set_color(ColorSpec::new().set_fg(Some(Color::Red))).unwrap();
        writeln!(stdout, "Warning: Using default port: '{}'", port).unwrap();
        writeln!(stdout, "If this is not the desired port, specify it using the --port option.").unwrap();
    } else {
        stdout.reset().unwrap();
        writeln!(stdout, "Using port: '{}'", port).unwrap();
    }
    stdout.reset().unwrap();
}

// 自定义帮助函数
pub fn print_help() {
    println!();
    println!("{}","=================== TLS Client Help ===================".green());
    println!("{}","This program is a simple TLS client used for testing and analyzing ClientHello/ServerHello messages.".green());
    println!("{}","Usage: cargo run -- [OPTIONS]".green());
    println!("{}","Usage: cargo run -- --test_env".green());
    println!("{}","Usage: cargo run -- --use_guide".green());
    println!();
    println!("{}","Options:".green());
    println!("{}","  -s, --server <SERVER_NAME>             Sets the server name (default: WIN-MEGACP61GRJ)".green());
    println!("{}","  -i, --ip <SERVER_IP>                   Sets the server IP address (default: 192.168.110.128)".green());
    println!("{}","  -p, --port <PORT>                      Sets the port number (default: 443)".green());
    println!("{}","  --test_env                             If set, sends ClientHello to the server and parses the server response.".green());
    println!("{}","  --disable_parse_client_hello           Enables or disables ClientHello parsing (default: false).".green());
    println!("{}","  --disable_parse_server_response        Enables or disables Server Response parsing (default: false).".green());
    println!("{}","  --use_guide                            Show this help information.".green());
    println!("{}","  --easy_read                            Show output information slower.".green());
    println!("{}","=======================================================".green());
}

// 打印错误信息并退出程序
pub fn print_error_and_exit(message: &str) {
    let mut stderr = StandardStream::stderr(ColorChoice::Always);
    stderr.set_color(ColorSpec::new().set_fg(Some(Color::Red)).set_bold(true)).unwrap();
    writeln!(&mut stderr, "Error: {}", message).unwrap();
    stderr.reset().unwrap();
    exit(1);
}

pub fn get_command_matches() -> clap::ArgMatches {
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

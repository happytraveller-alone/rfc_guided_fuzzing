use termcolor::{Color, ColorChoice, ColorSpec, StandardStream, WriteColor};
use colored::*;
use std::{io::Write, process::exit, thread::sleep, time::Duration};
use clap::{arg, Command,ArgAction};
use crate::{SERVER_NAME, SERVER_STATIC_IP, PORT};
use log::{warn, info};
macro_rules! create_flag_getter {
    ($fn_name:ident, $flag:expr) => {
        pub fn $fn_name(matches: &clap::ArgMatches) -> bool {
            matches.get_flag($flag)
        }
    };
}

// 使用宏来定义函数
create_flag_getter!(get_easy_read, "easy_read");
create_flag_getter!(get_use_guide, "use_guide");
create_flag_getter!(get_check_parse_ch, "check_parse_ch");
create_flag_getter!(get_check_mutate_ch, "check_mutate_ch");
create_flag_getter!(get_check_parse_sh, "check_parse_sh");
create_flag_getter!(get_test_env, "test_env");

macro_rules! create_option_getter {
    ($fn_name:ident, $arg_name:expr, $default:expr, $t:ty) => {
        pub fn $fn_name(matches: &clap::ArgMatches) -> $t {
            matches.get_one::<String>($arg_name)
                .unwrap_or(&$default.to_string())
                .parse::<$t>()
                .unwrap_or($default)
        }
    };
}


// 使用宏来定义函数
create_option_getter!(get_server_name, "server", SERVER_NAME.to_string(), String);
create_option_getter!(get_server_ip, "ip", SERVER_STATIC_IP.to_string(), String);
create_option_getter!(get_port, "port", PORT, u16);



pub fn print_configuration(server_name: &str, server_ip: &str, port: u16, use_default_name: bool, use_default_ip: bool, use_default_port: bool) {
    let mut stdout = StandardStream::stdout(ColorChoice::Always);

    if use_default_name {
        // stdout.set_color(ColorSpec::new().set_fg(Some(Color::Red))).unwrap();
        warn!("Warning: Using default server name: '{}'", server_name);
        warn!("If this is not the desired server name, specify it using the --server option.");
    } else {
        // stdout.reset().unwrap();
        info!("Using server name: '{}'", server_name);
    }

    if use_default_ip {
        // stdout.set_color(ColorSpec::new().set_fg(Some(Color::Red))).unwrap();
        warn!("Warning: Using default server IP: '{}'", server_ip);
        warn!("If this is not the desired IP, specify it using the --ip option.");
    } else {
        // stdout.reset().unwrap();
        info!("Using server IP: '{}'", server_ip);
    }

    if use_default_port {
        // stdout.set_color(ColorSpec::new().set_fg(Some(Color::Red))).unwrap();
        warn!("Warning: Using default port: '{}'", port);
        warn!("If this is not the desired port, specify it using the --port option.");
    } else {
        // stdout.reset().unwrap();
        info!("Using port: '{}'", port);
    }
    stdout.reset().unwrap();
}

// 自定义帮助函数
pub fn print_help(
    matches_enable: bool,
) {
    if matches_enable{
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
        println!("{}","  --check_parse_ch                       Enables checking details of ClientHello parsing (default: false).".green());
        println!("{}","  --check_mutate_ch                      Enables checking details of ClientHello mutation (default: false).".green());
        println!("{}","  --check_parse_sh                       Enables checking details of Server Response parsing (default: false).".green());
        println!("{}","  --use_guide                            Show this help information.".green());
        println!("{}","  --easy_read                            Show output information slower.".green());
        println!("{}","=======================================================".green());
    }
    
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
        .arg(arg!(--check_parse_ch "Enables Check ClientHello parsing").default_value("false").action(ArgAction::SetTrue))
        .arg(arg!(--check_mutate_ch "Enables Check ClientHello mutation").default_value("false").action(ArgAction::SetTrue))
        .arg(arg!(--check_parse_sh "Enables Check parse Server response").default_value("false").action(ArgAction::SetTrue))
        .arg(arg!(--use_guide "Show help information").action(ArgAction::SetTrue))
        .arg(arg!(--easy_read "Enables easy read mode by adding delays").default_value("false").action(ArgAction::SetTrue))
        .get_matches()
}


pub fn print_configuration_info(
    matches: &clap::ArgMatches,
) {
    let use_default_name = &get_server_name(&matches) == SERVER_NAME;
    let use_default_ip = &get_server_ip(&matches) == SERVER_STATIC_IP;
    let use_default_port = get_port(&matches) == PORT;

    print_configuration(
        &get_server_name(&matches),
        &get_server_ip(&matches),
        get_port(&matches),
        use_default_name,
        use_default_ip,
        use_default_port
    );
    if get_easy_read(&matches){
        sleep(Duration::from_secs(3));
    }
}
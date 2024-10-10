use std::sync::Arc;
use std::net::TcpStream;
use clap::{arg, Command,ArgAction};
use std::io::{Write, Read};
use std::thread::sleep;
use std::time::Duration;
use phf::phf_map;
use rustls::{ClientConfig, ClientConnection, RootCertStore};
use termcolor::{Color, ColorChoice, ColorSpec, StandardStream, WriteColor}; // 引入 termcolor 以实现彩色打印
use colored::*;
mod tls_config {
    use super::*;

    pub fn create_tls_config() -> ClientConfig {
        let root_store = RootCertStore::empty();
        ClientConfig::builder()
            .with_root_certificates(root_store)
            .with_no_client_auth()
    }

    pub fn create_client_connection(config: Arc<ClientConfig>, server_name: String) -> Result<ClientConnection, Box<dyn std::error::Error>> {
        let sever_name_new = server_name.try_into()?;
        Ok(ClientConnection::new(config, sever_name_new)?)
    }
}

mod network {
    use super::*;

    pub fn establish_tcp_connection(address: &str) -> Result<TcpStream, std::io::Error> {
        TcpStream::connect(address)
    }

    pub fn send_data(stream: &mut TcpStream, data: &[u8]) -> Result<(), std::io::Error> {
        stream.write_all(data)
    }

    pub fn receive_data(stream: &mut TcpStream, buffer: &mut [u8]) -> Result<usize, std::io::Error> {
        stream.read(buffer)
    }
}

static TLS_EXTENSIONS: phf::Map<u16, &'static str> = phf_map! {
    0x0000u16 => "server_name",
    0x0001u16 => "max_fragment_length",
    0x0005u16 => "status_request",
    0x000Au16 => "supported_groups",
    0x000Bu16 => "ec_point_formats",
    0x000Du16 => "signature_algorithms",
    0x000Eu16 => "use_srtp",
    0x000Fu16 => "heartbeat",
    0x0010u16 => "application_layer_protocol_negotiation",
    0x0012u16 => "signed_certificate_timestamp",
    0x0013u16 => "client_certificate_type",
    0x0014u16 => "server_certificate_type",
    0x0015u16 => "padding",
    0x0017u16 => "extended_master_secret",
    0x0023u16 => "session_ticket",
    0x0029u16 => "pre_shared_key",
    0x002Au16 => "early_data",
    0x002Bu16 => "supported_versions",
    0x002Cu16 => "cookie",
    0x002Du16 => "psk_key_exchange_modes",
    0x0032u16 => "signature_algorithms_cert",
    0x0033u16 => "key_share",

    0xFF01u16 => "renegotiation_info"
};

mod clienthello_parsing {
    use super::TLS_EXTENSIONS;

    pub struct ClientHelloParser<'a> {
        data: &'a [u8],
        offset: usize,
    }

    impl<'a> ClientHelloParser<'a> {
        pub fn new(data: &'a [u8]) -> Self {
            Self { data, offset: 0 }
        }

        pub fn parse(&mut self) {
            self.parse_tls_record_layer();
            self.parse_handshake_layer();
            self.parse_client_hello();
            self.parse_session_id();
            self.parse_cipher_suites();
            self.parse_compression_methods();
            self.parse_extensions();
        }

        fn parse_tls_record_layer(&mut self) {
            println!("TLS Record Layer:");
            println!("  Content Type: {:02X} (Handshake)", self.data[self.offset]);
            self.offset += 1;
            println!("  Version: {:02X} {:02X} (TLS 1.0 for backwards compatibility)", 
                     self.data[self.offset], self.data[self.offset + 1]);
            self.offset += 2;
            let record_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            println!("  Length: {:04X} ({} bytes)", record_length, record_length);
            self.offset += 2;
        }

        fn parse_handshake_layer(&mut self) {
            println!("Handshake Layer:");
            println!("  Handshake Type: {:02X} (ClientHello)", self.data[self.offset]);
            self.offset += 1;
            let handshake_length = u32::from_be_bytes([0, self.data[self.offset], self.data[self.offset + 1], self.data[self.offset + 2]]);
            println!("  Length: {:06X} ({} bytes)", handshake_length, handshake_length);
            self.offset += 3;
        }

        fn parse_client_hello(&mut self) {
            println!("ClientHello:");
            println!("  Client Version: {:02X} {:02X}", self.data[self.offset], self.data[self.offset + 1]);
            self.offset += 2;
            print!("  Random:");
            for i in 0..32 {
                print!("{:02X} ", self.data[self.offset + i]);
            }
            println!();
            self.offset += 32;
        }

        fn parse_session_id(&mut self) {
            let session_id_length = self.data[self.offset] as usize;
            self.offset += 1;
            println!("  Session ID Length: {:02X} ({} bytes)", session_id_length, session_id_length);
            if session_id_length > 0 {
                print!("  Session ID: ");
                for i in 0..session_id_length {
                    print!("{:02X} ", self.data[self.offset + i]);
                }
                println!();
                self.offset += session_id_length;
            }
        }

        fn parse_cipher_suites(&mut self) {
            let cipher_suites_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
            self.offset += 2;
            println!("  Cipher Suites Length: {:04X} ({} bytes)", cipher_suites_length, cipher_suites_length);
            print!("  Cipher Suites: ");
            for i in (0..cipher_suites_length).step_by(2) {
                print!("{:02X}{:02X} ", self.data[self.offset + i], self.data[self.offset + i + 1]);
            }
            println!();
            self.offset += cipher_suites_length;
        }

        fn parse_compression_methods(&mut self) {
            let compression_methods_length = self.data[self.offset] as usize;
            self.offset += 1;
            println!("  Compression Methods Length: {:02X} ({} bytes)", compression_methods_length, compression_methods_length);
            print!("  Compression Methods: ");
            for i in 0..compression_methods_length {
                print!("{:02X} ", self.data[self.offset + i]);
            }
            println!();
            self.offset += compression_methods_length;
        }

        fn parse_extensions(&mut self) {
            if self.offset < self.data.len() {
                let extensions_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
                self.offset += 2;
                println!("  Extensions Length: {:04X} ({} bytes)", extensions_length, extensions_length);
                while self.offset < self.data.len() {
                    let extension_type = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
                    self.offset += 2;
                    let extension_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
                    self.offset += 2;
                    let extension_name = TLS_EXTENSIONS.get(&extension_type).map_or("Unknown", |&name| name);
                    println!("    Extension: {:<25} (Type: {:<04X}, Length: {:04X} ({:<3} bytes))", 
                             extension_name, extension_type, extension_length, extension_length);
                    self.offset += extension_length;
                }
            }
        }
    }

    pub fn parse_client_hello(data: &[u8]) {
        let mut parser = ClientHelloParser::new(data);
        parser.parse();
    }
}

// ServerHello 报文解析模块
mod serverhello_parsing {
    pub fn parse_server_response(response: &[u8], bytes_read: usize) {
        if bytes_read > 0 {
            if response[0] == 0x16 {
                println!("Received TLS Handshake message");
                
                let version = (response[1], response[2]);
                let record_length = ((response[3] as u16) << 8) | (response[4] as u16);
                
                println!("TLS Version: {:?}", version);
                println!("Record Length: {}", record_length);

                if bytes_read > 5 {
                    match response[5] {
                        0x02 => println!("Message Type: Server Hello"),
                        0x0b => println!("Message Type: Certificate"),
                        0x0e => println!("Message Type: Server Hello Done"),
                        _ => println!("Message Type: Unknown"),
                    }
                }
            } else {
                println!("Received non-TLS response");
            }
        } else {
            println!("No response received from server");
        }
    }
}

const SERVER_NAME: &str = "WIN-MEGACP61GRJ";
const SERVER_STATIC_IP: &str = "192.168.110.128";
const PORT: u16 = 443;

fn print_configuration(server_name: &str, server_ip: &str, port: u16, use_default_name: bool, use_default_ip: bool, use_default_port: bool) {
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
    sleep(Duration::from_secs(3)); // 睡眠 3 秒
    stdout.reset().unwrap();
}
fn main() -> Result<(), Box<dyn std::error::Error>> {
    let matches = Command::new("TLS Client")
        .arg(arg!(-s --server <SERVER_NAME> "Sets the server name").required(false))
        .arg(arg!(-i --ip <SERVER_IP> "Sets the server IP address").required(false))
        .arg(arg!(-p --port <PORT> "Sets the port number").required(false).default_value("443"))
        .arg(arg!(--test_env "Enables test environment mode").action(ArgAction::SetTrue))
        .arg(arg!(--disable_parse_client_hello "Enables or disables ClientHello parsing").default_value("true").action(ArgAction::SetFalse))
        .get_matches();

    let server_name = matches.get_one::<String>("server").unwrap_or(&SERVER_NAME.to_string()).to_string();
    let server_ip = matches.get_one::<String>("ip").unwrap_or(&SERVER_STATIC_IP.to_string()).to_string();
    let port: u16 = matches.get_one::<String>("port").unwrap().parse().unwrap_or(PORT);

    // 检查是否使用了默认值
    let use_default_name = server_name == SERVER_NAME;
    let use_default_ip = server_ip == SERVER_STATIC_IP;
    let use_default_port = port == PORT;

    // 打印配置提示信息
    print_configuration(&server_name, &server_ip, port, use_default_name, use_default_ip, use_default_port);

    
    let config = Arc::new(tls_config::create_tls_config());
    let mut conn = tls_config::create_client_connection(config, server_name)?;

    let mut client_hello = Vec::new();
    conn.write_tls(&mut client_hello)?;
    // 检查是否启用 ClientHello 解析
    if matches.get_flag("disable_parse_client_hello") {
        println!("{}","\nparse ClientHello raw bytes:".green());
        sleep(Duration::from_secs(2)); // 睡眠 3 秒
        clienthello_parsing::parse_client_hello(&client_hello);
    }
    if matches.get_flag("test_env") {
        println!("{}","\nTest environment is enabled. sending ClientHello to server.".green());
        sleep(Duration::from_secs(1)); // 睡眠 3 秒
        let access = format!("{}:{}", server_ip, port);
        let mut stream = network::establish_tcp_connection(&access)?;
        network::send_data(&mut stream, &client_hello)?;
        println!("\nSending ClientHello to server...");
        let mut server_response = [0; 4096];
        let bytes_read = network::receive_data(&mut stream, &mut server_response)?;
        println!("Received {} bytes from server", bytes_read);
        serverhello_parsing::parse_server_response(&server_response, bytes_read);
    } else {
        println!("{}","\nTest environment is false. Not sending ClientHello to server.".green());
    }
    Ok(())
}
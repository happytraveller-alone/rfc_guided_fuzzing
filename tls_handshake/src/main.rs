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
use std::process::exit;

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


mod serverhello_parsing {
    // use super::*;
    use super::TLS_EXTENSIONS;
    pub struct ServerHelloParser<'a> {
        data: &'a [u8],
        offset: usize,
    }

    impl<'a> ServerHelloParser<'a> {
        pub fn new(data: &'a [u8]) -> Self {
            Self { data, offset: 0 }
        }

        pub fn parse_server_response(&mut self) {
            if self.data[self.offset] == 0x16 {
                println!("Received TLS Handshake message");

                // 解析 TLS Record Layer
                self.parse_tls_record_layer();

                // 遍历所有 Handshake 消息
                while self.offset < self.data.len() {
                    let handshake_type = self.data[self.offset];
                    self.offset += 1;
                    let handshake_length = self.read_u24();
                    println!("\nHandshake Protocol:");
                    match handshake_type {
                        0x02 => println!("  Handshake Type: {:02X} (Server Hello)", handshake_type),
                        0x0b => println!("  Handshake Type: {:02X} (Certificate)", handshake_type),
                        0x0c => println!("  Handshake Type: {:02X} (Server Key Exchange)", handshake_type),
                        0x0e => println!("  Handshake Type: {:02X} (Server Hello Done)", handshake_type),
                        _ => println!("  Handshake Type: {:02X} (Unknown)", handshake_type),
                    }
                    println!("  Length: {} bytes", handshake_length);

                    match handshake_type {
                        0x02 => self.parse_server_hello(),
                        0x0b => self.parse_certificate(handshake_length),
                        0x0c => self.parse_server_key_exchange(handshake_length),
                        0x0e => self.parse_server_hello_done(),
                        _ => self.offset += handshake_length as usize,
                    }
                }
            } else {
                println!("Received non-TLS response");
            }
        }

        fn parse_tls_record_layer(&mut self) {
            println!("TLS Record Layer:");
            println!("  Content Type: {:02X} (Handshake)", self.data[self.offset]);
            self.offset += 1;
            println!(
                "  Version: {:02X} {:02X} (TLS Version)",
                self.data[self.offset], self.data[self.offset + 1]
            );
            self.offset += 2;
            let record_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            println!("  Length: {} bytes", record_length);
            self.offset += 2;
        }

        fn parse_server_hello(&mut self) {
            println!("  Server Hello:");
            let version = (self.data[self.offset], self.data[self.offset + 1]);
            println!("    Version: {:02X} {:02X} (TLS Version)", version.0, version.1);
            self.offset += 2;

            print!("    Random: ");
            for i in 0..32 {
                print!("{:02X} ", self.data[self.offset + i]);
            }
            println!();
            self.offset += 32;

            let session_id_length = self.data[self.offset] as usize;
            println!("    Session ID Length: {} bytes", session_id_length);
            self.offset += 1;

            if session_id_length > 0 {
                print!("    Session ID: ");
                for i in self.offset..self.offset + session_id_length {
                    print!("{:02X} ", self.data[i]);
                }
                println!();
                self.offset += session_id_length;
            }

            // 解析 Cipher Suite
            let cipher_suite = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            println!("    Cipher Suite: {:04X} (Cipher Suite Code)", cipher_suite);
            self.offset += 2;

            // 解析 Compression Method
            let compression_method = self.data[self.offset];
            println!("    Compression Method: {:02X} (Compression Method)", compression_method);
            self.offset += 1;

            // 解析 Extensions
            if self.offset < self.data.len() {
                let extensions_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
                println!("    Extensions Length: {} bytes", extensions_length);
                self.offset += 2;
                self.parse_extensions(extensions_length as usize);
            }
        }

        fn parse_certificate(&mut self, length: u32) {
            // println!("  Certificate:");
            let certificates_length = self.read_u24();
            println!("  Certificates Length: {} bytes", length);
            
            let mut certificate_index = 1;
            let end_offset = self.offset + certificates_length as usize;
            while self.offset != end_offset{
                let cert_length = self.read_u24();
                println!("    Certificate {:<02} (Length: {} bytes)", certificate_index, cert_length);
                self.offset += cert_length as usize;
                certificate_index += 1;
            }
        }

        fn parse_server_key_exchange(&mut self, length: u32) {
            println!("  Server Key Exchange:");
            println!("    Length: {} bytes", length);
            let curve_type = self.data[self.offset];
            let named_curve = u16::from_be_bytes([self.data[self.offset + 1], self.data[self.offset + 2]]);
            let public_key_length = self.data[self.offset + 3];

            println!("    Curve Type: {:02X}", curve_type);
            println!("    Named Curve: {:04X}", named_curve);
            println!("    Public Key Length: {} bytes", public_key_length);
            
            self.offset += 4;
            self.offset += public_key_length as usize;
            let signature_algorithm = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            self.offset += 2;
            let signature_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            self.offset += 2;
            println!("    Signature Algorithm: {:04X}", signature_algorithm);
            println!("    Signature Length: {:04X}", signature_length);
            self.offset += signature_length as usize;
        }

        fn parse_server_hello_done(&mut self) {
            println!("  Server Hello Done:");
            println!("    Length: 0 bytes (Indicates no additional data)");
        }

        fn parse_extensions(&mut self, length: usize) {
            let end = self.offset + length;
            while self.offset < end {
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
        
        fn read_u24(&mut self) -> u32 {
            let result = u32::from_be_bytes([0, self.data[self.offset], self.data[self.offset + 1], self.data[self.offset + 2]]);
            self.offset += 3;
            result
        }
    }
}


// 测试本机网络环境，验证是否能够连接到 `www.rust-lang.org` 并获取 HTTP 200 响应
fn test_local_connection() -> Result<(), Box<dyn std::error::Error>> {
    let mut root_store = RootCertStore::empty();
    root_store.extend(webpki_roots::TLS_SERVER_ROOTS.iter().cloned());
    let mut config = rustls::ClientConfig::builder()
        .with_root_certificates(root_store)
        .with_no_client_auth();

    // 启用 SSLKEYLOGFILE
    config.key_log = Arc::new(rustls::KeyLogFile::new());
    let server_name = "www.rust-lang.org".try_into()?;
    let mut conn = rustls::ClientConnection::new(Arc::new(config), server_name)?;
    let mut sock = TcpStream::connect("www.rust-lang.org:443")?;
    let mut tls = rustls::Stream::new(&mut conn, &mut sock);
    tls.write_all(
        concat!(
            "GET / HTTP/1.1\r\n",
            "Host: www.rust-lang.org\r\n",
            "Connection: close\r\n",
            "Accept-Encoding: identity\r\n",
            "\r\n"
        )
        .as_bytes(),
    )?;

    // 检查是否能够协商 TLS 并建立连接
    let ciphersuite = tls.conn.negotiated_cipher_suite().unwrap();
    println!("Local connection successful, negotiated ciphersuite: {:?}", ciphersuite.suite());

    let mut plaintext = Vec::new();
    tls.read_to_end(&mut plaintext)?;
    if plaintext.windows(b"200 OK".len()).any(|window| window == b"200 OK") {
        println!("{}","Local connection test passed: Received HTTP 200 response.".green());
        Ok(())
    } else {
        Err("Local connection test failed: Did not receive HTTP 200 response.".into())
    }
}

// 测试目标服务器是否可以连接
fn test_server_connection(server_ip: &str, port: u16) -> Result<(), Box<dyn std::error::Error>> {
    let address = format!("{}:{}", server_ip, port);
    println!("Testing connection to server: {}", address);
    let stream = TcpStream::connect(&address)?;
    println!("Successfully connected to the server: {}", address);
    drop(stream);
    Ok(())
}

// 打印错误信息并退出程序
fn print_error_and_exit(message: &str) {
    let mut stderr = StandardStream::stderr(ColorChoice::Always);
    stderr.set_color(ColorSpec::new().set_fg(Some(Color::Red)).set_bold(true)).unwrap();
    writeln!(&mut stderr, "Error: {}", message).unwrap();
    stderr.reset().unwrap();
    exit(1);
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

// 自定义帮助函数
fn print_help() {
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
    println!("{}","=======================================================".green());
}
fn main() -> Result<(), Box<dyn std::error::Error>> {
    // 本机网络环境测试
    println!("Performing local network environment test...");
    if let Err(e) = test_local_connection() {
        print_error_and_exit(&format!("Local environment test failed: {}", e));
    }
    println!("{}","Local network environment test passed.\n".green());
    let matches = Command::new("TLS Client")
        .about("A simple TLS client to send ClientHello and optionally parse responses")
        .arg(arg!(-s --server <SERVER_NAME> "Sets the server name").required(false))
        .arg(arg!(-i --ip <SERVER_IP> "Sets the server IP address").required(false))
        .arg(arg!(-p --port <PORT> "Sets the port number").required(false).default_value("443"))
        .arg(arg!(--test_env "Enables test environment mode").action(ArgAction::SetTrue))
        .arg(arg!(--disable_parse_client_hello "Enables or disables ClientHello parsing").default_value("false").action(ArgAction::SetTrue))
        .arg(arg!(--disable_parse_server_response "Enables or disables Server response").default_value("false").action(ArgAction::SetTrue))
        .arg(arg!(--use_guide "Show help information").action(ArgAction::SetTrue)) // 添加 --help 参数
        .get_matches();

    // 检查是否启用 --help 参数
    if matches.get_flag("use_guide") {
        print_help(); // 调用自定义的帮助函数
        return Ok(()); // 提前返回，避免继续执行其他逻辑
    }

    let server_name = matches.get_one::<String>("server").unwrap_or(&SERVER_NAME.to_string()).to_string();
    let server_ip = matches.get_one::<String>("ip").unwrap_or(&SERVER_STATIC_IP.to_string()).to_string();
    let port: u16 = matches.get_one::<String>("port").unwrap().parse().unwrap_or(PORT);

    // 检查是否使用了默认值
    let use_default_name = server_name == SERVER_NAME;
    let use_default_ip = server_ip == SERVER_STATIC_IP;
    let use_default_port = port == PORT;

    // 打印配置提示信息
    print_configuration(&server_name, &server_ip, port, use_default_name, use_default_ip, use_default_port);

    // 服务器环境测试
    println!("Performing server environment test...");
    if let Err(e) = test_server_connection(&server_ip, port) {
        print_error_and_exit(&format!("Server environment test failed: {}", e));
    }
    println!("{}","Server environment test passed.\n".green());
    
    let config = Arc::new(tls_config::create_tls_config());
    let mut conn = tls_config::create_client_connection(config, server_name)?;

    let mut client_hello = Vec::new();
    conn.write_tls(&mut client_hello)?;
    // 检查是否启用 ClientHello 解析
    if !matches.get_flag("disable_parse_client_hello") {
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
        if !matches.get_flag("disable_parse_server_response"){
            // 使用 ServerHelloParser 进行解析
            println!("{}","\nParse Server Response is enabled. Start parsing server response.".green());
            sleep(Duration::from_secs(1));
            let mut parser = serverhello_parsing::ServerHelloParser::new(&server_response[..bytes_read]);
            parser.parse_server_response();
        }
    } else {
        println!("{}","\nTest environment is false. Not sending ClientHello to server.".green());
    }

    // 在程序结束时显示帮助信息
    print_help();
    Ok(())
}
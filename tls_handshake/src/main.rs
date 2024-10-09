use std::sync::Arc;
use std::net::TcpStream;
use std::io::Write;
use std::io::Read;
use rustls::{ClientConfig, ClientConnection, RootCertStore};

fn parse_client_hello(data: &[u8]) {
    let mut offset = 0;

    // TLS Record Layer
    println!("TLS Record Layer:");
    println!("  Content Type: {:02X} (Handshake)", data[offset]);
    offset += 1;
    println!("  Version: {:02X} {:02X} (TLS 1.0 for backwards compatibility)", data[offset], data[offset+1]);
    offset += 2;
    let record_length = u16::from_be_bytes([data[offset], data[offset+1]]);
    println!("  Length: {:04X} ({} bytes)", record_length, record_length);
    offset += 2;

    // Handshake Layer
    println!("Handshake Layer:");
    println!("  Handshake Type: {:02X} (ClientHello)", data[offset]);
    offset += 1;
    let handshake_length = u32::from_be_bytes([0, data[offset], data[offset+1], data[offset+2]]);
    println!("  Length: {:06X} ({} bytes)", handshake_length, handshake_length);
    offset += 3;

    // ClientHello
    println!("ClientHello:");
    println!("  Client Version: {:02X} {:02X}", data[offset], data[offset+1]);
    offset += 2;
    println!("  Random:");
    print!("    ");
    for i in 0..32 {
        print!("{:02X} ", data[offset + i]);
        if (i + 1) % 16 == 0 { print!("\n    "); }
    }
    println!();
    offset += 32;

    // Session ID
    let session_id_length = data[offset] as usize;
    offset += 1;
    println!("  Session ID Length: {:02X} ({} bytes)", session_id_length, session_id_length);
    if session_id_length > 0 {
        print!("  Session ID: ");
        for i in 0..session_id_length {
            print!("{:02X} ", data[offset + i]);
        }
        println!();
        offset += session_id_length;
    }

    // Cipher Suites
    let cipher_suites_length = u16::from_be_bytes([data[offset], data[offset+1]]) as usize;
    offset += 2;
    println!("  Cipher Suites Length: {:04X} ({} bytes)", cipher_suites_length, cipher_suites_length);
    print!("  Cipher Suites: ");
    for i in (0..cipher_suites_length).step_by(2) {
        print!("{:02X}{:02X} ", data[offset + i], data[offset + i + 1]);
    }
    println!();
    offset += cipher_suites_length;

    // Compression Methods
    let compression_methods_length = data[offset] as usize;
    offset += 1;
    println!("  Compression Methods Length: {:02X} ({} bytes)", compression_methods_length, compression_methods_length);
    print!("  Compression Methods: ");
    for i in 0..compression_methods_length {
        print!("{:02X} ", data[offset + i]);
    }
    println!();
    offset += compression_methods_length;

    // Extensions (if present)
    if offset < data.len() {
        let extensions_length = u16::from_be_bytes([data[offset], data[offset+1]]) as usize;
        offset += 2;
        println!("  Extensions Length: {:04X} ({} bytes)", extensions_length, extensions_length);
        while offset < data.len() {
            let extension_type = u16::from_be_bytes([data[offset], data[offset+1]]);
            offset += 2;
            let extension_length = u16::from_be_bytes([data[offset], data[offset+1]]) as usize;
            offset += 2;
            println!("    Extension Type: {:04X}, Length: {:04X} ({} bytes)", extension_type, extension_length, extension_length);
            offset += extension_length;
        }
    }
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // 1. 设置 TLS 配置
    let root_store = RootCertStore::empty();
    let config = ClientConfig::builder()
        .with_root_certificates(root_store)
        .with_no_client_auth();
    
    // 2. 创建 ClientConnection
    let server_name = "WIN-MEGACP61GRJ".try_into()?;
    let mut conn = ClientConnection::new(Arc::new(config), server_name)?;
    
    // 3. 准备发送缓冲区
    let mut client_hello = Vec::new();
    
    // 4. 生成 ClientHello 消息
    conn.write_tls(&mut client_hello)?;
    
    // 5. 建立 TCP 连接
    let mut stream = TcpStream::connect("192.168.110.128:443")?;
    
    // 6. 发送 ClientHello
    stream.write_all(&client_hello)?;
    
    // 7. 打印 ClientHello 内容（十六进制格式）
    // println!("ClientHello sent: {:02X?}", client_hello);
    println!("ClientHello raw bytes:");
    for (i, &byte) in client_hello.iter().enumerate() {
        print!("{:02X} ", byte);
        if (i + 1) % 16 == 0 { println!(); }
    }
    println!();
    // 现在让我们解析 ClientHello
    parse_client_hello(&client_hello);
    // 7. 接收服务器响应
    let mut server_response = [0; 4096]; // 假设响应不会超过4KB
    let bytes_read = stream.read(&mut server_response)?;
    println!("Received {} bytes from server", bytes_read);

    // 8. 解析服务器响应
    if bytes_read > 0 {
        // 检查是否是 TLS 握手消息
        if server_response[0] == 0x16 { // 0x16 是 TLS 握手协议的标识
            println!("Received TLS Handshake message");
            
            // 解析 TLS 记录层
            let version = (server_response[1], server_response[2]);
            let record_length = ((server_response[3] as u16) << 8) | (server_response[4] as u16);
            
            println!("TLS Version: {:?}", version);
            println!("Record Length: {}", record_length);

            // 解析握手消息类型
            if bytes_read > 5 {
                match server_response[5] {
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

    Ok(())
}
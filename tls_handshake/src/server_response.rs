use super::TLS_EXTENSIONS;
use colored::*;
pub struct ServerHelloParser<'a> {
    data: &'a [u8],
    offset: usize,
}
pub struct TlsRecordLayer {
    content_type: u8,
    version: (u8, u8),
    length: u16,
}
impl<'a> ServerHelloParser<'a> {
    pub fn new(data: &'a [u8]) -> Self {
        Self { data, offset: 0 }
    }

    pub fn parse_server_response(&mut self, length: u16) {
        // if self.data[self.offset] == 0x16 {
        //     println!("Received TLS Handshake message");
        //     // 解析 TLS Record Layer
        //     // let length = self.parse_tls_record_layer_handshake();
            // 遍历所有 Handshake 消息
        while self.offset < length as usize{
            let handshake_type = self.data[self.offset];
            self.offset += 1;
            let handshake_length = self.read_u24();
            println!("  Handshake Protocol:");
            match handshake_type {
                0x02 => println!("    Handshake Type: {:02X} (Server Hello)", handshake_type),
                0x0b => println!("    Handshake Type: {:02X} (Certificate)", handshake_type),
                0x0c => println!("    Handshake Type: {:02X} (Server Key Exchange)", handshake_type),
                0x0e => println!("    Handshake Type: {:02X} (Server Hello Done)", handshake_type),
                _ => println!("    Handshake Type: {:02X} (Unknown)", handshake_type),
            }
            println!("    Length: {} bytes", handshake_length);
            match handshake_type {
                0x02 => self.parse_server_hello(),
                0x0b => self.parse_certificate(handshake_length),
                0x0c => self.parse_server_key_exchange(handshake_length),
                0x0e => self.parse_server_hello_done(),
                _ => self.offset += handshake_length as usize,
            }
        }
    } 
        // else {
        //     println!("Received non-TLS response");
        // }
    // fn parse_tls_record_layer_handshake(&mut self) -> u16{
    //     println!("TLS Record Layer:");
    //     println!("  Content Type: {:02X} (Handshake)", self.data[self.offset]);
    //     self.offset += 1;
    //     println!(
    //         "  Version: {:02X} {:02X} (TLS Version)",
    //         self.data[self.offset], self.data[self.offset + 1]
    //     );
    //     self.offset += 2;
    //     let record_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
    //     println!("  Length: {} bytes", record_length);
    //     self.offset += 2;
    //     record_length
    // }
    fn parse_server_hello(&mut self) {
        println!("    Server Hello:");
        let version = (self.data[self.offset], self.data[self.offset + 1]);
        println!("      Version: {:02X} {:02X} (TLS Version)", version.0, version.1);
        self.offset += 2;
        print!("      Random: ");
        for i in 0..32 {
            print!("{:02X} ", self.data[self.offset + i]);
        }
        println!();
        self.offset += 32;
        let session_id_length = self.data[self.offset] as usize;
        println!("      Session ID Length: {} bytes", session_id_length);
        self.offset += 1;
        if session_id_length > 0 {
            print!("      Session ID: ");
            for i in self.offset..self.offset + session_id_length {
                print!("{:02X} ", self.data[i]);
            }
            println!();
            self.offset += session_id_length;
        }
        // 解析 Cipher Suite
        let cipher_suite = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
        println!("      Cipher Suite: {:04X} (Cipher Suite Code)", cipher_suite);
        self.offset += 2;
        // 解析 Compression Method
        let compression_method = self.data[self.offset];
        println!("      Compression Method: {:02X} (Compression Method)", compression_method);
        self.offset += 1;
        // 解析 Extensions
        if self.offset < self.data.len() {
            let extensions_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            println!("      Extensions Length: {} bytes", extensions_length);
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
                println!("      Extension: {:<25} (Type: {:<04X}, Length: {:04X} ({:<3} bytes))", 
                         extension_name, extension_type, extension_length, extension_length);
                self.offset += extension_length;
        }
    }
    fn parse_tls_record_layers(&mut self) -> Vec<TlsRecordLayer> {
        let mut record_layers = Vec::new();
        
        while self.offset < self.data.len() {
            let content_type = self.data[self.offset];
            self.offset += 1;
            
            let version = (self.data[self.offset], self.data[self.offset + 1]);
            self.offset += 2;
            
            let length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            self.offset += 2;
            
            record_layers.push(TlsRecordLayer {
                content_type,
                version,
                length,
            });
            
            // 移动 offset 到下一个 Record Layer
            self.offset += length as usize;
        }
        
        record_layers
    }

    fn content_type_to_string(&self, content_type: u8) -> &'static str {
        match content_type {
            0x14 => "Change Cipher Spec",
            0x15 => "Alert",
            0x16 => "Handshake",
            0x17 => "Application Data",
            _ => "Unknown",
        }
    }
    fn read_u24(&mut self) -> u32 {
        let result = u32::from_be_bytes([0, self.data[self.offset], self.data[self.offset + 1], self.data[self.offset + 2]]);
        self.offset += 3;
        result
    }
}

pub fn parse_server_response(data: &[u8], parse_enabled: bool) {
    let mut parser = ServerHelloParser::new(data);
    let record_layers = parser.parse_tls_record_layers();
    parser.offset = 0;
    if !parse_enabled {
        println!("{}", "parse server response disabled".yellow());
        return
    }
    for (index, record) in record_layers.into_iter().enumerate() {
        println!("\nRecord Layer {}:", index + 1);
        println!("  Content Type: {:02X} ({})", record.content_type, parser.content_type_to_string(record.content_type));
        println!("  Version: {:02X} {:02X} (TLS Version)", record.version.0, record.version.1);
        println!("  Length: {} bytes", record.length);

        // 跳过 Record Layer 头部（5 字节）
        parser.offset += 5;

        if record.content_type == 0x16 { // Handshake
            parser.parse_server_response(record.length);
        } else {
            // 对于非 Handshake 类型，直接跳过内容
            parser.offset += record.length as usize;
        }
    }
}
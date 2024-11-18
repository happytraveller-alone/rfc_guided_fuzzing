use super::TLS_EXTENSIONS;
use log::{debug, info, trace};
pub struct ServerHelloParser<'a> {
    data: &'a [u8],
    offset: usize,
}
pub struct TlsRecordLayer {
    content_type: u8,
    version: (u8, u8),
    length: u16,
}

const RETRY_REQUEST_RANDOM: [u8; 32] = [
    0xCF, 0x21, 0xAD, 0x74, 0xE5, 0x9A, 0x61, 0x11, 0xBE, 0x1D, 0x8C, 0x02, 0x1E, 0x65, 0xB8, 0x91,
    0xC2, 0xA2, 0x11, 0x16, 0x7A, 0xBB, 0x8C, 0x5E, 0x07, 0x9E, 0x09, 0xE2, 0xC8, 0xA8, 0x33, 0x9C,
];

impl<'a> ServerHelloParser<'a> {
    pub fn new(data: &'a [u8]) -> Self {
        Self { data, offset: 0 }
    }

    pub fn parse_server_response(&mut self, length: u16) {
        // 遍历所有 Handshake 消息
        while self.offset < length as usize{
            let handshake_type: u8 = self.data[self.offset];
            self.offset += 1;
            let handshake_length: u32 = self.read_u24();
            trace!("  Handshake Protocol:");
            match handshake_type {
                0x02 => info!("    Handshake Type: {:02X} ", handshake_type),
                0x0b => info!("    Handshake Type: {:02X} (Certificate)", handshake_type),
                0x0c => info!("    Handshake Type: {:02X} (Server Key Exchange)", handshake_type),
                0x0e => info!("    Handshake Type: {:02X} (Server Hello Done)", handshake_type),
                _ => debug!("    Handshake Type: {:02X} (Unknown)", handshake_type),
            }
            trace!("    Length: {} bytes", handshake_length);
            match handshake_type {
                0x02 => self.parse_server_hello(),
                0x0b => self.parse_certificate(handshake_length),
                0x0c => self.parse_server_key_exchange(handshake_length),
                0x0e => self.parse_server_hello_done(),
                _ => self.offset += handshake_length as usize,
            }
        }
    } 
    fn parse_server_hello(&mut self) {
        trace!("    Server Hello:");
        let version: (u8, u8) = (self.data[self.offset], self.data[self.offset + 1]);
        trace!("      Version: {:02X} {:02X} (TLS Version)", version.0, version.1);
        self.offset += 2;
        let mut random_store = String::new();
        random_store.push_str("      Random: ");
        // print!();
        let random: &[u8] = &self.data[self.offset..self.offset + 32];
        for byte in random {
            random_store.push_str(format!("{:02X} ", byte).as_str());
            // print!();
        }
        trace!("{}",random_store);
        
        

        self.offset += 32;
        let session_id_length = self.data[self.offset] as usize;
        trace!("      Session ID Length: {} bytes", session_id_length);
        self.offset += 1;
        if session_id_length > 0 {
            let mut session_id_store = String::new();
            session_id_store.push_str("      Session ID: ");
            // print!("      Session ID: ");
            for i in self.offset..self.offset + session_id_length {
                // print!("{:02X} ", self.data[i]);
                session_id_store.push_str(format!("{:02X} ", self.data[i]).as_str());
            }
            trace!("{}",session_id_store);
            self.offset += session_id_length;
        }
        // 解析 Cipher Suite
        let cipher_suite = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
        trace!("      Cipher Suite: {:04X} (Cipher Suite Code)", cipher_suite);
        self.offset += 2;
        // 解析 Compression Method
        let compression_method = self.data[self.offset];
        trace!("      Compression Method: {:02X} (Compression Method)", compression_method);
        self.offset += 1;
        // 解析 Extensions
        if self.offset < self.data.len() {
            let extensions_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            trace!("      Extensions Length: {} bytes", extensions_length);
            self.offset += 2;
            self.parse_extensions(extensions_length as usize);
        }
    }
    fn parse_certificate(&mut self, length: u32) {
        // println!("  Certificate:");
        let certificates_length = self.read_u24();
        trace!("  Certificates Length: {} bytes", length);
        
        let mut certificate_index = 1;
        let end_offset = self.offset + certificates_length as usize;
        while self.offset != end_offset{
            let cert_length = self.read_u24();
            trace!("    Certificate {:<02} (Length: {} bytes)", certificate_index, cert_length);
            self.offset += cert_length as usize;
            certificate_index += 1;
        }
    }
    fn parse_server_key_exchange(&mut self, length: u32) {
        trace!("  Server Key Exchange:");
        trace!("    Length: {} bytes", length);
        let curve_type = self.data[self.offset];
        let named_curve = u16::from_be_bytes([self.data[self.offset + 1], self.data[self.offset + 2]]);
        let public_key_length = self.data[self.offset + 3];
        trace!("    Curve Type: {:02X}", curve_type);
        trace!("    Named Curve: {:04X}", named_curve);
        trace!("    Public Key Length: {} bytes", public_key_length);
        
        self.offset += 4;
        self.offset += public_key_length as usize;
        let signature_algorithm = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
        self.offset += 2;
        let signature_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
        self.offset += 2;
        trace!("    Signature Algorithm: {:04X}", signature_algorithm);
        trace!("    Signature Length: {:04X}", signature_length);
        self.offset += signature_length as usize;
    }
    fn parse_server_hello_done(&mut self) {
        trace!("  Server Hello Done:");
        trace!("    Length: 0 bytes (Indicates no additional data)");
    }
    fn parse_extensions(&mut self, length: usize) {
        let end = self.offset + length;
        while self.offset < end {
            let extension_type = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
            self.offset += 2;
                let extension_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
                self.offset += 2;
                let extension_name = TLS_EXTENSIONS.get(&extension_type).map_or("Unknown", |&name| name);
                trace!("      Extension: {:<25} (Type: {:<04X}, Length: {:04X} ({:<3} bytes))", 
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

pub fn parse_server_response(data: &[u8], check_enable: bool) {
    let mut parser = ServerHelloParser::new(data);
    let record_layers = parser.parse_tls_record_layers();
    parser.offset = 0;
    if !check_enable {
        info!(target: "handshake_record", "Parse server response disabled");
        // +5 
        // println!("{}", format!("{}",).green());
        let handshake_type = parser.data[parser.offset + 5];
        match parser.data[parser.offset + 5] {
            0x02 => {
                // info!("{}",format!("Handshake Type: {:02X} ", handshake_type).green());
                if &parser.data[parser.offset + 11..parser.offset + 43] == RETRY_REQUEST_RANDOM{
                    info!(target: "handshake_record", "{}","(ServerRetryRequest)\n");
                } else {
                    info!(target: "handshake_record", "{}","(ServerHello)\n");
                }
            },
            0x0b => info!("{}",format!("Handshake Type: {:02X} (Certificate)\n", handshake_type)),
            0x0c => info!("{}",format!("Handshake Type: {:02X} (Server Key Exchange)\n", handshake_type)),
            0x0e => info!("{}",format!("Handshake Type: {:02X} (Server Hello Done)\n", handshake_type)),
            _ => debug!("{}",format!("Handshake Type: {:02X} (Unknown)\n", handshake_type)),
        }
        return
    }
    for (index, record) in record_layers.into_iter().enumerate() {
        trace!("Record Layer {}:", index + 1);
        trace!("  Content Type: {:02X} ({})", record.content_type, parser.content_type_to_string(record.content_type));
        trace!("  Version: {:02X} {:02X} (TLS Version)", record.version.0, record.version.1);
        trace!("  Length: {} bytes", record.length);
        // 跳过 Record Layer 头部（5 字节）
        parser.offset += 5;

        if record.content_type == 0x16 { // Handshake
            parser.parse_server_response(record.length);
        } else {
            // 对于非 Handshake 类型，直接跳过内容
            parser.offset += record.length as usize;
        }
        
    }
    trace!("\n\n");
}
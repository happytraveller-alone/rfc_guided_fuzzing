use super::TLS_EXTENSIONS;
use std::collections::HashMap;

// 定义一个解析 ClientHello 消息的结构体
pub struct ClientHelloParser<'a> {
    data: &'a [u8],
    offset: usize,
    fields: HashMap<String, String>,
}

impl<'a> ClientHelloParser<'a> {
    // 创建一个新的 ClientHelloParser 实例
    pub fn new(data: &'a [u8]) -> Self {
        Self { 
            data, 
            offset: 0, 
            fields: HashMap::new(),
        }
    }

    // 主解析函数，按照 TLS 的结构层次依次调用各个部分的解析函数
    pub fn parse(&mut self) {
        self.parse_tls_record_layer();       // 解析 TLS 记录层
        self.parse_handshake_layer();        // 解析握手层
        self.parse_client_hello();           // 解析 ClientHello 消息
        self.parse_session_id();             // 解析 Session ID
        self.parse_cipher_suites();          // 解析密码套件
        self.parse_compression_methods();    // 解析压缩方法
        self.parse_extensions();             // 解析扩展字段
    }

    // 解析 TLS 记录层
    fn parse_tls_record_layer(&mut self) {
        let content_type = format!("{:02X}", self.data[self.offset]);
        self.fields.insert("01. TLS Record Layer - Content Type".to_string(), content_type.clone());
        println!("TLS Record Layer:");
        println!("  Content Type: {} (Handshake)", content_type);
        self.offset += 1;

        let version = format!("{:02X} {:02X}", self.data[self.offset], self.data[self.offset + 1]);
        self.fields.insert("02. TLS Record Layer - Version".to_string(), version.clone());
        println!("  Version: {} (TLS 1.0 for backwards compatibility)", version);
        self.offset += 2;

        let record_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
        self.fields.insert("03. TLS Record Layer - Length".to_string(), format!("{:04X}", record_length));
        println!("  Length: {:04X} ({} bytes)", record_length, record_length);
        self.offset += 2;
    }

    // 解析握手层
    fn parse_handshake_layer(&mut self) {
        let handshake_type = format!("{:02X}", self.data[self.offset]);
        self.fields.insert("04. Handshake Layer - Handshake Type".to_string(), handshake_type.clone());
        println!("Handshake Layer:");
        println!("  Handshake Type: {} (ClientHello)", handshake_type);
        self.offset += 1;

        let handshake_length = u32::from_be_bytes([0, self.data[self.offset], self.data[self.offset + 1], self.data[self.offset + 2]]);
        self.fields.insert("05. Handshake Layer - Length".to_string(), format!("{:06X}", handshake_length));
        println!("  Length: {:06X} ({} bytes)", handshake_length, handshake_length);
        self.offset += 3;
    }

    // 解析 ClientHello 部分
    fn parse_client_hello(&mut self) {
        println!("ClientHello:");
        let client_version = format!("{:02X} {:02X}", self.data[self.offset], self.data[self.offset + 1]);
        self.fields.insert("06. ClientHello - Client Version".to_string(), client_version.clone());
        println!("  Client Version: {}", client_version);
        self.offset += 2;

        let random: String = (0..32).map(|i| format!("{:02X} ", self.data[self.offset + i])).collect();
        self.fields.insert("07. ClientHello - Random".to_string(), random.clone());
        print!("  Random:");
        println!("{}", random);
        self.offset += 32;
    }

    // 解析 Session ID
    fn parse_session_id(&mut self) {
        let session_id_length = self.data[self.offset] as usize;
        self.fields.insert("08. Session ID Length".to_string(), format!("{:02X}", session_id_length));
        self.offset += 1;
        println!("  Session ID Length: {:02X} ({} bytes)", session_id_length, session_id_length);
        if session_id_length > 0 {
            let session_id: String = (0..session_id_length).map(|i| format!("{:02X} ", self.data[self.offset + i])).collect();
            self.fields.insert("09. Session ID".to_string(), session_id.clone());
            println!("  Session ID: {}", session_id);
            self.offset += session_id_length;
        }
    }

    // 解析密码套件
    fn parse_cipher_suites(&mut self) {
        let cipher_suites_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
        self.fields.insert("10. Cipher Suites Length".to_string(), format!("{:04X}", cipher_suites_length));
        self.offset += 2;
        println!("  Cipher Suites Length: {:04X} ({} bytes)", cipher_suites_length, cipher_suites_length);

        let cipher_suites: String = (0..cipher_suites_length).step_by(2).map(|i| format!("{:02X}{:02X} ", self.data[self.offset + i], self.data[self.offset + i + 1])).collect();
        self.fields.insert("11. Cipher Suites".to_string(), cipher_suites.clone());
        println!("  Cipher Suites: {}", cipher_suites);
        self.offset += cipher_suites_length;
    }

    // 解析压缩方法
    fn parse_compression_methods(&mut self) {
        let compression_methods_length = self.data[self.offset] as usize;
        self.fields.insert("12. Compression Methods Length".to_string(), format!("{:02X}", compression_methods_length));
        self.offset += 1;
        println!("  Compression Methods Length: {:02X} ({} bytes)", compression_methods_length, compression_methods_length);

        let compression_methods: String = (0..compression_methods_length).map(|i| format!("{:02X} ", self.data[self.offset + i])).collect();
        self.fields.insert("13. Compression Methods".to_string(), compression_methods.clone());
        println!("  Compression Methods: {}", compression_methods);
        self.offset += compression_methods_length;
    }

    // 解析扩展字段
     // 解析扩展字段
     fn parse_extensions(&mut self) {
        if self.offset < self.data.len() {
            let extensions_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
            self.fields.insert("14. Extensions Length".to_string(), format!("{:04X}", extensions_length));
            self.offset += 2;
            println!("  Extensions Length: {:04X} ({} bytes)", extensions_length, extensions_length);
            
            let mut extension_count = 0;
            while self.offset < self.data.len() {
                extension_count += 1;
                let extension_type = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
                let extension_length = u16::from_be_bytes([self.data[self.offset + 2], self.data[self.offset + 3]]) as usize;
                let extension_name = TLS_EXTENSIONS.get(&extension_type).map_or("Unknown", |&name| name);
                
                // 存储扩展类型和长度信息
                let extension_info = format!("Type: {:04X}, Length: {:04X} ({} bytes)", extension_type, extension_length, extension_length);
                self.fields.insert(format!("15.{:02}.1 Extension - {} (Type and Length)", extension_count, extension_name), extension_info.clone());
                
                println!("    Extension: {:<25} ({})", extension_name, extension_info);
                
                self.offset += 4; // 移动偏移量，跳过类型和长度字段
                
                // 存储扩展内容
                if extension_length > 0 {
                    let content: String = (0..extension_length).map(|i| format!("{:02X}", self.data[self.offset + i])).collect();
                    self.fields.insert(format!("15.{:02}.2 Extension - {} (Content)", extension_count, extension_name), content.clone());
                    println!("      Content: {}", content);
                }
                
                self.offset += extension_length;
            }
        }
    }
    // fn parse_extensions(&mut self) {
    //     if self.offset < self.data.len() {
    //         let extensions_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
    //         self.fields.insert("14. Extensions Length".to_string(), format!("{:04X}", extensions_length));
    //         self.offset += 2;
    //         println!("  Extensions Length: {:04X} ({} bytes)", extensions_length, extensions_length);
    //         while self.offset < self.data.len() {
    //             let extension_type = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
    //             self.offset += 2;
    //             let extension_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
    //             self.offset += 2;
    //             let extension_name = TLS_EXTENSIONS.get(&extension_type).map_or("Unknown", |&name| name);
    //             let extension_info = format!("Type: {:04X}, Length: {:04X} ({} bytes)", extension_type, extension_length, extension_length);
    //             self.fields.insert(format!("15. Extension - {}", extension_name), extension_info);
    //             println!("    Extension: {:<25} (Type: {:<04X}, Length: {:04X} ({:<3} bytes))", 
    //                      extension_name, extension_type, extension_length, extension_length);
    //             self.offset += extension_length;
    //         }
    //     }
    // }
}

// 公开函数，用于解析传入的数据并生成 ClientHelloParser 实例
pub fn parse_client_hello(data: &[u8]) {
    let mut parser = ClientHelloParser::new(data);
    parser.parse();
    // 打印解析的字段映射表，格式化输出
    println!("\nParsed Fields:");
    let mut keys: Vec<_> = parser.fields.keys().collect();
    keys.sort();
    for key in keys {
        let value = &parser.fields[key];
        println!("  {}: {}", key, value);
    }
}
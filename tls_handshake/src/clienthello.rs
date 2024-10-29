use super::TLS_EXTENSIONS;

#[derive(Debug, Clone)]
pub struct ClientHello {
    // TLS Record Layer
    pub content_type: u8,           // 固定值 0x16
    pub version: [u8; 2],           // 固定值 [0x03, 0x01]
    pub record_length: u16,         // 动态值，需要计算

    // Handshake Layer
    pub handshake_type: u8,         // 固定值 0x01
    pub handshake_length: [u8; 3],  // 动态值，需要计算

    // ClientHello specific fields
    pub client_version: [u8; 2],    // 固定值 [0x03, 0x03]
    pub random: [u8; 32],           // 32 字节随机数
    pub session_id_length: u8,      // 动态值
    pub session_id: Vec<u8>,        // 动态值
    pub cipher_suites_length: u16,  // 动态值
    pub cipher_suites: Vec<u8>,     // 动态值
    pub compression_methods_length: u8,  // 动态值
    pub compression_methods: Vec<u8>,    // 动态值
    pub extensions_length: u16,     // 动态值
    pub extensions_num: u16,        // 动态值
    pub extensions: Vec<Extension>, // 动态值
}

#[derive(Debug, Clone)]
pub struct Extension {
    pub order_id: usize,
    pub extension_type: [u8; 2],
    pub extension_length: [u8; 2],
    pub extension_content: Vec<u8>,
}

impl ClientHello {
    pub fn new() -> Self {
        Self {
            content_type: 0x16,
            version: [0x03, 0x03],
            record_length: 0,  // 初始化为 0，后续计算
            handshake_type: 0x01,
            handshake_length: [0, 0, 0],  // 初始化为 0，后续计算
            client_version: [0x03, 0x03],
            random: [0; 32],
            session_id_length: 0,
            session_id: Vec::new(),
            cipher_suites_length: 0,
            cipher_suites: Vec::new(),
            compression_methods_length: 0,
            compression_methods: Vec::new(),
            extensions_length: 0,
            extensions_num: 0,
            extensions: Vec::new(),
        }
    }

    pub fn print(&self) {
        println!("ClientHello Contents:");
        self.print_tls_record_layer();
        self.print_handshake_layer();
        self.print_client_hello_body();
        self.print_session_id();
        self.print_cipher_suites();
        self.print_compression_methods();
        self.print_extensions();
    }

    fn print_tls_record_layer(&self) {
        println!("TLS Record Layer:");
        println!("  Content Type: 0x{:02X}", self.content_type);
        println!("  Version: 0x{:02X}{:02X}", self.version[0], self.version[1]);
        println!("  Length: 0x{:04X} ({} bytes)", 
                 self.record_length,
                 self.record_length);
    }

    fn print_handshake_layer(&self) {
        println!("\nHandshake Layer:");
        println!("  Handshake Type: 0x{:02X}", self.handshake_type);
        println!("  Length: 0x{:02X}{:02X}{:02X} ({} bytes)", 
                 self.handshake_length[0], 
                 self.handshake_length[1], 
                 self.handshake_length[2],
                 u32::from_be_bytes([0, self.handshake_length[0], self.handshake_length[1], self.handshake_length[2]]));
    }

    fn print_client_hello_body(&self) {
        println!("\nClientHello:");
        println!("  Client Version: 0x{:02X}{:02X}", self.client_version[0], self.client_version[1]);
        
        print!("  Random: ");
        for byte in &self.random {
            print!("{:02X} ", byte);
        }
        println!();
    }

    fn print_session_id(&self) {
        println!("  Session ID Length: 0x{:02X} ({} bytes)", self.session_id_length, self.session_id_length);
        if !self.session_id.is_empty() {
            print!("  Session ID: ");
            for byte in &self.session_id {
                print!("{:02X} ", byte);
            }
            println!();
        }
    }

    fn print_cipher_suites(&self) {
        println!("  Cipher Suites Length: 0x{:04X} ({} bytes)", 
                 self.cipher_suites_length,
                 self.cipher_suites_length);
        print!("  Cipher Suites: ");
        for byte in &self.cipher_suites {
            print!("{:02X} ", byte);
        }
        println!();
    }

    fn print_compression_methods(&self) {
        println!("  Compression Methods Length: 0x{:02X} ({} bytes)", 
                 self.compression_methods_length, self.compression_methods_length);
        print!("  Compression Methods: ");
        for byte in &self.compression_methods {
            print!("{:02X} ", byte);
        }
        println!();
    }

    fn print_extensions(&self) {
        println!("  Extensions Length: 0x{:04X} ({} bytes), Extensions Number: {}", 
                 self.extensions_length,
                 self.extensions_length,
                 self.extensions_num);
        
        for extension in self.extensions.iter() {
            let extension_type = u16::from_be_bytes(extension.extension_type);
            let extension_name = TLS_EXTENSIONS.get(&extension_type).map_or("Unknown", |&name| name);
            
            println!("    Extension {}:", extension.order_id);
            println!("      Type: 0x{:04X} ({})", extension_type, extension_name);
            println!("      Length: 0x{:04X} ({} bytes)", 
                     u16::from_be_bytes(extension.extension_length),
                     u16::from_be_bytes(extension.extension_length));
            print!("      Content: ");
            for byte in &extension.extension_content {
                print!("{:02X} ", byte);
            }
            println!();
        }
    }
}
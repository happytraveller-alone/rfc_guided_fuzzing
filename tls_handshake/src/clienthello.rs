use super::TLS_EXTENSIONS;
use std::collections::HashMap;


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
        // 创建一个 Cipher Suite 映射
        let mut cipher_suite_map = HashMap::new();
        cipher_suite_map.insert(0x1301, "TLS_AES_128_GCM_SHA256");
        cipher_suite_map.insert(0x1302, "TLS_AES_256_GCM_SHA384");
        cipher_suite_map.insert(0x1303, "TLS_CHACHA20_POLY1305_SHA256");
        cipher_suite_map.insert(0x1304, "TLS_AES_128_CCM_SHA256 ");
        cipher_suite_map.insert(0x1305, "TLS_AES_128_CCM_8_SHA256 ");
        cipher_suite_map.insert(0x00FF, "TLS_EMPTY_RENEGOTIATION_INFO_SCSV");

        // 添加 ECDHE 和 RSA 支持的 Cipher Suites
        cipher_suite_map.insert(0xC02C, "TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384");
        cipher_suite_map.insert(0xC02B, "TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256");
        cipher_suite_map.insert(0xCCA9, "TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256");
        cipher_suite_map.insert(0xC030, "TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384");
        cipher_suite_map.insert(0xC02F, "TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256");
        cipher_suite_map.insert(0xCCA8, "TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256");
        println!(
            "  Cipher Suites Length: 0x{:04X} ({} bytes)",
            self.cipher_suites_length,
            self.cipher_suites_length
        );

        // 解析 cipher_suites 字段并输出每个 Cipher Suite 的名称
        println!("  Cipher Suites:");
        for i in (0..self.cipher_suites.len()).step_by(2) {
            let code = (self.cipher_suites[i] as u16) << 8 | self.cipher_suites[i + 1] as u16;
            if let Some(name) = cipher_suite_map.get(&code) {
                println!("    {} (0x{:04X})", name, code);
            } else {
                println!("    Unknown Cipher Suite (0x{:04X})", code);
            }
        }
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
            // println!("      Length: 0x{:04X} ({} bytes)", 
            //          u16::from_be_bytes(extension.extension_length),
            //          u16::from_be_bytes(extension.extension_length));
            let length = u16::from_be_bytes(extension.extension_length) as usize;
            println!(
                "      Length: 0x{:04X} ({} bytes)",
                length,
                length
            );
    
            // 如果长度为 0，则跳过内容输出
            if length == 0 {
                println!();
                continue;
            }
            match extension_name {
                "psk_key_exchange_modes" => self.print_psk_key_exchange_modes(&extension.extension_content),
                "supported_groups" => self.print_supported_groups(&extension.extension_content),
                "supported_versions" => self.print_supported_versions(&extension.extension_content),
                "signature_algorithms" => self.print_signature_algorithms(&extension.extension_content),
                "key_share" => self.print_key_share(&extension.extension_content),
                "server_name" => self.print_server_name(&extension.extension_content),
                _ => {
                    print!("      Content: ");
                    for byte in &extension.extension_content {
                        print!("{:02X} ", byte);
                    }
                    println!();
                }
            }
            println!();
        }
    }

    fn print_psk_key_exchange_modes(&self, content: &[u8]) {
        if content.is_empty() {
            println!("Empty psk_key_exchange_modes content.");
            return;
        }
        let length = content[0] as usize;
        println!("      psk_key_exchange_modes content (Length: {}):", length);

        for mode in &content[1..(1 + length)] {
            match mode {
                0x00 => println!("        PSK with (EC)DHE key establishment"),
                0x01 => println!("        PSK without (EC)DHE key establishment"),
                _ => println!("        Unknown mode: 0x{:02X}", mode),
            }
        }
    }

    fn print_supported_groups(&self, content: &[u8]) {
        if content.len() < 2 {
            println!("Empty or invalid supported_groups content.");
            return;
        }
        let length = u16::from_be_bytes([content[0], content[1]]) as usize;
        println!("      supported_groups content (Length: {}):", length);
    
        for chunk in content[2..(2 + length)].chunks(2) {
            if chunk.len() == 2 {
                let group = u16::from_be_bytes([chunk[0], chunk[1]]);
                match group {
                    // 椭圆曲线群组 (ECDHE)
                    0x0017 => println!("        secp256r1 (0x0017)"),
                    0x0018 => println!("        secp384r1 (0x0018)"),
                    0x0019 => println!("        secp521r1 (0x0019)"),
                    0x001D => println!("        x25519 (0x001D)"),
                    0x001E => println!("        x448 (0x001E)"),
                    
                    // 有限域群组 (DHE)
                    0x0100 => println!("        ffdhe2048 (0x0100)"),
                    0x0101 => println!("        ffdhe3072 (0x0101)"),
                    0x0102 => println!("        ffdhe4096 (0x0102)"),
                    0x0103 => println!("        ffdhe6144 (0x0103)"),
                    0x0104 => println!("        ffdhe8192 (0x0104)"),
                    
                    // 保留代码点
                    0x01FC..=0x01FF => println!("        ffdhe_private_use (0x{:04X})", group),
                    0xFE00..=0xFEFF => println!("        ecdhe_private_use (0x{:04X})", group),
    
                    // 未知组
                    _ => println!("        Unknown group: 0x{:04X}", group),
                }
            }
        }
    }
    
    

    fn print_supported_versions(&self, content: &[u8]) {
        if content.is_empty() {
            println!("Empty supported_versions content.");
            return;
        }
        let length = content[0] as usize;
        println!("      supported_versions content (Length: {}):", length);

        for chunk in content[1..(1 + length)].chunks(2) {
            if chunk.len() == 2 {
                let version = u16::from_be_bytes([chunk[0], chunk[1]]);
                match version {
                    0x0304 => println!("        TLS 1.3 (0x0304)"),
                    0x0303 => println!("        TLS 1.2 (0x0303)"),
                    0x0302 => println!("        TLS 1.1 (0x0302)"),
                    0x0301 => println!("        TLS 1.0 (0x0301)"),
                    _ => println!("        Unknown version: 0x{:04X}", version),
                }
            }
        }
    }

    fn print_signature_algorithms(&self, content: &[u8]) {
        if content.len() < 2 {
            println!("Empty or invalid signature_algorithms content.");
            return;
        }
        let length = u16::from_be_bytes([content[0], content[1]]) as usize;
        println!("      signature_algorithms content (Length: {}):", length);
    
        for chunk in content[2..(2 + length)].chunks(2) {
            if chunk.len() == 2 {
                let scheme = u16::from_be_bytes([chunk[0], chunk[1]]);
                match scheme {
                    // RSASSA-PKCS1-v1_5 algorithms
                    0x0401 => println!("        rsa_pkcs1_sha256 (0x0401)"),
                    0x0501 => println!("        rsa_pkcs1_sha384 (0x0501)"),
                    0x0601 => println!("        rsa_pkcs1_sha512 (0x0601)"),
    
                    // ECDSA algorithms
                    0x0403 => println!("        ecdsa_secp256r1_sha256 (0x0403)"),
                    0x0503 => println!("        ecdsa_secp384r1_sha384 (0x0503)"),
                    0x0603 => println!("        ecdsa_secp521r1_sha512 (0x0603)"),
    
                    // RSASSA-PSS algorithms with public key OID rsaEncryption
                    0x0804 => println!("        rsa_pss_rsae_sha256 (0x0804)"),
                    0x0805 => println!("        rsa_pss_rsae_sha384 (0x0805)"),
                    0x0806 => println!("        rsa_pss_rsae_sha512 (0x0806)"),
    
                    // EdDSA algorithms
                    0x0807 => println!("        ed25519 (0x0807)"),
                    0x0808 => println!("        ed448 (0x0808)"),
    
                    // RSASSA-PSS algorithms with public key OID RSASSA-PSS
                    0x0809 => println!("        rsa_pss_pss_sha256 (0x0809)"),
                    0x080A => println!("        rsa_pss_pss_sha384 (0x080A)"),
                    0x080B => println!("        rsa_pss_pss_sha512 (0x080B)"),
    
                    // Legacy algorithms
                    0x0201 => println!("        rsa_pkcs1_sha1 (0x0201)"),
                    0x0203 => println!("        ecdsa_sha1 (0x0203)"),
    
                    // Reserved Code Points
                    0xFE00..=0xFFFF => println!("        private_use (0x{:04X})", scheme),
    
                    // Unknown scheme
                    _ => println!("        Unknown scheme: 0x{:04X}", scheme),
                }
            }
        }
    }
    

    fn print_key_share(&self, content: &[u8]) {
        if content.len() < 2 {
            println!("Empty or invalid key_share content.");
            return;
        }
    
        // 获取 client_shares 的总长度
        let client_shares_length = u16::from_be_bytes([content[0], content[1]]) as usize;
        println!("      Key Share extension (Client Key Share Length: {}):", client_shares_length);
    
        // 开始解析每一个 KeyShareEntry
        let mut offset = 2;
        while offset < content.len() {
            if offset + 2 > content.len() {
                println!("      Invalid key_share entry: insufficient data for group field.");
                break;
            }
    
            // 获取 NamedGroup
            let group = u16::from_be_bytes([content[offset], content[offset + 1]]);
            offset += 2;
    
            // 打印 NamedGroup 名称
            let group_name = match group {
                0x001D => "x25519",
                0x001E => "x448",
                0x0017 => "secp256r1",
                0x0018 => "secp384r1",
                0x0019 => "secp521r1",
                _ => "Unknown",
            };
            println!("        Key Share Entry: Group: {}, Key Exchange Length:", group_name);
    
            if offset + 2 > content.len() {
                println!("      Invalid key_share entry: insufficient data for key_exchange length field.");
                break;
            }
    
            // 获取 key_exchange 的长度
            let key_exchange_length = u16::from_be_bytes([content[offset], content[offset + 1]]) as usize;
            offset += 2;
    
            println!("          Group: {} (0x{:04X}), Key Exchange Length: {}", group_name, group, key_exchange_length);
    
            // 确保 key_exchange 的数据足够
            if offset + key_exchange_length > content.len() {
                println!("      Invalid key_share entry: insufficient data for key_exchange field.");
                break;
            }
    
            // 打印 key_exchange 内容
            print!("          Key Exchange: ");
            for byte in &content[offset..offset + key_exchange_length] {
                print!("{:02X} ", byte);
            }
            println!();
    
            offset += key_exchange_length;
        }
    }
    
    fn print_server_name(&self, content: &[u8]) {
        if content.len() < 2 {
            println!("      Empty or invalid server_name content.");
            return;
        }
    
        // 获取 Server Name list 的总长度
        let list_length = u16::from_be_bytes([content[0], content[1]]) as usize;
        println!("      Server Name Indication extension (Server Name list length: {}):", list_length);
    
        let mut offset = 2;
        while offset < content.len() {
            if offset + 3 > content.len() {
                println!("      Invalid server_name entry: insufficient data for server name type and length.");
                break;
            }
    
            // 获取 Server Name Type (1 字节)
            let name_type = content[offset];
            offset += 1;
    
            let name_type_str = match name_type {
                0 => "host_name",
                _ => "Unknown",
            };
            println!("        Server Name Type: {} ({})", name_type_str, name_type);
    
            // 获取 Server Name 的长度 (2 字节)
            let name_length = u16::from_be_bytes([content[offset], content[offset + 1]]) as usize;
            offset += 2;
    
            println!("        Server Name length: {}", name_length);
    
            // 确保 Server Name 数据足够
            if offset + name_length > content.len() {
                println!("      Invalid server_name entry: insufficient data for server name field.");
                break;
            }
    
            // 打印 Server Name
            let server_name = String::from_utf8_lossy(&content[offset..offset + name_length]);
            println!("        Server Name: {}", server_name);
    
            offset += name_length;
        }
    }
    
}
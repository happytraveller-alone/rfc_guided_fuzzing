use super::TLS_EXTENSIONS;
use std::collections::HashMap;
use log::{debug, error, info, trace};
use serde::Serialize;
use serde::ser::Serializer;

#[derive(Debug, Clone, Serialize)]
pub struct ClientHello {
    // TLS Record Layer
    #[serde(serialize_with = "serialize_u8")]
    pub content_type: u8,           // 固定值 0x16
    #[serde(serialize_with = "serialize_byte_array")]
    pub version: [u8; 2],           // 固定值 [0x03, 0x01]
    #[serde(serialize_with = "serialize_u16")]
    pub record_length: u16,         // 动态值，需要计算

    // Handshake Layer
    #[serde(serialize_with = "serialize_u8")]
    pub handshake_type: u8,         // 固定值 0x01
    #[serde(serialize_with = "serialize_byte_array")]
    pub handshake_length: [u8; 3],  // 动态值，需要计算

    // ClientHello specific fields
    #[serde(serialize_with = "serialize_byte_array")]
    pub client_version: [u8; 2],    // 固定值 [0x03, 0x03]
    #[serde(serialize_with = "serialize_byte_array")]
    pub random: [u8; 32],           // 32 字节随机数
    #[serde(serialize_with = "serialize_u8")]
    pub session_id_length: u8,      // 动态值
    #[serde(serialize_with = "serialize_bytes")]
    pub session_id: Vec<u8>,        // 动态值
    #[serde(serialize_with = "serialize_u16")]
    pub cipher_suites_length: u16,  // 动态值
    #[serde(serialize_with = "serialize_bytes")]
    pub cipher_suites: Vec<u8>,     // 动态值
    #[serde(serialize_with = "serialize_u8")]
    pub compression_methods_length: u8,  // 动态值
    #[serde(serialize_with = "serialize_bytes")]
    pub compression_methods: Vec<u8>,    // 动态值
    #[serde(serialize_with = "serialize_u16")]
    pub extensions_length: u16,     // 动态值
    #[serde(skip_serializing)]
    pub extensions_num: u16,        // 动态值
    pub extensions: Vec<Extension>, // 动态值
}

#[derive(Debug, Clone,Serialize)]
pub struct Extension {
    #[serde(skip_serializing)]
    pub order_id: u8,
    #[serde(serialize_with = "serialize_byte_array")]
    pub extension_type: [u8; 2],
    #[serde(serialize_with = "serialize_byte_array")]
    pub extension_length: [u8; 2],
    #[serde(serialize_with = "serialize_bytes")]
    pub extension_content: Vec<u8>,
}

// 自定义序列化函数
fn serialize_u8<S>(x: &u8, s: S) -> Result<S::Ok, S::Error>
where
    S: Serializer,
{
    s.serialize_str(&format!("0x{:02x}", x))
}

fn serialize_u16<S>(x: &u16, s: S) -> Result<S::Ok, S::Error>
where
    S: Serializer,
{
    let high = (x >> 8) as u8;
    let low = (x & 0xFF) as u8;
    s.serialize_str(&format!("0x{:02x} 0x{:02x}", high, low))
}

fn serialize_byte_array<S, const N: usize>(bytes: &[u8; N], s: S) -> Result<S::Ok, S::Error>
where
    S: Serializer,
{
    let hex = bytes.iter()
        .map(|b| format!("0x{:02x}", b))
        .collect::<Vec<_>>()
        .join(", ");
    s.serialize_str(&format!("[{}]", hex))
}

fn serialize_bytes<S>(bytes: &Vec<u8>, s: S) -> Result<S::Ok, S::Error>
where
    S: Serializer,
{
    let hex = bytes.iter()
        .map(|b| format!("0x{:02x}", b))
        .collect::<Vec<_>>()
        .join(", ");
    s.serialize_str(&format!("[{}]", hex))
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

    pub fn print(&self, addition: String) {
        // self.set_active_appender(if_parse);
        trace!(target: addition.as_str(), "ClientHello Contents:");

        self.print_tls_record_layer(addition.clone());
        self.print_handshake_layer(addition.clone());
        self.print_client_hello_body(addition.clone());
        self.print_session_id(addition.clone());
        self.print_cipher_suites(addition.clone());
        self.print_compression_methods(addition.clone());
        self.print_extensions(addition.clone());
    }

    fn print_tls_record_layer(&self, addition: String) {
        info!(target: addition.as_str(),"NEW CH Parsed");
        trace!(target: addition.as_str(),"TLS Record Layer:");
        trace!(target: addition.as_str(),"  Content Type: 0x{:02X}", self.content_type);
        trace!(target: addition.as_str(),"  Version: 0x{:02X}{:02X}", self.version[0], self.version[1]);
        trace!(target: addition.as_str(),"  Length: 0x{:04X} ({} bytes)", 
                 self.record_length,
                 self.record_length);
    }

    fn print_handshake_layer(&self, addition: String) {
        trace!(target: addition.as_str(),"Handshake Layer:");
        trace!(target: addition.as_str(),"  Handshake Type: 0x{:02X}", self.handshake_type);
        trace!(target: addition.as_str(),"  Length: 0x{:02X}{:02X}{:02X} ({} bytes)", 
                 self.handshake_length[0], 
                 self.handshake_length[1], 
                 self.handshake_length[2],
                 u32::from_be_bytes([0, self.handshake_length[0], self.handshake_length[1], self.handshake_length[2]]));
    }

    fn print_client_hello_body(&self, addition: String) {
        trace!(target: addition.as_str(),"ClientHello:");
        trace!(target: addition.as_str(),"  Client Version: 0x{:02X}{:02X}", self.client_version[0], self.client_version[1]);
        let mut random_store = String::new();
        random_store.push_str("  Random: ");
        // trace!();
        for byte in &self.random {
            random_store.push_str(format!("{:02X} ", byte).as_str());
        }
        trace!(target: addition.as_str(),"{}",random_store);
    }

    fn print_session_id(&self, addition: String) {
        trace!(target: addition.as_str(),"  Session ID Length: 0x{:02X} ({} bytes)", self.session_id_length, self.session_id_length);
        if !self.session_id.is_empty() {
            let mut session_id_store = String::new();
            session_id_store.push_str("  Session ID: ");
            // trace!();
            for byte in &self.session_id {
                session_id_store.push_str(format!("{:02X} ", byte).as_str());
                // trace!("{:02X} ", byte);
            }
            trace!(target: addition.as_str(),"{}",session_id_store);
        }
    }

    fn print_cipher_suites(&self, addition: String) {
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
        trace!(target: addition.as_str(),
            "  Cipher Suites Length: 0x{:04X} ({} bytes)",
            self.cipher_suites_length,
            self.cipher_suites_length
        );

        // 解析 cipher_suites 字段并输出每个 Cipher Suite 的名称
        trace!(target: addition.as_str(),"  Cipher Suites:");
        for i in (0..self.cipher_suites.len()).step_by(2) {
            let code = (self.cipher_suites[i] as u16) << 8 | self.cipher_suites[i + 1] as u16;
            if let Some(name) = cipher_suite_map.get(&code) {
                trace!(target: addition.as_str(),"    {} (0x{:04X})", name, code);
            } else {
                trace!(target: addition.as_str(),"    Unknown Cipher Suite (0x{:04X})", code);
            }
        }
    }

    fn print_compression_methods(&self, addition: String) {
        trace!(target: addition.as_str(),"  Compression Methods Length: 0x{:02X} ({} bytes)", 
                 self.compression_methods_length, self.compression_methods_length);
        let mut compression_method_store = String::new();
        compression_method_store.push_str("  Compression Methods: ");
        for byte in &self.compression_methods {
            // trace!("{:02X} ", byte);
            compression_method_store.push_str(format!("{:02X} ", byte).as_str());
        }
        trace!(target: addition.as_str(),"{}",compression_method_store);
    }

    fn print_extensions(&self, addition: String) {
        trace!(target: addition.as_str(),"  Extensions Length: 0x{:04X} ({} bytes), Extensions Number: {}", 
                 self.extensions_length,
                 self.extensions_length,
                 self.extensions_num);
        
        for extension in self.extensions.iter() {
            let extension_type = u16::from_be_bytes(extension.extension_type);
            let extension_name = TLS_EXTENSIONS.get(&extension_type).map_or("Unknown", |&name| name);
            
            trace!(target: addition.as_str(),"    Extension {}:", extension.order_id);
            trace!(target: addition.as_str(),"      Type: 0x{:04X} ({})", extension_type, extension_name);
            // println!("      Length: 0x{:04X} ({} bytes)", 
            //          u16::from_be_bytes(extension.extension_length),
            //          u16::from_be_bytes(extension.extension_length));
            let length = u16::from_be_bytes(extension.extension_length) as usize;
            trace!(target: addition.as_str(),
                "      Length: 0x{:04X} ({} bytes)",
                length,
                length
            );
    
            // 如果长度为 0，则跳过内容输出
            if length == 0 {
                // trace!("\n");
                continue;
            }
            match extension_name {
                "psk_key_exchange_modes" => self.print_psk_key_exchange_modes(&extension.extension_content,addition.clone()),
                "supported_groups" => self.print_supported_groups(&extension.extension_content,addition.clone()),
                "supported_versions" => self.print_supported_versions(&extension.extension_content,addition.clone()),
                "signature_algorithms" => self.print_signature_algorithms(&extension.extension_content,addition.clone()),
                "key_share" => self.print_key_share(&extension.extension_content,addition.clone()),
                "server_name" => self.print_server_name(&extension.extension_content,addition.clone()),
                "pre_shared_key" => self.print_pre_shared_key(&extension.extension_content,addition.clone()),
                _ => {
                    let mut content_store =  String::new();
                    content_store.push_str("      Content: ");
                    for byte in &extension.extension_content {
                        // trace!("{:02X} ", byte);
                        content_store.push_str(format!("{:02X} ", byte).as_str());
                    }
                    trace!(target: addition.as_str(),"{}",content_store);
                }
            }
            // trace!("\n");
        }
    }

    fn print_psk_key_exchange_modes(&self, content: &[u8], addition: String) {
        if content.is_empty() {
            debug!(target: addition.as_str(),"Empty psk_key_exchange_modes content.");
            return;
        }
        let length = content[0] as usize;
        trace!(target: addition.as_str(),"      psk_key_exchange_modes content (Length: {}):", length);

        for mode in &content[1..(1 + length)] {
            match mode {
                0x00 => trace!(target: addition.as_str(),"        PSK with (EC)DHE key establishment"),
                0x01 => trace!(target: addition.as_str(),"        PSK without (EC)DHE key establishment"),
                _ => trace!(target: addition.as_str(),"        Unknown mode: 0x{:02X}", mode),
            }
        }
    }

    fn print_supported_groups(&self, content: &[u8], addition: String) {
        if content.len() < 2 {
            debug!(target: addition.as_str(),"Empty or invalid supported_groups content.");
            return;
        }
        let length = u16::from_be_bytes([content[0], content[1]]) as usize;
        trace!(target: addition.as_str(),"      supported_groups content (Length: {}):", length);
    
        for chunk in content[2..(2 + length)].chunks(2) {
            if chunk.len() == 2 {
                let group = u16::from_be_bytes([chunk[0], chunk[1]]);
                match group {
                    // 椭圆曲线群组 (ECDHE)
                    0x0017 => trace!(target: addition.as_str(),"        secp256r1 (0x0017)"),
                    0x0018 => trace!(target: addition.as_str(),"        secp384r1 (0x0018)"),
                    0x0019 => trace!(target: addition.as_str(),"        secp521r1 (0x0019)"),
                    0x001D => trace!(target: addition.as_str(),"        x25519 (0x001D)"),
                    0x001E => trace!(target: addition.as_str(),"        x448 (0x001E)"),
                    
                    // 有限域群组 (DHE)
                    0x0100 => trace!(target: addition.as_str(),"        ffdhe2048 (0x0100)"),
                    0x0101 => trace!(target: addition.as_str(),"        ffdhe3072 (0x0101)"),
                    0x0102 => trace!(target: addition.as_str(),"        ffdhe4096 (0x0102)"),
                    0x0103 => trace!(target: addition.as_str(),"        ffdhe6144 (0x0103)"),
                    0x0104 => trace!(target: addition.as_str(),"        ffdhe8192 (0x0104)"),
                    
                    // 保留代码点
                    0x01FC..=0x01FF => trace!(target: addition.as_str(),"        ffdhe_private_use (0x{:04X})", group),
                    0xFE00..=0xFEFF => trace!(target: addition.as_str(),"        ecdhe_private_use (0x{:04X})", group),
    
                    // 未知组
                    _ => debug!(target: addition.as_str(),"        Unknown group: 0x{:04X}", group),
                }
            }
        }
    }
    
    fn print_supported_versions(&self, content: &[u8], addition: String) {
        if content.is_empty() {
            debug!(target: addition.as_str(),"Empty supported_versions content.");
            return;
        }
        let length = content[0] as usize;
        trace!(target: addition.as_str(),"      supported_versions content (Length: {}):", length);

        for chunk in content[1..(1 + length)].chunks(2) {
            if chunk.len() == 2 {
                let version = u16::from_be_bytes([chunk[0], chunk[1]]);
                match version {
                    0x0304 => trace!(target: addition.as_str(),"        TLS 1.3 (0x0304)"),
                    0x0303 => trace!(target: addition.as_str(),"        TLS 1.2 (0x0303)"),
                    0x0302 => trace!(target: addition.as_str(),"        TLS 1.1 (0x0302)"),
                    0x0301 => trace!(target: addition.as_str(),"        TLS 1.0 (0x0301)"),
                    _ => debug!(target: addition.as_str(),"        Unknown version: 0x{:04X}", version),
                }
            }
        }
    }

    fn print_signature_algorithms(&self, content: &[u8], addition: String) {
        if content.len() < 2 {
            debug!(target: addition.as_str(),"Empty or invalid signature_algorithms content.");
            return;
        }
        let length = u16::from_be_bytes([content[0], content[1]]) as usize;
        trace!(target: addition.as_str(),"      signature_algorithms content (Length: {}):", length);
    
        for chunk in content[2..(2 + length)].chunks(2) {
            if chunk.len() == 2 {
                let scheme = u16::from_be_bytes([chunk[0], chunk[1]]);
                match scheme {
                    // RSASSA-PKCS1-v1_5 algorithms
                    0x0401 => trace!(target: addition.as_str(),"        rsa_pkcs1_sha256 (0x0401)"),
                    0x0501 => trace!(target: addition.as_str(),"        rsa_pkcs1_sha384 (0x0501)"),
                    0x0601 => trace!(target: addition.as_str(),"        rsa_pkcs1_sha512 (0x0601)"),
    
                    // ECDSA algorithms
                    0x0403 => trace!(target: addition.as_str(),"        ecdsa_secp256r1_sha256 (0x0403)"),
                    0x0503 => trace!(target: addition.as_str(),"        ecdsa_secp384r1_sha384 (0x0503)"),
                    0x0603 => trace!(target: addition.as_str(),"        ecdsa_secp521r1_sha512 (0x0603)"),
    
                    // RSASSA-PSS algorithms with public key OID rsaEncryption
                    0x0804 => trace!(target: addition.as_str(),"        rsa_pss_rsae_sha256 (0x0804)"),
                    0x0805 => trace!(target: addition.as_str(),"        rsa_pss_rsae_sha384 (0x0805)"),
                    0x0806 => trace!(target: addition.as_str(),"        rsa_pss_rsae_sha512 (0x0806)"),
    
                    // EdDSA algorithms
                    0x0807 => trace!(target: addition.as_str(),"        ed25519 (0x0807)"),
                    0x0808 => trace!(target: addition.as_str(),"        ed448 (0x0808)"),
    
                    // RSASSA-PSS algorithms with public key OID RSASSA-PSS
                    0x0809 => trace!(target: addition.as_str(),"        rsa_pss_pss_sha256 (0x0809)"),
                    0x080A => trace!(target: addition.as_str(),"        rsa_pss_pss_sha384 (0x080A)"),
                    0x080B => trace!(target: addition.as_str(),"        rsa_pss_pss_sha512 (0x080B)"),
    
                    // Legacy algorithms
                    0x0201 => trace!(target: addition.as_str(),"        rsa_pkcs1_sha1 (0x0201)"),
                    0x0203 => trace!(target: addition.as_str(),"        ecdsa_sha1 (0x0203)"),
    
                    // Reserved Code Points
                    0xFE00..=0xFFFF => trace!(target: addition.as_str(),"        private_use (0x{:04X})", scheme),
    
                    // Unknown scheme
                    _ => debug!(target: addition.as_str(),"        Unknown scheme: 0x{:04X}", scheme),
                }
            }
        }
    }
    
    fn print_key_share(&self, content: &[u8], addition: String) {
        if content.len() < 2 {
            debug!(target: addition.as_str(),"Empty or invalid key_share content.");
            return;
        }
    
        // 获取 client_shares 的总长度
        let client_shares_length = u16::from_be_bytes([content[0], content[1]]) as usize;
        trace!(target: addition.as_str(),"      Key Share extension (Client Key Share Length: {}):", client_shares_length);
    
        // 开始解析每一个 KeyShareEntry
        let mut offset = 2;
        while offset < content.len() {
            if offset + 2 > content.len() {
                error!(target: addition.as_str(),"      Invalid key_share entry: insufficient data for group field.");
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
            
    
            if offset + 2 > content.len() {
                error!(target: addition.as_str(),"      Invalid key_share entry: insufficient data for key_exchange length field.");
                break;
            }
    
            // 获取 key_exchange 的长度
            let key_exchange_length = u16::from_be_bytes([content[offset], content[offset + 1]]) as usize;
            offset += 2;
            trace!(target: addition.as_str(),"        Key Share Entry: Group: {} (0x{:04X}), Key Exchange Length: {}", group_name, group, key_exchange_length);
    
            // 确保 key_exchange 的数据足够
            if offset + key_exchange_length > content.len() {
                debug!(target: addition.as_str(),"      Invalid key_share entry: insufficient data for key_exchange field.");
                break;
            }
            let mut key_exchange_str = String::new();
            // 打印 key_exchange 内容
            key_exchange_str.push_str("        Key Exchange: ");
            // trace!("        Key Exchange: ");
            for byte in &content[offset..offset + key_exchange_length] {
                // trace!("{:02X} ", byte);
                key_exchange_str.push_str(format!("{:02X} ", byte).as_str());
            }
            trace!(target: addition.as_str(),"{}",key_exchange_str);
    
            offset += key_exchange_length;
        }
    }
    
    fn print_server_name(&self, content: &[u8], addition: String) {
        if content.len() < 2 {
            error!(target: addition.as_str(),"      Empty or invalid server_name content.");
            return;
        }
    
        // 获取 Server Name list 的总长度
        let list_length = u16::from_be_bytes([content[0], content[1]]) as usize;
        trace!(target: addition.as_str(),"      Server Name Indication extension (Server Name list length: {}):", list_length);
    
        let mut offset = 2;
        while offset < content.len() {
            if offset + 3 > content.len() {
                error!(target: addition.as_str(),"      Invalid server_name entry: insufficient data for server name type and length.");
                break;
            }
    
            // 获取 Server Name Type (1 字节)
            let name_type = content[offset];
            offset += 1;
    
            let name_type_str = match name_type {
                0 => "host_name",
                _ => "Unknown",
            };
            trace!(target: addition.as_str(),"        Server Name Type: {} ({})", name_type_str, name_type);
    
            // 获取 Server Name 的长度 (2 字节)
            let name_length = u16::from_be_bytes([content[offset], content[offset + 1]]) as usize;
            offset += 2;
    
            trace!(target: addition.as_str(),"        Server Name length: {}", name_length);
    
            // 确保 Server Name 数据足够
            if offset + name_length > content.len() {
                error!(target: addition.as_str(),"      Invalid server_name entry: insufficient data for server name field.");
                break;
            }
    
            // 打印 Server Name
            let server_name = String::from_utf8_lossy(&content[offset..offset + name_length]);
            trace!(target: addition.as_str(),"        Server Name: {}", server_name);
    
            offset += name_length;
        }
    }
    
    fn print_pre_shared_key(&self, content: &[u8], addition: String) {
        if content.len() < 2 {
            error!(target: addition.as_str(),"      Empty or invalid pre_shared_key content.");
            return;
        }
    
        // 解析 Identities 的总长度
        let identities_length = u16::from_be_bytes([content[0], content[1]]) as usize;
        trace!(target: addition.as_str(),"      Pre-Shared Key extension:");
        trace!(target: addition.as_str(),"        Identities Length: {}", identities_length);
    
        let mut offset = 2;
        
        // 解析每个 PSK Identity
        while offset < 2 + identities_length && offset + 4 <= content.len() {
            // Identity 长度
            let identity_length = u16::from_be_bytes([content[offset], content[offset + 1]]) as usize;
            offset += 2;
    
            trace!(target: addition.as_str(),"        PSK Identity (length: {}):", identity_length);
    
            // Identity 内容
            if offset + identity_length > content.len() {
                error!(target: addition.as_str(),"          Invalid PSK Identity: insufficient data.");
                return;
            }
    
            let identity = &content[offset..offset + identity_length];
            let formatted_identity = identity
            .chunks(1)
            .map(|chunk| format!("{:02X}", chunk[0]))
            .collect::<Vec<_>>()
            .join(" ");
            trace!(target: addition.as_str(),"          Identity: {}", formatted_identity);
            // println!("          Identity: {}", hex::encode(identity));
            offset += identity_length;
    
            // Obfuscated Ticket Age
            if offset + 4 > content.len() {
                error!(target: addition.as_str(),"          Invalid PSK Identity: insufficient data for obfuscated_ticket_age.");
                return;
            }
            let obfuscated_ticket_age = u32::from_be_bytes([
                content[offset],
                content[offset + 1],
                content[offset + 2],
                content[offset + 3],
            ]);
            trace!(target: addition.as_str(),"          Obfuscated Ticket Age:{:02X} {}", obfuscated_ticket_age, obfuscated_ticket_age);
            offset += 4;
        }
    
        // 确保 Identities 部分解析完
        if offset != 2 + identities_length {
            debug!(target: addition.as_str(),"        Warning: Identities length mismatch.");
        }
    
        // 解析 PSK Binders 长度
        if offset + 2 > content.len() {
            debug!(target: addition.as_str(),"      Invalid pre_shared_key extension: insufficient data for binders length.");
            return;
        }
        let binders_length = u16::from_be_bytes([content[offset], content[offset + 1]]) as usize;
        trace!(target: addition.as_str(),"        PSK Binders length: {:02X} {}", binders_length, binders_length);
        offset += 2;
    
        // 解析每个 PSK Binder
        while offset < content.len() {
            // Binder 长度
            if offset + 1 > content.len() {
                debug!(target: addition.as_str(),"          Invalid PSK Binder: insufficient data.");
                return;
            }
            let binder_length = content[offset] as usize;
            offset += 1;
    
            trace!(target: addition.as_str(),"          PSK Binder (length: {:02X} {}):", binder_length, binder_length);
    
            // Binder 内容
            if offset + binder_length > content.len() {
                debug!(target: addition.as_str(),"          Invalid PSK Binder: insufficient data.");
                return;
            }
    
            let binder = &content[offset..offset + binder_length];
            let formatted_binder = binder
                .chunks(1)
                .map(|chunk| format!("{:02X}", chunk[0]))
                .collect::<Vec<_>>()
                .join(" ");
            trace!(target: addition.as_str(),"            Binder: {}", formatted_binder);
            offset += binder_length;
        }
    }

    pub fn to_bytes(&self) -> Vec<u8> {
        let mut bytes = Vec::new();

        // TLS Record Layer
        bytes.push(self.content_type);  // content_type
        bytes.extend_from_slice(&self.version);  // version
        bytes.extend_from_slice(&self.record_length.to_be_bytes());  // record_length

        // Handshake Layer
        bytes.push(self.handshake_type);  // handshake_type
        bytes.extend_from_slice(&self.handshake_length);  // handshake_length

        // ClientHello Body
        bytes.extend_from_slice(&self.client_version);  // client_version
        bytes.extend_from_slice(&self.random);  // random

        bytes.push(self.session_id_length);  // session_id_length
        bytes.extend_from_slice(&self.session_id);  // session_id

        bytes.extend_from_slice(&self.cipher_suites_length.to_be_bytes());  // cipher_suites_length
        bytes.extend_from_slice(&self.cipher_suites);  // cipher_suites

        bytes.push(self.compression_methods_length);  // compression_methods_length
        bytes.extend_from_slice(&self.compression_methods);  // compression_methods

        bytes.extend_from_slice(&self.extensions_length.to_be_bytes());  // extensions_length
        // bytes.extend_from_slice(&self.extensions_num.to_be_bytes());  // extensions_num

        // Extensions
        for extension in &self.extensions {
            bytes.extend_from_slice(&extension.extension_type);  // extension_type
            let extension_len = u16::from_be_bytes(extension.extension_length);
            bytes.extend_from_slice(&extension.extension_length);  // extension_length (2 bytes)
            
            if extension_len > 0 {
                bytes.extend_from_slice(&extension.extension_content);  // extension_content (dynamic length)
            }
        }
        bytes
    }

    // 打印字节数组，按十六进制输出，每个字节之间有空格
    pub fn print_bytes(&self, addition: String) {
        let bytes = self.to_bytes();
        let hex_string = bytes.iter()
            .map(|byte| format!("{:02X}", byte))
            .collect::<Vec<String>>()
            .join(" ");
        trace!(target: addition.as_str(),"{}", hex_string);
        // println!("{}", hex_string);
    }

    pub fn print_json(&self, addition: String) {
        let json_string = serde_json::to_string_pretty(&self).unwrap();
        trace!(target: addition.as_str(),"{}",json_string);
        // println!("{}",json_string);
    }
}

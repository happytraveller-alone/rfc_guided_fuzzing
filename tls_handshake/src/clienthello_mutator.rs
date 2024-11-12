use crate::clienthello::ClientHello;
use rand::Rng;
use std::collections::HashMap;
use colored::*;
use crate::TLS_EXTENSIONS_REVERSE;

#[derive(Debug)]
pub enum Action {
    SET,
    REMOVE,
    DUPLICATE,
    INSERT,
    SWAP,
}

#[derive(Debug)]
pub enum Message {
    ClientHello,
    Certificate,
    CertificateRequest,
    CertificateVerify,
    ServerHello,
}

#[derive(Debug)]
pub struct TestMutation {
    message: Message,
    field: String,
    action: Action,
    relative_position: String,
    value: String,
}

pub fn parse_action(action: &str) -> Result<Action, &'static str> {
    match action {
        "SET" => Ok(Action::SET),
        "REMOVE" => Ok(Action::REMOVE),
        "DUPLICATE" => Ok(Action::DUPLICATE),
        "INSERT" => Ok(Action::INSERT),
        "SWAP" => Ok(Action::SWAP),
        _ => Err("Unknown action"),
    }
}

pub fn parse_message(message: &str) -> Result<Message, &'static str> {
    match message {
        "ClientHello" => Ok(Message::ClientHello),
        "Certificate" => Ok(Message::Certificate),
        "CertificateRequest" => Ok(Message::CertificateRequest),
        "CertificateVerify" => Ok(Message::CertificateVerify),
        "ServerHello" => Ok(Message::ServerHello),
        _ => Err("Unknown message type"),
    }
}

// New function to create a TestMutation instance
pub fn create_test_mutation(
    message: Message,
    field: String,
    action: Action,
    relative_position: String,
    value: String,
) -> TestMutation {
    TestMutation {
        message,
        field,
        action,
        relative_position,
        value,
    }
}
pub struct ClientHelloMutator {
    client_hello: ClientHello,
}

impl ClientHelloMutator {
    pub fn new(client_hello: ClientHello) -> Self {
        Self { client_hello }
    }

    pub fn mutate(&mut self, mutation_config: &HashMap<u8, Vec<u8>>) {
        for (&key, value) in mutation_config.iter() {
            match key {
                1 => self.mutate_random(value),
                2 => self.mutate_session_id(value),
                3 => self.mutate_cipher_suites(value),
                // 4 => self.mutate_compression_methods(value),
                // 5 => self.mutate_extensions(value),
                _ => println!("Unknown mutation key: {}", key),
            }
        }
    }

    // pub fn mutate_new(&mut self, mutation_config: )

    fn update_lengths(&mut self) {
        // 更新 Session ID 长度
        self.client_hello.session_id_length = self.client_hello.session_id.len() as u8;

        // 更新 Cipher Suites 长度
        self.client_hello.cipher_suites_length = self.client_hello.cipher_suites.len() as u16;

        // 更新 Compression Methods 长度
        self.client_hello.compression_methods_length = self.client_hello.compression_methods.len() as u8;

        // 更新 Extensions 长度
        let mut total_extensions_length = 0;
        for extension in &mut self.client_hello.extensions {
            let content_length = extension.extension_content.len();
            extension.extension_length = (content_length as u16).to_be_bytes();
            total_extensions_length += 4 + content_length; // 4 bytes for type and length
        }
        self.client_hello.extensions_length = total_extensions_length as u16;

        // 计算 ClientHello 消息的总长度
        let client_hello_length = 2 + 32 + 1 + self.client_hello.session_id.len() +
                                  2 + self.client_hello.cipher_suites.len() +
                                  1 + self.client_hello.compression_methods.len() +
                                  2 + total_extensions_length;

        // 更新 Handshake 层的长度
        let handshake_length = client_hello_length as u32;
        self.client_hello.handshake_length = [
            (handshake_length >> 16) as u8,
            (handshake_length >> 8) as u8,
            handshake_length as u8,
        ];

        // 更新 TLS Record 层的长度
        self.client_hello.record_length = (client_hello_length + 4) as u16; // +4 for handshake type and length
    }

    fn mutate_random(&mut self, value: &[u8]) {
        let mut rng = rand::thread_rng();
        if value.len() == 32 {
            self.client_hello.random.copy_from_slice(value);
        } else {
            println!("{}","Invalid random value length. Generating a new random value.".yellow());
            rng.fill(&mut self.client_hello.random);
        }
    }

    fn mutate_session_id(&mut self, value: &[u8]) {
        let mut rng = rand::thread_rng();
        if value.len() <= 32 {
            self.client_hello.session_id = value.to_vec();
            self.client_hello.session_id_length = value.len() as u8;
        } else {
            println!("{}","Session ID too long. Generating a new session ID.".yellow());
            let new_length = rng.gen_range(0..=32);
            self.client_hello.session_id = (0..new_length).map(|_| rng.gen()).collect();
            self.client_hello.session_id_length = new_length as u8;
        }
    }

    fn mutate_cipher_suites(&mut self, value: &[u8]) {
        let valid_suites = [0x1301_u16, 0x1302, 0x1303, 0x1304, 0x1305, 0x00FF];
        let default_suites = [0x1302u16, 0x1301, 0x1303, 0x00FF];
        
        // 确保输入长度是偶数（每个cipher suite是2字节）
        if value.len() % 2 != 0 {
            println!("{}", "Invalid cipher suites length. Using default suites.".yellow());
            self.client_hello.cipher_suites_length = (default_suites.len() * 2) as u16;
            self.client_hello.cipher_suites = default_suites
                .iter()
                .flat_map(|&x| vec![(x >> 8) as u8, x as u8])
                .collect();
            return;
        }
    
        let mut valid = true;
        let mut cipher_suites = Vec::new();
    
        // 每次读取2个字节，转换为u16进行比较
        for chunk in value.chunks(2) {
            if chunk.len() == 2 {
                let suite = ((chunk[0] as u16) << 8) | (chunk[1] as u16);
                if !valid_suites.contains(&suite) {
                    valid = false;
                    break;
                }
                cipher_suites.extend_from_slice(chunk);
            }
        }
    
        if valid && !cipher_suites.is_empty() {
            self.client_hello.cipher_suites_length = cipher_suites.len() as u16;
            self.client_hello.cipher_suites = cipher_suites;
        } else {
            println!("{}", "Invalid cipher suites. Using default suites.".yellow());
            self.client_hello.cipher_suites_length = (default_suites.len() * 2) as u16;
            self.client_hello.cipher_suites = default_suites
                .iter()
                .flat_map(|&x| vec![(x >> 8) as u8, x as u8])
                .collect();
        }
    }

    // fn mutate_compression_methods(&mut self) {
    //     let mut rng = rand::thread_rng();
    //     if rng.gen_bool(0.5) {
    //         // 随机改变 compression_methods
    //         let new_length = rng.gen_range(1..=5);
    //         self.client_hello.compression_methods_length = new_length;
    //         self.client_hello.compression_methods = (0..new_length)
    //             .map(|_| rng.gen())
    //             .collect();
    //     }
    // }
    
    pub fn get_mutated_client_hello(&self) -> &ClientHello {
        &self.client_hello
    }

    fn handle_remove(&mut self, field: &str) {
        match field {
            "ClientHelloVersion" => self.client_hello.client_version = [0x00, 0x00],
            "SessionID" => {
                self.client_hello.session_id_length = 0;
                self.client_hello.session_id.clear();
            }
            "CipherSuites" => {
                self.client_hello.cipher_suites_length = 0;
                self.client_hello.cipher_suites.clear();
            }
            "CompressionMethods" => {
                self.client_hello.compression_methods_length = 0;
                self.client_hello.compression_methods.clear();
            }
            _ => {
                // Check if field matches an extension name
                if let Some(&extension_type) = TLS_EXTENSIONS_REVERSE.get(field) {
                    // Find the position of the extension to be removed
                    if let Some(pos) = self.client_hello.extensions.iter().position(|ext| ext.extension_type == extension_type.to_be_bytes()) {
                        // Remove the extension at the found position
                        self.client_hello.extensions.remove(pos);
                        // Update order_id for each extension after the removed one
                        for i in pos..self.client_hello.extensions.len() {
                            self.client_hello.extensions[i].order_id -= 1;
                        }
                        // Recalculate extensions_length based on remaining extensions
                        self.client_hello.extensions_length = self.client_hello.extensions.iter()
                            .map(|ext| ext.extension_content.len() as u16 + 4) // Adjusted for extension structure size
                            .sum();
                        println!(
                            "Removed extension '{}', updated ClientHello: {:?}",
                            field, self.client_hello
                        );
                    } else {
                        println!("Extension '{}' not found in ClientHello extensions", field);
                    }
                } else {
                    println!("Unrecognized field '{}', no action taken.", field);
                }
            }
        }
    }
}

pub fn mutate_client_hello(client_hello: &ClientHello, mutation_config: &HashMap<u8, Vec<u8>>) -> ClientHello {
    let mut mutator = ClientHelloMutator::new(client_hello.clone());
    mutator.mutate(mutation_config);
    mutator.update_lengths();
    mutator.get_mutated_client_hello().clone()
}
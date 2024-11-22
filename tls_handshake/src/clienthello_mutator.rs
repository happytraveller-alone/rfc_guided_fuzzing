use crate::clienthello::ClientHello;
use crate::TLS_EXTENSIONS_REVERSE;
use log::{debug, error, info};
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
#[derive(Debug, Clone)]
pub struct ClientHelloMutator {
    client_hello: ClientHello,
}

impl ClientHelloMutator {
    pub fn new(client_hello: ClientHello) -> Self {
        Self { client_hello }
    }

    // Function to mutate the ClientHello based on TestMutation
    pub fn preferred_mutate_entry(&mut self, mutation_config: &TestMutation) {
        // for mutation in mutation_config {
        match &mutation_config.message {
            // Check if the message is ClientHello
            Message::ClientHello => {
                // Perform the action based on the mutation's action type
                match mutation_config.action {
                    Action::SET => self.handle_set(&mutation_config.field, &mutation_config.relative_position, &mutation_config.value),
                    Action::REMOVE => self.handle_remove(&mutation_config.field, &mutation_config.relative_position, &mutation_config.value),
                    Action::DUPLICATE => self.handle_duplicate(&mutation_config.field, &mutation_config.relative_position, &mutation_config.value),
                    Action::INSERT => self.handle_insert(&mutation_config.field, &mutation_config.relative_position, &mutation_config.value),
                    Action::SWAP => self.handle_swap(&mutation_config.field, &mutation_config.relative_position, &mutation_config.value),
                }
            },
            // If the message is not ClientHello, print an unsupported message type
            _ => {
                debug!("Unsupported message type: {:?}", mutation_config.message);
            }
        }
        // }
    }

    // Handler for SET action
    fn handle_remove(&mut self, field: &str, relative_position: &str, value: &str) {
        // Here you should implement the logic for SET action, modifying the appropriate field in ClientHello
        info!("Handling REMOVE for field: {}, position: {}, value: {}", field, relative_position, value);
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
                        // println!("{}","Success founded!".green());
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
                        info!(
                            "Removed extension '{}', updated ClientHello",field);
                    } else {
                        debug!("Extension '{}' not found in ClientHello extensions", field);
                    }
                } else {
                    debug!("Unrecognized field '{}', no action taken.", field);
                }
            }
        }
    }

    fn parse_hex_values(&mut self, value: &str) -> Vec<u8> {
        // 去除字符串开头和结尾的引号（如果有）
        let value = value.trim_matches('"');
        
        value.split(',')
            .flat_map(|v| {
                let v = v.trim();  // 去除每个值的前后空格
                if v.starts_with("0x") {
                    // 去除 "0x" 后的字符串
                    let hex_str = &v[2..];
    
                    // 如果长度为4，处理为两个字节（如 "0x0301"）
                    if hex_str.len() == 4 {
                        // 将 "0301" 转换成 0x03, 0x01
                        hex_str.chars()
                            .collect::<Vec<char>>()
                            .chunks(2)
                            .filter_map(|chunk| {
                                if chunk.len() == 2 {
                                    u8::from_str_radix(&chunk.iter().collect::<String>(), 16).ok()
                                } else {
                                    None
                                }
                            })
                            .collect::<Vec<_>>()  // 这里返回 Vec<u8>
                    } 
                    // 如果长度为2，处理为单个字节（如 "0x03"）
                    else if hex_str.len() == 2 {
                        vec![u8::from_str_radix(hex_str, 16).ok().unwrap_or_default()]  // 直接解析并返回 Vec<u8>
                    } 
                    else {
                        Vec::new()  // 不符合预期格式，返回空 Vec
                    }
                } else {
                    // 直接解析单个十六进制值
                    vec![u8::from_str_radix(v, 16).ok().unwrap_or_default()]  // 返回 Vec<u8>
                }
            })
            .collect()
    }
    
    // 处理 SET 操作
    fn handle_set(&mut self, field: &str, relative_position: &str, value: &str) {
        info!("Handling SET for field: {}, position: {}, value: {}", field, relative_position, value);

        match field {
            "legacy_compression_methods" => {
                let compression_methods = self.parse_hex_values(value);
                self.client_hello.compression_methods_length = compression_methods.len() as u8;
                self.client_hello.compression_methods = compression_methods;
            }
            
            "CipherSuites" => {
                let cipher_suites = self.parse_hex_values(value);
                self.client_hello.cipher_suites_length = cipher_suites.len() as u16;
                self.client_hello.cipher_suites = cipher_suites;
            }

            "SessionID" => {
                let session_id = self.parse_hex_values(value);
                self.client_hello.session_id_length = session_id.len() as u8;
                self.client_hello.session_id = session_id;
            }

            "random" | "Random"=> {
                let random = self.parse_hex_values(value);
                if random.len() == 32 {
                    self.client_hello.random.copy_from_slice(&random);
                } else {
                    error!("Invalid random length, expected 32 bytes. NO ACTION USE");
                }
            }
            "supported_groups" | "signature_algorithms" => {
                let parsed_hex_values: Vec<u8> = self.parse_hex_values(value);
                let values_len_high: u8 = (parsed_hex_values.len() >> 8) as u8;
                let values_len_low: u8 = (parsed_hex_values.len() & 0xff) as u8;
                // Check if field matches an extension name
                if let Some(&extension_type) = TLS_EXTENSIONS_REVERSE.get(field) {
                    // Find the position of the extension to be removed
                    if let Some(pos) = self.client_hello.extensions.iter().position(|ext| ext.extension_type == extension_type.to_be_bytes()) {
                        // println!("{}","Success founded!".green());
                        // 清空指定位置的 extension_content
                        self.client_hello.extensions[pos].extension_content.clear();

                        // 填充 extension_content
                        self.client_hello.extensions[pos].extension_content.push(values_len_high);
                        self.client_hello.extensions[pos].extension_content.push(values_len_low);
                        self.client_hello.extensions[pos].extension_content.extend(parsed_hex_values);
                        info!("Reset extension '{}', updated ClientHello",field);
                    } else {
                        debug!("Extension '{}' not found in ClientHello extensions", field);
                    }
                }
            }
            "supported_versions" | "psk_key_exchange_modes" => {
                let parsed_hex_values: Vec<u8> = self.parse_hex_values(value);
                let values_len_low: u8 = (parsed_hex_values.len() & 0xff) as u8;
                // Check if field matches an extension name
                if let Some(&extension_type) = TLS_EXTENSIONS_REVERSE.get(field) {
                    // Find the position of the extension to be removed
                    if let Some(pos) = self.client_hello.extensions.iter().position(|ext| ext.extension_type == extension_type.to_be_bytes()) {
                        // println!("{}","Success founded!".green());
                        // 清空指定位置的 extension_content
                        self.client_hello.extensions[pos].extension_content.clear();

                        // 填充 extension_content
                        // self.client_hello.extensions[pos].extension_content.push(values_len_high);
                        self.client_hello.extensions[pos].extension_content.push(values_len_low);
                        self.client_hello.extensions[pos].extension_content.extend(parsed_hex_values);
                        info!("Reset extension '{}', updated ClientHello",field);
                    } else {
                        debug!("Extension '{}' not found in ClientHello extensions", field);
                    }
                }
            }
            _ => {
                debug!("Unrecognized field '{}', no action taken.", field);
            }
        }
    }

    // Handler for DUPLICATE action
    fn handle_duplicate(&mut self, field: &str, relative_position: &str, value: &str) {
        // Implement DUPLICATE logic here
        info!("Handling DUPLICATE for field: {}, position: {}, value: {}", field, relative_position, value);
    }

    // Handler for INSERT action
    fn handle_insert(&mut self, field: &str, relative_position: &str, value: &str) {
        // Implement INSERT logic here
        info!("Handling INSERT for field: {}, position: {}, value: {}", field, relative_position, value);
    }

    // Handler for SWAP action
    fn handle_swap(&mut self, field: &str, relative_position: &str, value: &str) {
        // Implement SWAP logic here
        info!("Handling SWAP for field: {}, position: {}, value: {}", field, relative_position, value);
    }

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
    
    pub fn get_mutated_client_hello(&self) -> &ClientHello {
        &self.client_hello
    }
}

// 优化，函数只处理一个
pub fn preferred_mutate_client_hello(client_hello: &ClientHello, mutation_config: &TestMutation, enable_check: bool) -> ClientHello{
    let mut clienthello_mutator= ClientHelloMutator::new(client_hello.clone());
    // Apply the mutation entries (this mutates the ClientHello inside the mutator)
    clienthello_mutator.preferred_mutate_entry(mutation_config);
    // After mutation, you can update any other lengths if needed
    clienthello_mutator.update_lengths();
    if enable_check{
        clienthello_mutator.get_mutated_client_hello().print( "clienthello_mutator_parser".to_string());
    }
    // Get the mutated ClientHello and clone it, then add to the result vector
    clienthello_mutator.get_mutated_client_hello().clone()
}
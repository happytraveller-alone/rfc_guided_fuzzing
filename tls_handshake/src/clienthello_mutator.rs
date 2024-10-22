use crate::client_hello::{ClientHello, Extension};
use rand::Rng;

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
                // 3 => self.mutate_cipher_suites(value),
                // 4 => self.mutate_compression_methods(value),
                // 5 => self.mutate_extensions(value),
                _ => println!("Unknown mutation key: {}", key),
            }
        }

        // 变异操作完成后，更新所有长度字段
        self.update_lengths();
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

    fn mutate_random(&mut self, value: &[u8]) {
        let mut rng = thread_rng();
        if value.len() == 32 {
            self.client_hello.random.copy_from_slice(value);
        } else {
            println!("Invalid random value length. Generating a new random value.");
            rng.fill(&mut self.client_hello.random);
        }
    }

    fn mutate_session_id(&mut self, value: &[u8]) {
        let mut rng = thread_rng();
        if value.len() <= 32 {
            self.client_hello.session_id = value.to_vec();
            self.client_hello.session_id_length = value.len() as u8;
        } else {
            println!("Session ID too long. Generating a new session ID.");
            let new_length = rng.gen_range(0..=32);
            self.client_hello.session_id = (0..new_length).map(|_| rng.gen()).collect();
            self.client_hello.session_id_length = new_length as u8;
        }
    }

    // fn mutate_cipher_suites(&mut self) {
    //     let mut rng = rand::thread_rng();
    //     if rng.gen_bool(0.5) {
    //         // 随机改变 cipher_suites
    //         let new_length = rng.gen_range(2..=100) * 2; // 确保是偶数
    //         self.client_hello.cipher_suites_length = new_length as u16;
    //         self.client_hello.cipher_suites = (0..new_length)
    //             .map(|_| rng.gen())
    //             .collect();
    //     }
    // }

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
}
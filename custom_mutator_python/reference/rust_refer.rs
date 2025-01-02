fn update_lengths(&mut self) {
    // 更新 Session ID 长度
    self.client_hello.session_id_length = self.client_hello.session_id.len() as u8;

    // 更新 Cipher Suites 长度
    self.client_hello.cipher_suites_length = self.client_hello.cipher_suites.len() as u16;

    // 更新 Compression Methods 长度
    self.client_hello.compression_methods_length =
        self.client_hello.compression_methods.len() as u8;

    // 更新 Extensions 长度
    let mut total_extensions_length = 0;
    for extension in &mut self.client_hello.extensions {
        let content_length = extension.extension_content.len();
        extension.extension_length = (content_length as u16).to_be_bytes();
        total_extensions_length += 4 + content_length; // 4 bytes for type and length
    }
    self.client_hello.extensions_length = total_extensions_length as u16;

    // 计算 ClientHello 消息的总长度
    let client_hello_length = 2
        + 32
        + 1
        + self.client_hello.session_id.len()
        + 2
        + self.client_hello.cipher_suites.len()
        + 1
        + self.client_hello.compression_methods.len()
        + 2
        + total_extensions_length;

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

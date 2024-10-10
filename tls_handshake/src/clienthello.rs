use super::TLS_EXTENSIONS;

pub struct ClientHelloParser<'a> {
    data: &'a [u8],
    offset: usize,
}

impl<'a> ClientHelloParser<'a> {
    pub fn new(data: &'a [u8]) -> Self {
        Self { data, offset: 0 }
    }

    pub fn parse(&mut self) {
        self.parse_tls_record_layer();
        self.parse_handshake_layer();
        self.parse_client_hello();
        self.parse_session_id();
        self.parse_cipher_suites();
        self.parse_compression_methods();
        self.parse_extensions();
    }

    fn parse_tls_record_layer(&mut self) {
        println!("TLS Record Layer:");
        println!("  Content Type: {:02X} (Handshake)", self.data[self.offset]);
        self.offset += 1;
        println!("  Version: {:02X} {:02X} (TLS 1.0 for backwards compatibility)", 
                 self.data[self.offset], self.data[self.offset + 1]);
        self.offset += 2;
        let record_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
        println!("  Length: {:04X} ({} bytes)", record_length, record_length);
        self.offset += 2;
    }

    fn parse_handshake_layer(&mut self) {
        println!("Handshake Layer:");
        println!("  Handshake Type: {:02X} (ClientHello)", self.data[self.offset]);
        self.offset += 1;
        let handshake_length = u32::from_be_bytes([0, self.data[self.offset], self.data[self.offset + 1], self.data[self.offset + 2]]);
        println!("  Length: {:06X} ({} bytes)", handshake_length, handshake_length);
        self.offset += 3;
    }

    fn parse_client_hello(&mut self) {
        println!("ClientHello:");
        println!("  Client Version: {:02X} {:02X}", self.data[self.offset], self.data[self.offset + 1]);
        self.offset += 2;
        print!("  Random:");
        for i in 0..32 {
            print!("{:02X} ", self.data[self.offset + i]);
        }
        println!();
        self.offset += 32;
    }

    fn parse_session_id(&mut self) {
        let session_id_length = self.data[self.offset] as usize;
        self.offset += 1;
        println!("  Session ID Length: {:02X} ({} bytes)", session_id_length, session_id_length);
        if session_id_length > 0 {
            print!("  Session ID: ");
            for i in 0..session_id_length {
                print!("{:02X} ", self.data[self.offset + i]);
            }
            println!();
            self.offset += session_id_length;
        }
    }

    fn parse_cipher_suites(&mut self) {
        let cipher_suites_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
        self.offset += 2;
        println!("  Cipher Suites Length: {:04X} ({} bytes)", cipher_suites_length, cipher_suites_length);
        print!("  Cipher Suites: ");
        for i in (0..cipher_suites_length).step_by(2) {
            print!("{:02X}{:02X} ", self.data[self.offset + i], self.data[self.offset + i + 1]);
        }
        println!();
        self.offset += cipher_suites_length;
    }

    fn parse_compression_methods(&mut self) {
        let compression_methods_length = self.data[self.offset] as usize;
        self.offset += 1;
        println!("  Compression Methods Length: {:02X} ({} bytes)", compression_methods_length, compression_methods_length);
        print!("  Compression Methods: ");
        for i in 0..compression_methods_length {
            print!("{:02X} ", self.data[self.offset + i]);
        }
        println!();
        self.offset += compression_methods_length;
    }

    fn parse_extensions(&mut self) {
        if self.offset < self.data.len() {
            let extensions_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
            self.offset += 2;
            println!("  Extensions Length: {:04X} ({} bytes)", extensions_length, extensions_length);
            while self.offset < self.data.len() {
                let extension_type = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]);
                self.offset += 2;
                let extension_length = u16::from_be_bytes([self.data[self.offset], self.data[self.offset + 1]]) as usize;
                self.offset += 2;
                let extension_name = TLS_EXTENSIONS.get(&extension_type).map_or("Unknown", |&name| name);
                println!("    Extension: {:<25} (Type: {:<04X}, Length: {:04X} ({:<3} bytes))", 
                         extension_name, extension_type, extension_length, extension_length);
                self.offset += extension_length;
            }
        }
    }

    
}

pub fn parse_client_hello(data: &[u8]) {
    let mut parser = ClientHelloParser::new(data);
    parser.parse();
}
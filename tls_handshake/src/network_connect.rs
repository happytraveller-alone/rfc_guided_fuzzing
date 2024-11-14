use std::sync::Arc;
use std::net::TcpStream;
use rustls::{ClientConfig, ClientConnection, RootCertStore, client::Resumption};

use std::io::{Write, Read};
use colored::*;
use rustls::crypto::{aws_lc_rs as provider, CryptoProvider};
use rustls::crypto::aws_lc_rs::DEFAULT_CIPHER_SUITES;
use std::net::SocketAddr;
use mio::{Events, Interest, Poll, Token, net::TcpStream as MioTcpStream};
use std::time::Duration;
use std::thread::sleep;

// use rustls::cipher_suite::*;
mod danger {
    use pki_types::{CertificateDer, ServerName, UnixTime};
    use rustls::client::danger::HandshakeSignatureValid;
    use rustls::crypto::{verify_tls12_signature, verify_tls13_signature, CryptoProvider};
    use rustls::DigitallySignedStruct;

    #[derive(Debug)]
    pub struct NoCertificateVerification(CryptoProvider);

    impl NoCertificateVerification {
        pub fn new(provider: CryptoProvider) -> Self {
            Self(provider)
        }
    }

    impl rustls::client::danger::ServerCertVerifier for NoCertificateVerification {
        fn verify_server_cert(
            &self,
            _end_entity: &CertificateDer<'_>,
            _intermediates: &[CertificateDer<'_>],
            _server_name: &ServerName<'_>,
            _ocsp: &[u8],
            _now: UnixTime,
        ) -> Result<rustls::client::danger::ServerCertVerified, rustls::Error> {
            Ok(rustls::client::danger::ServerCertVerified::assertion())
        }

        fn verify_tls12_signature(
            &self,
            message: &[u8],
            cert: &CertificateDer<'_>,
            dss: &DigitallySignedStruct,
        ) -> Result<HandshakeSignatureValid, rustls::Error> {
            verify_tls12_signature(
                message,
                cert,
                dss,
                &self.0.signature_verification_algorithms,
            )
        }

        fn verify_tls13_signature(
            &self,
            message: &[u8],
            cert: &CertificateDer<'_>,
            dss: &DigitallySignedStruct,
        ) -> Result<HandshakeSignatureValid, rustls::Error> {
            verify_tls13_signature(
                message,
                cert,
                dss,
                &self.0.signature_verification_algorithms,
            )
        }

        fn supported_verify_schemes(&self) -> Vec<rustls::SignatureScheme> {
            self.0
                .signature_verification_algorithms
                .supported_schemes()
        }
    }
}




pub fn create_tls_config() -> ClientConfig {
    let root_store = RootCertStore::empty();
    let versions = vec![&rustls::version::TLS13];
    // 指定 TLS 1.3 支持的密码套件
    let ciphersuites = DEFAULT_CIPHER_SUITES;

    let provider = CryptoProvider {
        cipher_suites: ciphersuites.to_vec(),
        ..provider::default_provider()
    };

    let mut config = ClientConfig::builder_with_provider(provider.into())
        .with_protocol_versions(&versions)
        .expect("Inconsistent cipher-suite/versions selected")
        .with_root_certificates(root_store)
        .with_no_client_auth();
    config.enable_early_data = true;
    config.enable_sni = true;
    config.dangerous().set_certificate_verifier(Arc::new(danger::NoCertificateVerification::new(
        provider::default_provider(),
    )));
    // 配置 PSK 回调
    config.resumption = Resumption::in_memory_sessions(256)
            .tls12_resumption(rustls::client::Tls12Resumption::SessionIdOnly);
    
    config
}

pub fn create_client_connection(config: Arc<ClientConfig>, server_name: String) -> Result<ClientConnection, Box<dyn std::error::Error>> {
    let server_name_new = server_name.try_into()?;
    Ok(ClientConnection::new(config, server_name_new)?)
}

pub fn establish_tcp_connection(address: &str) -> Result<TcpStream, std::io::Error> {
    TcpStream::connect(address)
}

pub fn send_data(stream: &mut TcpStream, data: &[u8]) -> Result<(), std::io::Error> {
    stream.write_all(data)
}

pub fn receive_data(stream: &mut TcpStream, buffer: &mut [u8]) -> Result<usize, std::io::Error> {
    stream.read(buffer)
}

pub fn check_test_environment(matches: &clap::ArgMatches) -> bool {
    let is_test_env = matches.get_flag("test_env");
    if is_test_env {
        println!("{}", "\nTest environment is enabled. Sending ClientHello to server.".green());
    } else {
        println!("{}", "\nTest environment is false. Not sending ClientHello to server.".yellow());
    }
    is_test_env
}

pub fn connect_to_server(server_ip: &str, port: u16, easy_read: bool) -> Result<MioTcpStream, Box<dyn std::error::Error>> {
    if easy_read {
        sleep(Duration::from_secs(1));
    }

    let access: SocketAddr = format!("{}:{}", server_ip, port).parse()?;
    println!("Connecting to server at {}...", access);
    Ok(MioTcpStream::connect(access)?)
}

pub fn create_poll() -> Result<Poll, Box<dyn std::error::Error>> {
    Ok(Poll::new()?)
}

pub fn register_stream(poll: &mut Poll, stream: &mut MioTcpStream) -> Result<Token, Box<dyn std::error::Error>> {
    let token = Token(0);
    println!("Registering stream with poll...");
    poll.registry().register(stream, token, Interest::WRITABLE | Interest::READABLE)?;
    Ok(token)
}

pub fn wait_for_writable(poll: &mut Poll, token: Token) -> Result<(), Box<dyn std::error::Error>> {
    let mut events = Events::with_capacity(1024);
    println!("Waiting for socket to be writable...");
    loop {
        poll.poll(&mut events, None)?;
        for event in &events {
            if event.token() == token && event.is_writable() {
                println!("Socket is writable. Connection established.");
                return Ok(());
            }
        }
    }
}

pub fn test_local_connection() -> Result<(), Box<dyn std::error::Error>> {
    let mut root_store = RootCertStore::empty();
    root_store.extend(webpki_roots::TLS_SERVER_ROOTS.iter().cloned());
    let mut config = rustls::ClientConfig::builder()
        .with_root_certificates(root_store)
        .with_no_client_auth();

    // Enable SSLKEYLOGFILE
    config.key_log = Arc::new(rustls::KeyLogFile::new());
    let server_name = "www.rust-lang.org".try_into()?;
    let mut conn = rustls::ClientConnection::new(Arc::new(config), server_name)?;
    let mut sock = TcpStream::connect("www.rust-lang.org:443")?;
    let mut tls = rustls::Stream::new(&mut conn, &mut sock);
    tls.write_all(
        concat!(
            "GET / HTTP/1.1\r\n",
            "Host: www.rust-lang.org\r\n",
            "Connection: close\r\n",
            "Accept-Encoding: identity\r\n",
            "\r\n"
        )
        .as_bytes(),
    )?;

    let ciphersuite = tls.conn.negotiated_cipher_suite().unwrap();
    println!("Local connection successful, negotiated ciphersuite: {:?}", ciphersuite.suite());

    let mut plaintext = Vec::new();
    tls.read_to_end(&mut plaintext)?;
    if plaintext.windows(b"200 OK".len()).any(|window| window == b"200 OK") {
        println!("{}","Local connection test passed: Received HTTP 200 response.".green());
        Ok(())
    } else {
        Err("Local connection test failed: Did not receive HTTP 200 response.".into())
    }
}

pub fn test_server_connection(server_ip: &str, port: u16) -> Result<(), Box<dyn std::error::Error>> {
    let address = format!("{}:{}", server_ip, port);
    println!("Testing connection to server: {}", address);
    let stream = TcpStream::connect(&address)?;
    println!("Successfully connected to the server: {}", address);
    drop(stream);
    Ok(())
}
use std::sync::Arc;
use std::net::TcpStream;
use rustls::{ClientConfig, ClientConnection, RootCertStore};
use std::io::{Write, Read};
use colored::*;
use rustls::crypto::aws_lc_rs as provider;

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
    let mut config = ClientConfig::builder()
        .with_root_certificates(root_store)
        .with_no_client_auth();
    config.dangerous().set_certificate_verifier(Arc::new(danger::NoCertificateVerification::new(
        provider::default_provider(),
    )));
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
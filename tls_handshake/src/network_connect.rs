use std::sync::Arc;
use std::net::TcpStream;
use rustls::{ClientConfig, ClientConnection, RootCertStore};
use std::io::{Write, Read};
use colored::*;

pub fn create_tls_config() -> ClientConfig {
    let root_store = RootCertStore::empty();
    ClientConfig::builder()
        // .with_safe_defaults()
        .with_root_certificates(root_store)
        .with_no_client_auth()
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
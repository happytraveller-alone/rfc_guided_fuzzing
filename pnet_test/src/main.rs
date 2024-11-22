use pnet::datalink::{self, NetworkInterface};
use pnet::packet::ethernet::{EtherTypes, EthernetPacket};
use pnet::packet::ip::IpNextHeaderProtocols;
use pnet::packet::ipv4::Ipv4Packet;
use pnet::packet::tcp::TcpPacket;
use pnet::packet::Packet;
use std::net::IpAddr;

// TLS Constants
const TLS_HANDSHAKE: u8 = 0x16;

// Handshake Types
const HELLO_REQUEST: u8 = 0x00;
const CLIENT_HELLO: u8 = 0x01;
const SERVER_HELLO: u8 = 0x02;
const CERTIFICATE: u8 = 0x0B;
const SERVER_KEY_EXCHANGE: u8 = 0x0C;
const CERTIFICATE_REQUEST: u8 = 0x0D;
const SERVER_HELLO_DONE: u8 = 0x0E;
const CERTIFICATE_VERIFY: u8 = 0x0F;
const CLIENT_KEY_EXCHANGE: u8 = 0x10;
const FINISHED: u8 = 0x14;

fn get_handshake_type_str(handshake_type: u8) -> &'static str {
    match handshake_type {
        HELLO_REQUEST => "Hello Request",
        CLIENT_HELLO => "Client Hello",
        SERVER_HELLO => "Server Hello",
        CERTIFICATE => "Certificate",
        SERVER_KEY_EXCHANGE => "Server Key Exchange",
        CERTIFICATE_REQUEST => "Certificate Request",
        SERVER_HELLO_DONE => "Server Hello Done",
        CERTIFICATE_VERIFY => "Certificate Verify",
        CLIENT_KEY_EXCHANGE => "Client Key Exchange",
        FINISHED => "Finished",
        _ => "Unknown Handshake Type"
    }
}

fn is_tls_handshake(payload: &[u8]) -> bool {
    if payload.len() < 6 {  // TLS header (5 bytes) + Handshake type (1 byte)
        return false;
    }
    payload[0] == TLS_HANDSHAKE
}

fn print_handshake_info(source_ip: IpAddr, dest_ip: IpAddr, tcp: &TcpPacket, payload: &[u8]) {
    let version = format!("{}.{}", payload[1], payload[2]);
    let record_length = ((payload[3] as u16) << 8) | payload[4] as u16;
    let handshake_type = payload[5];
    
    println!("\n=== TLS Handshake Detected ===");
    println!("Time: {}", chrono::Local::now().format("%Y-%m-%d %H:%M:%S"));
    println!("Connection: {}:{} -> {}:{}", 
        source_ip, tcp.get_source(),
        dest_ip, tcp.get_destination()
    );
    println!("TLS Version: {}", version);
    println!("Record Length: {}", record_length);
    println!("Handshake Type: {} (0x{:02X})", 
        get_handshake_type_str(handshake_type),
        handshake_type
    );

    // Parse specific handshake message types
    if payload.len() >= 10 {
        match handshake_type {
            CLIENT_HELLO => {
                if let Some(client_version) = parse_client_hello(payload) {
                    println!("Client Version: {}.{}", 
                        client_version.0, client_version.1);
                }
            },
            SERVER_HELLO => {
                if let Some(server_version) = parse_server_hello(payload) {
                    println!("Server Version: {}.{}", 
                        server_version.0, server_version.1);
                }
            },
            _ => {}
        }
    }
    
    println!("===============================");
}

fn parse_client_hello(payload: &[u8]) -> Option<(u8, u8)> {
    if payload.len() >= 12 {
        Some((payload[9], payload[10]))  // Client Version
    } else {
        None
    }
}

fn parse_server_hello(payload: &[u8]) -> Option<(u8, u8)> {
    if payload.len() >= 12 {
        Some((payload[9], payload[10]))  // Server Version
    } else {
        None
    }
}

fn main() {
    // 获取VMware NAT接口
    let interfaces = datalink::interfaces();
    let interface = interfaces
        .into_iter()
        .find(|iface| iface.description == "VMware Virtual Ethernet Adapter for VMnet8")
        .expect("VMware NAT interface (VMnet8) not found!");

    println!("Starting capture on VMware NAT interface (VMnet8)");
    println!("Interface details:");
    println!("  Name: {}", interface.name);
    println!("  Description: {}", interface.description);
    println!("  MAC: {}", interface.mac.unwrap_or_else(|| panic!("No MAC address found")));
    println!("  IP addresses:");
    for ip in &interface.ips {
        println!("    {}", ip);
    }
    println!("\nListening for TLS Handshake messages...\n");

    // 创建数据包捕获通道
    let (_, mut rx) = match datalink::channel(&interface, Default::default()) {
        Ok(datalink::Channel::Ethernet(tx, rx)) => (tx, rx),
        Ok(_) => panic!("Unhandled channel type"),
        Err(e) => panic!("Error creating channel: {}", e),
    };

    loop {
        match rx.next() {
            Ok(packet) => {
                if let Some(ethernet) = EthernetPacket::new(packet) {
                    if ethernet.get_ethertype() != EtherTypes::Ipv4 {
                        continue;
                    }
                    
                    if let Some(ipv4) = Ipv4Packet::new(ethernet.payload()) {
                        if ipv4.get_next_level_protocol() != IpNextHeaderProtocols::Tcp {
                            continue;
                        }
                        
                        if let Some(tcp) = TcpPacket::new(ipv4.payload()) {
                            if tcp.get_destination() == 443 || tcp.get_source() == 443 {
                                let payload = tcp.payload();
                                if is_tls_handshake(payload) {
                                    print_handshake_info(
                                        IpAddr::V4(ipv4.get_source()),
                                        IpAddr::V4(ipv4.get_destination()),
                                        &tcp,
                                        payload
                                    );
                                }
                            }
                        }
                    }
                }
            }
            Err(e) => {
                eprintln!("Error receiving packet: {}", e);
                continue;
            }
        }
    }
}
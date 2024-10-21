use phf::phf_map;

pub mod clienthello_parser;
pub mod server_response;
pub mod network_connect;
pub mod terminal;
pub mod clienthello;

pub use clienthello::*;
pub use clienthello_parser::*;
pub use server_response::*;
pub use network_connect::*;
pub use terminal::*;


pub const SERVER_NAME: &str = "WIN-1C2P8R1FV76";
pub const SERVER_STATIC_IP: &str = "192.168.110.129";
pub const PORT: u16 = 443;

static TLS_EXTENSIONS: phf::Map<u16, &'static str> = phf_map! {
    0x0000u16 => "server_name",
    0x0001u16 => "max_fragment_length",
    0x0005u16 => "status_request",
    0x000Au16 => "supported_groups",
    0x000Bu16 => "ec_point_formats",
    0x000Du16 => "signature_algorithms",
    0x000Eu16 => "use_srtp",
    0x000Fu16 => "heartbeat",
    0x0010u16 => "application_layer_protocol_negotiation",
    0x0012u16 => "signed_certificate_timestamp",
    0x0013u16 => "client_certificate_type",
    0x0014u16 => "server_certificate_type",
    0x0015u16 => "padding",
    0x0017u16 => "extended_master_secret",
    0x0023u16 => "session_ticket",
    0x0029u16 => "pre_shared_key",
    0x002Au16 => "early_data",
    0x002Bu16 => "supported_versions",
    0x002Cu16 => "cookie",
    0x002Du16 => "psk_key_exchange_modes",
    0x0032u16 => "signature_algorithms_cert",
    0x0033u16 => "key_share",

    0xFF01u16 => "renegotiation_info"
};


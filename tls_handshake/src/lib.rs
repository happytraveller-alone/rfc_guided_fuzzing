use phf::phf_map;

pub mod clienthello;
pub mod clienthello_mutator;
pub mod clienthello_parser;
pub mod network_connect;
pub mod server_response;
pub mod terminal;

pub use clienthello::*;
pub use clienthello_mutator::*;
pub use clienthello_parser::*;
pub use network_connect::*;
pub use server_response::*;
pub use terminal::*;

// own:cargo run -- --server WIN-A9626JATE0P --ip 172.23.214.40  --test_env --check_parse_ch --check_mutate_ch --check_parse_sh
pub const SERVER_NAME: &str = "WIN-1C2P8R1FV76";
// WIN_QCU7FNFT726 WIN-A9626JATE0P
pub const SERVER_STATIC_IP: &str = "192.168.110.130";
// 192.168.133.129 172.23.214.40
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

static TLS_EXTENSIONS_REVERSE: phf::Map<&'static str, u16> = phf_map! {
    "server_name" => 0x0000u16,
    "max_fragment_length" => 0x0001u16,
    "status_request" => 0x0005u16,
    "supported_groups" => 0x000Au16,
    "ec_point_formats" => 0x000Bu16,
    "signature_algorithms" => 0x000Du16,
    "use_srtp" => 0x000Eu16,
    "heartbeat" => 0x000Fu16,
    "application_layer_protocol_negotiation" => 0x0010u16,
    "signed_certificate_timestamp" => 0x0012u16,
    "client_certificate_type" => 0x0013u16,
    "server_certificate_type" => 0x0014u16,
    "padding" => 0x0015u16,
    "extended_master_secret" => 0x0017u16,
    "session_ticket" => 0x0023u16,
    "pre_shared_key" => 0x0029u16,
    "early_data" => 0x002Au16,
    "supported_versions" => 0x002Bu16,
    "cookie" => 0x002Cu16,
    "psk_key_exchange_modes" => 0x002Du16,
    "signature_algorithms_cert" => 0x0032u16,
    "key_share" => 0x0033u16,
    "renegotiation_info" => 0xFF01u16
};

use serde::{Deserialize, Serialize};
use serde_json;
use std::error::Error;
use std::fs::File;
use std::io::{self, Write};

#[derive(Serialize, Deserialize, Debug)]
struct Message {
    message_construction: Construction,
    message_processing: Processing,
}

#[derive(Serialize, Deserialize, Debug)]
struct Construction {
    construction_rule_type: String,
    construction_explicitness: u8,
    construction_base: String,
}

#[derive(Serialize, Deserialize, Debug)]
struct Processing {
    processing_rule_type: String,
    processing_explicitness: u8,
    processing_base: String,
}

#[derive(Serialize, Deserialize, Debug)]
struct Rule {
    construction_rule_type: String,
    construction_explicitness: u8,
    construction_base: String,
    processing_rule_type: String,
    processing_explicitness: u8,
    processing_base: String,
}

fn escape_csv_field(field: &str) -> String {
    let mut escaped = String::from("\"");
    for c in field.chars() {
        if c == '"' {
            escaped.push('"');
        }
        escaped.push(c);
    }
    escaped.push('"');
    escaped
}

fn main() -> Result<(), Box<dyn Error>> {
    let data = r#"
    [
        {
            "message_construction": {
                "construction_rule_type": "CLI-MSG-CONST",
                "construction_explicitness": 1,
                "construction_base": "Clients MUST send the ClientHello as their first TLS message when connecting to a server."
            },
            "message_processing": {
                "processing_rule_type": "SRV-MSG-PROC",
                "processing_explicitness": 0,
                "processing_base": "Servers MUST expect a ClientHello message as the first TLS message."
            }
        },
        {
            "message_construction": {
                "construction_rule_type": "CLI-MSG-CONST",
                "construction_explicitness": 1,
                "construction_base": "After receiving a HelloRetryRequest, clients MUST send a modified ClientHello with: (1) a new \"key_share\" extension with a single KeyShareEntry if requested, (2) removal of the \"early_data\" extension if present, and (3) inclusion of a \"cookie\" extension if provided."
            },
            "message_processing": {
                "processing_rule_type": "SRV-MSG-PROC",
                "processing_explicitness": 0,
                "processing_base": "Servers MUST verify these mandatory modifications in the new ClientHello."
            }
        },
        {
            "message_construction": {
                "construction_rule_type": "CLI-MSG-CONST",
                "construction_explicitness": 1,
                "construction_base": "Clients MUST update the \"pre_shared_key\" values and MAY modify the \"padding\" extension as needed."
            },
            "message_processing": {
                "processing_rule_type": "SRV-MSG-PROC",
                "processing_explicitness": 0,
                "processing_base": "Servers MUST verify updated \"pre_shared_key\" values and accept optional \"padding\" modifications."
            }
        }
    ]
    "#;

    let messages: Vec<Message> = serde_json::from_str(data)?;

    let mut csv_file = File::create("output.csv")?;
    writeln!(csv_file, "index,construction_rule_type,construction_explicitness,construction_base,processing_rule_type,processing_explicitness,processing_base")?;

    for (index, message) in messages.iter().enumerate() {
        let rule = Rule {
            construction_rule_type: message.message_construction.construction_rule_type.clone(),
            construction_explicitness: message.message_construction.construction_explicitness,
            construction_base: message.message_construction.construction_base.clone(),
            processing_rule_type: message.message_processing.processing_rule_type.clone(),
            processing_explicitness: message.message_processing.processing_explicitness,
            processing_base: message.message_processing.processing_base.clone(),
        };

        writeln!(csv_file, "{},{},{},{},{},{},{}",
                 index + 1,
                 rule.construction_rule_type,
                 rule.construction_explicitness,
                 escape_csv_field(&rule.construction_base),
                 rule.processing_rule_type,
                 rule.processing_explicitness,
                 escape_csv_field(&rule.processing_base))?;
    }

    Ok(())
}

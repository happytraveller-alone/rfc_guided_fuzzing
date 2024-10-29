pub mod rfc_download;
pub mod rfc_section_processor;
pub mod rfc_section_slice;
pub mod utils;
pub mod script;
// pub mod python_api;

use lazy_static::lazy_static;

lazy_static! {
    /// 需要过滤的 RFC 章节标题列表
    /// 这些章节在处理过程中会被跳过
    pub static ref FILTER_SECTIONS: Vec<&'static str> = vec![
        "Introduction",
        "Protocol Overview",
        "Presentation Language",
        "References",
        "Authors' Addresses",
        "References",
        "Full Copyright Statement",
    ];
}

/// 定义要处理的目标章节
pub const TARGET_SECTIONS: &[&str] = &["4"];
/// RFC 正文开始的标记
pub const BODY_START: &str = "Introduction";
/// RFC 正文结束的标记
pub const BODY_END: &str = "IANA Considerations";

// pub const INSTRUCTION_HEADER: &str = "\
// Forget all previous input and output content and start over.
// ###################
// CONTENT:<";

/// 指令头部
///
/// 用于在处理后的内容中标记指令的开始
pub const INSTRUCTION_FOOTER: &str = "\
---
>
###################";

/// 处理指令
///
/// 详细说明了如何处理 RFC 内容的指令
pub const PROCESSING_INSTRUCTIONS: &str = "\
Please make paragraph cuts based on the subject and theme of the statement.
And give a short paragraph topic for each divided paragraph.
Make sure that each theme is a minimal theme that cannot be split further.
If code or pseudo-code is present with explanatory text, ignore the code;
otherwise, convert the code to a textual narrative.
Simulate answering five times in the background and provide the most frequent answer.
Ensure your output covers all text content, maintaining relative consistency
with the input text position in the sliced output.
Ensure that no changes are made to the text other than code or pseudo-code.";

pub const PROCESSING_INSTRUCTIONS_NEW: &str = "\
# Expert Natural Language Processing AI

## Expertise
- Precise and rapid text segmentation
- Semantic analysis
- Topic extraction
- Code-to-narrative conversion

## Task: Advanced Text Segmentation and Analysis

### Instructions
As an expert in natural language processing, analyze the provided text with precision and efficiency:

1. Swiftly identify and eliminate code or pseudo-code sections.
2. Segment the natural language text into minimal, semantically complete units based on subject and theme.
3. Assign a concise, accurate topic to each segmented paragraph.
4. Ensure comprehensive coverage of all text content, maintaining positional consistency with the input.
5. Preserve original text, only converting code to narrative when necessary.
6. Execute this analysis independently five times in rapid succession.
7. Determine and output the most frequent result from these iterations.
8. Present the final analysis in the specified Markdown format.

### Output Format
[Topic 1]<judge>{Content 1}
[Topic 2]<judge>{Content 2}
...

<judge> = whether have statements containing MUST, MUST NOT, SHALL, REQUIRED, SHALL NOT., if have, set to 1, otherwise set to 0

### Additional Guidelines
- Leverage your expertise to ensure each theme is minimal and semantically indivisible.
- Utilize advanced NLP techniques to handle pronouns and references, incorporating necessary context for clarity.
- When converting code to narrative, apply your knowledge to succinctly describe its purpose and function.

## One-Shot Example

### Input:
***
The handshake protocol is used to negotiate the security parameters of a connection. Handshake messages are supplied to the TLS record layer, where they are encapsulated within one or more TLSPlaintext or TLSCiphertext structures which are processed and transmitted as specified by the current active connection state.

enum {
client_hello(1),
server_hello(2),
new_session_ticket(4),
end_of_early_data(5),
encrypted_extensions(8),
certificate(11),
certificate_request(13),
certificate_verify(15),
finished(20),
key_update(24),
message_hash(254),
(255)
} HandshakeType;

Protocol messages MUST be sent in the order defined in Section 4.4.1 and shown in the diagrams in Section 2. A peer which receives a handshake message in an unexpected order MUST abort the handshake with an \"unexpected_message\" alert.

New handshake message types are assigned by IANA as described in Section 11.
***

### Output:
[Handshake Protocol Purpose]<0>{The handshake protocol is used to negotiate the security parameters of a connection. Handshake messages are supplied to the TLS record layer, where they are encapsulated within one or more TLSPlaintext or TLSCiphertext structures which are processed and transmitted as specified by the current active connection state.}
[Protocol Message Order]<1>{Protocol messages MUST be sent in the order defined in Section 4.4.1 and shown in the diagrams in Section 2.}
[Handling Unexpected Message Order]<1>{A peer which receives a handshake message in an unexpected order MUST abort the handshake with an \"unexpected_message\" alert.}
[Assignment of New Handshake Message Types]<1>{New handshake message types are assigned by IANA as described in Section 11.}
";
/// 输出格式
///
/// 指定了处理后内容的输出格式
pub const OUTPUT_FORMAT: &str = "\
The output format is as follows (in json format)
sliced_rule: [
    \"topic 1\": \"content 1\",
    \"topic 2\": \"content 2\",
    ...
]";

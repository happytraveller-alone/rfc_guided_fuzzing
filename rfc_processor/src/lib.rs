pub mod download;
pub mod process;
pub mod slice;
pub mod utils;

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

/// RFC 正文开始的标记
pub const BODY_START: &str = "Introduction";
/// RFC 正文结束的标记
pub const BODY_END: &str = "IANA Considerations";

pub const INSTRUCTION_HEADER: &str = "\
Forget all previous input and output content and start over.
###################
CONTENT:<";

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

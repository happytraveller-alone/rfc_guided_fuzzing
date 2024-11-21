pub mod rfc_download;
pub mod rfc_section_processor;
pub mod rfc_section_slice;
pub mod utils;
pub mod processing_script;
pub mod rust_csv_processor;
pub mod python_csv_processor;
// pub mod python_api;

use lazy_static::lazy_static;

lazy_static! {
    /// 需要过滤的 RFC 章节标题列表
    /// 这些章节在处理过程中会被跳过
    pub static ref FILTER_SECTIONS: Vec<&'static str> = vec![
        "Syntax Notation",
        "Requirements Notation",
        "Introduction",
        "Protocol Overview",
        "Presentation Language",
        "References",
        "Acknowledgments",
        "Normative References",
        "Informative References",
        "Authors' Addresses",
        "References",
        "Full Copyright Statement",
        "Conformance and Error Handling",
        "STATUS OF THIS MEMO",
    ];
}

/// 定义要处理的目标章节
pub const TARGET_SECTIONS: &[&str] = &["4"];
/// RFC 正文开始的标记
pub const BODY_START: &str = "Introduction";
/// RFC 正文结束的标记
pub const BODY_END: &str = "IANA Considerations";
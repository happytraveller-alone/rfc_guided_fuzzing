pub mod download;
pub mod process;
pub mod slice;
pub mod utils;

use lazy_static::lazy_static;

use std::error::Error;
use std::path::{Path, PathBuf};

pub trait DownloadClient {
    fn download_rfc(&self, rfc_number: &str, input_file: &PathBuf) -> Result<(), Box<dyn Error>>;
    fn get_rfc_title(&self, rfc_number: &str) -> Result<String, Box<dyn Error>>;
}

pub trait ProcessClient {
    fn process_rfc_content(&self, input_file: &PathBuf) -> Result<String, Box<dyn Error>>;
}

pub trait SliceClient {
    fn slice_content(&self, content: &str, rfc_output_dir: &Path, rfc_number: &str) -> Result<(), Box<dyn Error>>;
}

lazy_static! {
    pub static ref FILTER_SECTIONS: Vec<&'static str> = vec![
        "Introduction",
        "Protocol Overview",
        "Presentation Language",
        "References",
        "Authors' Addresses",
        "Full Copyright Statement",
    ];
}

pub const BODY_START: &str = "Introduction";
pub const BODY_END: &str = "IANA Considerations";

pub const INSTRUCTION_HEADER: &str = "\
Forget all previous input and output content and start over.
###################
CONTENT:<";

pub const INSTRUCTION_FOOTER: &str = "\
---
>
###################";

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

pub const OUTPUT_FORMAT: &str = "\
The output format is as follows (in json format)
sliced_rule: [
    \"topic 1\": \"content 1\",
    \"topic 2\": \"content 2\",
    ...
]";
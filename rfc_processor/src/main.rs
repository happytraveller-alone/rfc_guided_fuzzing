use rfc_processor::{download, process, slice, utils};
use std::env;
use std::error::Error;
use std::thread;
use std::time::Duration;
use colored::*;

fn main() -> Result<(), Box<dyn Error>> {
    let args: Vec<String> = env::args().collect();
    let rfc_number = if args.len() != 2 {
        eprintln!("{}", "Warning: No RFC number provided.".red());
        println!("Please provide an RFC number. Using default RFC 2675.");
        thread::sleep(Duration::from_secs(3));
        "2675".to_string()
    } else {
        args[1].clone()
    };

    let project_root = utils::get_project_root();
    let (input_dir, output_dir) = utils::create_directories(&project_root)?;
    let input_file = input_dir.join(format!("{}.txt", rfc_number));

    if !input_file.exists() {
        download::download_rfc(&rfc_number, &input_file)?;
    } else {
        println!("找到本地文件 {:?}", input_file);
    }

    let body = process::process_rfc_content(&input_file)?;

    let rfc_output_dir = utils::create_rfc_output_directory(&output_dir, &rfc_number)?;

    let rfc_title = download::get_rfc_title(&rfc_number)?;
    utils::save_rfc_info(&rfc_number, &rfc_title, &rfc_output_dir)?;
    
    let pre_processed_content = utils::remove_headers_footers(&input_file)?;
    let pre_processed_file = rfc_output_dir.join("pre_processed.txt");
    utils::save_content(&pre_processed_content, &pre_processed_file)?;
    println!("预处理内容已保存到 {:?}", pre_processed_file);

    let body_file = rfc_output_dir.join(format!("{}_processed.txt", rfc_number));
    utils::save_content(&body, &body_file)?;

    slice::slice_content(&body, &rfc_output_dir, &rfc_number)?;

    println!("处理完成。");

    Ok(())
}
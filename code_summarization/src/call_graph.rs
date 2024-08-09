use regex::Regex;
use std::collections::{HashMap, HashSet};
use std::fs::File;
use std::io::{self, Read, Write};
use std::path::Path;
pub struct CallGraph {
    callers: HashMap<String, HashSet<String>>,
    callees: HashMap<String, HashSet<String>>,
}

impl CallGraph {
    pub fn new() -> Self {
        CallGraph {
            callers: HashMap::new(),
            callees: HashMap::new(),
        }
    }

    pub fn add_edge(&mut self, caller: String, callee: String) {
        self.callers
            .entry(callee.clone())
            .or_insert_with(HashSet::new)
            .insert(caller.clone());
        self.callees
            .entry(caller)
            .or_insert_with(HashSet::new)
            .insert(callee);
    }

    pub fn find_entry_points(&self) -> HashSet<String> {
        let all_functions: HashSet<_> = self
            .callers
            .keys()
            .chain(self.callees.keys())
            .cloned()
            .collect();
        all_functions
            .into_iter()
            .filter(|f| !self.callers.contains_key(f))
            .collect()
    }

    pub fn print_entry_points(&self, node_labels: &HashMap<String, String>) {
        println!("函数调用图的入口点（没有被其他函数调用的函数）：");
        for point in self.find_entry_points() {
            let label = node_labels
                .get(&point)
                .map(String::as_str)
                .unwrap_or("Unknown");
            println!("{}: {}", point, label);
        }
    }

    pub fn print_all_calls(&self) {
        println!("\n所有函数调用关系：");
        for (caller, callees) in &self.callees {
            println!("函数 {} 调用了: {:?}", caller, callees);
        }
    }
}

pub fn process_call_graph(input_file: &str, output_dir: &Path) -> io::Result<()> {
    let call_graph_input = Path::new("input").join("call_graph").join(input_file);
    if !call_graph_input.exists() {
        return Err(io::Error::new(
            io::ErrorKind::NotFound,
            format!("Call graph input file not found: {:?}", call_graph_input),
        ));
    }

    let mut content = String::new();
    File::open(&call_graph_input)?.read_to_string(&mut content)?;

    // 功能点 1: 原有的功能
    let node_labels = process_original_functionality(&content, output_dir)?;

    // 功能点 2: 新添加的 CallGraph 功能
    process_call_graph_functionality(&content, output_dir, &node_labels)?;

    Ok(())
}

fn process_original_functionality(
    content: &str,
    output_dir: &Path,
) -> io::Result<HashMap<String, String>> {
    let result = process_node_lines(content);

    let summary_dir = output_dir.join("summary");
    std::fs::create_dir_all(&summary_dir)?;

    let output_file = summary_dir.join("call_graph_summary.txt");
    let mut file = File::create(output_file)?;

    // 将 HashMap 转换为 Vec 并排序
    let mut sorted_result: Vec<_> = result.iter().collect();
    sorted_result.sort_by(|a, b| {
        a.0.parse::<usize>()
            .unwrap_or(0)
            .cmp(&b.0.parse::<usize>().unwrap_or(0))
    });

    // 写入排序后的结果
    for (key, value) in sorted_result {
        writeln!(file, "{}: {}", key, value)?;
    }

    Ok(result)
}

fn process_call_graph_functionality(
    content: &str,
    output_dir: &Path,
    node_labels: &HashMap<String, String>,
) -> io::Result<()> {
    let mut graph = CallGraph::new();
    let re = Regex::new(r#"edge: \{ sourcename: "(\w+)" targetname: "(\w+)" \}"#).unwrap();

    for cap in re.captures_iter(content) {
        let caller = cap[1].to_string();
        let callee = cap[2].to_string();
        graph.add_edge(caller, callee);
    }

    // 打印入口点和所有调用关系
    graph.print_entry_points(node_labels);
    // graph.print_all_calls();

    // 将 CallGraph 结果写入文件
    let summary_dir = output_dir.join("summary");
    std::fs::create_dir_all(&summary_dir)?;
    let call_graph_output_file = summary_dir.join("call_graph_details.txt");
    let mut call_graph_file = File::create(call_graph_output_file)?;

    writeln!(call_graph_file, "函数调用图的入口点：")?;
    for point in graph.find_entry_points() {
        let label = node_labels
            .get(&point)
            .map(String::as_str)
            .unwrap_or("Unknown");
        writeln!(call_graph_file, "{}: {}", point, label)?;
    }

    // writeln!(call_graph_file, "\n所有函数调用关系：")?;
    // for (caller, callees) in &graph.callees {
    //     let caller_label = node_labels
    //         .get(caller)
    //         .map(String::as_str)
    //         .unwrap_or("Unknown");
    //     let callee_labels: Vec<_> = callees
    //         .iter()
    //         .map(|callee| {
    //             node_labels
    //                 .get(callee)
    //                 .map(String::as_str)
    //                 .unwrap_or("Unknown")
    //         })
    //         .collect();
    //     writeln!(
    //         call_graph_file,
    //         "函数 {} ({}) 调用了: {:?}",
    //         caller, caller_label, callee_labels
    //     )?;
    // }

    Ok(())
}

fn process_node_lines(input: &str) -> HashMap<String, String> {
    let mut result = HashMap::new();
    let node_regex = Regex::new(
        r#"node: \{ title: "(\d+)" label: "(.*?)" color: \d+ textcolor: \d+ bordercolor: black \}"#,
    )
    .unwrap();
    let cleanup_regex = Regex::new(r"@@[A-Z0-9_]+").unwrap();
    let cleanup_regex_2 = Regex::new(r"@@[A-Z0-9_]+[A-Z][a-z]").unwrap();
    let head_cleanup_regex = Regex::new(r"^[^a-zA-Z]+").unwrap();
    let tail_cleanup_regex = Regex::new(r"_[0-9A-Z_]+$").unwrap();

    for cap in node_regex.captures_iter(input) {
        let title = cap[1].to_string();
        let mut label = cap[2].to_string();

        // 清理和处理标签
        label = head_cleanup_regex.replace(&label, "").to_string();
        label = cleanup_regex_2
            .replace_all(&label, |caps: &regex::Captures| {
                let matched = caps.get(0).unwrap().as_str();
                let chars: Vec<char> = matched.chars().collect();
                let len = chars.len();

                if len >= 2
                    && chars[len - 2].is_ascii_uppercase()
                    && chars[len - 1].is_ascii_lowercase()
                {
                    format!("_{}{}", chars[len - 2], chars[len - 1])
                } else {
                    "_".to_string()
                }
            })
            .to_string();

        label = cleanup_regex.replace(&label, "_").to_string();
        label = label.replace('@', "_").replace('?', "_").replace('$', "_");
        label = Regex::new(r"_+")
            .unwrap()
            .replace_all(&label, "_")
            .to_string();

        let mut seen = HashSet::new();
        label = label
            .split('_')
            .filter(|&x| seen.insert(x))
            .collect::<Vec<&str>>()
            .join("_");

        label = label.trim_matches('_').to_string();
        label = tail_cleanup_regex.replace(&label, "").to_string();
        label = tail_cleanup_regex.replace(&label, "").to_string();

        let value = if label.is_empty() {
            "none".to_string()
        } else {
            label
        };

        result.insert(title, value);
    }

    result
}

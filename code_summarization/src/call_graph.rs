use regex::Regex;
use std::collections::VecDeque;
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

    // #[warn(dead_code)]
    // pub fn print_entry_points(&self, node_labels: &HashMap<String, String>) {
    //     println!("函数调用图的入口点（没有被其他函数调用的函数，且包含TLS13）：");
    //     for point in self.find_entry_points() {
    //         let label = node_labels
    //             .get(&point)
    //             .map(String::as_str)
    //             .unwrap_or("Unknown");
    //         // if let Some(label) = node_labels.get(&point) {
    //         let lower_label = label.to_lowercase();
    //         if lower_label.contains("tls13")
    //             && (lower_label.contains("server") || lower_label.contains("client"))
    //         {
    //             println!("{}: {}", point, label);
    //         }
    //         // }
    //     }
    // }

    pub fn write_entry_points<W: Write>(
        &self,
        writer: &mut W,
        node_labels: &HashMap<String, String>,
    ) -> io::Result<()> {
        writeln!(writer, "函数调用图的入口点（包含TLS13和server/client）：")?;
        for point in self.find_entry_points() {
            if let Some(label) = node_labels.get(&point) {
                let lower_label = label.to_lowercase();
                if lower_label.contains("tls13")
                    && (lower_label.contains("server") || lower_label.contains("client"))
                {
                    writeln!(writer, "{}: {}", point, label)?;
                }
            }
        }
        Ok(())
    }

    // #[warn(dead_code)]
    // pub fn print_all_calls(&self) {
    //     println!("\n所有函数调用关系：");
    //     for (caller, callees) in &self.callees {
    //         println!("函数 {} 调用了: {:?}", caller, callees);
    //     }
    // }
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
    // graph.print_entry_points(node_labels);
    // graph.print_all_calls();

    // 将 CallGraph 结果写入文件
    let summary_dir = output_dir.join("summary");
    std::fs::create_dir_all(&summary_dir)?;
    let call_graph_output_file = summary_dir.join("call_graph_details.txt");
    let mut call_graph_file = File::create(call_graph_output_file)?;
    graph.write_entry_points(&mut call_graph_file, node_labels)?;

    // New useful call graph
    let useful_call_graph_file = summary_dir.join("useful_call_graph.txt");
    let mut useful_call_graph_file = File::create(useful_call_graph_file)?;
    write_useful_call_graph(&graph, &mut useful_call_graph_file, node_labels)?;

    // New useful root node call graph in dfs to check relevance
    let useful_root_node_file = summary_dir.join("dfs_useful_root_node.txt");
    let mut useful_root_node_file = File::create(useful_root_node_file)?;
    dfs_write_useful_root_node(&graph, &mut useful_root_node_file, node_labels, "1435")?;

    // New useful root node call graph in bfs to check node number related
    let useful_root_node_file = summary_dir.join("bfs_useful_root_node.txt");
    let mut useful_root_node_file = File::create(useful_root_node_file)?;
    bfs_write_useful_root_node(&graph, &mut useful_root_node_file, node_labels, "1435")?;

    Ok(())
}

pub fn bfs_write_useful_root_node<W: Write>(
    graph: &CallGraph,
    writer: &mut W,
    node_labels: &HashMap<String, String>,
    root_node: &str,
) -> io::Result<()> {
    writeln!(
        writer,
        "Useful Call Graph for root node {} (filtered by blacklist criteria):",
        root_node
    )?;

    let mut visited = HashSet::new();
    let mut queue = VecDeque::new();
    queue.push_back((root_node.to_string(), 0));

    while let Some((node, depth)) = queue.pop_front() {
        if !visited.insert(node.clone()) {
            continue;
        }

        if is_useful_node(&node, node_labels) {
            let node_label = node_labels
                .get(&node)
                .map(String::as_str)
                .unwrap_or("Unknown");
            writeln!(writer, "{}{} ({})", "  ".repeat(depth), node, node_label)?;

            if let Some(callees) = graph.callees.get(&node) {
                for callee in callees {
                    if is_useful_node(callee, node_labels) {
                        queue.push_back((callee.clone(), depth + 1));
                    }
                }
            }
        }
    }

    Ok(())
}

fn dfs_write_useful_root_node<W: Write>(
    graph: &CallGraph,
    writer: &mut W,
    node_labels: &HashMap<String, String>,
    root_node: &str,
) -> io::Result<()> {
    writeln!(
        writer,
        "Useful Call Graph for root node {} (filtered by blacklist criteria):",
        root_node
    )?;

    let mut visited = HashSet::new();
    dfs_traverse(graph, writer, node_labels, root_node, 0, &mut visited)?;

    Ok(())
}

fn dfs_traverse<W: Write>(
    graph: &CallGraph,
    writer: &mut W,
    node_labels: &HashMap<String, String>,
    node: &str,
    depth: usize,
    visited: &mut HashSet<String>,
) -> io::Result<()> {
    if !visited.insert(node.to_string()) {
        return Ok(());
    }

    if is_useful_node(node, node_labels) {
        let node_label = node_labels
            .get(node)
            .map(String::as_str)
            .unwrap_or("Unknown");
        writeln!(writer, "{}{} ({})", "  ".repeat(depth), node, node_label)?;

        if let Some(callees) = graph.callees.get(node) {
            let mut useful_callees: Vec<_> = callees
                .iter()
                .filter(|callee| is_useful_node(callee, node_labels))
                .collect();

            // Sort callees for consistent output
            useful_callees.sort();

            for callee in useful_callees {
                dfs_traverse(graph, writer, node_labels, callee, depth + 1, visited)?;
            }
        }
    }

    Ok(())
}

fn write_useful_call_graph<W: Write>(
    graph: &CallGraph,
    writer: &mut W,
    node_labels: &HashMap<String, String>,
) -> io::Result<()> {
    writeln!(
        writer,
        "Useful Call Graph (filtered by blacklist criteria):"
    )?;

    for (caller, callees) in &graph.callees {
        if is_useful_node(caller, node_labels) {
            let useful_callees: Vec<_> = callees
                .iter()
                .filter(|callee| is_useful_node(callee, node_labels))
                .cloned()
                .collect();
            if !useful_callees.is_empty() {
                let caller_label = node_labels
                    .get(caller)
                    .map(String::as_str)
                    .unwrap_or("Unknown");
                writeln!(writer, "{} ({}): ", caller, caller_label)?;
                for callee in useful_callees {
                    let callee_label = node_labels
                        .get(&callee)
                        .map(String::as_str)
                        .unwrap_or("Unknown");
                    writeln!(writer, "  -> {} ({})", callee, callee_label)?;
                }
                writeln!(writer)?;
            }
        }
    }

    Ok(())
}

fn is_useful_node(node: &str, node_labels: &HashMap<String, String>) -> bool {
    if let Ok(num) = node.parse::<u32>() {
        if num <= 1565 && num > 347 && num != 572 && num != 847 && num != 1299 && num != 1423 {
            if let Some(label) = node_labels.get(node) {
                let lower_label = label.to_lowercase();
                lower_label.contains("tls13")
                    && (lower_label.contains("server")
                        || lower_label.contains("client")
                        || lower_label.contains("context"))
                    && !lower_label.contains("delete")
                    && !lower_label.contains("wpp")
                    && !lower_label.contains("initialize")
            } else {
                false
            }
        } else {
            false
        }
    } else {
        false
    }
}

fn process_node_lines(input: &str) -> HashMap<String, String> {
    let mut result = HashMap::new();
    let node_regex = Regex::new(
        r#"node: \{ title: "(\d+)" label: "(.*?)" color: (\d+)( textcolor: (\d+))?( bordercolor: (\w+))? \}"#,
    )
    .unwrap();
    let head_cleanup_regex = Regex::new(r"^[@?_]+").unwrap();
    let skip_regex = Regex::new(r"[@?$]+").unwrap();

    for cap in node_regex.captures_iter(input) {
        let title = cap[1].to_string();
        let mut label = cap[2].to_string();

        label = head_cleanup_regex.replace(&label, "").to_string();
        if !skip_regex.is_match(&label) {
            result.insert(title, label);
            continue;
        }

        label = cleanup_and_process_label(label);

        let value = if label.is_empty() { "none" } else { &label };
        result.insert(title, value.to_string());
    }

    result
}

fn cleanup_and_process_label(mut label: String) -> String {
    let cleanup_regex = Regex::new(r"@@[A-Z0-9_]+").unwrap();
    let cleanup_regex_2 = Regex::new(r"@@[A-Z0-9_]+[A-Z][a-z]").unwrap();
    let tail_cleanup_regex = Regex::new(r"_[0-9A-Z_]+$").unwrap();
    let special_chars_regex = Regex::new(r"[?_$@]").unwrap();

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

    if !special_chars_regex.is_match(&label) {
        label = tail_cleanup_regex.replace(&label, "").to_string();
    } else {
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
    }

    label
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_process_node_lines() {
        let input = r#"
        node: { title: "1447" label: "?ProcessHandshake@CTls13ClientContext@@EEAAKPEAEKPEAH@Z" color: 76 textcolor: 73 bordercolor: black }
        node: { title: "99" label: "?AddCertificateSignatureSuite@CTlsSignatureSuiteList@@QEAAEPEBU_CERT_CONTEXT@@@Z" color: 76 textcolor: 73 bordercolor: black }
        node: { title: "1449" label: "?QueryKeyingMaterial@CTls13ServerContext@@MEAAKPEAX@Z" color: 76 textcolor: 73 bordercolor: black }
        node: { title: "1855" label: "__imp_SetThreadpoolTimer" color: 80 bordercolor: black }
        node: { title: "349" label: "SpCompleteAuthToken" color: 76 textcolor: 73 bordercolor: black }
        node: { title: "1140" label: "WPP_SF_DS" color: 76 textcolor: 73 bordercolor: black }
        "#;

        let result = process_node_lines(input);

        assert_eq!(result.len(), 6);
        assert_eq!(result.get("1140"), Some(&"WPP_SF_DS".to_string()));
        assert_eq!(
            result.get("1855"),
            Some(&"imp_SetThreadpoolTimer".to_string())
        );
        assert_eq!(result.get("349"), Some(&"SpCompleteAuthToken".to_string()));
        assert_eq!(
            result.get("1447"),
            Some(&"ProcessHandshake_CTls13ClientContext".to_string())
        );
        assert_eq!(
            result.get("99"),
            Some(&"AddCertificateSignatureSuite_CTlsSignatureSuiteList".to_string())
        );
        assert_eq!(
            result.get("1449"),
            Some(&"QueryKeyingMaterial_CTls13ServerContext".to_string())
        );
    }
}

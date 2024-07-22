use regex::Regex;
use std::collections::HashMap;

fn extract_rfc_info(text: &str) -> HashMap<String, String> {
    let re = Regex::new(r#"(?P<authors>.*?), "(?P<title>.*?)", RFC (?P<number>\d+)"#).unwrap();
    let mut rfc_map = HashMap::new();

    for cap in re.captures_iter(text) {
        let number = cap.name("number").unwrap().as_str().to_string();
        let title = cap.name("title").unwrap().as_str().to_string();
        rfc_map.insert(number, title);
    }

    rfc_map
}

fn main() {
    let text1 = r#"Borman, D., Deering, S., and R. Hinden, "IPv6 Jumbograms", RFC 2675, DOI 10.17487/RFC2675, August 1999, <https://www.rfc-editor.org/info/rfc2675>."#;

    let text2 = r#"Rescorla, E., "The Transport Layer Security (TLS) Protocol Version 1.3", RFC 8446, DOI 10.17487/RFC8446, August 2018, <https://www.rfc-editor.org/info/rfc8446>."#;

    let rfc_map1 = extract_rfc_info(text1);
    let rfc_map2 = extract_rfc_info(text2);

    println!("RFC 2675 Title: {:?}", rfc_map1.get("2675"));
    println!("RFC 8446 Title: {:?}", rfc_map2.get("8446"));

    // Combine the maps
    let mut combined_map = rfc_map1;
    combined_map.extend(rfc_map2);

    println!("Combined RFC Map: {:?}", combined_map);
}

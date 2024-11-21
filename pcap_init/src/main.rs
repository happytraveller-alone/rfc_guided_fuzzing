use pcap;
use std::env;
use std::path::Path;
use hex;
fn main() {
    let dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    println!(
        "cargo:rustc-link-search=native={}",
        Path::new(&dir).join("x64").display()
    );
    // list all of the devices pcap tells us are available
    let mut device_use: Option<pcap::Device> = None;
    // let mut device_use: Option<pcap::Device> = None;
    for device in pcap::Device::list().expect("device lookup failed") {
    if let Some(ref desc) = device.desc {
        if desc.contains("VMware Virtual Ethernet Adapter for VMnet") {
            device_use = Some(device.clone());
            println!("Found device! {:?}", desc);
                break; // 添加 break 语句以避免部分移动值的问题
            }
        }
        // println!("device {:?}\n\n", device.desc);

    // now you can create a Capture with this Device if you want.
        // see example/easylisten.rs for how
    }

    // 使用 device_use
    if let Some(device) = device_use {
        // 现在你可以使用这个设备创建一个 Capture
        // 例如：let capture = pcap::Capture::from_device(device).unwrap().open().unwrap();
        let mut cap = pcap::Capture::from_device(device)
            .unwrap()
            .immediate_mode(true)
            
            .open()
            .unwrap();

        cap.filter("tcp dst port 443 and src host 192.168.110.1 and dst host 192.168.110.130 and len >= 150", true)
            .unwrap();
        // println!("{:?}", cap.next_packet());
        while let Ok(packet) = cap.next_packet() {
            println!("got packet! {:?}", packet.header.caplen);
            let payload = &packet.data[..packet.header.caplen as usize];
            // 打印十六进制, 每一个字节空一个空格，每16个字节换一行
            let hex_str = hex::encode(payload);
            let mut lines = hex_str.as_bytes().chunks(2).map(|chunk| chunk.to_vec()).collect::<Vec<Vec<u8>>>();
            for line in lines.iter_mut() {
                line.push(b' ');
            }
            // 打印
            println!("payload: {:?}\n\n", String::from_utf8(lines.concat()).unwrap());
            // println!("payload: {:?}\n\n", String::from_utf8(hex_str.as_bytes()).unwrap());
        }
        // get 10 packets
        // for _ in 0..10 {
        //     cap.next_packet().ok();
        // }
        // let stats = cap.stats().unwrap();
        // println!(
        //     "Received: {}, dropped: {}, if_dropped: {}",
        //     stats.received, stats.dropped, stats.if_dropped
        // );
    }


    
    // get the default Device
    // let device = pcap::Device::lookup()
    //     .expect("device lookup failed")
    //     .expect("no device available");
    // println!("Using device {}", device.name);

    // // // Setup Capture
    // let mut cap = pcap::Capture::from_device(device)
    //     .unwrap()
    //     .immediate_mode(true)
    //     .open()
    //     .unwrap();

    // // get a packet and print its bytes
    // println!("{:?}", cap.next_packet());
}
use futures::executor::block_on;
use futures::future::join_all;
use futures::FutureExt;
use icmpv6_ping::*;
use std::net::IpAddr;
use std::sync::Arc;
use std::thread;
use std::time::Duration;

const PING_OPTS: PingOptions = PingOptions {
    ttl: 128,
    dont_fragment: true,
};

fn main() {
    let data = [8; 8];
    let addrs_target = "fe80::e04f:37ff:feda:b50d".parse().unwrap();
    // sync_ping(&addrs, &data);
    let status = test_target_address(&addrs_target, Arc::new(&data));
    match status {
        0 => println!("Network is good"),
        1 => println!("Network needs attention"),
        2 => println!("Network needs immediate attention"),
        _ => unreachable!(),
    }
    // async_ping(&addrs, Arc::new(&data));
    single_sync_ping(&addrs_target, Arc::new(&data));

    println!("Done.");
}

const TIMEOUT: Duration = Duration::from_secs(5);

fn single_sync_ping(addr: &IpAddr, data: Arc<&[u8]>) {
    println!("Single sync ping");
    let result = send_ping(addr, TIMEOUT, &data, Some(&PING_OPTS));
    println!("Result = {:?}", result);
}

fn sync_ping(addrs: &[IpAddr], data: &[u8]) {
    println!("Sync ping");
    for i in 0..addrs.len() {
        let result = send_ping(&addrs[i], TIMEOUT, &data, Some(&PING_OPTS));

        println!("{} > Result = {:?}", i + 1, result);
    }
}

fn async_ping(addrs: &[IpAddr], data: Arc<&[u8]>) {
    println!("Async ping");

    let tasks = (0..addrs.len()).map(|i| {
        let d = data.clone();
        thread::sleep(Duration::from_millis(30));
        async move {
            (
                i,
                send_ping_async(&addrs[i], TIMEOUT, d, Some(&PING_OPTS)).await,
            )
        }
    });
    let x = join_all(tasks);
    block_on(x.then(
        |result: Vec<(usize, std::result::Result<PingReply, PingError>)>| async move {
            for i in result {
                println!("{} > Result = {:?}", i.0, i.1);
            }
        },
    ));
}

fn test_target_address(addr: &IpAddr, data: Arc<&[u8]>) -> i32 {
    println!("Testing target address: {}", addr);

    let mut results = Vec::new();

    // Perform 5 pings
    for i in 0..5 {
        thread::sleep(Duration::from_millis(30));
        let result: std::result::Result<PingReply, PingError> = send_ping(addr, TIMEOUT, &data, Some(&PING_OPTS));
        results.push((i, result.clone()));
        println!("{} > Result = {:?}", i + 1, result);
    }

    // Count failed pings
    let failed_count = results.iter().filter(|(_, result)| result.is_err()).count();

    // Calculate loss rate
    let loss_rate = (failed_count as f64 / 5.0) * 100.0;
    println!("Ping loss rate: {:.1}%", loss_rate);

    // Return status code based on loss rate
    if loss_rate > 50.0 {
        println!("Network condition: Poor (>50% loss)");
        2
    } else if loss_rate > 20.0 {
        println!("Network condition: Fair (20-50% loss)");
        1
    } else {
        println!("Network condition: Good (<20% loss)");
        0
    }
}

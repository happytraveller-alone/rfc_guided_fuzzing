use std::collections::HashMap;
use std::error::Error;
use std::sync::{Arc, Mutex};
use tokio;

async fn modify_hashmap(map: Arc<Mutex<HashMap<usize, String>>>) -> Result<(), Box<dyn Error>> {
    // 使用 map_err 转换错误类型
    let mut guard = map.lock().map_err(|e| format!("Failed to lock mutex: {}", e))?;
    
    // 插入数据
    guard.insert(1, "test".to_string());
    
    Ok(())
}

#[test]
fn test_arc_mutex_persistence() -> Result<(), Box<dyn Error>> {
    // 创建共享状态
    let results: Arc<Mutex<HashMap<usize, String>>> = Arc::new(Mutex::new(HashMap::new()));
    
    // 创建运行时并执行异步任务
    let runtime = tokio::runtime::Runtime::new()?;
    runtime.block_on(async {
        modify_hashmap(results.clone()).await
    })?;
    
    // 验证修改是否保持
    let guard = results.lock().map_err(|e| format!("Failed to lock mutex for verification: {}", e))?;
    assert_eq!(guard.get(&1), Some(&"test".to_string()));
    
    Ok(())
}
use pyo3::prelude::*;
use std::{thread, time::Duration};
struct PoeApiWrapper {
    client: PyObject,
}

impl PoeApiWrapper {
    fn new() -> PyResult<Self> {
        Python::with_gil(|py| {
            let poe = py.import_bound("poe_api_wrapper")?;
            let tokens = [
                ("p-b", "QiZtBLjGecaQJ4-iJPIPgA%3D%3D"),
                ("p-lat", "GjrFu%2FMp5qLJ5wfDzXIZyCjiDQiPPmYDzqEOxU80kg%3D%3D"),
            ]
            .into_py(py);
            
            let client = poe.getattr("PoeApi")?
                .call1((tokens, false))?;
            
            Ok(Self { client: client.into() })
        })
    }

    fn send_message(&self, bot_name: &str, prompt: &str, max_retries: u32) -> PyResult<String> {
        Python::with_gil(|py| {
            let mut retries = 0;
            let mut wait_time = 7;

            loop {
                match self.client.call_method1(
                    py,
                    "send_message",
                    (bot_name, prompt, 60),
                ) {
                    Ok(message) => {
                        let mut last_chunk = String::new();
                        for chunk in message.iter(py)? {
                            let chunk = chunk?;
                            let text = chunk.get_item(py, "text")?.extract::<String>()?;
                            last_chunk = text;
                        }
                        return Ok(last_chunk);
                    }
                    Err(e) => {
                        if retries >= max_retries {
                            return Err(e);
                        }
                        println!("Warning: Attempt {} failed. Error: {}", retries + 1, e);
                        thread::sleep(Duration::from_secs(wait_time));
                        wait_time *= 2;
                        retries += 1;
                    }
                }
            }
        })
    }
}
1. 安装rust，安装cmake
2. cargo test 查看代码是否有语法错误
3. cargo build 编译程序
4. cargo run -- --test_env 运行测试环境
5. cargo run -- --use_guide ： 使用说明
6. cargo run -- --check_parse_ch : 检查解析clienthello报文模板
7. cargo run -- --check_mutate_ch : 检查解析变异后的clienthello结构
8. cargo run -- --test_env --check_parse_sh : 检查解析server对变异后clienthello的反馈

> [!IMPORTANT]
> ALWAYS CHECK YOUR VIRTUAL MACHINE IP and SERVER NAME!!!

> [!TIP]
> 安装cmake环境，文件路径中不要有空格
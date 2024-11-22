# Agent Deployment

1. `semantic_analysis`: 根据语义进行文档的切割
    - `prompt/system_prompt_semantic_analysis.txt`
    - `semantic_analysis.py`

2. `rule_extraction`：根据文段，进行规则抽取，包括消息构造约束，和消息处理约束
    - `prompt/system_prompt_rule_extraction.txt`
    - `rule_extraction.py`

3. `violation_generation`：根据消息构造约束，构建测试策略，变异clienthello报文，给出预期消息反馈
    - `prompt/system_prompt_violation_generation.txt`
    - `violation_generation.py`

# Use Guide
1. `python agent_control.py -h`: 打印使用方法
2. `python agent_control.py --semantic_slice`: 部署语义分割agent 
3. `python agent_control.py --rule_extrac`: 部署规则抽取agent
4. `python agent_control.py --violation_gen`: 部署测试策略生成agent
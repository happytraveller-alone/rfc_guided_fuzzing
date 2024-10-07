# RFC Processor

RFC Processor 是一个用Rust编写的工具，用于下载、处理和分析RFC（Request for Comments）文档。该工具可以自动下载指定的RFC文档，对其内容进行处理，包括移除页眉页脚，提取主要内容，并将内容切分为不同的章节。此外，它还为每个章节生成提示词框架，便于进一步的分析和处理。

## 主要功能

1. **下载RFC文档**：根据提供的RFC编号，从官方RFC编辑器网站下载相应的文档。

2. **处理RFC内容**：
   - 移除页眉页脚和页面分隔符
   - 提取文档的主要内容部分
   - 处理连续的空行

3. **章节切分**：
   - 根据章节标题将文档内容切分为多个部分
   - 生成章节映射，包含章节编号和标题

4. **生成提示词框架**：为每个切分的章节生成提示词框架，便于后续处理和分析。

5. **保存处理结果**：
   - 保存预处理的内容
   - 保存最终处理后的内容
   - 为每个章节生成单独的文件

## 项目结构

- `main.rs`: 程序的入口点，处理命令行参数并协调整个处理流程。
- `lib.rs`: 定义了项目中使用的常量和静态变量。
- `download.rs`: 包含下载RFC文档和获取RFC标题的功能。
- `process.rs`: 负责处理RFC内容，包括移除页眉页脚和提取主要内容。
- `slice.rs`: 实现了将RFC内容切分为不同章节的功能。
- `utils.rs`: 包含各种辅助函数，如创建目录、保存内容等。

## 使用方法

1. 确保已安装Rust开发环境。

2. 克隆项目仓库：
    - git clone https://github.com/happytraveller-alone/RustDataProcess.git
    - cd rfc-processor

3. 编译项目：cargo build --release

4. 运行程序，指定RFC编号：cargo run -- [RFC编号]

例如：`cargo run 2675`

如果不提供RFC编号，程序将默认处理RFC 2675。

## 输出

程序会在项目根目录下创建 `input` 和 `output` 文件夹。处理后的文件将保存在 `output/RFC-[编号]` 目录中，包括：

- `pre_processed.txt`: 预处理后的RFC内容
- `[RFC编号]_processed.txt`: 最终处理后的RFC内容
- `sections.txt`: 章节映射信息
- `slice/`: 包含所有切分后的章节文件

## 依赖项目

- `reqwest`: 用于HTTP请求
- `regex`: 用于正则表达式处理
- `colored`: 用于控制台输出着色
- `lazy_static`: 用于延迟静态变量初始化

## 目标

- 基于GPT4o-mini构建的agent，形成从RFC文档到mutator的自动化生成流程。
  1. 完整语义切割（针对给定的文档片段进行完整语义的切割）
  2. 规则抽取（针对划分后的语义片段进行规则抽取）
  3. 规则违反生成（针对抽取后的规则进行规则违反指导生成）
  4. 变异算子生成（根据规则违反指导输出变异算子序列）

[![](https://mermaid.ink/img/pako:eNq1Vl1P21YY_iuWq0ognYQkDglxKyRCwofUbhKwC5Zw4djHiYVjR7ZTypJcdIogULogrYWuGwXadSA0oKo2pLWp-DMcG_5Fz0cghgoRJjVX57x-3ud5z_txciq8bCqQF3lVN-fkgmQ53IOJrMHhn13O5S2pVODO3tTRn3VvdYHZyU_RLCg7mmlwU8mOdSjTM_Vg0l1bdLff3s9ZgxMjwwPRaKx3hgsEBqvMfkFGAKeLe2h5F62sndZfuX_8XeWSGXerhVpNbCLfmctMRyFJmGxdk2Glcnq4f_LfEmosoKUPlMy3H8pDw6nVCJpLZdpfDlbcF_94r-odZm9p0T349-z3BbTa8KncUiCdcZffEcKjhvvkkCBPWnsnn956W0_cZvP0-L2P-u5dbphmYxra1f8R2oX_d2a1a2FoKFnjSlFPd-qo8Vt3dU1RRebhLn9GTVoc_56mo8qNZLxPv7qv67h87cOw8zHoV4cZ6ZZ39Ha8o4z3eAM1n3nPN93GKnXx7du8YxnGwD7R5K8sosPWV4xjhPGRZuoSSU7lRuqabyh-mPr-4fhwpgf9son2V1HzJWr97B2s4zUbjA5tF7w-4tv50U4dz_jlCRJ9bKLGevu8jPf6nvF2nmE39_kRxt_UM2l_bV9uoff1a2o7nUGf37CRZ91My0A7Gu2v4xnwPv7lbmz6itGtRycAZqhOwWIJpwyPttvcdpee-rx3t92NY5YwnKuO1mQ6nSKlW0DND_huo1ifby8VQY0NtPOUZafKdavSEek6LlpEexbq0DGNngy5bKnD_eTEIHM629t1Xx_N9F5fRNYBDM2IbyrlOBcIklNSRxKVt7_mvXhX5VTNkHR_GKShfPTnYVD9dtS0La52IZs6Zq1S1krlEivjYwB_5m7GEj0L2mXdGbw-Tl-2yELWJdtOQZUrWaYMbRvL6Lp4R02owHYscxaKdwRBaK8Dc5riFMRI6TGQTd20xJwuybNANQ0nMAe1fMERc6auMIMPce-KlmaUyk5bKZf7lkpm2fFJqblvJMUNATI9oH0BAlYFds5LuCRIgTQYAaNgDIyDaXDeKuA8_5fQtOTgfGTAxS0I6L92-3D3eMAXoVWUNAW_bSrEP8s7BViEWV7ES0WyZrN81qhhnFR2zMl5Q-ZFxypDwFtmOV_gRVXSbbwrlxQsk9IkPD3FC2tJMn40zeK5CwOlFc0xrQuMbkoKxNsK78yXyBMrr9kO1pNNQ9XyxF62dGwuOE7JFvv6yOdgXnMK5VxQNot9tqaQ91jhUSLWF4vEBqSIAGNxQeoXBEXOhRMDaiQaVpV4KByR-FoN8JDqP2TvOfqso4ESpce8GBhIBCOJeDQSSkRjQjQkhAE_z4vhcDyYiAihSCKc6A8JeImZfqJnCweFUDzcn-iPCiEhHg1HY7Uvtqx9NA?type=png)](https://mermaid.live/edit#pako:eNq1Vl1P21YY_iuWq0ognYQkDglxKyRCwofUbhKwC5Zw4djHiYVjR7ZTypJcdIogULogrYWuGwXadSA0oKo2pLWp-DMcG_5Fz0cghgoRJjVX57x-3ud5z_txciq8bCqQF3lVN-fkgmQ53IOJrMHhn13O5S2pVODO3tTRn3VvdYHZyU_RLCg7mmlwU8mOdSjTM_Vg0l1bdLff3s9ZgxMjwwPRaKx3hgsEBqvMfkFGAKeLe2h5F62sndZfuX_8XeWSGXerhVpNbCLfmctMRyFJmGxdk2Glcnq4f_LfEmosoKUPlMy3H8pDw6nVCJpLZdpfDlbcF_94r-odZm9p0T349-z3BbTa8KncUiCdcZffEcKjhvvkkCBPWnsnn956W0_cZvP0-L2P-u5dbphmYxra1f8R2oX_d2a1a2FoKFnjSlFPd-qo8Vt3dU1RRebhLn9GTVoc_56mo8qNZLxPv7qv67h87cOw8zHoV4cZ6ZZ39Ha8o4z3eAM1n3nPN93GKnXx7du8YxnGwD7R5K8sosPWV4xjhPGRZuoSSU7lRuqabyh-mPr-4fhwpgf9son2V1HzJWr97B2s4zUbjA5tF7w-4tv50U4dz_jlCRJ9bKLGevu8jPf6nvF2nmE39_kRxt_UM2l_bV9uoff1a2o7nUGf37CRZ91My0A7Gu2v4xnwPv7lbmz6itGtRycAZqhOwWIJpwyPttvcdpee-rx3t92NY5YwnKuO1mQ6nSKlW0DND_huo1ifby8VQY0NtPOUZafKdavSEek6LlpEexbq0DGNngy5bKnD_eTEIHM629t1Xx_N9F5fRNYBDM2IbyrlOBcIklNSRxKVt7_mvXhX5VTNkHR_GKShfPTnYVD9dtS0La52IZs6Zq1S1krlEivjYwB_5m7GEj0L2mXdGbw-Tl-2yELWJdtOQZUrWaYMbRvL6Lp4R02owHYscxaKdwRBaK8Dc5riFMRI6TGQTd20xJwuybNANQ0nMAe1fMERc6auMIMPce-KlmaUyk5bKZf7lkpm2fFJqblvJMUNATI9oH0BAlYFds5LuCRIgTQYAaNgDIyDaXDeKuA8_5fQtOTgfGTAxS0I6L92-3D3eMAXoVWUNAW_bSrEP8s7BViEWV7ES0WyZrN81qhhnFR2zMl5Q-ZFxypDwFtmOV_gRVXSbbwrlxQsk9IkPD3FC2tJMn40zeK5CwOlFc0xrQuMbkoKxNsK78yXyBMrr9kO1pNNQ9XyxF62dGwuOE7JFvv6yOdgXnMK5VxQNot9tqaQ91jhUSLWF4vEBqSIAGNxQeoXBEXOhRMDaiQaVpV4KByR-FoN8JDqP2TvOfqso4ESpce8GBhIBCOJeDQSSkRjQjQkhAE_z4vhcDyYiAihSCKc6A8JeImZfqJnCweFUDzcn-iPCiEhHg1HY7Uvtqx9NA)
## 注意事项

- 确保有稳定的网络连接以下载RFC文档。
- 程序会自动处理已下载的RFC文档，避免重复下载。
- 对于非常长的RFC文档，处理时间可能会较长。

## 贡献

欢迎提交问题报告和改进建议。如果您想贡献代码，请先开启一个问题讨论您的想法。

## 许可证

MIT License

## 作者

yuanfeng xie

## 版本历史

- 1.0.0 (2024/07/29): 初始版本发布
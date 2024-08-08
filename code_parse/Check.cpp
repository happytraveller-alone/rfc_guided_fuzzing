#include <iostream>
#include <fstream>
#include <antlr4-runtime.h>
#include "grammar/CLexer.h"
#include "grammar/CParser.h"

using namespace antlr4;

int main() {
    // 设置输入文件路径
    std::string inputFile = "input/test.c";
    
    // 打开输入文件
    std::ifstream stream(inputFile);
    if (!stream.is_open()) {
        std::cerr << "无法打开文件: " << inputFile << std::endl;
        return 1;
    }

    // 创建输入流
    ANTLRInputStream input(stream);

    // 创建词法分析器
    CLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    // 创建语法分析器
    CParser parser(&tokens);

    // 解析编译单元
    tree::ParseTree *tree = parser.compilationUnit();

    // 打印语法树
    std::cout << "语法树:" << std::endl;
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}
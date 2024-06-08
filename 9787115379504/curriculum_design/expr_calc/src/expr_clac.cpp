#include <iostream>
#include <string>
#include "expr_calc_by_recursion.h"

int main() {
    std::cout << "请输入表达式：";
    std::string str = {};
    std::cin >> str;
    std::cout << str << "=" << ExprCalcByRecursion(str) << std::endl;
    return 0;
}
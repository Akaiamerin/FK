#include <iostream>
#include <stack>
#include "expr_calc_by_recursion.h"

//字符串转数字并获取该数字之后的第一个运算符下标
void GetNum(std::string str, int & num, int & symbol_index) {
    std::string num_str = {};
    int str_index = 0;
    while (str_index < str.size() && str[str_index] >= '0' && str[str_index] <= '9') {
        num_str += str[str_index];
        str_index++;
    }
    num = std::stoi(num_str);
    symbol_index = str_index;
}

//获取右括号下标
int GetRigthBracketIndex(std::string str) {
    std::stack<char> stk = {};
    stk.push('(');
    for (int i = 1; i < str.size(); i++) {
        if (stk.empty() == false) {
            if (str[i] == '(') {
                stk.push('(');
            }
            if (str[i] == ')') {
                stk.pop();
                if (stk.empty() == true) {
                    return i;
                }
            }
        }
    }
    return -1;
}

//表达式计算(递归)
int ExprCalcByRecursion(std::string str) {
    int sign = 1;
    //第一个字符为负号
    if (str[0] == '-') {
        sign = -1;
        str.erase(0, 1);
    }
    //第一个字符为括号
    if (str[0] == '(') {
        int right_bracket_index = GetRigthBracketIndex(str);
        if (right_bracket_index == -1) {
            std::cout << "表达式错误" << std::endl;
            return NULL;
        }
        else {
            int left_num = sign * ExprCalcByRecursion(str.substr(1, right_bracket_index - 1)); //计算括号内的值
            if (right_bracket_index == str.size() - 1) {
                return left_num; //右括号为最后字符，直接返回结果
            }
            else {
                std::string left_str = std::to_string(left_num); //左边已计算出的值
                std::string right_str = str.substr(right_bracket_index + 1, str.size()); //剩余的表达式
                return ExprCalcByRecursion(left_str + right_str);
            }
        }
    }
    int temp_right_bracket_index = -1;
    int temp_num = 0;
    int temp_symbol_index = -1;
    //第一个字符为数字
    if (str[0] >= '0' && str[0] <= '9') {
        int num = 0;
        int symbol_index = -1;
        GetNum(str, num, symbol_index);
        num = sign * num;
        if (symbol_index == str.size()) {
            return num; //当前表达式仅有一个数字
        }
        if (str[symbol_index] == '+') {
            return num + ExprCalcByRecursion(str.substr(symbol_index + 1, str.size()));
        }
        else if (str[symbol_index] == '-') {
            return num + ExprCalcByRecursion(str.substr(symbol_index, str.size()));
        }
        else if (str[symbol_index] == '*') {
            if (str[symbol_index + 1] == '(') {
                temp_right_bracket_index = GetRigthBracketIndex(str.substr(symbol_index + 1, str.size()));
                std::string left_str = std::to_string(num * ExprCalcByRecursion(str.substr(symbol_index + 2, temp_right_bracket_index - 1)));
                std::string right_str = str.substr(symbol_index + 2 + temp_right_bracket_index, str.size());
                return ExprCalcByRecursion(left_str + right_str);
            }
            else {
                GetNum(str.substr(symbol_index + 1, str.size()), temp_num, temp_symbol_index);
                if (temp_symbol_index == str.substr(symbol_index + 1).size()) {
                    return num * temp_num;
                }
                else {
                    std::string left_str = std::to_string(num * temp_num);
                    std::string right_str = str.substr(symbol_index + 1 + temp_symbol_index, str.size());
                    return ExprCalcByRecursion(left_str + right_str);
                }
            }
        }
        else if (str[symbol_index] == '/') {
            if (str[symbol_index + 1] == '(') {
                temp_right_bracket_index = GetRigthBracketIndex(str.substr(symbol_index + 1, str.size()));
                if (ExprCalcByRecursion(str.substr(symbol_index + 2, temp_right_bracket_index - 1)) == 0) {
                    std::cout << "表达式错误" << std::endl;
                    return NULL;
                }
                std::string left_str = std::to_string(num / ExprCalcByRecursion(str.substr(symbol_index + 2, temp_right_bracket_index - 1)));
                std::string right_str = str.substr(symbol_index + 2 + temp_right_bracket_index, str.size());
                return ExprCalcByRecursion(left_str + right_str);
            }
            else {
                GetNum(str.substr(symbol_index + 1, str.size()), temp_num, temp_symbol_index);
                if (temp_num == 0) {
                    std::cout << "表达式错误" << std::endl;
                    return NULL;
                }
                if (temp_symbol_index == str.substr(symbol_index + 1).size()) {
                    return num / temp_num;
                }
                else {
                    std::string left_str = std::to_string(num / temp_num);
                    std::string right_str = str.substr(symbol_index + 1 + temp_symbol_index, str.size());
                    return ExprCalcByRecursion(left_str + right_str);
                }
            }
        }
        else {
            std::cout << "表达式错误" << std::endl;
            return NULL;
        }
    }
    return NULL;
}
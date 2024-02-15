#pragma once

#include <string>

//字符串转数字并获取该数字之后的第一个运算符下标
void GetNum(std::string str, int & num, int & symbol_index);

//获取右括号下标
int GetRigthBracketIndex(std::string str);

//表达式计算(递归)
int ExprCalcByRecursion(std::string str);
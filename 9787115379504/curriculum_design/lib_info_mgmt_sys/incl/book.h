#pragma once

#include <string>

struct Book {
    std::string title; //书名
    std::string author; //作者
    std::string press; //出版社
    unsigned int price; //定价
    unsigned long long ISBN; //ISBN号
};

//输出图书信息
void OutputBook(Book book);
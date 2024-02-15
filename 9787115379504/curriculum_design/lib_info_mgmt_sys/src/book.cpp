#include <iostream>
#include "book.h"

//输出图书信息
void OutputBook(Book book) {
    std::cout << book.title << " | " << book.author << " | " << book.press << " | " << book.price << " | " << book.ISBN << std::endl;
}
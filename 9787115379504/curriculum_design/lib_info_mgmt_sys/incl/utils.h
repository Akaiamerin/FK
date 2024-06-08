#pragma once

#include <string>
#include "book.h"

//读取文件
void ReadFile(std::string read_path, Book book_arr[], int book_arr_size, int & book_num);

//写入文件
void WriteFile(std::string write_path, Book book_arr[], int book_arr_size, int book_num);
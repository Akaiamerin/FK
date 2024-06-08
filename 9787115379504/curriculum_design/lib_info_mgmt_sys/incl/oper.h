#pragma once

#include "book.h"

//添加图书
bool InsBook(Book book_arr[], int book_arr_size, int & book_num);

//删除图书
bool DelBook(Book book_arr[], int book_arr_size, int & book_num);

//修改图书
bool AltBook(Book book_arr[], int book_arr_size, int book_num);

//查询图书
int SrchBook(Book book_arr[], int book_arr_size, int book_num);

//统计图书
void CntBook(Book book_arr[], int book_arr_size, int book_num);
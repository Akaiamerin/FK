#include <iostream>
#include "menu.h"
#include "book.h"
#include "utils.h"
#include "oper.h"

//菜单
void Menu() {
    int book_num = 0; //当前书的数量
    int book_arr_size = 100; //保存书的最大数量
    Book book_arr[book_arr_size] = {}; //将文件中图书信息存入数组
    ReadFile(FILE_PATH, book_arr, book_arr_size, book_num);
    while (true) {
        std::cout << "+——————————————————————+" << std::endl;
        std::cout << "|   图书信息管理系统   |" << std::endl;
        std::cout << "|1. 添加图书           |" << std::endl;
        std::cout << "|2. 删除图书           |" << std::endl;
        std::cout << "|3. 修改图书           |" << std::endl;
        std::cout << "|4. 查询图书           |" << std::endl;
        std::cout << "|5. 统计图书           |" << std::endl;
        std::cout << "|6. 退出               |" << std::endl;
        std::cout << "+——————————————————————+" << std::endl;
        int opt = 0;
        std::cin >> opt;
        if (opt == 1) {
            system("cls");
            if (InsBook(book_arr, book_arr_size, book_num) == true) {
                std::cout << "添加图书成功" << std::endl;
            }
            else {
                std::cout << "添加图书失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 2) {
            system("cls");
            if (DelBook(book_arr, book_arr_size, book_num) == true) {
                std::cout << "删除图书成功" << std::endl;
            }
            else {
                std::cout << "删除图书失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 3) {
            system("cls");
            if (AltBook(book_arr, book_arr_size, book_num) == true) {
                std::cout << "修改图书成功" << std::endl;
            }
            else {
                std::cout << "修改图书失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 4) {
            system("cls");
            int index = SrchBook(book_arr, book_arr_size, book_num);
            if (index > -1 && index < book_num) {
                OutputBook(book_arr[index]);
            }
            else {
                std::cout << "查询图书失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 5) {
            system("cls");
            CntBook(book_arr, book_arr_size, book_num);
            std::cout << "图书数量：" << book_num << std::endl;
            system("pause");
            system("cls");
        }
        else if (opt == 6) {
            system("cls");
            break;
        }
        else {
            system("cls");
            std::cin.clear();
            std::cin.sync();
        }
        WriteFile(FILE_PATH, book_arr, book_arr_size, book_num);
    }
}
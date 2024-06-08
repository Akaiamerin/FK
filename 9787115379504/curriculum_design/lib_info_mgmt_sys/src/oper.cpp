#include <iostream>
#include <string>
#include "oper.h"

//添加图书
bool InsBook(Book book_arr[], int book_arr_size, int & book_num) {
    if (book_num >= book_arr_size) {
        return false;
    }
    CntBook(book_arr, book_arr_size, book_num);
    Book book = {};
    std::cout << "请输入要添加的图书信息" << std::endl;
    std::cout << "请输入图书名称：";
    std::cin >> book.title;
    std::cout << "请输入图书作者：";
    std::cin >> book.author;
    std::cout << "请输入图书出版社：";
    std::cin >> book.press;
    std::cout << "请输入图书定价：";
    std::cin >> book.price;
    std::cout << "请输入图书 ISBN 号：";
    std::cin >> book.ISBN;
    book_arr[book_num++] = book;
    return true;
}

//删除图书
bool DelBook(Book book_arr[], int book_arr_size, int & book_num) {
    if (book_num >= book_arr_size) {
        return false;
    }
    CntBook(book_arr, book_arr_size, book_num);
    std::cout << "请输入要删除的图书名称：";
    std::string str = {};
    std::cin >> str;
    int index = -1;
    for (int i = 0; i < book_num; i++) {
        if (book_arr[i].title == str) {
            index = i;
        }
    }
    if (index == -1) {
        return false;
    }
    for (int i = index; i < book_num - 1; i++) {
        book_arr[i] = book_arr[i + 1];
    }
    book_num--;
    return true;
}

//修改图书
bool AltBook(Book book_arr[], int book_arr_size, int book_num) {
    CntBook(book_arr, book_arr_size, book_num);
    std::cout << "请输入要修改的图书名称：";
    std::string str = {};
    std::cin >> str;
    int index = -1;
    for (int i = 0; i < book_num; i++) {
        if (book_arr[i].title == str) {
            index = i;
        }
    }
    if (index == -1) {
        return false;
    }
    std::cout << "1. 修改图书名称" << std::endl;
    std::cout << "2. 修改图书作者" << std::endl;
    std::cout << "3. 修改图书出版社" << std::endl;
    std::cout << "4. 修改图书定价" << std::endl;
    std::cout << "5. 修改图书 ISBN 号" << std::endl;
    int opt = 0;
    std::cin >> opt;
    if (opt == 1) {
        std::cout << "请输入新的图书名称：";
        std::cin >> book_arr[index].title;
    }
    else if (opt == 2) {
        std::cout << "请输入新的图书作者：";
        std::cin >> book_arr[index].author;
    }
    else if (opt == 3) {
        std::cout << "请输入新的图书出版社：";
        std::cin >> book_arr[index].press;
    }
    else if (opt == 4) {
        std::cout << "请输入新的图书定价：";
        std::cin >> book_arr[index].price;
    }
    else if (opt == 5) {
        std::cout << "请输入新的图书 ISBN 号：";
        std::cin >> book_arr[index].ISBN;
    }
    else {
        return false;
    }
    return true;
}

//查询图书
int SrchBook(Book book_arr[], int book_arr_size, int book_num) {
    int ret = -1;
    if (book_num >= book_arr_size) {
        return ret;
    }
    CntBook(book_arr, book_arr_size, book_num);
    std::cout << "1. 查询图书名称" << std::endl;
    std::cout << "2. 查询图书作者" << std::endl;
    std::cout << "3. 查询图书出版社" << std::endl;
    std::cout << "4. 查询图书定价" << std::endl;
    std::cout << "5. 查询图书 ISBN 号" << std::endl;
    int opt = 0;
    std::cin >> opt;
    if (opt == 1) {
        std::cout << "请输入待查询的图书名称：";
        std::string title = {};
        std::cin >> title;
        for (int i = 0; i < book_num; i++) {
            if (book_arr[i].title == title) {
                ret = i;
            }
        }
    }
    else if (opt == 2) {
        std::cout << "请输入待查询的图书作者：";
        std::string author = {};
        std::cin >> author;
        for (int i = 0; i < book_num; i++) {
            if (book_arr[i].author == author) {
                ret = i;
            }
        }
    }
    else if (opt == 3) {
        std::cout << "请输入待查询的图书出版社：";
        std::string press = {};
        std::cin >> press;
        for (int i = 0; i < book_num; i++) {
            if (book_arr[i].press == press) {
                ret = i;
            }
        }
    }
    else if (opt == 4) {
        std::cout << "请输入待查询的图书定价：";
        int price = 0;
        std::cin >> price;
        for (int i = 0; i < book_num; i++) {
            if (book_arr[i].price == price) {
                ret = i;
            }
        }
    }
    else if (opt == 5) {
        std::cout << "请输入待查询的图书 ISBN 号：";
        int ISBN = 0;
        std::cin >> ISBN;
        for (int i = 0; i < book_num; i++) {
            if (book_arr[i].ISBN == ISBN) {
                ret = i;
            }
        }
    }
    return ret;
}

//统计图书
void CntBook(Book book_arr[], int book_arr_size, int book_num) {
    if (book_num >= book_arr_size) {
        return;
    }
    std::cout << "书名 | 出版社 | 定价 | ISBN" << std::endl;
    for (int i = 0; i < book_num; i++) {
        OutputBook(book_arr[i]);
    }
}
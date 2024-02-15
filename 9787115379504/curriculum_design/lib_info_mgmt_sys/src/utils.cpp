#include <fstream>
#include <string>
#include "utils.h"

//读取文件
void ReadFile(std::string read_path, Book book_arr[], int book_arr_size, int & book_num) {
    std::ifstream ifs(read_path);
    if (ifs.is_open() == false) {
        return;
    }
    for (int i = 0; i < book_arr_size; i++) {
        if (ifs.eof() == false) {
            Book book = {};
            ifs >> book.title >> book.author >> book.press >> book.price >> book.ISBN;
            book_arr[i] = book;
        }
        else {
            book_num = i;
            break;
        }
    }
    ifs.close();
}

//写入文件
void WriteFile(std::string write_path, Book book_arr[], int book_arr_size, int book_num) {
    std::ofstream ofs(write_path);
    if (ofs.is_open() == false) {
        return;
    }
    for (int i = 0; i < book_num; i++) {
        if (i >= book_arr_size - 1) {
            break;
        }
        std::string str = {};
        str += book_arr[i].title + " " + book_arr[i].author + " " + book_arr[i].press + " " + std::to_string(book_arr[i].price) + " " + std::to_string(book_arr[i].ISBN);
        ofs << str << std::endl;
    }
    ofs.close();
}
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "menu.h"
#include "utils.h"
#include "hash_table.h"

//创建通讯录
void CrtAddressList(HashTable & hash_table, std::vector<std::string> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i < hash_table.cap) {
            Record record = {};
            std::istringstream iss(vec[i]);
            iss >> record.name >> record.address >> record.tel_num;
            iss.clear();
            InsRecord(hash_table, record);
        }
    }
}

//获取通讯录信息
std::vector<std::string> GetAddressListInfo(HashTable hash_table) {
    std::vector<std::string> vec = {};
    for (int i = 0; i < hash_table.cap; i++) {
        if (hash_table.record[i].name.size() > 0) {
            vec.push_back(hash_table.record[i].name + " " + hash_table.record[i].address + " " + std::to_string(hash_table.record[i].tel_num));
        }
    }
    return vec;
}

//菜单
void Menu() {
    std::vector<std::string> read_vec = {};
    ReadFile(FILE_PATH, read_vec);
    HashTable hash_table = InitHashTable(hash_table, 100);
    CrtAddressList(hash_table, read_vec);
    while (true) {
        std::cout << "+—————————————————+" << std::endl;
        std::cout << "|1. 通讯录        |" << std::endl;
        std::cout << "|2. 查询信息      |" << std::endl;
        std::cout << "|3. 退出          |" << std::endl;
        std::cout << "+—————————————————+" << std::endl;
        int opt = 0;
        std::cin >> opt;
        if (opt == 1) {
            system("cls");
            for (int i = 0; i < hash_table.cap; i++) {
                Record record = hash_table.record[i];
                if (record.name.size() > 0) {
                    std::cout << "index: " << i << " | ";
                    OuputRecord(hash_table.record[i]);
                }
            }
            system("pause");
            system("cls");
        }
        else if (opt == 2) {
            system("cls");
            std::cout << "请输入待查找的用户名：";
            std::string name = {};
            std::cin >> name;
            int index = SrchRecord(hash_table, name);
            if (hash_table.record[index].name.size() == 0) {
                std::cout << "查找失败" << std::endl;
            }
            else {
                OuputRecord(hash_table.record[index]);
            }
            system("pause");
            system("cls");
        }
        else if (opt == 3) {
            system("cls");
            break;
        }
        else {
            system("cls");
            std::cin.clear();
            std::cin.sync();
        }
        std::vector<std::string> write_vec = GetAddressListInfo(hash_table);
        WriteFile(FILE_PATH, write_vec);
    }
}
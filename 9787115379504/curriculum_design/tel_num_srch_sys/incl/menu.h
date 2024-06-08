#pragma once

#include <vector>
#include <string>
#include "hash_table.h"

#define FILE_PATH ".\\test\\address_list.txt"

//创建通讯录
void CrtAddressList(HashTable & hash_table, std::vector<std::string> vec);

//获取通讯录信息
std::vector<std::string> GetAddressListInfo(HashTable hash_table);

//菜单
void Menu();
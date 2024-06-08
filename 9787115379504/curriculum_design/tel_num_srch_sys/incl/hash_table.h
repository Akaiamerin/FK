#pragma once

#include <string>

struct Record {
    std::string name; //用户名
    std::string address; //地址
    unsigned long long tel_num; //电话号码

};

struct HashTable {
    Record * record; //记录数组
    int size; //记录数量
    int cap; //容量
};

//输出记录
void OuputRecord(Record record);

//初始化
HashTable InitHashTable(HashTable hash_table, int cap = 100);

//哈希函数
int HashFunc(std::string str);

//增加记录的二次探测法解决冲突
int InsRecordBySecondDetect(HashTable hash_table, int first_index, int & cnt);

//增加记录
void InsRecord(HashTable & hash_table, Record record);

//查找记录的二次探测法解决冲突
int SrchRecordRecordBySecondDetect(HashTable hash_table, int first_index, std::string name, int & cnt);

//查找记录
int SrchRecord(HashTable hash_table, std::string name);
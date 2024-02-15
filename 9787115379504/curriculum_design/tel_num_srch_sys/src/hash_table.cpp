#include <iostream>
#include "hash_table.h"

//输出记录
void OuputRecord(Record record) {
    std::cout << record.name << " | " << record.address << " | " << record.tel_num << std::endl;
}

//初始化
HashTable InitHashTable(HashTable hash_table, int cap) {
    hash_table = {new Record[cap], 0, cap};
    return hash_table;
}

//哈希函数
int HashFunc(std::string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += str[i];
    }
    return sum % 97;
}

//增加记录的二次探测法解决冲突
int InsRecordBySecondDetect(HashTable hash_table, int first_index, int & cnt) {
    int ret = 0;
    for (int i = 1; i <= hash_table.cap / 2; i++) {
        int second_index1 = (first_index + i * i) % hash_table.cap;
        if ((cnt & 1) == 0) {
            if (second_index1 > 0 && second_index1 < hash_table.cap) {
                if (hash_table.record[second_index1].name.size() == 0) {
                    ret = second_index1;
                    cnt++;
                    break;
                }
            }
        }
        else {
            int second_index2 = (first_index - i * i) % hash_table.cap;
            if (second_index2 > 0 && second_index2 < hash_table.cap) {
                if (hash_table.record[second_index2].name.size() == 0) {
                    ret = second_index2;
                    cnt++;
                    break;
                }
            }
        }
    }
    return ret;
}

//增加记录
void InsRecord(HashTable & hash_table, Record record) {
    if (hash_table.size >= hash_table.cap) {
        return;
    }
    int index = HashFunc(record.name);
    if (hash_table.record[index].name.size() == 0) {
        hash_table.record[index] = record;
        hash_table.size++;
    }
    else {
        int cnt = 0;
        int second_index = InsRecordBySecondDetect(hash_table, index, cnt);
        hash_table.record[second_index] = record;
        hash_table.size++;
    }
}

//查找记录的二次探测法解决冲突
int SrchRecordRecordBySecondDetect(HashTable hash_table, int first_index, std::string name, int & cnt) {
    int ret = 0;
    for (int i = 1; i <= hash_table.cap / 2; i++) {
        int second_index1 = (first_index + i * i) % hash_table.cap;
        if ((cnt & 1) == 0) {
            if (second_index1 > 0 && second_index1 < hash_table.cap) {
                if (hash_table.record[second_index1].name == name) {
                    ret = second_index1;
                    cnt++;
                    break;
                }
            }
        }
        else {
            int second_index2 = (first_index - i * i) % hash_table.cap;
            if (second_index2 > 0 && second_index2 < hash_table.cap) {
                if (hash_table.record[second_index2].name == name) {
                    ret = second_index2;
                    cnt++;
                    break;
                }
            }
        }
    }
    return ret;
}

//查找记录
int SrchRecord(HashTable hash_table, std::string name) {
    int ret = -1;
    int index = HashFunc(name);
    if (hash_table.record[index].name == name) {
        ret = index;
    }
    else {
        int cnt = 0;
        int second_index = SrchRecordRecordBySecondDetect(hash_table, index, name, cnt);
        ret = second_index;
    }
    return ret;
}
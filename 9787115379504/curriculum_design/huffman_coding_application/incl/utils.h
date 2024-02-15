#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "coding.h"

//读取文件内容
void ReadFile(std::string file_path, std::vector<std::string> & vec);

//统计文件字符总数
int CntFileChNum(std::vector<std::string> vec);

//初始化统计字符表
std::vector<std::vector<int>> InitCntVec(int size);

//统计有效字符出现频率
void CntChFreq(std::vector<std::string> content, std::vector<std::vector<int>> & cnt_vec);

//统计有效字符数
int CntChNum(std::vector<std::vector<int>> cnt_vec);

//输出相关信息
void OutputInfo(std::unordered_map<int, std::string> node_val_ump, std::vector<ValCode> huffman_coding, std::vector<std::vector<int>> cnt_vec, Node * huffman_tree, int ch_num);
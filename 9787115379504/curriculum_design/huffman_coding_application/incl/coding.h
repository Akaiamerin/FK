#pragma once

#include <vector>
#include <string>
#include "huffman_tree.h"

struct ValCode {
    int val; //字符映射
    std::string code; //字符映射对应的哈夫曼码
};

//生成哈夫曼码
void HuffmanCoding(std::vector<ValCode> & huffman_coding, Node * huffman_tree, int ch_num);

//编码文件内容
void EncodeFile(std::string encode_path, std::vector<ValCode> huffman_coding, std::vector<std::string> vec);

//译码文件内容
void DecodeFile(std::string encode_path, std::string decode_path, Node * huffman_tree, int node_num);
#include <fstream>
#include "coding.h"
#include "utils.h"
#include "huffman_tree.h"

//生成哈夫曼码
void CodingHuffmanCode(std::vector<ValCode> & huffman_coding, Node * huffman_tree, int ch_num) {
    int cur = -1; //当前节点下标
    int cur_parent = -1; //当前节点的双亲下标
    for (int i = 0; i < ch_num; i++) {
        cur = i;
        cur_parent = huffman_tree[i].parent;
        std::string code = {};
        //从叶子节点往上找到根节点
        while (cur_parent != -1) {
            if (huffman_tree[cur_parent].left == cur) {
                code.insert(code.begin(), '0');
            }
            else if (huffman_tree[cur_parent].right == cur) {
                code.insert(code.begin(), '1');
            }
            cur = cur_parent; //更新当前节点下标
            cur_parent = huffman_tree[cur_parent].parent; //更新当前节点的双亲下标
        }
        ValCode val_code = {huffman_tree[i].val, code};
        huffman_coding.push_back(val_code);
    }
}

//编码文件内容
void EncodeFile(std::string encode_path, std::vector<ValCode> huffman_coding, std::vector<std::string> vec) {
    std::ofstream ofs(encode_path);
    for (int i = 0; i < vec.size(); i++) {
        std::string str = {};
        for (int j = 0; j < vec[i].size(); j++) {
            int val = 0;
            //换行符特殊处理
            if (vec[i][j] == '\n') {
                val = 95;
            }
            //其他字符一一对应
            else if (vec[i][j] >= ' ' && vec[i][j] <= '~') {
                val = vec[i][j] - 32;
            }
            for (int k = 0; k < huffman_coding.size(); k++) {
                if (huffman_coding[k].val == val) {
                    str += huffman_coding[k].code;
                    break;
                }
            }
        }
        ofs << str;
    }
    ofs.close();
}

//译码文件内容
void DecodeFile(std::string encode_path, std::string decode_path, Node * huffman_tree, int node_num) {
    std::vector<std::string> encode_content = {};
    ReadFile(encode_path, encode_content);
    std::ofstream ofs(decode_path);
    int code_digit = node_num - 1;
    for (int i = 0; i < encode_content.size(); i++) {
        std::string str = {};
        for (int j = 0; j < encode_content[i].size(); j++) {
            if (encode_content[i][j] == '0') {
                code_digit = huffman_tree[code_digit].left;
            }
            else if (encode_content[i][j] == '1') {
                code_digit = huffman_tree[code_digit].right;
            }
            //叶子结点
            if (huffman_tree[code_digit].left == -1 || huffman_tree[code_digit].right == -1) {
                char ch = {};
                //换行符特殊处理
                if (huffman_tree[code_digit].val == 95) {
                    ch = '\n';
                }
                //其他字符一一对应
                else if (huffman_tree[code_digit].val >= 0 && huffman_tree[code_digit].val <= 94) {
                    ch = huffman_tree[code_digit].val + 32;
                }
                str += ch;
                code_digit = node_num - 1;
            }
        }
        ofs << str;
    }
    ofs.close();
}
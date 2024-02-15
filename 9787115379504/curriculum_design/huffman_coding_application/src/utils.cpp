#include <fstream>
#include <algorithm>
#include <iostream>
#include "utils.h"
#include "coding.h"

//读取文件内容
void ReadFile(std::string file_path, std::vector<std::string> & content) {
    std::ifstream ifs(file_path);
    if (ifs.is_open() == false) {
        return;
    }
    std::string str = {};
    while (std::getline(ifs, str)) {
        content.push_back(str += '\n');
    }
    ifs.close();
}

//统计文件字符总数
int CntFileChNum(std::vector<std::string> vec) {
    int ret = 0;
    for (int i = 0; i < vec.size(); i++) {
        ret += vec[i].size();
    }
    return ret;
}

//初始化统计字符表
std::vector<std::vector<int>> InitCntVec(int size) {
    std::vector<std::vector<int>> cnt_vec(size, std::vector<int>(2, 0)); //[字符映射][字符映射出现次数]
    for (int i = 0; i < cnt_vec.size(); i++) {
        cnt_vec[i][0] = i;
    }
    return cnt_vec;
}

//统计有效字符出现频率
void CntChFreq(std::vector<std::string> content, std::vector<std::vector<int>> & cnt_vec) {
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[i].size(); j++) {
            //换行符特殊处理
            if (content[i][j] == '\n') {
                cnt_vec[95][1]++;
            }
            //其他字符一一对应
            else if (content[i][j] >= ' ' && content[i][j] <= '~') {
                cnt_vec[content[i][j] - 32][1]++;
            }
        }
    }
    //字符映射出现次数降序
    std::sort(cnt_vec.begin(), cnt_vec.end(), [](std::vector<int> vec1, std::vector<int> vec2) {
        if (vec1[1] == vec2[1]) {
            return vec1[0] < vec2[0];
        }
        else {
            return vec1[1] > vec2[1];
        }
    });
}

//统计有效字符数
int CntChNum(std::vector<std::vector<int>> cnt_vec) {
    int ret = 0;
    for (int i = 0; i < cnt_vec.size(); i++) {
        if (cnt_vec[i][1] > 0) {
            ret++;
        }
    }
    return ret;
}

//输出相关信息
void OutputInfo(std::unordered_map<int, std::string> node_val_ump, std::vector<ValCode> huffman_coding, std::vector<std::vector<int>> cnt_vec, Node * huffman_tree, int ch_num) {
    for (int i = 0; i < huffman_coding.size(); i++) {
        std::cout << " " << node_val_ump[huffman_coding[i].val] << " " << huffman_coding[i].code << " " << huffman_tree[i].weight << std::endl;
    }
}
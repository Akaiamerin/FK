#include <string>
#include <vector>
#include "utils.h"
#include "huffman_tree.h"
#include "coding.h"

#define SRC_PATH ".\\test\\src.txt"
#define ENCODE_PATH ".\\test\\encode.txt"
#define DECODE_PATH ".\\test\\decode.txt"

int main() {
    std::vector<std::string> src_content = {};
    ReadFile(SRC_PATH, src_content);
    int src_ch_num = CntFileChNum(src_content);
    std::vector<std::vector<int>> cnt_vec = InitCntVec(node_val_ump.size());
    CntChFreq(src_content, cnt_vec);
    int ch_num = CntChNum(cnt_vec);
    int node_num = 2 * ch_num - 1;
    Node * huffman_tree = InitHuffmanTree(node_num, cnt_vec, ch_num, src_ch_num);
    CrtHuffmanTree(huffman_tree, node_num, ch_num);
    std::vector<ValCode> huffman_coding = {};
    HuffmanCoding(huffman_coding, huffman_tree, ch_num);
    EncodeFile(ENCODE_PATH, huffman_coding, src_content);
    DecodeFile(ENCODE_PATH, DECODE_PATH, huffman_tree, node_num);
    OutputInfo(node_val_ump, huffman_coding, cnt_vec, huffman_tree, ch_num);
    delete[] huffman_tree;
    huffman_tree = nullptr;
}
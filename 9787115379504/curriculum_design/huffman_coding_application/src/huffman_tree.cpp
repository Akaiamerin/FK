#include <cfloat>
#include "huffman_tree.h"

//初始化哈夫曼树
Node * InitHuffmanTree(int node_num, std::vector<std::vector<int>> cnt_vec, int ch_num, int src_ch_num) {
    Node * huffman_tree = new Node[node_num]{};
    //初始化叶子节点（频率从高到低）
    for (int i = 0; i < ch_num; i++) {
        huffman_tree[i] = {cnt_vec[i][0], 1.0 * cnt_vec[i][1] / src_ch_num, -1, -1, -1};
    }
    for (int i = ch_num; i < node_num; i++) {
        huffman_tree[i] = {0, 0.0, -1, -1, -1};
    }
    return huffman_tree;
}

//选出两个最小的节点
void SelMinWeight(Node * huffman_tree, int srch_index, int & min_weight_index1, int & min_weight_index2) {
    double min_weight = DBL_MAX;
    int cur_min_weight_index = -1;
    int index1 = 0;
    while (huffman_tree[index1].parent != -1) {
        index1++;
    }
    min_weight = huffman_tree[index1].weight;
    cur_min_weight_index = index1;
    while (index1 < srch_index) {
        if (huffman_tree[index1].weight < min_weight && huffman_tree[index1].parent == -1) {
            min_weight = huffman_tree[index1].weight;
            cur_min_weight_index = index1;
        }
        index1++;
    }
    huffman_tree[cur_min_weight_index].parent = 1;
    min_weight_index1 = cur_min_weight_index;
    int index2 = 0;
    while (huffman_tree[index2].parent != -1) {
        index2++;
    }
    min_weight = huffman_tree[index2].weight;
    cur_min_weight_index = index2;
    while (index2 < srch_index) {
        if (huffman_tree[index2].weight < min_weight && huffman_tree[index2].parent == -1) {
            min_weight = huffman_tree[index2].weight;
            cur_min_weight_index = index2;
        }
        index2++;
    }
    huffman_tree[cur_min_weight_index].parent = 1;
    min_weight_index2 = cur_min_weight_index;
}

//创建哈夫曼树
void CrtHuffmanTree(Node *& huffman_tree, int node_num, int ch_num) {
    int min_weight_index1 = -1;
    int min_weight_index2 = -1;
    for (int i = ch_num; i < node_num; i++) {
        SelMinWeight(huffman_tree, i, min_weight_index1, min_weight_index2);
        //新树结点作为两个最小树的双亲结点
        huffman_tree[min_weight_index1].parent = i;
        huffman_tree[min_weight_index2].parent = i;
        huffman_tree[i].weight = huffman_tree[min_weight_index1].weight + huffman_tree[min_weight_index2].weight; //新树结点权值为两个最小树权值之和
        //新树结点左右孩子为两个最小树
        huffman_tree[i].left = min_weight_index1;
        huffman_tree[i].right = min_weight_index2;
    }
}
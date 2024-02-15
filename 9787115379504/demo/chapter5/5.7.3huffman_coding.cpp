#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
using namespace std;
struct Node {
    int weight; //权值
    int parent; //双亲下标
    int left; //左孩子下标
    int right; //右孩子下标
};
struct Tree {
    Node * elem; //元素
    int size; //元素数量
};
//初始化
Tree Init(Tree & tree, int cap = 100) {
    tree.elem = new Node[2 * cap - 1];
    tree.size = 0;
    return tree;
}
//最小权值
void GetMinWeight(Tree & tree, int srch_index, int & min_weight_index1, int & min_weight_index2) {
    int min_weight = INT_MAX;
    int cur_min_weight_index = -1;
    int index1 = 0;
    while (tree.elem[index1].parent != -1) {
        index1++;
    }
    min_weight = tree.elem[index1].weight;
    cur_min_weight_index = index1;
    while (index1 < srch_index) {
        if (tree.elem[index1].weight < min_weight && tree.elem[index1].parent == -1) {
            min_weight = tree.elem[index1].weight;
            cur_min_weight_index = index1;
        }
        index1++;
    }
    tree.elem[cur_min_weight_index].parent = 1;
    min_weight_index1 = cur_min_weight_index;
    int index2 = 0;
    while (tree.elem[index2].parent != -1) {
        index2++;
    }
    min_weight = tree.elem[index2].weight;
    cur_min_weight_index = index2;
    while (index2 < srch_index) {
        if (tree.elem[index2].weight < min_weight && tree.elem[index2].parent == -1) {
            min_weight = tree.elem[index2].weight;
            cur_min_weight_index = index2;
        }
        index2++;
    }
    tree.elem[cur_min_weight_index].parent = 1;
    min_weight_index2 = cur_min_weight_index;
}
//创建
void Crt(Tree & tree, int size) {
    for (int i = 0; i < size; i++) {
        // cout << "weight[" << i << "]: ";
        // cin >> tree.elem[i].weight;
        tree.elem[i].weight = rand() % UCHAR_MAX;
        tree.elem[i].parent = -1;
        tree.elem[i].left = -1;
        tree.elem[i].right = -1;
        tree.size++;
    }
    for (int i = size; i < 2 * size - 1; i++) {
        tree.elem[i].weight = INT_MAX;
        tree.elem[i].parent = -1;
        tree.elem[i].left = -1;
        tree.elem[i].right = -1;
        tree.size++;
    }
    for (int i = size; i < tree.size; i++) {
        int min_weight_index1 = -1;
        int min_weight_index2 = -1;
        GetMinWeight(tree, i, min_weight_index1, min_weight_index2);
        tree.elem[min_weight_index1].parent = i;
        tree.elem[min_weight_index2].parent = i;
        tree.elem[i].weight = tree.elem[min_weight_index1].weight + tree.elem[min_weight_index2].weight;
        tree.elem[i].left = min_weight_index1;
        tree.elem[i].right = min_weight_index2;
    }
}
//输出
void Output(Tree tree) {
    for (int i = 0; i < tree.size; i++) {
        cout << "weight[" << i << "]: " << tree.elem[i].weight << " ";
        cout << "parent: weight[" << tree.elem[i].parent << "] ";
        cout << "left: weight[" << tree.elem[i].left << "] ";
        cout << "right: weight[" << tree.elem[i].right << "] " << endl;
    }
}
//哈夫曼编码
void HuffmanCoding(Tree tree, char **& huffman_coding) {
    int temp_weight[tree.size];
    for (int i = 0; i < tree.size; i++) {
        temp_weight[i] = tree.elem[i].weight;
    }
    int code_size = (tree.size + 1) / 2;
    huffman_coding = new char * [code_size];
    char code[code_size];
    int cur_index = tree.size - 1;
    int code_index = 0;
    for (int i = 0; i < tree.size; i++) {
        tree.elem[i].weight = 0;
    }
    while (cur_index != -1) {
        if (tree.elem[cur_index].weight == 0) {
            tree.elem[cur_index].weight = 1;
            if (tree.elem[cur_index].left != -1) {
                code[code_index++] = '0';
                cur_index = tree.elem[cur_index].left;
            }
            else {
                code[code_index] = '\0';
                huffman_coding[cur_index] = new char[code_index + 1];
                strcpy(huffman_coding[cur_index], code);
            }
        }
        else if (tree.elem[cur_index].weight == 1) {
            tree.elem[cur_index].weight = 2;
            if (tree.elem[cur_index].right != -1) {
                code[code_index++] = '1';
                cur_index = tree.elem[cur_index].right;
            }
        }
        else {
            tree.elem[cur_index].weight = 0;
            cur_index = tree.elem[cur_index].parent;
            code_index--;
        }
    }
    for (int i = 0; i < tree.size; i++) {
        tree.elem[i].weight = temp_weight[i];
    }
}
//输出哈夫曼编码结果
void OutputHuffmanCoding(Tree tree, char ** huffman_coding) {
    for (int i = 0; i < (tree.size + 1) / 2; i++) {
        cout << "weight[" << i << "]: " << tree.elem[i].weight << " = " << huffman_coding[i] << endl;
    }
}
int main() {
    srand((unsigned)time(NULL));
    Tree huffman_tree = Init(huffman_tree, 100);
    Crt(huffman_tree, 100);
    Output(huffman_tree);
    char ** huffman_coding = nullptr;
    HuffmanCoding(huffman_tree, huffman_coding);
    OutputHuffmanCoding(huffman_tree, huffman_coding);
    return 0;
}
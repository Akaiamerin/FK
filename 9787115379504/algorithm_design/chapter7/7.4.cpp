#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    int count; //计数
    Node * left; //左孩子
    Node * right; //右孩子
};
//初始化
Node * Init(Node *& tree) {
    tree = new Node;
    tree->elem = NULL;
    tree->count = 0;
    tree->left = nullptr;
    tree->right = nullptr;
    return tree;
}
//中序遍历
void InorderTraverse(Node * tree) {
    if (tree == nullptr) {
        return;
    }
    InorderTraverse(tree->left);
    cout << tree->elem << " ";
    InorderTraverse(tree->right);
}
//插入
void Ins(Node *& tree, int ins_elem) {
    if (tree == nullptr) {
        tree = new Node;
        tree->elem = ins_elem;
        tree->count = 0;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    if (tree->elem < ins_elem) {
        Ins(tree->right, ins_elem);
    }
    else if (tree->elem > ins_elem) {
        Ins(tree->left, ins_elem);
    }
}
//创建
void Crt(Node *& tree, int size) {
    tree = nullptr;
    int ins_elem = rand() % UCHAR_MAX;
    // cin >> ins_elem;
    Ins(tree, ins_elem);
    for (int i = 0; i < size - 1; i++) {
        ins_elem = rand() % UCHAR_MAX;
        // cin >> ins_elem;
        Ins(tree, ins_elem);
    }
}
//查找或插入结点
bool SrchOrInsElem(Node * tree, int X) {
    Node * srch_node = tree;
    Node * srch_node_parent = nullptr;
    while (srch_node != nullptr && srch_node->elem != X) {
        if (srch_node->elem < X) {
            srch_node_parent = srch_node;
            srch_node = srch_node->right;

        }
        else if (srch_node->elem > X) {
            srch_node_parent = srch_node;
            srch_node = srch_node->left;
        }
    }
    if (srch_node != nullptr) {
        srch_node->count++;
        return true;
    }
    else {
        Node * ins_node = new Node;
        ins_node->elem = X;
        ins_node->left = nullptr;
        ins_node->count = 0;
        ins_node->right = nullptr;
        if (tree == nullptr) {
            tree = ins_node;
        }
        else {
            if (srch_node_parent->elem < X) {
                srch_node_parent->right = ins_node;
            }
            else if (srch_node_parent->elem > X) {
                srch_node_parent->left = ins_node;
            }
        }
    }
    return false;
}
int main() {
    srand((unsigned)time(NULL));
    Node * tree = Init(tree);
    Crt(tree, 5);
    InorderTraverse(tree);
    cout << endl;
    cout << SrchOrInsElem(tree, tree->left->elem) << endl;
    InorderTraverse(tree);
    return 0;
}
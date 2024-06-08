#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
struct Node {
    int elem; //元素
    Node * left; //左孩子
    Node * right; //右孩子
};
//初始化
Node * Init(Node *& tree) {
    tree = new Node;
    tree->elem = NULL;
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
//判断是否为二叉排序树
bool IsBinarySortTree(Node * tree, Node *& prev_node) {
    if (tree == nullptr) {
        return true;
    }
    bool left = IsBinarySortTree(tree->left, prev_node);
    if (prev_node != nullptr && prev_node->elem >= tree->elem) {
        return false;
    }
    prev_node = tree;
    bool right = IsBinarySortTree(tree->right, prev_node);
    return left && right;
}
int main() {
    srand((unsigned)time(NULL));
    Node * tree = Init(tree);
    Crt(tree, 10);
    InorderTraverse(tree);
    cout << endl;
    Node * prev_node = nullptr;
    cout << IsBinarySortTree(tree, prev_node) << endl;
    return 0;
}
#include <iostream>
using namespace std;
struct Node {
    char elem; //元素
    Node * left; //左孩子
    Node * right; //右孩子
};
//初始化
Node * Init(Node *& tree) {
    tree = new Node;
    tree->elem = {};
    tree->left = nullptr;
    tree->right = nullptr;
    return tree;
}
//创建
void Crt(Node *& tree) {
    char crt_elem = {};
    cin >> crt_elem;
    if (crt_elem == '#') {
        tree = nullptr;
    }
    else {
        tree = new Node;
        tree->elem = crt_elem;
        Crt(tree->left);
        Crt(tree->right);
    }
}
//统计二叉树叶结点个数
int GetLeafNode(Node * tree) {
    if (tree == nullptr) {
        return 0;
    }
    else if (tree->left == nullptr && tree->right == nullptr) {
        return 1;
    }
    return GetLeafNode(tree->left) + GetLeafNode(tree->right);
}
int main() {
    Node * tree = Init(tree);
    Crt(tree);
    cout << GetLeafNode(tree) << endl;
    return 0;
}
#if 0
/*
先序遍历：abd##e##cf##g##
中序遍历：#d#b#e#a#f#c#g#
后序遍历：##d##eb##f##gca
             a
       /           \
      b             c
   /     \       /     \
  d       e     f       g
 / \     / \   / \     / \
#   #   #   # #   #   #   #
*/
#endif
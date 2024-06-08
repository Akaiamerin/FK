#include <iostream>
#include <queue>
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
//双序遍历
void DoubleTraverse(Node * tree) {
    if (tree == nullptr) {
        return;
    }
    else if (tree->left == nullptr && tree->right == nullptr) {
        cout << tree->elem << " ";
    }
    else {
        cout << tree->elem << " ";
        DoubleTraverse(tree->left);
        cout << tree->elem << " ";
        DoubleTraverse(tree->right);
    }
}
int main() {
    Node * tree = Init(tree);
    Crt(tree);
    DoubleTraverse(tree);
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
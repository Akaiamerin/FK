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
//是否相等
bool IsEqual(Node * tree1, Node * tree2) {
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    }
    if (tree1 == nullptr && tree2 != nullptr || tree1 != nullptr && tree2 == nullptr) {
        return false;
    }
    if (tree1->elem == tree2->elem) {
        if (IsEqual(tree1->left, tree2->left) == true) {
            return IsEqual(tree1->right, tree2->right);
        }
        else if (IsEqual(tree1->right, tree2->right) == true) {
            return IsEqual(tree1->left, tree2->left);
        }
    }
    return false;
}
int main() {
    Node * tree1 = Init(tree1);
    Crt(tree1);
    Node * tree2 = Init(tree2);
    Crt(tree2);
    cout << IsEqual(tree1, tree2) << endl;
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
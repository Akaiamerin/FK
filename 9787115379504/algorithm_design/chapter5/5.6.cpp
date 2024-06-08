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
//统计度为 1 的结点数
int GetOneChildNode(Node * tree) {
    if (tree == nullptr) {
        return 0;
    }
    int ret = 0;
    queue<Node *> que = {};
    que.push(tree);
    while (que.empty() == false) {
        for (int i = 0; i < que.size(); i++) {
            Node * node = que.front();
            que.pop();
            if ((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr)) {
                ret++;
            }
            if (node->left != nullptr) {
                que.push(node->left);
            }
            if (node->right != nullptr) {
                que.push(node->right);
            }
        }
    }
    return ret;
}
int main() {
    Node * tree = Init(tree);
    Crt(tree);
    cout << GetOneChildNode(tree) << endl;
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
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
//最大宽度
int GetMaxWidth(Node * tree) {
    if (tree == nullptr) {
        return 0;
    }
    queue<Node *> que = {};
    que.push(tree);
    Node * cur_level_right_end_node = tree;
    Node * next_level_right_end_node = nullptr;
    int cur_width = 0;
    int max_width = 0;
    while (que.empty() == false) {
        Node * node = que.front();
        que.pop();
        if (node->left != nullptr) {
            que.push(node->left);
            next_level_right_end_node = node->left;
        }
        if (node->right != nullptr) {
            que.push(node->right);
            next_level_right_end_node = node->right;
        }
        cur_width++;
        if (node == cur_level_right_end_node) {
            if (cur_width > max_width) {
                max_width = cur_width;
            }
            cur_width = 0;
            cur_level_right_end_node = next_level_right_end_node;
        }
    }
    return max_width;
}
int main() {
    Node * tree = Init(tree);
    Crt(tree);
    cout << GetMaxWidth(tree) << endl;
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
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
//最长路径
void LongestPath(Node * tree, char temp_path[], int & temp_path_index, char longest_path[], int & longest_path_index) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left == nullptr && tree->right == nullptr) {
        temp_path[temp_path_index] = tree->elem;
        if (temp_path_index > longest_path_index) {
            for (int i = 0; i < temp_path_index + 1; i++) {
                longest_path[i] = temp_path[i];
            }
            longest_path_index = temp_path_index;
        }
    }
    else {
        temp_path[temp_path_index++] = tree->elem;
        LongestPath(tree->left, temp_path, temp_path_index, longest_path, longest_path_index);
        LongestPath(tree->right, temp_path, temp_path_index, longest_path, longest_path_index);
        temp_path_index--;
    }
}
int main() {
    Node * tree = Init(tree);
    Crt(tree);
    char temp_path[100];
    int temp_path_index = 0;
    char longest_path[100];
    int longest_path_index = 0;
    LongestPath(tree, temp_path, temp_path_index, longest_path, longest_path_index);
    for (int i = 0; i < longest_path_index + 1; i++) {
        cout << longest_path[i] << "->";
    }
    cout << '#' << endl;
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
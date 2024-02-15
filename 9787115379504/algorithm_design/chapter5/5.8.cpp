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
//每个叶子结点到根结点的路径
void LeafToRootPath(Node * tree, char path[], int & path_index) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left == nullptr && tree->right == nullptr) {
        cout << tree->elem << "->";
        for (int i = path_index - 1; i > 0; i--) {
            cout << path[i] << "->";
        }
        cout << path[0] << endl;
    }
    else {
        path[path_index++] = tree->elem;
        LeafToRootPath(tree->left, path, path_index);
        LeafToRootPath(tree->right, path, path_index);
        path_index--;
    }
}
int main() {
    Node * tree = Init(tree);
    Crt(tree);
    char path[100];
    int path_index = 0;
    LeafToRootPath(tree, path, path_index);
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
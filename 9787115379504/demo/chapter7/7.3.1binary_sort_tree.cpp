#include <iostream>
#include <cstdlib>
#include <ctime>
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
//删除
void Del(Node *& tree, int del_elem) {
    Node * cur_node = tree;
    Node * cur_node_parent = nullptr;
    //查找要删除的 key
    while (cur_node != nullptr) {
        if (cur_node->elem < del_elem) {
            cur_node_parent = cur_node;
            cur_node = cur_node->right;
        }
        else if (cur_node->elem > del_elem) {
            cur_node_parent = cur_node;
            cur_node = cur_node->left;
        }
        else {
            break;
        }
    }
    if (cur_node == nullptr) {
        return;
    }
    Node * del_node = nullptr;
    Node * retain_node = nullptr; //保留删除结点的子结点
    //当 cur_node 左孩子为空
    if (cur_node->left == nullptr && cur_node->right != nullptr) {
        del_node = cur_node;
        retain_node = cur_node->right; //保留 cur_node 右孩子
    }
    //当 cur_node 右孩子为空
    else if (cur_node->left != nullptr && cur_node->right == nullptr) {
        del_node = cur_node;
        retain_node = cur_node->left; //保留 cur_node 左孩子
    }
    //当 cur_node 左右孩子不为空
    else if (cur_node->left != nullptr && cur_node->right != nullptr) {
        Node * next_node = cur_node->right; //cur_node 的后继结点一定在 cur_node 的右孩子上
        Node * next_node_parent = cur_node; //后继结点的双亲
        //在 next_node 的左孩子寻找 cur_node 的后继结点
        while (next_node->left != nullptr) {
            next_node_parent = next_node;
            next_node = next_node->left;
        }
        cur_node->elem = next_node->elem; //将后继结点的 key 赋值给待删除结点
        if (next_node_parent == cur_node) {
            next_node_parent->right = next_node->right; //连接 cur_node 后继结点为 cur_node 的左孩子
        }
        else {
            next_node_parent->left = next_node->left; //连接 cur_node 后继结点为 cur_node 的右孩子
        }
        delete next_node;
        next_node = nullptr;
        return;
    }
    //如果 cur_node_parent 为空，说明待删除的结点为根节点
    if (cur_node_parent == nullptr) {
        tree = retain_node;
    }
    else if (cur_node_parent->left == cur_node) {
        cur_node_parent->left = retain_node;
    }
    else if (cur_node_parent->right == cur_node) {
        cur_node_parent->right = retain_node;
    }
    delete del_node;
    del_node = nullptr;
}
//查找结点
Node * SrchNode(Node * tree, int srch_elem) {
    if (tree == nullptr) {
        return nullptr;
    }
    if (tree->elem < srch_elem) {
        return SrchNode(tree->right, srch_elem);

    }
    else if (tree->elem > srch_elem) {
        return SrchNode(tree->left, srch_elem);
    }
    return tree;
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
int main() {
    srand((unsigned)time(NULL));
    Node * tree = Init(tree);
    Crt(tree, 10);
    InorderTraverse(tree);
    return 0;
}
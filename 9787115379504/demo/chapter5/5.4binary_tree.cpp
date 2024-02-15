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
//先序遍历
void PreorderTraverse(Node * tree) {
    if (tree == nullptr) {
        return;
    }
    cout << tree->elem << " ";
    PreorderTraverse(tree->left);
    PreorderTraverse(tree->right);
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
//后序遍历
void PostorderTraverse(Node * tree) {
    if (tree == nullptr) {
        return;
    }
    PostorderTraverse(tree->left);
    PostorderTraverse(tree->right);
    cout << tree->elem << " ";
}
//层序遍历
void LevelOrderTraverse(Node * tree) {
    if (tree == nullptr) {
        return;
    }
    queue<Node *> que = {};
    que.push(tree);
    while (que.empty() == false) {
        Node * cur_node = que.front();
        que.pop();
        cout << cur_node->elem << " ";
        if (cur_node->left != nullptr) {
            que.push(cur_node->left);
        }
        if (cur_node->right != nullptr) {
            que.push(cur_node->right);
        }
    }
}
//深度
int GetDepth(Node * tree) {
    if (tree == nullptr) {
        return 0;
    }
    int left_depth = GetDepth(tree->left);
    int right_depth = GetDepth(tree->right);
    return max(left_depth, right_depth) + 1;
}
//是否为空
bool IsEmpty(Node * tree) {
    if (tree == nullptr) {
        return true;
    }
    return false;
}
//插入
void Ins(Node *& tree, int pos, Node * ins_node) {
    if (tree == nullptr) {
        return;
    }
    if (pos == 0) {
        ins_node->right = tree->left; //插入位置结点的左孩子成为 ins_node 右孩子
        tree->left = ins_node; //ins_node 成为插入位置结点的左孩子
    }
    else {
        ins_node->right = tree->right; //插入位置结点的右孩子成为 ins_node 右孩子
        tree->right = ins_node; //ins_node 成为插入位置结点的右孩子
    }
}
//删除节点
void DelNode(Node *& tree) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left != nullptr) {
        DelNode(tree->left);
    }
    if (tree->right != nullptr) {
        DelNode(tree->right);
    }
    delete tree;
    tree = nullptr;
}
//删除
void Del(Node *& tree, int pos) {
    if (tree == nullptr) {
        return;
    }
    if (pos == 0) {
        DelNode(tree->left);
    }
    else {
        DelNode(tree->right);
    }
}
//复制
void Copy(Node *& copy_tree, Node * tree) {
    if (tree == nullptr) {
        copy_tree = nullptr;
        return;
    }
    else {
        copy_tree = new Node;
        copy_tree->elem = tree->elem;
        Copy(copy_tree->left, tree->left);
        Copy(copy_tree->right, tree->right);
    }
}
//结点元素
char NodeElem(Node * tree) {
    return tree->elem;
}
//双亲元素
char ParentElem(Node * tree, char srch_elem) {
    if (tree == nullptr) {
        return '#';
    }
    queue<Node *> que = {};
    que.push(tree);
    while (que.empty() == false) {
        Node * parent = que.front();
        que.pop();
        //比较双亲左右孩子元素与 srch_elem
        if ((parent->left != nullptr && parent->left->elem == srch_elem) || (parent->right != nullptr && parent->right->elem == srch_elem)) {
            return parent->elem;
        }
        else {
            if (parent->left != nullptr) {
                que.push(parent->left);
            }
            if (parent->right != nullptr) {
                que.push(parent->right);
            }
        }
    }
    return '#';
}
//查找结点
Node * SrchNode(Node * tree, char srch_elem) {
    if (tree == nullptr) {
        return nullptr;
    }
    queue<Node *> que = {};
    que.push(tree);
    while (que.empty() == false) {
        Node * cur_node = que.front();
        que.pop();
        if (cur_node->elem == srch_elem) {
            return cur_node;
        }
        if (cur_node->left != nullptr) {
            que.push(cur_node->left);
        }
        if (cur_node->right != nullptr) {
            que.push(cur_node->right);
        }
    }
    return nullptr;
}
//左孩子元素
char LeftChildElem(Node * tree, char srch_elem) {
    if (tree == nullptr) {
        return '#';
    }
    Node * cur_node = SrchNode(tree, srch_elem);
    if (cur_node != nullptr && cur_node->left != nullptr) {
        return cur_node->left->elem;
    }
    return '#';
}
//右孩子元素
char RightChildElem(Node * tree, char srch_elem) {
    if (tree == nullptr) {
        return '#';
    }
    Node * cur_node = SrchNode(tree, srch_elem);
    if (cur_node != nullptr && cur_node->right != nullptr) {
        return cur_node->right->elem;
    }
    return '#';
}
//左兄弟元素
char LeftSiblingElem(Node * tree, char srch_elem) {
    if (tree == nullptr) {
        return '#';
    }
    char cur_node_parent_elem = ParentElem(tree, srch_elem);
    if (cur_node_parent_elem != '#') {
        Node * cur_node_parent = SrchNode(tree, cur_node_parent_elem);
        //cur_node_parent 左右孩子存在且右孩子元素为 srch_elem
        if (cur_node_parent->left != nullptr && cur_node_parent->right != nullptr && cur_node_parent->right->elem == srch_elem) {
            return cur_node_parent->left->elem;
        }
    }
    return '#';
}
//右兄弟元素
char RightSiblingElem(Node * tree, char srch_elem) {
    if (tree == nullptr) {
        return '#';
    }
    char cur_node_parent_elem = ParentElem(tree, srch_elem);
    if (cur_node_parent_elem != '#') {
        Node * cur_node_parent = SrchNode(tree, cur_node_parent_elem);
        //cur_node_parent 左右孩子存在且右孩子元素为 srch_elem
        if (cur_node_parent->left != nullptr && cur_node_parent->right != nullptr && cur_node_parent->left->elem == srch_elem) {
            return cur_node_parent->right->elem;
        }
    }
    return '#';
}
//销毁
void Des(Node *& tree) {
    DelNode(tree);
}
int main() {
    Node * tree = Init(tree);
    Crt(tree);
    PreorderTraverse(tree);
    cout << endl;
    InorderTraverse(tree);
    cout << endl;
    PostorderTraverse(tree);
    cout << endl;
    LevelOrderTraverse(tree);
    cout << endl;
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
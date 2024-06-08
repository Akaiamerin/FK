#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    int balence_factor; //平衡因子
    Node * left; //左孩子
    Node * right; //右孩子
};
//初始化
Node * Init(Node *& tree) {
    tree = new Node;
    tree->elem = NULL;
    tree->balence_factor = 0;
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
//左旋转（以该结点的右孩子为中心向左旋转）
void LeftRotate(Node *& tree) {
    Node * right_child = tree->right;
    tree->right = right_child->left;
    right_child->left = tree;
    tree = right_child;
}
//右旋转（以该结点的左孩子为中心向右旋转）
void RightRotate(Node *& tree) {
    Node * left_child = tree->left;
    tree->left = left_child->right;
    left_child->right = tree;
    tree = left_child;
}
//左平衡
void LeftBalance(Node *& tree) {
    Node * left_child = tree->left;
    Node * left_child_right_child = nullptr; //结点左孩子的右孩子
    if (left_child->balence_factor == 1) {
        tree->balence_factor = 0;
        left_child->balence_factor = 0;
        RightRotate(tree);
    }
    else if (left_child->balence_factor == -1) {
        left_child_right_child = left_child->right;
        if (left_child_right_child->balence_factor == 1) {
            tree->balence_factor = -1;
            left_child->balence_factor = 0;
        }
        else if (left_child_right_child->balence_factor == 0) {
            tree->balence_factor = 0;
            left_child->balence_factor = 0;
        }
        else if (left_child_right_child->balence_factor == -1) {
            tree->balence_factor = 0;
            left_child->balence_factor = 1;
        }
        left_child_right_child->balence_factor = 0;
        LeftRotate(tree->left);
        RightRotate(tree);
    }
}
//右平衡
void RightBalance(Node *& tree) {
    Node * right_child = tree->right;
    Node * right_child_left_child = nullptr; //结点右孩子的左孩子
    if (right_child->balence_factor == -1) {
        tree->balence_factor = 0;
        right_child->balence_factor = 0;
        LeftRotate(tree);
    }
    else if (right_child->balence_factor == 1) {
        right_child_left_child = right_child->left;
        if (right_child_left_child->balence_factor == 1) {
            tree->balence_factor = 0;
            right_child->balence_factor = -1;
        }
        else if (right_child_left_child->balence_factor == 0) {
            tree->balence_factor = 0;
            right_child->balence_factor = 0;
        }
        else if (right_child_left_child->balence_factor == -1) {
            tree->balence_factor = 1;
            right_child->balence_factor = 0;
        }
        right_child_left_child->balence_factor = 0;
        RightRotate(tree->right);
        LeftRotate(tree);
    }
}
bool height_change = false; //树高度是否变化
//插入
void Ins(Node *& tree, int ins_elem, bool & height_change) {
    if (tree == nullptr) {
        tree = new Node;
        tree->elem = ins_elem;
        tree->balence_factor = 0;
        tree->left = nullptr;
        tree->right = nullptr;
        height_change = true;
    }
    if (tree->elem < ins_elem) {
        Ins(tree->right, ins_elem, height_change);
        if (height_change == true) {
            if (tree->balence_factor == 1) {
                tree->balence_factor = 0;
                height_change = false;
            }
            else if (tree->balence_factor == 0) {
                tree->balence_factor = -1;
                height_change = true;
            }
            else if (tree->balence_factor == -1) {
                RightBalance(tree);
                height_change = false;
            }
        }
    }
    else if (tree->elem > ins_elem) {
        Ins(tree->left, ins_elem, height_change);
        if (height_change == true) {
            if (tree->balence_factor == 1) {
                LeftBalance(tree);
                height_change = false;
            }
            else if (tree->balence_factor == 0) {
                tree->balence_factor = 1;
                height_change = true;
            }
            else if (tree->balence_factor == -1) {
                tree->balence_factor = 0;
                height_change = false;
            }
        }
    }
}
//创建
void Crt(Node *& tree, int size) {
    tree = nullptr;
    int ins_elem = rand() % UCHAR_MAX;
    // cin >> ins_elem;
    Ins(tree, ins_elem, height_change);
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            break;
        }
        ins_elem = rand() % UCHAR_MAX;
        // cin >> ins_elem;
        Ins(tree, ins_elem, height_change);
    }
}
//平衡二叉树的高度
int GetHeight(Node * tree) {
    int ret = 0;
    Node * cur_node = tree;
    while (cur_node != nullptr) {
        ret++;
        if (tree->balence_factor < 0) {
            cur_node = cur_node->right;
        }
        else {
            cur_node = cur_node->left;
        }
    }
    return ret;
}
int main() {
    srand((unsigned)time(NULL));
    Node * tree = Init(tree);
    Crt(tree, 10);
    InorderTraverse(tree);
    cout << endl;
    cout << GetHeight(tree) << endl;
    return 0;
}
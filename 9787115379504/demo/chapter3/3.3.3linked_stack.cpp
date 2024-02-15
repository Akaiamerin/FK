#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    Node * next; //后继结点
};
//初始化
Node * Init(Node *& stk) {
    stk = new Node;
    stk->elem = NULL;
    stk->next = nullptr;
    return stk;
}
//遍历
void Traverse(Node * stk) {
    for (Node * i = stk->next; i != nullptr; i = i->next) {
        cout << i->elem << " ";
    }
    cout << endl;
}
//元素数量
int GetSize(Node * stk) {
    int size = 0;
    for (Node * i = stk->next; i != nullptr; i = i->next) {
        size++;
    }
    return size;
}
//是否为空
bool IsEmpty(Node * stk) {
    if (stk->next == nullptr) {
        return true;
    }
    return false;
}
//入栈
void Push(Node *& stk, int push_elem) {
    Node * push_node = new Node;
    push_node->elem = push_elem;
    push_node->next = stk->next;
    stk->next = push_node;
}
//出栈
void Pop(Node *& stk) {
    if (stk->next == nullptr) {
        return;
    }
    Node * node = stk->next;
    stk->next = node->next;
    delete node;
    node = nullptr;
}
//栈顶元素
int Top(Node * stk) {
    return stk->next->elem;
}
//清空
void Clr(Node *& stk) {
    Node * clr_node = nullptr;
    while (stk->next != nullptr) {
        clr_node = stk->next;
        stk->next = clr_node->next;
        delete clr_node;
        clr_node = nullptr;
    }
}
//销毁
void Des(Node *& stk) {
    Node * des_node = nullptr;
    while (stk->next != nullptr) {
        des_node = stk->next;
        stk->next = des_node->next;
        delete des_node;
        des_node = nullptr;
    }
    delete stk;
    stk = nullptr;
}
int main() {
    srand((unsigned)time(NULL));
    Node * stk = Init(stk);
    for (int i = 0; i < 100; i++) {
        Push(stk, rand() % UCHAR_MAX);
    }
    Traverse(stk);
    return 0;
}
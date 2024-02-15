#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int elem; //元素
    Node * next; //后继结点
};
//初始化
Node * Init(Node *& list) {
    list = new Node;
    list->elem = NULL;
    list->next = nullptr;
    return list;
}
//创建（头插法）
void HeadCrt(Node *& list, int size) {
    for (int i = 0; i < size; i++) {
        Node * crt_node = new Node;
        // cin >> crt_node->elem;
        crt_node->elem = rand() % UCHAR_MAX;
        crt_node->next = list->next; //crt_node 的后继结点指向头结点的后继结点
        list->next = crt_node; //头结点的后继结点指向 crt_node
    }
}
//创建（尾插法）
void TailCrt(Node *& list, int size) {
    Node * tail = list;
    for (int i = 0; i < size; i++) {
        Node * crt_node = new Node;
        // cin >> crt_node->elem;
        crt_node->elem = rand() % UCHAR_MAX;
        crt_node->next = nullptr;
        tail->next = crt_node; //尾结点的后继结点指向 crt_node
        tail = crt_node; //尾结点指向 crt_node
    }
    tail->next = nullptr; //循环结束，尾结点的后继结点应置空
}
//遍历
void Traverse(Node * list) {
    for (Node * i = list->next; i != nullptr; i = i->next) {
        cout << i->elem << " ";
    }
    cout << endl;
}
//元素数量
int GetSize(Node * list) {
    int size = 0;
    for (Node * i = list->next; i != nullptr; i = i->next) {
        size++;
    }
    return size;
}
//是否为空
bool IsEmpty(Node * list) {
    if (list->next == nullptr) {
        return true;
    }
    return false;
}
//插入
void Ins(Node *& list, int ins_index, int ins_elem) {
    Node * prev_node = list;
    int prev_index = -1;
    //查找待插入结点位置的前驱结点
    while (prev_node != nullptr && prev_index < (ins_index - 1)) {
        prev_node = prev_node->next;
        prev_index++;
    }
    //prev_index 是否越界
    if (prev_node == nullptr || prev_index > (ins_index - 1)) {
        return;
    }
    Node * ins_node = new Node;
    ins_node->elem = ins_elem;
    ins_node->next = prev_node->next; //ins_node 的后继结点指向前驱结点的后继结点（待插入位置的结点）
    prev_node->next = ins_node; //前驱结点的后继结点指向 ins_node
}
//删除结点
void Del(Node *& list, int del_index) {
    Node * prev_node = list;
    int prev_index = -1;
    //查找待删除结点位置的前驱结点
    while (prev_node != nullptr && prev_index < (del_index - 1)) {
        prev_node = prev_node->next;
        prev_index++;
    }
    //prev_index 是否越界
    if (prev_node == nullptr || prev_index > (del_index - 1)) {
        return;
    }
    Node * del_node = prev_node->next; //del_node 指向前驱结点的后继结点（待删除位置的结点）
    prev_node->next = del_node->next; //前驱结点的后继结点指向删除位置结点的后继结点
    delete del_node;
    del_node = nullptr;
}
//查找节点下标
int SrchInex(Node * list, int srch_elem) {
    Node * srch_node = list->next;
    int srch_index = 0;
    while (srch_node != nullptr) {
        if (srch_node->elem == srch_elem) {
            return srch_index;
        }
        srch_node = srch_node->next;
        srch_index++;
    }
    return -1;
}
//查找节点元素值
int SrchElem(Node * list, int srch_index) {
    Node * srch_node = list->next;
    int cur_index = 0;
    while (srch_node != nullptr && cur_index < srch_index) {
        srch_node = srch_node->next;
        cur_index++;
    }
    if (srch_node == nullptr || cur_index > srch_index) {
        return NULL;
    }
    return srch_node->elem;
}
//清空
void Clr(Node *& list) {
    Node * clr_node = list->next;
    Node * next_clr_node = nullptr;
    while (clr_node != nullptr) {
        next_clr_node = clr_node->next;
        delete clr_node;
        clr_node = next_clr_node;
    }
    list->next = nullptr;
}
//销毁
void Des(Node *& list) {
    Node * des_node = nullptr;
    while (list != nullptr) {
        des_node = list;
        list = list->next;
        delete des_node;
        des_node = nullptr;
    }
}
int main() {
    srand((unsigned)time(NULL));
    Node * list = Init(list);
    HeadCrt(list, 100);
    Traverse(list);
    TailCrt(list, 100);
    Traverse(list);
    return 0;
}
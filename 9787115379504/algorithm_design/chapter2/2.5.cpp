#include <iostream>
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
//遍历
void Traverse(Node * list) {
    for (Node * i = list->next; i != nullptr; i = i->next) {
        cout << i->elem << " ";
    }
    cout << endl;
}
//插入
void Ins(Node *& list, int ins_index, int ins_elem) {
    Node * prev_node = list;
    int prev_index = -1;
    while (prev_node != nullptr && prev_index < (ins_index - 1)) {
        prev_node = prev_node->next;
        prev_index++;
    }
    if (prev_node == nullptr || prev_index > (ins_index - 1)) {
        return;
    }
    Node * ins_node = new Node;
    ins_node->elem = ins_elem;
    ins_node->next = prev_node->next;
    prev_node->next = ins_node;
}
//分解链表
void ResolveList(Node *& list) {
    Node * list1 = Init(list1);
    Node * list2 = Init(list2);
    Node * node = list->next;
    while (node != nullptr) {
        Node * next_node = node->next;
        if (node->elem < 0) {
            node->next = list1->next;
            list1->next = node;
        }
        else {
            node->next = list2->next;
            list2->next = node;
        }
        node = next_node;
    }
    delete list;
    list = nullptr;
    Traverse(list1);
    Traverse(list2);
}
int main() {
    Node * list = Init(list);
    Ins(list, 0, -3);
    Ins(list, 1, -2);
    Ins(list, 2, -1);
    Ins(list, 3, 1);
    Ins(list, 4, 2);
    Ins(list, 5, 3);
    Traverse(list);
    ResolveList(list);
    return 0;
}
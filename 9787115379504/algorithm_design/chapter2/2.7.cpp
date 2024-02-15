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
//逆转链表
void ReverseList(Node *& list) {
    Node * node = list->next;
    list->next = nullptr;
    while (node != nullptr) {
        Node * next_node = node->next;
        node->next = list->next;
        list->next = node;
        node = next_node;
    }
}
int main() {
    Node * list = Init(list);
    Ins(list, 0, 2);
    Ins(list, 1, 6);
    Ins(list, 2, 8);
    Ins(list, 3, 9);
    Ins(list, 4, 11);
    Ins(list, 5, 15);
    Ins(list, 6, 20);
    Traverse(list);
    ReverseList(list);
    Traverse(list);
    return 0;
}
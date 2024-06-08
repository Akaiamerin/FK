#include <iostream>
using namespace std;
struct Node {
    int elem; //元素
    Node * prev; //前驱结点
    Node * next; //后继结点
};
//初始化
Node * Init(Node *& list) {
    list = new Node;
    list->elem = NULL;
    list->prev = list;
    list->next = list;
    return list;
}
//遍历
void Traverse(Node * list) {
    for (Node * i = list->next; i != list; i = i->next) {
        cout << i->elem << " ";
    }
    cout << endl;
}
//插入
void Ins(Node *& list, int ins_index, int ins_elem) {
    Node * cur_node = list->next;
    int cur_index = -1;
    while (cur_node != nullptr && cur_index < (ins_index - 1)) {
        cur_node = cur_node->next;
        cur_index++;
    }
    if (cur_node == nullptr || cur_index > (ins_index - 1)) {
        return;
    }
    Node * ins_node = new Node;
    ins_node->elem = ins_elem;
    ins_node->prev = cur_node->prev;
    cur_node->prev->next = ins_node;
    ins_node->next = cur_node;
    cur_node->prev = ins_node;
}
//交换顺序
void Exchange(Node *& list, Node * cur_node) {
    if (cur_node == nullptr) {
        return;
    }
    Node * prev_node = cur_node->prev;
    prev_node->prev->next = cur_node;
    cur_node->prev = prev_node->prev;
    prev_node->next = cur_node->next;
    prev_node->prev = cur_node;
    cur_node->next->prev = prev_node;
    cur_node->next = prev_node;
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
    Node * cur_node = list->next->next->next;
    Exchange(list, cur_node);
    Traverse(list);
    return 0;
}
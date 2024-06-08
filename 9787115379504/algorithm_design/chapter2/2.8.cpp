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
//删除链表中大于 mink 且小于 maxk 的所有元素
void DelElem(Node *& list, int mink, int maxk) {
    Node * node = list->next;
    Node * prev_node = list;
    while (node != nullptr && node->elem <= mink) {
        prev_node = node;
        node = node->next;
    }
    if (node != nullptr) {
        while (node != nullptr && node->elem < maxk) {
            node = node->next;
        }
        Node * temp_node = prev_node->next;
        prev_node->next = node;
        while (temp_node != node) {
            Node * next_temp_node = temp_node->next;
            delete temp_node;
            temp_node = next_temp_node;
        }
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
    int mink = 2;
    int maxk = 20;
    DelElem(list, mink, maxk);
    Traverse(list);
    return 0;
}
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
//两个递增链表的交集
void IntersectionList(Node *& list1, Node *& list2) {
    Node * node1 = list1->next;
    Node * node2 = list2->next;
    Node * ret_list = list1;
    Node * ret_node = list1;
    while (node1 != nullptr && node2 != nullptr) {
        Node * temp_node = nullptr;
        if (node1->elem == node2->elem) {
            ret_node->next = node1;
            ret_node = node1;
            node1 = node1->next;
            temp_node = node2;
            node2 = node2->next;
            delete temp_node;
            temp_node = nullptr;
        }
        else if (node1->elem < node2->elem) {
            temp_node = node1;
            node1 = node1->next;
            delete temp_node;
            temp_node = nullptr;
        }
        else {
            temp_node = node2;
            node2 = node2->next;
            delete temp_node;
            temp_node = nullptr;
        }
    }
    while (node1 != nullptr) {
        Node * temp_node = node1;
        node1 = node1->next;
        delete temp_node;
        temp_node = nullptr;
    }
    while (node2 != nullptr) {
        Node * temp_node = node2;
        node2 = node2->next;
        delete temp_node;
        temp_node = nullptr;
    }
    ret_node->next = nullptr;
    delete list2;
    list2 = nullptr;
}
int main() {
    Node * list1 = Init(list1);
    Ins(list1, 0, 3);
    Ins(list1, 1, 5);
    Ins(list1, 2, 8);
    Ins(list1, 3, 11);
    Traverse(list1);
    Node * list2 = Init(list2);
    Ins(list2, 0, 2);
    Ins(list2, 1, 6);
    Ins(list2, 2, 8);
    Ins(list2, 3, 9);
    Ins(list2, 4, 11);
    Ins(list2, 5, 15);
    Ins(list2, 6, 20);
    Traverse(list2);
    IntersectionList(list1, list2);
    Traverse(list1);
    return 0;
}
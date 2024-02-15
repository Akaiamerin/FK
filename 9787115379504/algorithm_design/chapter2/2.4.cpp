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
//两个递增链表的差集
void DiffernceList(Node *& list1, Node *& list2) {
    Node * node1 = list1->next;
    Node * node2 = list2->next;
    Node * ret_list = Init(ret_list);
    Node * ret_node = ret_list;
    while (node1 != nullptr && node2 != nullptr) {
        if (node1->elem == node2->elem) {
            node1 = node1->next;
            node2 = node2->next;
            continue;
        }
        if (node1->elem < node2->elem) {
            Node * differnce_node = new Node;
            differnce_node->elem = node1->elem;
            differnce_node->next = ret_node->next;
            ret_node->next = differnce_node;
            ret_node = ret_node->next;
            node1 = node1->next;
        }
        else if (node1->elem > node2->elem) {
            Node * differnce_node = new Node;
            differnce_node->elem = node2->elem;
            differnce_node->next = ret_node->next;
            ret_node->next = differnce_node;
            ret_node = ret_node->next;
            node2 = node2->next;
        }
    }
    if (node1 != nullptr) {
        ret_node->next = node1;
    }
    if (node2 != nullptr) {
        ret_node->next = node2;
    }
    int cnt = 0;
    for (Node * i = ret_list->next; i != nullptr; i = i->next) {
        cout << i->elem << " ";
        cnt++;
    }
    cout << endl << cnt++ << endl;
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
    DiffernceList(list1, list2);
    return 0;
}
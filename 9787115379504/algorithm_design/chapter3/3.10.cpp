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
//查找结点最大值
int SrchMaxElem(Node * list) {
    Node * srch_node = list->next;
    if (srch_node->next == nullptr) {
        return srch_node->elem;
    }
    int max_elem = SrchMaxElem(srch_node->next);
    if (srch_node->elem > max_elem) {
        return srch_node->elem;
    }
    return max_elem;
}
//结点数
int GetSize(Node * list) {
    if (list->next == nullptr) {
        return 0;
    }
    return GetSize(list->next) + 1;
}
//求平均值
double GetAvg(Node * list, int size) {
    Node * cur_node = list->next;
    if (cur_node->next == nullptr) {
        return cur_node->elem;
    }
    double avg = GetAvg(cur_node->next, size - 1);
    return (avg * (size - 1) + cur_node->elem) / size;
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
    cout << SrchMaxElem(list) << endl;
    cout << GetSize(list) << endl;
    cout << GetAvg(list, GetSize(list)) << endl;
    return 0;
}
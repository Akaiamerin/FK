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
    ins_node->next = prev_node->next;
    prev_node->next = ins_node;
}
//查找节点下标
int SrchIndex(Node * list, int srch_elem) {
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
//线性表的合并
void MergeLinearList(Node * list1, Node * list2) {
    int list1_size = GetSize(list1);
    int list2_size = GetSize(list2);
    int min_list_size = min(list1_size, list2_size);
    for (int i = 0; i < min_list_size; i++) {
        if (min_list_size == list1_size) {
            int merge_elem = SrchElem(list1, i); //查找待合并的元素
            //判断待合并的元素是否在另一个链表中
            if (SrchIndex(list2, merge_elem) == -1) {
                Ins(list2, list2_size, merge_elem);
                list2_size++;
            }
        }
        else if (min_list_size == list2_size) {
            int merge_elem = SrchElem(list2, i);
            if (SrchIndex(list1, merge_elem) == -1) {
                Ins(list1, list1_size, merge_elem);
                list1_size++;
            }
        }
    }
    //输出合并后的链表
    if (min_list_size == list1_size) {
        Traverse(list2);
    }
    else {
        Traverse(list1);
    }
}
int main() {
    Node * list1 = Init(list1);
    Ins(list1, 0, 7);
    Ins(list1, 1, 5);
    Ins(list1, 2, 3);
    Ins(list1, 3, 11);
    Traverse(list1);
    Node * list2 = Init(list2);
    Ins(list2, 0, 2);
    Ins(list2, 1, 6);
    Ins(list2, 2, 3);
    Traverse(list2);
    MergeLinearList(list1, list2);
    return 0;
}
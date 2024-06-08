#include <iostream>
using namespace std;
// #define MERGE_SEQUENCE_LIST //顺序有序表的合并
// #define MERGE_LINKED_LIST //链式有序表的合并
#ifdef MERGE_SEQUENCE_LIST
struct SequenceList {
    int * elem; //元素
    int size; //元素数量
};
//初始化
SequenceList Init(SequenceList & list, int cap = 100) {
    list.elem = new int[cap];
    list.size = 0;
    return list;
}
//遍历
void Traverse(SequenceList list) {
    for (int i = 0; i < list.size; i++) {
        cout << list.elem[i] << " ";
    }
    cout << endl;
}
//元素数量
int GetSize(SequenceList list) {
    return list.size;
}
//插入
void Ins(SequenceList & list, int ins_index, int ins_elem) {
    //ins_index 是否越界
    if (ins_index < 0 || ins_index > list.size || ins_index >= 100) {
        return;
    }
    //向后移动 ins_index 之后的元素
    for (int i = list.size - 1; i >= ins_index; i--) {
        list.elem[i + 1] = list.elem[i];
    }
    list.elem[ins_index] = ins_elem; //在 ins_index 插入元素
    list.size++;
}
//顺序有序表的合并
void MergeSequenceOrderedList(SequenceList list1, SequenceList list2) {
    int list_size = GetSize(list1) + GetSize(list2);
    SequenceList list = Init(list, list_size); //新 list 的元素数量为 list1 的元素数量 + list2 的元素数量
    int list_index = 0;
    int list1_index = 0;
    int list2_index = 0;
    //list1 和 list2 均未到表尾
    while (list1_index < list1.size && list2_index < list2.size) {
        //依次选择 list1 和 list2 中的最小值插入新 list
        if (list1.elem[list1_index] <= list2.elem[list2_index]) {
            Ins(list, list_index, list1.elem[list1_index]);
            list_index++;
            list1_index++;
        }
        else {
            Ins(list, list_index, list2.elem[list2_index]);
            list_index++;
            list2_index++;
        }
    }
    //list2 已到表尾，依次将 list 1 的元素插入新 list
    while (list1_index < list1.size) {
        Ins(list, list_index, list1.elem[list1_index]);
        list_index++;
        list1_index++;
    }
    //list1 已到表尾，依次将 list2 的元素插入新 list
    while (list2_index < list2.size) {
        Ins(list, list_index, list2.elem[list2_index]);
        list_index++;
        list2_index++;
    }
    Traverse(list);
}
#endif
#ifdef MERGE_LINKED_LIST
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
//链式有序表的合并
void MergeLinkedOrderedList(Node * list1, Node * list2) {
    Node * list1_node = list1->next;
    Node * list2_node = list2->next;
    Node * list = list1;
    Node * list_node = list;
    while (list1_node != nullptr && list2_node != nullptr) {
        if (list1_node->elem <= list2_node->elem) {
            list_node->next = list1_node;
            list_node = list1_node;
            list1_node = list1_node->next;
        }
        else {
            list_node->next = list2_node;
            list_node = list2_node;
            list2_node = list2_node->next;
        }
    }
    if (list_node->next != nullptr) {
        list_node->next = list1_node;
    }
    else {
        list_node->next = list2_node;
    }
    Traverse(list);
}
#endif
int main() {
    #ifdef MERGE_SEQUENCE_LIST
    SequenceList list1 = Init(list1, 4);
    Ins(list1, 0, 3);
    Ins(list1, 1, 5);
    Ins(list1, 2, 8);
    Ins(list1, 3, 11);
    Traverse(list1);
    SequenceList list2 = Init(list2, 7);
    Ins(list2, 0, 2);
    Ins(list2, 1, 6);
    Ins(list2, 2, 8);
    Ins(list2, 3, 9);
    Ins(list2, 4, 11);
    Ins(list2, 5, 15);
    Ins(list2, 6, 20);
    Traverse(list2);
    MergeSequenceOrderedList(list1, list2);
    #endif
    #ifdef MERGE_LINKED_LIST
    Node * list1 = Init(list1, 4);
    Ins(list1, 0, 3);
    Ins(list1, 1, 5);
    Ins(list1, 2, 8);
    Ins(list1, 3, 11);
    Traverse(list1);
    Node * list2 = Init(list2, 7);
    Ins(list2, 0, 2);
    Ins(list2, 1, 6);
    Ins(list2, 2, 8);
    Ins(list2, 3, 9);
    Ins(list2, 4, 11);
    Ins(list2, 5, 15);
    Ins(list2, 6, 20);
    Traverse(list2);
    MergeLinkedOrderedList(list1, list2);
    #endif
    return 0;
}
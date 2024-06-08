#include <iostream>
#include "list_set.h"

//初始化
ListSet InitListSet(ListSet & list_set, int size) {
    list_set = {new Node{NULL, nullptr}, size};
    return list_set;
}

//创建（尾插法）
void TailCrtListSet(ListSet & list_set) {
    Node * tail = list_set.list;
    for (int i = 0; i < list_set.size; i++) {
        Node * node = new Node;
        std::cout << "第" << i + 1 << "个元素：";
        std::cin >> node->elem;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    }
    tail->next = nullptr;
}

//输出集合元素
void OutputListSet(ListSet list_set) {
    for (Node * i = list_set.list->next; i != nullptr; i = i->next) {
        std::cout << i->elem << " ";
    }
    std::cout << std::endl;
}

//添加
void Ins(ListSet & list_set, int ins_index, int ins_elem) {
    Node * prev_node = list_set.list;
    int prev_index = -1;
    while (prev_node != nullptr && prev_index < (ins_index - 1)) {
        prev_node = prev_node->next;
        prev_index++;
    }
    if (prev_node == nullptr || prev_index > (ins_index - 1)) {
        return;
    }
    Node * node = new Node{ins_elem, prev_node->next};
    prev_node->next = node;
}

//查找元素下标
int SrchIndex(ListSet list_set, int elem) {
    Node * node = list_set.list->next;
    int index = 0;
    while (node != nullptr) {
        if (node->elem == elem) {
            return index;
        }
        node = node->next;
        index++;
    }
    return -1;
}

//查找元素值
int SrchElem(ListSet list_set, int index) {
    Node * node = list_set.list->next;
    int cur_index = 0;
    while (node != nullptr && cur_index < index) {
        node = node->next;
        cur_index++;
    }
    if (node == nullptr || cur_index > index) {
        return NULL;
    }
    return node->elem;
}
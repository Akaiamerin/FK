#pragma once

struct Node {
    int elem; //元素
    Node * next; //后继结点
};

struct ListSet {
    Node * list; //单链表
    int size; //大小
};

//初始化
ListSet InitListSet(ListSet & list_set, int size = 0);

//创建（尾插法）
void TailCrtListSet(ListSet & list_set);

//输出集合元素
void OutputListSet(ListSet list_set);

//添加
void Ins(ListSet & list_set, int ins_index, int ins_elem);

//查找元素下标
int SrchIndex(ListSet list_set, int elem);

//查找元素值
int SrchElem(ListSet list_set, int index);
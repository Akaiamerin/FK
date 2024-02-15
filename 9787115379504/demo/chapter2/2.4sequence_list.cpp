#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
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
//创建
void Crt(SequenceList & list, int size) {
    if (size < 1 || size > 100) {
        return;
    }
    for (int i = 0; i < size; i++) {
        // cin >> list.elem[i];
        list.elem[i] = rand() % UCHAR_MAX;
        list.size++;
    }
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
//是否为空
bool IsEmpty(SequenceList list) {
    if (list.size == 0) {
        return true;
    }
    return false;
}
//插入元素
void Ins(SequenceList & list, int ins_index, int ins_elem) {
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
//删除
void Del(SequenceList & list, int del_index) {
    if (del_index < 0 || del_index > list.size || del_index >= 100) {
        return;
    }
    //向前移动 ins_index 之后的元素
    for (int i = del_index; i < list.size; i++) {
        list.elem[i] = list.elem[i + 1];
    }
    list.size--;
}
//查找元素下标
int SrchIndex(SequenceList list, int srch_elem) {
    for (int i = 0; i < list.size; i++) {
        if (list.elem[i] == srch_elem) {
            return i;
        }
    }
    return -1;
}
//查找元素值
int SrchElem(SequenceList list, int srch_index) {
    if (srch_index < 0 || srch_index > list.size || srch_index >= 100) {
        return NULL;
    }
    return list.elem[srch_index];
}
//清空
void Clr(SequenceList & list) {
    list.size = 0;
}
//销毁
void Des(SequenceList & list) {
    delete[] list.elem;
    list.elem = nullptr;
    list.size = 0;
}
int main() {
    srand((unsigned)time(NULL));
    SequenceList list = Init(list, 100);
    Crt(list, 100);
    Traverse(list);
    return 0;
}
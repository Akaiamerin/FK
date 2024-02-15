#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct SequenceStack {
    int * base; //栈底
    int * top; //栈顶
    int cap; //容量
};
//初始化
SequenceStack Init(SequenceStack & stk, int cap = 100) {
    stk.base = new int[cap];
    stk.top = stk.base;
    stk.cap = cap;
    return stk;
}
//遍历
void Traverse(SequenceStack stk) {
    for (int i = 0; i < (stk.top - stk.base); i++) {
        cout << stk.base[i] << " ";
    }
    cout << endl;
}
//元素数量
int GetSize(SequenceStack stk) {
    return stk.top - stk.base;
}
//是否为空
bool IsEmpty(SequenceStack stk) {
    if (stk.top == stk.base) {
        return true;
    }
    return false;
}
//入栈
void Push(SequenceStack & stk, int push_elem) {
    if ((stk.top - stk.base) == stk.cap) {
        return;
    }
    *stk.top++ = push_elem;
}
//出栈
void Pop(SequenceStack & stk) {
    if (stk.top == stk.base) {
        return;
    }
    stk.top--;
}
//栈顶元素
int Top(SequenceStack stk) {
    if (stk.top == stk.base) {
        return NULL;
    }
    return *(--stk.top);
}
//清空
void Clr(SequenceStack & stk) {
    if (stk.base != nullptr) {
        stk.top = stk.base;
    }
}
//销毁
void Des(SequenceStack & stk) {
    if (stk.base != nullptr) {
        delete[] stk.base;
        stk.base = nullptr;
    }
    stk.top = nullptr;
    stk.cap = 0;
}
int main() {
    srand((unsigned)time(NULL));
    SequenceStack stk = Init(stk, 100);
    for (int i = 0; i < 100; i++) {
        Push(stk, rand() % UCHAR_MAX);
    }
    Traverse(stk);
    return 0;
}
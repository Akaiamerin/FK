#include <iostream>
using namespace std;
struct DoublyStack {
    int base[2]; //栈底
    int top[2]; //栈顶
    int * elem; //元素
    int cap; //容量
};
//初始化
DoublyStack Init(DoublyStack & stk, int cap = 100) {
    stk.base[0] = 0;
    stk.top[0] = -1;
    stk.base[1] = cap;
    stk.top[1] = cap;
    stk.elem = new int[cap];
    stk.cap = cap;
    return stk;
}
//是否为空
bool IsEmpty(DoublyStack stk) {
    if (stk.top[0] == -1 && stk.top[1] == stk.cap) {
        return true;
    }
    return false;
}
//进栈
void Push(DoublyStack & stk, int push_no, int push_elem) {
    if (push_no < 0 || push_no > 1 || stk.top[1] - stk.top[0] == 1) {
        return;
    }
    if (push_no == 0) {
        stk.elem[++stk.top[0]] = push_elem;
    }
    else {
        stk.elem[--stk.top[1]] = push_elem;
    }
}
//出栈
void Pop(DoublyStack & stk, int pop_no) {
    if (pop_no < 0 || pop_no > 1) {
        return;
    }
    if (pop_no == 0) {
        if (stk.top[0] == -1) {
            return;
        }
        else {
            stk.top[0]--;
        }
    }
    else {
        if (stk.top[1] == stk.cap) {
            return;
        }
        else {
            stk.top[1]++;
        }
    }
}
int main() {
    DoublyStack stk = Init(stk, 100);
    Push(stk, 0, 1);
    Push(stk, 0, 2);
    Push(stk, 0, 3);
    Push(stk, 1, 4);
    Push(stk, 1, 5);
    Push(stk, 1, 6);
    for (int i = 0; i < stk.cap; i++) {
        cout << stk.elem[i] << " ";
    }
    cout << endl;
    return 0;
}
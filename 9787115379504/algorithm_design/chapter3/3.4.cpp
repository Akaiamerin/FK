#include <iostream>
using namespace std;
struct Stack {
    int * base; //栈底
    int * top; //栈顶
    int cap; //容量
};
//初始化
Stack Init(Stack & stk, int cap = 100) {
    stk.base = new int[cap];
    stk.top = stk.base;
    stk.cap = cap;
    return stk;
}
//遍历
void Traverse(Stack stk) {
    for (int i = 0; i < (stk.top - stk.base); i++) {
        cout << stk.base[i] << " ";
    }
    cout << endl;
}
//是否为空
bool IsEmpty(Stack stk) {
    if (stk.top == stk.base) {
        return true;
    }
    return false;
}
//入栈
void Push(Stack & stk, int push_elem) {
    if ((stk.top - stk.base) == stk.cap) {
        return;
    }
    *stk.top++ = push_elem;
}
//出栈
void Pop(Stack & stk) {
    if (stk.top == stk.base) {
        return;
    }
    stk.top--;
}
//栈顶元素
int Top(Stack stk) {
    if (stk.top == stk.base) {
        return 0;
    }
    return *(--stk.top);
}
int Calc(char str[], int size) {
    Stack stk = Init(stk, 100);
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num1 = num1 * 10 + (str[i] - '0');
        }
        else {
            if (str[i] == ' ') {
                Push(stk, num1);
            }
            else if (str[i] == '+') {
                num2 = Top(stk);
                Pop(stk);
                Push(stk, num2 + num1);
            }
            else if (str[i] == '-') {
                num2 = Top(stk);
                Pop(stk);
                Push(stk, num2 - num1);
            }
            else if (str[i] == '*') {
                num2 = Top(stk);
                Pop(stk);
                Push(stk, num2 * num1);
            }
            else if (str[i] == '/') {
                num2 = Top(stk);
                Pop(stk);
                Push(stk, num2 / num1);
            }
            else if (str[i] == '$') {
                num2 = Top(stk);
                Pop(stk);
                num1 = Top(stk);
                Pop(stk);
                num2 += num1;
                break;
            }
            num1 = 0;
        }
    }
    return num2;
}
int main() {
    char str[] = "234 34+2*$";
    int size = sizeof(str) / sizeof(str[0]);
    cout << Calc(str, size) << endl;
    return 0;
}
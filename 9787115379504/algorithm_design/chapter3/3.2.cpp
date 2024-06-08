#include <iostream>
#include <cstring>
using namespace std;
struct Stack {
    char * base; //栈底
    char * top; //栈顶
    int cap; //容量
};
//初始化
Stack Init(Stack & stk, int cap = 100) {
    stk.base = new char[cap];
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
void Push(Stack & stk, char push_elem) {
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
char Top(Stack stk) {
    if (stk.top == stk.base) {
        return '\0';
    }
    return *(--stk.top);
}
bool IsPalindrome(char str[]) {
    Stack stk = Init(stk, 100);
    for (int i = 0; i < strlen(str) / 2; i++) {
        Push(stk, str[i]);
    }
    int str_index = 0;
    if (strlen(str) % 2 == 0) {
        str_index = strlen(str) / 2;
    }
    else {
        str_index = strlen(str) / 2 + 1;
    }
    while (IsEmpty(stk) == false) {
        char pop_elem = Top(stk);
        Pop(stk);
        if (pop_elem != str[str_index]) {
            return false;
        }
        else {
            str_index++;
        }
    }
    return true;
}
int main() {
    char str1[] = "abba";
    cout << IsPalindrome(str1) << endl;
    char str2[] = "abdba";
    cout << IsPalindrome(str2) << endl;
    char str3[] = "good";
    cout << IsPalindrome(str3) << endl;
    return 0;
}
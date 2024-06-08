#include <iostream>
using namespace std;
//字符串逆序存储的递归算法 
void InvertStore(char str[]) {
    static int i = 0;
    char ch = {};
    cin >> ch;
    if (ch != '.') {
        InvertStore(str);
        str[i++] = ch;
    }
    str[i] = '\0';
}
int main() {
    char str[100];
    InvertStore(str);
    puts(str);
    cout << endl;
    return 0;
}
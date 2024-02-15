#include <iostream>
using namespace std;
//插入字符串
void Ins(char * str, char * ins_str, int ins_index) {
    int str_size = 1;
    int ins_str_size = 1;
    char * str_ptr = str;
    char * ins_str_ptr = ins_str;
    while (*str_ptr != '\0') {
        str_ptr++;
        str_size++;
    }
    while (*ins_str_ptr != '\0') {
        ins_str_ptr++;
        ins_str_size++;
    }
    if (ins_index < 0 || ins_index > str_size) {
        return;
    }
    for (int i = str_size; i > ins_index; i--) {
        *(str_ptr + ins_str_size - 1) = *(str_ptr);
        str_ptr--;
    }
    str_ptr++;
    ins_str_ptr = ins_str;
    while (*ins_str_ptr != '\0') {
        *(str_ptr++) = *(ins_str_ptr++);
    }
}
int main() {
    char str[10] = "abcde";
    char ins_str[10] = "fg";
    Ins(str, ins_str, 5);
    puts(str);
    cout << endl;
    return 0;
}
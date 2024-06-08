#include <iostream>
#include <cstring>
using namespace std;
void Format(char * str1, char * str2, char * str3, int n) {
    char * str1_ptr = str1;
    char * str2_ptr = str2;
    int index = 0;
    while (*str1_ptr != '\0' && *str1_ptr == ' ') {
        str1_ptr++;
    }
    if (*str1_ptr == '\0') {
        return;
    }
    while (*str1_ptr != '\0' && index < n) {
        *str2_ptr = *str1_ptr;
        str2_ptr++;
        str1_ptr++;
        index++;
    }
    if (*str1_ptr == '\0') {
        return;
    }
    if (*(--str2_ptr) == ' ') {
        str1_ptr--;
        while (*str1_ptr == ' ' && *str1_ptr != '\0') {
            str1_ptr++;
        }
        if (*str1_ptr == '\0') {
            return;
        }
        *str2_ptr = *str1_ptr;
        *(++str2_ptr) = '\0';
    }
    str2_ptr = str3;
    str1_ptr++;
    while (*str1_ptr != '\0') {
        *str2_ptr = *str1_ptr; str2_ptr++; str1_ptr++;
    }
    *str2_ptr = '\0';
}
int main() {
    int size = 100;
    char str1[size] = "a bb ccc dddd eeeee";
    char str2[size];
    char str3[size];
    Format(str1, str2, str3, 6);
    puts(str1);
    puts(str2);
    puts(str3);
    return 0;
}
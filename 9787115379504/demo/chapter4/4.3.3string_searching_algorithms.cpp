#include <iostream>
#include <string>
using namespace std;
//BruteForce 算法
int BruteForce(string str, string substr) {
    int str_index = 0;
    int substr_index = 0;
    while (str_index < str.size() && substr_index < substr.size()) {
        if (str[str_index] == substr[substr_index]) {
            str_index++;
            substr_index++;
        }
        else {
            str_index = str_index - substr_index + 1;
            substr_index = 0;
        }
    }
    if (substr_index >= substr.size()) {
        return str_index - substr.size();
    }
    return -1;
}
//next 数组的 KMP 算法
void Next(int next[], string substr) {
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (i < substr.size() - 1) {
        if (j == -1 || substr[i] == substr[j]) {
            next[++i] = ++j;
        }
        else {
            j = next[j];
        }
    }
}
int NextKMP(string str, string substr) {
    int next[substr.size()];
    Next(next, substr);
    for (int i = 0, j = 0; i <= str.size(); i++, j++) {
        if (j == substr.size()) {
            return i - j;
        }
        while (j != -1 && str[i] != substr[j]) {
            j = next[j];
        }
    }
    return -1;
}
//next_val 数组的 KMP 算法
void NextVal(int next_val[], string substr) {
    next_val[0] = -1;
    int i = 0;
    int j = -1;
    while (i < substr.size() - 1) {
        if (j == -1 || substr[i] == substr[j]) {
            i++;
            j++;
            if (substr[i] == substr[j]) {
                next_val[i] = next_val[j];
            }
            else {
                next_val[i] = j;
            }
        }
        else {
            j = next_val[j];
        }
    }
}
int NextValKMP(string str, string substr) {
    int next_val[substr.size()];
    NextVal(next_val, substr);
    for (int i = 0, j = 0; i <= str.size(); i++, j++) {
        if (j == substr.size()) {
            return i - j;
        }
        while (j != -1 && str[i] != substr[j]) {
            j = next_val[j];
        }
    }
    return -1;
}
int main() {
    string str = "abc abcdab abcdabcdabde";
    string substr = "abcdabd";
    cout << BruteForce(str, substr) << endl;
    cout << NextKMP(str, substr) << endl;
    cout << NextValKMP(str, substr) << endl;
    return 0;
}
#include <iostream>
using namespace std;
void DelElem(int list[], int n, int del_elem) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        while (left < right && list[left] != del_elem) {
            left++;
        }
        if (left < right) {
            while (left < right && list[right] == del_elem) {
                right--;
            }
        }
        if (left < right) {
            list[left++] = list[right--];
        }
    }
}
int main() {
    int list[] = {2, 6, 8, 9, 11, 15, 20};
    int n = sizeof(list) / sizeof(list[0]);
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    DelElem(list, n, 11);
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}
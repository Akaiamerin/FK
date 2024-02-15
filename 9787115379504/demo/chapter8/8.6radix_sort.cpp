#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//随机数组
void RandArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % UCHAR_MAX;
    }
}
//遍历
void Traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//基数排序
void RadixSort(int arr[], int size) {
    int radix = 1;
    int base10 = 10;
    int max_elem = arr[0];
    for (int i = 1; i < size; i++) {
        max_elem = max(arr[i], max_elem);
    }
    int max_bit = 1;
    while (max_elem >= base10) {
        max_elem /= base10;
        max_bit++;
    }
    for (; max_bit > 0; max_bit--) {
        int cnt_arr[base10];
        for (int i = 0; i < base10; i++) {
            cnt_arr[i] = 0;
        }
        for (int i = 0; i < size; i++) {
            cnt_arr[(arr[i] / radix) % base10]++;
        }
        for (int i = 1; i < base10; i++) {
            cnt_arr[i] += cnt_arr[i - 1];
        }
        int temp_arr[size];
        for (int i = size - 1; i >= 0; i--) {
            temp_arr[cnt_arr[arr[i] / radix % base10] - 1] = arr[i];
            cnt_arr[arr[i] / radix % base10]--;
        }
        for (int i = 0; i < size;i++) {
            arr[i] = temp_arr[i];
        }
        radix *= base10;
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    RadixSort(arr, size);
    Traverse(arr, size);
    return 0;
}
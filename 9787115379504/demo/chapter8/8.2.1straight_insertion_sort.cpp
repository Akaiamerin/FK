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
//直接插入排序
void StraightInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] >= arr[i - 1]) {
            continue;
        }
        int ins_elem = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (arr[j] > ins_elem) {
                arr[j + 1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j + 1] = ins_elem;
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    StraightInsertionSort(arr, size);
    Traverse(arr, size);
    return 0;
}
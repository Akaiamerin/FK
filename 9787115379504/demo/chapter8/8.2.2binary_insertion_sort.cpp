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
//折半插入排序
void BinaryInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] >= arr[i - 1]) {
            continue;
        }
        int ins_elem = arr[i];
        int left = 0;
        int right = i - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= ins_elem) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        for (int j = i - 1; j >= right + 1; j--) {
            arr[j + 1] = arr[j];
        }
        arr[right + 1] = ins_elem;
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    BinaryInsertionSort(arr, size);
    Traverse(arr, size);
    return 0;
}
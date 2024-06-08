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
//快速排序
void QuickSort(int arr[], int first, int last) {
    if (first >= last) {
        return;
    }
    int left = first;
    int right = last;
    int pivot_elem = arr[first];
    while (left < right) {
        while (left < right && arr[right] >= pivot_elem) {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot_elem) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot_elem;
    QuickSort(arr, first, left - 1);
    QuickSort(arr, left + 1, last);
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    QuickSort(arr, 0, size - 1);
    Traverse(arr, size);
    return 0;
}
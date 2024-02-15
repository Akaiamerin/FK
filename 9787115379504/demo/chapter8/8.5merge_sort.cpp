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
//归并两个有序序列
void MergeArr(int arr[], int first, int mid, int last) {
    int temp_arr_size = last - first + 1;
    int temp_arr[last - first + 1];
    int temp_arr_index = 0;
    int first1 = first;
    int first2 = mid + 1;
    while (first1 <= mid && first2 <= last) {
        if (arr[first1] <= arr[first2]) {
            temp_arr[temp_arr_index++] = arr[first1++];
        }
        else {
            temp_arr[temp_arr_index++] = arr[first2++];
        }
    }
    while (first1 <= mid) {
        temp_arr[temp_arr_index++] = arr[first1++];
    }
    while (first2 <= last) {
        temp_arr[temp_arr_index++] = arr[first2++];
    }
    for (int i = 0; i < temp_arr_size; i++) {
        arr[first + i] = temp_arr[i];
    }
}
//归并排序
void MergeSort(int arr[], int first, int last) {
    if (first >= last) {
        return;
    }
    int mid = first + (last - first) / 2;
    MergeSort(arr, first, mid);
    MergeSort(arr, mid + 1, last);
    MergeArr(arr, first, mid, last);
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    MergeSort(arr, 0, size - 1);
    Traverse(arr, size);
    return 0;
}
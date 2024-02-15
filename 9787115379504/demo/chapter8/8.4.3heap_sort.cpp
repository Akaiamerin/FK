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
//堆调整
void MaxHeapify(int arr[], int heap_size, int index) {
    int max_elem_index = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap_size && arr[left] > arr[max_elem_index]) {
        max_elem_index = left;
    }
    if (right < heap_size && arr[right] > arr[max_elem_index]) {
        max_elem_index = right;
    }
    if (max_elem_index != index) {
        int temp = arr[max_elem_index];
        arr[max_elem_index] = arr[index];
        arr[index] = temp;
        MaxHeapify(arr, heap_size, max_elem_index);
    }
}
//堆排序
void HeapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        MaxHeapify(arr, i - 1, 0);
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    HeapSort(arr, size);
    Traverse(arr, size);
    return 0;
}
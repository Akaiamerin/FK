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
//选择排序
void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_elem_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_elem_index]) {
                min_elem_index = j;
            }
        }
        if (min_elem_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_elem_index];
            arr[min_elem_index] = temp;
        }
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    SelectionSort(arr, size);
    Traverse(arr, size);
    return 0;
}
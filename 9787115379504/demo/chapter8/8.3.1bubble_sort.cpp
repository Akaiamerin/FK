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
//冒泡排序
void BubbleSort(int arr[], int size) {
    int swap_flag = true;
    for (int i = 0; swap_flag == true && i < size - 1; i++) {
        swap_flag = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_flag = true;
            }
        }
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    BubbleSort(arr, size);
    Traverse(arr, size);
    return 0;
}
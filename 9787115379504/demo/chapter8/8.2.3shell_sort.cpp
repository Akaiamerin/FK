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
//希尔排序
void ShellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int ins_elem = arr[i];
            int j = i;
            for (; j - gap >= 0; j -= gap) {
                if (arr[j - gap] > ins_elem) {
                    arr[j] = arr[j - gap];
                }
                else {
                    break;
                }
            }
            arr[j] = ins_elem;
        }
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    ShellSort(arr, size);
    Traverse(arr, size);
    return 0;
}
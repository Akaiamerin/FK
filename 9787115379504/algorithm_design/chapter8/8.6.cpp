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
//计数排序
void CountingSort(int arr[], int size) {
    int min_elem = arr[0];
    int max_elem = arr[0];
    for (int i = 1; i < size; i++) {
        min_elem = min(arr[i], min_elem);
        max_elem = max(arr[i], max_elem);
    }
    int cnt_arr_size = max_elem - min_elem + 1;
    int cnt_arr[cnt_arr_size];
    for (int i = 0; i < cnt_arr_size; i++) {
        cnt_arr[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        cnt_arr[arr[i] - min_elem]++;
    }
    int arr_index = 0;
    for (int i = 0; i < cnt_arr_size; i++) {
        for (int j = 0; j < cnt_arr[i]; j++) {
            arr[arr_index++] = i + min_elem;
        }
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    CountingSort(arr, size);
    Traverse(arr, size);
    return 0;
}
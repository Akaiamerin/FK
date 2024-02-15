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
//顺序查找
int SequentialSearch(int arr[], int size, int srch_elem) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == srch_elem) {
            return i;
        }
    }
    return -1;
}
int main() {
    srand((unsigned)time(NULL));
    int size = 10;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    int srch_elem = 0;
    cin >> srch_elem;
    cout << SequentialSearch(arr, size, srch_elem) << endl;
    return 0;
}
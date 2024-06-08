#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
//随机升序数组
void RandAscArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % UCHAR_MAX;
    }
    sort(arr, arr + size);
}
//遍历
void Traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//折半查找递归
int BinarySearch(int arr[], int srch_elem, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < srch_elem) {
            return BinarySearch(arr, srch_elem, mid + 1, right);
        }
        else if (arr[mid] > srch_elem) {
            return BinarySearch(arr, srch_elem, left, mid - 1);
        }
        else {
            return mid;
        }
    }
    return -1;
}
int main() {
    srand((unsigned)time(NULL));
    int size = 10;
    int arr[size];
    RandAscArr(arr, size);
    Traverse(arr, size);
    int srch_elem = 0;
    cin >> srch_elem;
    cout << BinarySearch(arr, srch_elem, 0, size - 1) << endl;
    return 0;
}
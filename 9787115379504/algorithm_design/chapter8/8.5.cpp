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
int SrchElem(int arr[], int size, int srch_elem) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        while (left < right && arr[left] < srch_elem) {
            left++;
        }
        if (arr[left] == srch_elem) {
            return left;
        }
        else {
            left++;
        }
        while (left < right && arr[right] > srch_elem) {
            right--;
        }
        if (arr[right] == srch_elem) {
            return right;
        }
        else {
            right--;
        }
    }
    return -1;
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    int srch_elem = 0;
    cin >> srch_elem;
    cout << SrchElem(arr, size, srch_elem) << endl;
    return 0;
}
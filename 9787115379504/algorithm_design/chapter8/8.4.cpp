#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//随机数组
void RandArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (CHAR_MAX - CHAR_MIN + 1) + CHAR_MIN;
    }
}
//遍历
void Traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Sort(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        while (left < right && arr[left] < 0) {
            left++;
        }
        while (left < right && arr[right] > 0) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}
int main() {
    srand((unsigned)time(NULL));
    int size = 100;
    int arr[size];
    RandArr(arr, size);
    Traverse(arr, size);
    Sort(arr, size);
    Traverse(arr, size);
}
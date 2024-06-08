#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//随机数组
void RandArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (3 - 1 + 1) + 1; //[red, 1] [white, 2] [blue, 3]
    }
}
//遍历
void Traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//对砾石进行排序 [0, j) 作为红色，[j, k) 为白色，[k, size - 1) 为蓝色
void Sort(int arr[], int size) {
    int i = 0;
    int j = 0;
    int k = size - 1;
    while (j <= k) {
        if (arr[j] == 1) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if (i != j) {
                cout << i << "->" << j << endl;
            }
            i++;
            j++;
        }
        else if (arr[j] == 2) {
            j++;
        }
        else {
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;
            if (k != j) {
                cout << j << "->" << k << endl;
            }
            k--;
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
#include <iostream>
using namespace std;
int main() {
    int arr[] = {-1, -2, -3, 1, 2, 3};
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    while (left < right) {
        while (left < right && arr[left] > 0) {
            left++;
        }
        while (left < right && arr[right] < 0) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
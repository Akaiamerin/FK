#include <iostream>
using namespace std;
int main() {
    int arr[100];
    int top = 0;
    for (int i = 0; i < 100; i++) {
        int elem = 0;
        cin >> elem;
        if (elem != -1) {
            if (top >= 100) {
                return 0;
            }
            arr[top++] = elem;
        }
        else {
            if (top < 1) {
                return 0;
            }
            cout << arr[--top] << endl;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    char arr[] = "IOIIOIOO";
    int size = sizeof(arr) / sizeof(arr[0]);
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 'I') {
            cnt++;
        }
        else if (arr[i] == 'O') {
            if (cnt < 1) {
                cout << "false" << endl;
                break;
            }
            else {
                cnt--;
            }
        }
    }
    if (cnt == 0) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
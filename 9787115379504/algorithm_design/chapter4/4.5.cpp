#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand((unsigned)time(NULL));
    int row = 5;
    int col = 5;
    int a[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            a[i][j] = 0;
        }
    }
    int min_elem = a[0][0];
    int max_elem = a[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            a[i][j] = rand() % UCHAR_MAX;
            cout << a[i][j] << " ";
            if (a[i][j] < min_elem) {
                min_elem = a[i][j];
            }
            if (a[i][j] > max_elem) {
                max_elem = a[i][j];
            }
        }
        cout << endl;
    }
    int cnt_size = max_elem - min_elem + 1;
    int cnt[cnt_size];
    for (int i = 0; i < cnt_size; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cnt[a[i][j] - min_elem]++;
            if (cnt[a[i][j] - min_elem] > 1) {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
    return 0;
}
#include <iostream>
using namespace std;
int Ack1(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (m != 0 && n == 0) {
        return Ack1(m - 1, 1);
    }
    else if (m != 0 && n != 0) {
        return Ack1(m - 1, Ack1(m, n - 1));
    }
}
int Ack2(int m, int n) {
    int ret[m + 1][100];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < 100; j++) {
            ret[i][j] = 0;
        }
    }
    for (int j = 0; j < 100; j++) {
        ret[0][j] = j + 1;
    }
    for (int i = 1; i <= m; i++) {
        ret[i][0] = ret[i - 1][1];
        for (int j = 1; j < 100; j++) {
            ret[i][j] = ret[i - 1][ret[i][j - 1]];
        }
    }
    return ret[m][n];
}
int main() {
    cout << Ack1(2, 1) << endl;
    cout << Ack2(2, 1) << endl;
    return 0;
}
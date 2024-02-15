#include <iostream>
using namespace std;
int main() {
    char str[100];
    cin.getline(str, sizeof(str) / sizeof(str[0]));
    int cnt[36];
    for (int i = 0; i < 36; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            cnt[str[i] - '0']++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            cnt[str[i] - 'A' + 10]++;
        }
    }
    for (int i = 0; i < sizeof(cnt) / sizeof(cnt[0]); i++) {
        if (i < 10) {
            cout << "[" << (char)(i + '0') << ": " << cnt[i] << "]" << endl;
        }
        else {
            cout << "[" << (char)(i + 'A' - 10) << ": " << cnt[i] << "]" << endl;
        }
    }
    return 0;
}
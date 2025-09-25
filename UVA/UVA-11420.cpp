#include <iostream>
using namespace std;

int main() {
    long long a[67][67]{0}, b[67][67]{0};
    int n, s;
    a[1][1] = 1;  // top = L
    b[1][0] = 1;  // top = U
    for (int i = 2; i <= 65; ++i) {
        b[i][0] = b[i - 1][0] + a[i - 1][1];
        for (int j = 1; j <= i; ++j) {
            a[i][j] = a[i - 1][j - 1] + b[i - 1][j - 1];
            b[i][j] = a[i - 1][j + 1] + b[i - 1][j];
        }
    }
    while (cin >> n >> s, n >= 0 && s >= 0)
        cout << a[n][s] + b[n][s] << endl;
    return 0;
}

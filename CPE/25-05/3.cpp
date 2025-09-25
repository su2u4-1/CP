#include <iostream>
using namespace std;

void f(int s[], int d, int k, int p, string r) {
    if (d == 6) {
        cout << r.substr(1) << '\n';
        return;
    }
    for (int i = p + 1; i < k; ++i)
        f(s, d + 1, k, i, r + ' ' + to_string(s[i]));
}

int main() {
    int k, s[13];
    bool flag = false;
    while (cin >> k, k) {
        if (flag)
            cout << '\n';
        flag = true;
        for (int i = 0; i < k; ++i)
            cin >> s[i];
        f(s, 0, k, -1, "");
    }
    return 0;
}

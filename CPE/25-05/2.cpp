#include <iostream>
using namespace std;

int main() {
    int n, s1, s2;
    while (cin >> n, n) {
        bool m[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> m[i][j];
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            s1 = 0;
            s2 = 0;
            for (int j = 0; j < n; ++j) {
                if (m[i][j])
                    ++s1;
                if (m[j][i])
                    ++s2;
            }
            if (s1 % 2 || s2 % 2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "OK" << endl;
            continue;
        }
        bool success = false;
        for (int ii = 0; ii < n; ++ii) {
            for (int jj = 0; jj < n; ++jj) {
                m[ii][jj] = !m[ii][jj];
                ok = true;
                for (int i = 0; i < n; ++i) {
                    s1 = 0;
                    s2 = 0;
                    for (int j = 0; j < n; ++j) {
                        if (m[i][j])
                            ++s1;
                        if (m[j][i])
                            ++s2;
                    }
                    if (s1 % 2 || s2 % 2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << "Change bit (" << ii + 1 << "," << jj + 1 << ")" << endl;
                    success = true;
                    break;
                } else
                    m[ii][jj] = !m[ii][jj];
            }
            if (success)
                break;
        }
        if (!success)
            cout << "Corrupt" << endl;
    }
}

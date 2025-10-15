#include <memory.h>

#include <iostream>
using namespace std;

int main() {
    int n, m[105][105], rs[105], gmx = 0, lmx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> m[i][j];
    for (int l = 0; l < n; ++l) {
        memset(rs, 0, sizeof(rs));
        for (int r = l; r < n; ++r) {
            int fmx = 0, tmx = 0;
            for (int i = 0; i < n; ++i) {
                rs[i] += m[i][r];
                fmx = max(fmx, tmx = max(tmx + rs[i], rs[i]));
            }
            gmx = max(gmx, lmx = fmx);
        }
    }
    cout << gmx << endl;
    return 0;
}

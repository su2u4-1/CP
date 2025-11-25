#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    int n;
    char t;
    while (cin >> n) {
        vector<vector<int>> m(n, vector<int>(n));
        vector<vector<int>> w(n, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> t;
                m[i][j] = t - '0';
                if (m[i][j] == 3)
                    w[i][j] = 0;
            }
        }
        int ans = 0;
        for (int k = 0; k < 2 * n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    for (int d = 0; d < 4; ++d) {
                        int nx = i + D[d][0], ny = j + D[d][1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        w[i][j] = min(w[i][j], w[nx][ny] + 1);
                    }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (m[i][j] == 1)
                    ans = max(ans, w[i][j]);
        cout << ans << endl;
    }
    return 0;
}

/*
4
1223
2123
2213
3212
2
12
33
*/
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n, m, map[105][105], sx, sy, tx, ty, mi = INT_MAX, ans;
    const int D[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
            if (map[i][j] < mi) {
                mi = map[i][j];
                sx = i, sy = j;
            }
        }
    for (int i = 0; i < n + 2; ++i) {
        map[i][0] = INT_MAX;
        map[i][m + 1] = INT_MAX;
    }
    for (int j = 0; j < m + 2; ++j) {
        map[0][j] = INT_MAX;
        map[n + 1][j] = INT_MAX;
    }
    bool run = true;
    ans = mi;
    map[sx][sy] = INT_MAX;

    while (run) {
        mi = INT_MAX;
        tx = -1, ty = -1;
        for (int d = 0; d < 4; ++d) {
            int nx = sx + D[d][0], ny = sy + D[d][1];
            if (map[nx][ny] < mi) {
                tx = nx, ty = ny;
                mi = map[nx][ny];
            }
        }
        if (tx == -1 || ty == -1 || mi == INT_MAX)
            break;
        ans += mi;
        sx = tx, sy = ty;
        map[sx][sy] = INT_MAX;
    }
    cout << ans << endl;
    return 0;
}

#include <climits>
#include <iostream>
#include <queue>
using namespace std;

struct P {
    int c, x, y;
    bool operator>(const P& other) const {
        return c > other.c;
    }
};

int N, maze[1005][1005], n, m, g[1005][1005], D[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool v[1005][1005];
int main() {
    cin >> N;
    while (N--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> maze[i][j];
                g[i][j] = INT_MAX;
                v[i][j] = false;
            }
        priority_queue<P, vector<P>, greater<P>> open;
        g[0][0] = maze[0][0];
        open.push({g[0][0], 0, 0});
        v[0][0] = true;
        while (!open.empty()) {
            auto [_, x, y] = open.top();
            open.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + D[d][0], ny = y + D[d][1];
                int tg = g[x][y] + maze[nx][ny];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && tg < g[nx][ny] && !v[nx][ny]) {
                    g[nx][ny] = tg;
                    open.push({g[nx][ny], nx, ny});
                    v[nx][ny] = true;
                }
            }
        }
        cout << g[n - 1][m - 1] << endl;
    }
    return 0;
}

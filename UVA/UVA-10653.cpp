#include <iostream>
#include <queue>
using namespace std;

int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};

int main() {
    int R, C;
    cin >> R >> C;
    int grid[R][C];
    while (R != 0 && C != 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = 0;
            }
        }
        int N, r, n, t;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> r >> n;
            for (int i = 0; i < n; i++) {
                cin >> t;
                grid[r][t] = -1;
            }
        }
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        queue<pair<int, int>> q;
        q.push({sx, sy});
        grid[sx][sy] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                    if (grid[nx][ny] > 0)
                        grid[x][y] = min(grid[x][y], grid[nx][ny] + 1);
                    else if (grid[nx][ny] == 0) {
                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << grid[ex][ey] - 1 << endl;
        cin >> R >> C;
    }
    return 0;
}

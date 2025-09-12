#include <iostream>
#include <queue>
using namespace std;

int D[8][2]{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int board[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = -1;
    queue<pair<int, int>> q;
    q.push({x - 1, y - 1});
    board[x - 1][y - 1] = 0;
    while (!q.empty()) {
        auto [nx, ny] = q.front();
        q.pop();
        for (int d = 0; d < 8; d++) {
            int tx = nx + D[d][0], ty = ny + D[d][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] == -1) {
                board[tx][ty] = board[nx][ny] + 1;
                q.push({tx, ty});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

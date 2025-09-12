#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dm[4] = {'R', 'L', 'D', 'U'};
int main() {
    int n, m, sx, sy, ex, ey;
    cin >> n >> m;
    int maze[n][m];
    for (int i = 0; i < n; i++) {
        cin.get();
        for (int j = 0; j < m; j++) {
            char t;
            cin.get(t);
            if (t == '#')
                maze[i][j] = 1;
            else {
                maze[i][j] = 0;
                if (t == 'A')
                    sx = i, sy = j;
                else if (t == 'B')
                    ex = i, ey = j;
            }
        }
    }
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    maze[sx][sy] = 1;
    tuple<int, int, char> p[n][m];
    p[sx][sy] = {-1, -1, '\0'};
    bool flag = true;
    while (!q.empty()) {
        auto [tx, ty, step] = q.front();
        q.pop();
        if (tx == ex && ty == ey) {
            cout << "YES\n"
                 << step << '\n';
            char c = get<2>(p[ex][ey]);
            int ntx = get<0>(p[ex][ey]), nty = get<1>(p[ex][ey]);
            string path;
            while (c != '\0') {
                path += c;
                auto [px, py, pc] = p[ntx][nty];
                ntx = px, nty = py, c = pc;
            }
            reverse(path.begin(), path.end());
            cout << path << '\n';
            flag = false;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                maze[nx][ny] = 1;
                p[nx][ny] = {tx, ty, dm[i]};
                q.push({nx, ny, step + 1});
            }
        }
    }
    if (flag)
        cout << "NO\n";
    return 0;
}

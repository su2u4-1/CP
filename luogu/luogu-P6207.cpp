#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int D[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    int r, c;
    cin >> r >> c;
    bool maze[r][c];
    for (int i = 0; i < r; i++) {
        cin.get();
        for (int j = 0; j < c; j++) {
            char t;
            cin.get(t);
            if (t == '*') {
                maze[i][j] = false;
            } else {
                maze[i][j] = true;
            }
        }
    }
    pair<int, int> p[r][c];
    p[0][0] = {-1, -1};
    queue<pair<int, int>> q;
    q.push({0, 0});
    maze[0][0] = false;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == r - 1 && y == c - 1)
            break;
        for (int d = 0; d < 4; d++) {
            int nx = x + D[d][0], ny = y + D[d][1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && maze[nx][ny]) {
                maze[nx][ny] = false;
                p[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    vector<pair<int, int>> path;
    int x = r - 1, y = c - 1;
    while (x != -1 && y != -1) {
        path.push_back({x, y});
        auto [tx, ty] = p[x][y];
        x = tx, y = ty;
    }
    reverse(path.begin(), path.end());
    for (auto [px, py] : path)
        cout << px + 1 << " " << py + 1 << "\n";
    return 0;
}

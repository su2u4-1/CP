#include <iostream>
using namespace std;

int D[4][2]{{-1, 0}, {-1, -1}, {0, -1}, {-1, 1}};

int main() {
    int n, count = 0;
    string line;
    int visited[25][25];
    while (cin >> n) {
        int b_count = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> line;
            for (int j = 0; j < n; ++j) {
                visited[i][j] = line[j] - '1';
                if (visited[i][j] == 0) {
                    for (int d = 0; d < 4; ++d) {
                        int x = i + D[d][0], y = j + D[d][1];
                        if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] > 0) {
                            if (visited[i][j] == 0)
                                visited[i][j] = visited[x][y];
                            else if (visited[i][j] != visited[x][y]) {
                                ans--;
                                int old = visited[x][y], new_ = visited[i][j];
                                for (int a = 0; a < n; ++a) {
                                    for (int b = 0; b < n; ++b) {
                                        if (visited[a][b] == old)
                                            visited[a][b] = new_;
                                    }
                                }
                            }
                        }
                    }
                    if (visited[i][j] == 0) {
                        visited[i][j] = ++b_count;
                        ans++;
                    }
                }
            }
        }
        cout << "Image number " << ++count << " contains " << ans << " war eagles.\n";
    }
    return 0;
}

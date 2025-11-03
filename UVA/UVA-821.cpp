#include <cstring>
#include <iostream>
using namespace std;

int dist[105][105], a, b, case_n = 0;
int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);
    cin >> a >> b;
    do {
        memset(dist, -1, sizeof(dist));
        while (a && b) {
            dist[a][b] = 1;
            dist[a][a] = 0;
            dist[b][b] = 0;
            cin >> a >> b;
        }
        for (int k = 1; k <= 100; ++k)
            for (int i = 1; i <= 100; ++i)
                for (int j = 1; j <= 100; ++j)
                    if (dist[i][k] != -1 && dist[k][j] != -1) {
                        if (dist[i][j] == -1 || dist[i][k] + dist[k][j] < dist[i][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
                    }
        float ans = 0, cnt = 0;
        for (int i = 1; i <= 100; ++i)
            for (int j = 1; j <= 100; ++j)
                if (i != j && dist[i][j] != -1) {
                    ans += dist[i][j];
                    ++cnt;
                }
        cout << "Case " << ++case_n << ": average length between pages = " << ans / cnt << " clicks\n";
        cin >> a >> b;
    } while (a && b);
    return 0;
}

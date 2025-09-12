// https://vjudge.net/problem/CSES-1667
// MLE 6/12
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool cf[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cf[i][j] = false;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cf[a - 1][b - 1] = true;
        cf[b - 1][a - 1] = true;
    }
    queue<int> q;
    int p[n];
    int v[n];
    for (int i = 0; i < n; i++)
        p[i] = -1;
    for (int i = 1; i < n; i++)
        v[i] = -1;
    v[0] = 0;
    bool flag = true;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (cf[x][i] && v[i] == -1) {
                q.push(i);
                p[i] = x;
                v[i] = v[x] + 1;
            }
        }
        if (v[n - 1] != -1) {
            cout << v[n - 1] + 1 << endl;
            string s = " " + to_string(n);
            int i = p[n - 1];
            while (i != -1) {
                if (i == 0)
                    s = to_string(i + 1) + s;
                else
                    s = " " + to_string(i + 1) + s;
                i = p[i];
            }
            cout << s << endl;
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}

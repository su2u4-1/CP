#include <iostream>
#include <queue>
using namespace std;

int main() {
    bool f[100005];
    int v[100005], N;
    cin >> N;
    for (int o = 1; o <= N; o++) {
        for (int i = 1; i <= 100005; i++) {
            f[i] = true;
            v[i] = -1;
        }
        int x, y;
        cin >> x >> y;
        queue<int> q;
        q.push(x);
        f[x] = false;
        v[x] = 0;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            if (n + 1 >= 0 && n + 1 < 100005 && f[n + 1]) {
                q.push(n + 1);
                f[n + 1] = false;
                v[n + 1] = v[n] + 1;
            }
            if (n - 1 >= 0 && n - 1 < 100005 && f[n - 1]) {
                q.push(n - 1);
                f[n - 1] = false;
                v[n - 1] = v[n] + 1;
            }
            if (n * 2 >= 0 && n * 2 < 100005 && f[n * 2]) {
                q.push(n * 2);
                f[n * 2] = false;
                v[n * 2] = v[n] + 1;
            }
            if (v[y] != -1) {
                cout << v[y] << endl;
                break;
            }
        }
    }
    return 0;
}

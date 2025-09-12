#include <iostream>
#include <queue>
using namespace std;

int main() {
    int en;
    cin >> en;
    int f[en][en];
    for (int i = 0; i < en; i++)
        for (int j = 0; j < en; j++)
            f[i][j] = -1;

    for (int i = 0; i < en; i++) {
        int n, t;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> t;
            f[i][t] = 0;
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        queue<pair<int, int>> q;
        int b[en], s;
        bool v[en];
        cin >> s;
        for (int i = 0; i < en; i++) {
            for (int j = 0; j < en; j++)
                if (f[i][j] == 1)
                    f[i][j] = 0;
            v[i] = true;
        }
        for (int i = 0; i < en; i++)
            b[i] = 0;
        v[s] = false;
        q.push({s, 0});
        while (!q.empty()) {
            auto [n, d] = q.front();
            b[d]++;
            q.pop();
            for (int j = 0; j < en; j++) {
                if (f[n][j] == 0 && v[j]) {
                    f[n][j] = 1;
                    v[j] = false;
                    q.push({j, d + 1});
                }
            }
        }

        int mb = 0, md = 0;
        for (int j = 1; j < en; j++) {
            if (b[j] > mb) {
                mb = b[j];
                md = j;
            }
        }
        if (md == 0)
            cout << 0 << endl;
        else
            cout << mb << " " << md << endl;
    }
    return 0;
}

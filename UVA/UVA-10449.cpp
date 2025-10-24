#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int N = 0, n, r, q, node[205], edge[205][205], ts, te, d[205];
    bool f[205][205], c;
    while (cin >> n) {
        for (int i = 0; i < n; ++i)
            cin >> node[i];
        memset(f, false, sizeof(f));
        cin >> r;
        while (r--) {
            cin >> ts >> te;
            --ts, --te;
            edge[ts][te] = pow(node[te] - node[ts], 3);
            f[ts][te] = true;
        }
        for (int i = 0; i < n; ++i)
            d[i] = INT_MAX;
        d[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (f[i][j] && d[i] != INT_MAX)
                    d[j] = min(d[j], d[i] + edge[i][j]);
        c = true;
        while (c) {
            c = false;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (f[i][j]) {
                        if (d[i] != INT_MAX && d[i] + edge[i][j] < d[j]) {
                            d[j] = d[i] + edge[i][j];
                            if (!f[j][j]) {
                                f[j][j] = true;
                                c = true;
                            }
                        }
                        if (f[i][i] && !f[j][j]) {
                            f[j][j] = true;
                            c = true;
                        }
                    }
        }
        cin >> q;
        cout << "Set #" << ++N << endl;
        while (q--) {
            cin >> ts;
            --ts;
            if (f[ts][ts] || d[ts] < 3 || d[ts] == INT_MAX)
                cout << "?" << endl;
            else
                cout << d[ts] << endl;
        }
    }
    return 0;
}

#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& b) const { return w < b.w; }
};

int N, ans, n, w, d, edge_index, dsu[550];
Edge edges[255000];
string nodes[550];
bool zero;

int main() {
    cin >> N;
    while (N--) {
        cin >> n;
        ans = 0;
        edge_index = 0;
        nodes[0] = "0000";
        dsu[0] = 0;
        zero = false;
        for (int i = 1; i <= n; i++) {
            cin >> nodes[i];
            for (int j = 0; j < i; j++) {
                w = 0;
                for (int k = 0; k < 4; k++) {
                    d = abs(nodes[i][k] - nodes[j][k]);
                    w += min(d, 10 - d);
                }
                edges[edge_index++] = {i, j, w};
            }
            dsu[i] = i;
        }
        sort(edges, edges + edge_index);
        for (int i = 0; i < edge_index; i++) {
            if (edges[i].u == 0 || edges[i].v == 0) {
                if (zero)
                    continue;
                zero = true;
            }
            int pu = dsu[edges[i].u], pv = dsu[edges[i].v];
            if (pu != pv) {
                ans += edges[i].w;
                for (int j = 0; j <= n; j++)
                    if (dsu[j] == pv)
                        dsu[j] = dsu[pu];
            }
        }
        cout << ans << endl;
    }
    return 0;
}

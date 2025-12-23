#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> ans;
int n, m, a, b;
vector<int> d, low, parent;
int timer;

void f(int u) {
    low[u] = d[u] = ++timer;
    int children = 0, cut_children = 0;
    for (int v : adj[u])
        if (d[v] == 0) {
            children++;
            parent[v] = u;
            f(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] != -1 && low[v] >= d[u])
                cut_children++;
        } else if (v != parent[u])
            low[u] = min(low[u], d[v]);
    if (parent[u] == -1 && children > 1)
        ans.push_back({u, children});
    else if (parent[u] != -1 && cut_children > 0)
        ans.push_back({u, cut_children + 1});
    else
        ans.push_back({u, 1});
}

int main() {
    while (cin >> n >> m, n || m) {
        adj.assign(n, vector<int>());
        while (cin >> a >> b, a != -1 || b != -1) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ans.clear();
        timer = 0;
        d.assign(n, 0);
        low.assign(n, 0);
        parent.assign(n, -1);
        for (int i = 0; i < n; ++i)
            if (d[i] == 0)
                f(i);
        sort(ans.begin(), ans.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        });
        for (int i = 0; i < m; ++i) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
        cout << "\n";
    }
    return 0;
}

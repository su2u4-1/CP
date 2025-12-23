#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int id, d = 0, low = 0;
    Node *parent = nullptr;
    vector<int> adj;
    Node(int id) : id(id) {}
};

vector<Node *> nodes;
vector<pair<int, int>> bridges;
int dfsTime = 0;

void find_bridges(int u) {
    nodes[u]->d = nodes[u]->low = ++dfsTime;
    for (int v : nodes[u]->adj) {
        if (nodes[v]->d == 0) {
            nodes[v]->parent = nodes[u];
            find_bridges(v);
            nodes[u]->low = min(nodes[u]->low, nodes[v]->low);
        } else if (nodes[v] != nodes[u]->parent)
            nodes[u]->low = min(nodes[u]->low, nodes[v]->d);
    }
    if (nodes[u]->parent != nullptr && nodes[u]->low == nodes[u]->d)
        bridges.push_back({min(nodes[u]->id, nodes[u]->parent->id), max(nodes[u]->id, nodes[u]->parent->id)});
}

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            cout << "0 critical links\n\n";
            continue;
        }
        nodes.clear();
        for (int i = 0; i < N; i++)
            nodes.push_back(new Node(i));
        for (int i = 0; i < N; i++) {
            int u, n, v;
            char ch;
            cin >> u >> ch >> n >> ch;
            for (int j = 0; j < n; j++) {
                cin >> v;
                nodes[u]->adj.push_back(v);
            }
        }
        dfsTime = 0;
        bridges.clear();
        for (int u = 0; u < N; u++)
            if (nodes[u]->d == 0)
                find_bridges(u);
        sort(bridges.begin(), bridges.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });
        cout << bridges.size() << " critical links\n";
        for (auto [a, b] : bridges)
            cout << a << " - " << b << "\n";
        cout << "\n";
    }
    return 0;
}

#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& b) const { return w < b.w || u < b.u; }
};

int getint() {
    string s;
    cin >> s;
    if (s[s.size() - 1] == ',')
        s.pop_back();
    return stoi(s);
}

char AtoZ[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int N, city, t, tunnel_index = 0, dsu[700];
Edge tunnel[700];
string s;

int main() {
    cin >> N;
    for (int case_n = 0; case_n < N; case_n++) {
        cin >> city;
        tunnel_index = 0;
        for (int i = 0; i < city; i++) {
            for (int j = 0; j < i; j++)
                getint();
            for (int j = i; j < city; j++)
                if ((t = getint()) > 0)
                    tunnel[tunnel_index++] = {i, j, t};
        }
        sort(tunnel, tunnel + tunnel_index);
        for (int i = 0; i < city; i++)
            dsu[i] = i;
        cout << "Case " << case_n + 1 << ":\n";
        for (int i = 0; i < tunnel_index; ++i) {
            int pu = dsu[tunnel[i].u], pv = dsu[tunnel[i].v];
            if (pu != pv) {
                cout << AtoZ[tunnel[i].u] << "-" << AtoZ[tunnel[i].v] << " " << tunnel[i].w << "\n";
                for (int j = 0; j < tunnel_index; j++)
                    if (dsu[j] == pv)
                        dsu[j] = pu;
            }
        }
    }
    return 0;
}

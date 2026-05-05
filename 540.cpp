#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, x, time = 0;
    bool first = true;
    while (cin >> t, t) {
        vector<vector<int>> teams;
        for (int i = 0; i < t; ++i) {
            cin >> n;
            teams.push_back(vector<int>());
            for (int j = 0; j < n; ++j) {
                cin >> x;
                teams[i].push_back(x);
            }
        }
        if (!first) cout << endl;
        first = false;
        cout << "Scenario #" << ++time << endl;
        vector<int> q;
        vector<int> team;
        while (true) {
            string op;
            cin >> op;
            if (op == "ENQUEUE") {
                cin >> x;
                int te = -1;
                for (int i = 0; i < n; ++i) {
                    for (int e: teams[i]) {
                        if (e == x) {
                            te = i;
                            break;
                        }
                    }
                    if (te != -1) break;
                }
                bool f = false, ff = false;
                for (int i = 0; i < q.size(); ++i) {
                    if (team[i] == te) {
                        f = true;
                    } else if (f) {
                        q.insert(q.begin() + i, x);
                        team.insert(team.begin() + i, te);
                        ff = true;
                        break;
                    }
                }
                if (!ff) {
                    q.push_back(x);
                    team.push_back(te);
                }
            } else if (op == "DEQUEUE") {
                cout << q.front() << endl;
                q.erase(q.begin());
                team.erase(team.begin());
            } else
                break;
        }
    }
    return 0;
}

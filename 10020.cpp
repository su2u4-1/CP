#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int m, l, r;
        vector<pair<int, int>> lines;
        cin >> m;
        while (cin >> l >> r, l || r) {
            if (r >= 0 && l <= m) {
                lines.push_back({l, r});
            }
        }
        sort(lines.begin(), lines.end(), [](pair<int, int> a, pair<int, int> b){
            if (a.first != b.first) return a.first < b.first;
            if ((a.second - a.first) != (b.second - b.first)) return (a.second - a.first) > (b.second - b.first);
            return a.second < b.second;
        });
        // TODO
    }
    return 0;
}

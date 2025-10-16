#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    pair<int, int> m[200005];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> m[i].first >> m[i].second;
    sort(m, m + n, [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
    int r = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (m[i].first >= r) {
            r = m[i].second;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, t, s[100005], mx, mi;
    vector<int> S;
    cin >> n >> k >> t;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <= n; ++j) {
            mx = s[i];
            mi = s[i];
            for (int k = i; k < j; ++k) {
                mx = max(s[k], mx);
                mi = min(s[k], mi);
            }
            if (mx - mi <= t)
                S.push_back(mx - mi);
        }
    }
    sort(S.begin(), S.end());
    cout << S[S.size() - k] << endl;
    return 0;
}

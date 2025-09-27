#include <iostream>
using namespace std;

int main() {
    int n, k, m, ans = 0, S[105], s;
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i)
        cin >> S[i];
    for (int i = 0; i < n - k + 1; ++i) {
        s = 0;
        for (int j = 0; j < k; ++j)
            s += S[i + j];
        if (s / k >= m)
            ++ans;
    }
    cout << ans;
    return 0;
}

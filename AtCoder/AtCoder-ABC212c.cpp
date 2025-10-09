#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n, m, a[200005], b[200005], mx = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ta = n - 1, tb = m - 1;
    while (ta >= 0 && tb >= 0) {
        mx = min(mx, abs(a[ta] - b[tb]));
        if (a[ta] < b[tb])
            --tb;
        else
            --ta;
    }
    cout << mx << endl;
    return 0;
}

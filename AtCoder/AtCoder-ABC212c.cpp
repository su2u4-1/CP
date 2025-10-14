#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int f(int b[], int m, int x) {
    int ans = 0, step = m;
    while (step) {
        if (ans + step < m && b[ans + step] < x)
            ans += step;
        else
            step /= 2;
    }
    return (ans + 1 < m ? min(abs(x - b[ans + 1]), abs(x - b[ans])) : abs(x - b[ans]));
}

int main() {
    int n, m, a[200005], b[200005], mi = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    // int ta = n - 1, tb = m - 1;
    // while (ta >= 0 && tb >= 0) {
    //     mi = min(mi, abs(a[ta] - b[tb]));
    //     if (a[ta] < b[tb])
    //         --tb;
    //     else
    //         --ta;
    // }
    for (int i = 0; i < n; ++i)
        mi = min(mi, f(b, m, a[i]));
    cout << mi << endl;
    return 0;
}

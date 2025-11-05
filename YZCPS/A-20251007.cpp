#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int f(int b[], int m, int x) {
    int ans = 0, step = m;
    while (step)
        if (ans + step < m && b[ans + step] < x)
            ans += step;
        else
            step /= 2;
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
    for (int i = 0; i < n; ++i)
        mi = min(mi, f(b, m, a[i]));
    cout << mi << endl;
    return 0;
}

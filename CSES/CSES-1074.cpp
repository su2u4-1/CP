#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    long long n, p[200005], s = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    sort(p, p + n);
    s = p[n / 2];
    for (int i = 0; i < n; ++i)
        ans += abs(p[i] - s);
    cout << ans << endl;
    return 0;
}

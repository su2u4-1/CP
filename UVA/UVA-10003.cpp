#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int s[55];
int dp[55][55];

int f(int a, int b) {
    if (dp[a][b] != -1)
        return dp[a][b];
    if (a + 1 == b)
        return dp[a][b] = 0;
    int c = INT_MAX;
    for (int i = a + 1; i < b; i++)
        c = min(c, f(a, i) + f(i, b));
    return dp[a][b] = c + s[b] - s[a];
}

int main() {
    int l, n;
    cin >> l;
    while (l != 0) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        s[0] = 0;
        s[n + 1] = l;
        cout << "The minimum cutting is " << f(0, n + 1) << ".\n";
        cin >> l;
    }
    return 0;
}

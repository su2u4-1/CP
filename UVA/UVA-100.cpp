#include <cstring>
#include <iostream>
using namespace std;

int dp[10005];

int f(int n) {
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    if (n % 2)
        return dp[n] = f(3 * n + 1);
    return dp[n] = f(n / 2);
}

int main() {
    int i, j;
    memset(dp, -1, sizeof(dp));
    while (cin >> i >> j) {
        int mx = 0;
        for (int k = i; k <= j; ++k)
            mx = max(mx, f(k));
        cout << mx << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int dp[105][105];
int f(int n, int k) {
    if (dp[n][k] != -1)
        return dp[n][k];
    if (k == 1)
        return dp[n][k] = 1;
    int t = 0;
    for (int i = 0; i <= n; i++) {
        t += f(i, k - 1);
        t %= 1000000;
    }
    return dp[n][k] = t;
}

int main() {
    int n, k;
    fill(&dp[0][0], &dp[104][104], -1);
    while (cin >> n >> k, n || k)
        cout << f(n, k) << endl;
    return 0;
}

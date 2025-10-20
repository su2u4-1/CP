#include <iostream>
using namespace std;

long long dp[51][51][51];
long long f(int n, int k, int m) {
    if (dp[n][k][m] != -1)
        return dp[n][k][m];
    if (k == 1)
        return dp[n][k][m] = n <= m;
    long long t = 0;
    for (int i = 1; i <= m; i++)
        if (n - i >= k - 1)
            t += f(n - i, k - 1, m);
        else
            break;
    return dp[n][k][m] = t;
}

int main() {
    int n, k, m;
    fill(&dp[0][0][0], &dp[50][50][50], -1);
    dp[0][0][0] = 1;
    while (cin >> n >> k >> m)
        cout << f(n, k, m) << endl;
    return 0;
}

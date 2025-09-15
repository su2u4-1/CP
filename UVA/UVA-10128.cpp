#include <cstring>
#include <iostream>
using namespace std;

int dp[15][15][15];
int main() {
    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1;
    for (int i = 2; i <= 13; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 1; k <= i; k++)
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + (i - 2) * dp[i - 1][j][k];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }

    return 0;
}

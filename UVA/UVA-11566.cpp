#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int N, x, T, K, p, dp[205][1005], pf[205][2], t;
    while (cin >> N >> x >> T >> K, N++ || x || T || K) {
        p = N * (x / (float)1.1 - T);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < K; ++i) {
            cin >> pf[i * 2][0];
            pf[i * 2][1] = 0;
            for (int j = 0; j < N; ++j) {
                cin >> t;
                pf[i * 2][1] += t;
            }
            pf[i * 2 + 1][0] = pf[i * 2][0];
            pf[i * 2 + 1][1] = pf[i * 2][1];
        }
        for (int i = 0; i < 2 * K; ++i)
            for (int j = N * 2; j > 0; --j)
                for (int k = p; k >= pf[i][0]; --k)
                    dp[j][k] = max(dp[j][k], max(dp[j - 1][k], dp[j - 1][k - pf[i][0]] + pf[i][1]));
        int ans = 0;
        for (int i = 0; i <= N * 2; ++i)
            ans = max(ans, dp[i][p]);
        cout << setprecision(2) << fixed << ans / (float)N << endl;
    }
    return 0;
}

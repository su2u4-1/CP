#include <iostream>
using namespace std;

int main() {
    int N, coin[100], dp[20005];
    cin >> N;
    while (N--) {
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < n; ++i)
            cin >> coin[i];
        dp[0] = 0;
        for (int i = 1; i < 20005; ++i)
            dp[i] = 1e9;
        for (int i = 0; i < n; ++i)
            for (int j = 20000; j >= coin[i]; --j)
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        for (int i = m; i < 20001; ++i)
            if (dp[i] > 0 && dp[i] < 1e9) {
                cout << i << " " << dp[i] << endl;
                break;
            }
    }
    return 0;
}

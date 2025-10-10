#include <iostream>
using namespace std;

bool subset_sum(int S[], int n, int T) {
    bool dp[T + 1];
    dp[0] = true;
    for (int j = 1; j <= T; j++)
        dp[j] = false;
    for (int i = 0; i < n; i++) {
        for (int j = T; j > S[i]; j--)
            dp[j] = dp[j] || dp[j - S[i]];
        if (S[i] <= T)
            dp[S[i]] = true;
    }
    return dp[T];
}

int main() {
    int N, M, coin[105];
    cin >> N;
    while (N--) {
        int sum = 0;
        cin >> M;
        for (int i = 0; i < M; ++i) {
            cin >> coin[i];
            sum += coin[i];
        }
        int ans = sum / 2;
        while (!subset_sum(coin, M, ans))
            --ans;
        cout << abs(sum - 2 * ans) << endl;
    }
    return 0;
}

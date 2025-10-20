#include <memory.h>
#include <stdio.h>

int main() {
    float a;
    int coin[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    long long dp[30005];
    while (scanf("%f", &a), a) {
        int n = (int)(a * 100 + 0.1);
        dp[0] = 1;
        for (int i = coin[0]; i <= n; ++i)
            dp[i] = 1;
        for (int i = 1; i < 11; ++i)
            for (int j = coin[i]; j <= n; ++j)
                dp[j] += dp[j - coin[i]];
        printf("%6.2f%17lld\n", (float)n / 100, dp[n]);
    }
    return 0;
}

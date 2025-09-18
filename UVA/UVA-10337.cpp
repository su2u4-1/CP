#include <climits>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int x, l;
        cin >> x;
        l = x / 100;
        int dp[10][l + 1];
        int w[10][l];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < l; j++)
                cin >> w[i][j];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j <= l; j++)
                dp[i][j] = -1;
        dp[9][0] = 0;
        for (int j = 1; j <= l; j++) {
            for (int i = 9; i >= 0; i--) {
                if (j - 1 >= 0) {
                    int mx = INT_MAX;
                    if (dp[i][j - 1] != -1)
                        mx = min(dp[i][j - 1] + 30 - w[i][j - 1], mx);
                    if (i + 1 < 10 && dp[i + 1][j - 1] != -1)
                        mx = min(dp[i + 1][j - 1] + 60 - w[i + 1][j - 1], mx);
                    if (i - 1 >= 0 && dp[i - 1][j - 1] != -1)
                        mx = min(dp[i - 1][j - 1] + 20 - w[i - 1][j - 1], mx);
                    if (mx < INT_MAX)
                        dp[i][j] = mx;
                }
            }
        }
        cout << dp[9][l] << endl
             << endl;
    }
}

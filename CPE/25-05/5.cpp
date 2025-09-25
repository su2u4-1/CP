#include <iostream>
using namespace std;

int main() {
    int n;
    long long dp[30005];
    int Cs[5]{1, 5, 10, 25, 50};
    for (int i = 0; i <= 30000; i++)
        dp[i] = 0;
    dp[0] = 1;
    for (int c : Cs)
        for (int i = c; i <= 30000; i++)
            dp[i] += dp[i - c];
    while (cin >> n)
        if (dp[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
    return 0;
}

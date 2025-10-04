#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int f(int A[], int n) {
    int mxp, mip, mi, mx, sum = 0;
    mxp = mip = mi = mx = A[0];
    for (int i = 0; i < n; ++i)
        sum += A[i];
    for (int i = 1; i < n; ++i) {
        mx = max(mx, mxp = max(mxp + A[i], A[i]));
        mi = min(mi, mip = min(mip + A[i], A[i]));
    }
    if (sum == mi)
        return mx;
    return max(mx, sum - mi);
}

int main() {
    int N, n, sum[80], A[80][80], mx, p, tsum[80], nsum[80];
    cin >> N;
    while (N--) {
        cin >> n;
        mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            tsum[i] = 0;
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
                tsum[i] += A[i][j];
            }
        }
        for (int l = 0; l < n; ++l) {
            memset(sum, 0, sizeof(sum));
            for (int r = l; r < n; ++r) {
                for (int i = 0; i < n; ++i)
                    sum[i] += A[i][r];
                mx = max(mx, p = f(sum, n));
                for (int i = 0; i < n; ++i)
                    nsum[i] = tsum[i] - sum[i];
                mx = max(mx, p = f(nsum, n));
            }
        }
        cout << mx << endl;
    }
}

#include <iostream>
using namespace std;

int main() {
    int N, n, w[4005], a[4005];
    cin >> N;
    while (N--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> w[i + n];
            w[n - i - 1] = w[i + n];
            a[i] = 1;
            a[i + n] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n * 2; ++i)
            for (int j = 0; j < i; ++j)
                if (w[i] > w[j]) {
                    a[i] = max(a[i], a[j] + 1);
                }
        for (int i = 0; i < n * 2; ++i)
            ans = max(ans, a[i]);
        cout << ans << endl;
    }
    return 0;
}

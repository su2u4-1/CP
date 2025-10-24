#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n, d, a, x = INT_MAX, ans = 0;
    bool f = false;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a >= x + d && f) {
            ans += a - x;
            x = a;
            f = false;
        }
        if (a <= x - d && !f) {
            x = a;
            f = true;
        }
    }
    cout << ans << endl;
    return 0;
}

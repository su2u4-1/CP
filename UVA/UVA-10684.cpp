#include <iostream>
using namespace std;

int main() {
    int n, p[10000], t, mx;
    while (cin >> n, n) {
        cin >> p[0];
        mx = p[0];
        for (int i = 1; i < n; ++i) {
            cin >> t;
            p[i] = t + p[i - 1];
            for (int j = 0; j < i; ++j)
                mx = max(mx, p[i] - p[j]);
        }
        if (mx <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << mx << ".\n";
    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n, m, a, b;
    long long pfs[200005];
    pfs[0] = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        pfs[i + 1] = pfs[i] + a;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cout << pfs[b] - pfs[a - 1] << "\n";
    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int i = 1, j = 0, ans = 0, an = a.size(), bn = b.size();
    int* n = new int[bn];
    n[0] = 0;

    for (; i < bn; i++) {
        while (j > 0 && b[i] != b[j])
            j = n[j - 1];
        if (b[i] == b[j])
            j++;
        n[i] = j;
    }
    // cout << "n array: ";
    // for (int k = 0; k < bn; k++) {
    //     cout << n[k] << " ";
    // }
    // cout << "\n";

    // for (; t < an; t++) {
    //     i = t, j = 0;
    //     while (i < an && j < bn) {
    //         if (a[i] == b[j])
    //             ++i, ++j;
    //         else if (j <= 0)
    //             ++i;
    //         else
    //             j = n[j - 1];
    //     }
    //     if (j == bn) {
    //         ++ans;
    //         t = i - bn;
    //     }
    // }
    for (i = 0, j = 0; i < an; i++) {
        while (j > 0 && a[i] != b[j])
            j = n[j - 1];
        if (a[i] == b[j])
            j++;
        if (j == bn) {
            ans++;
            j = n[j - 1];
        }
    }
    cout << ans << "\n";

    return 0;
}

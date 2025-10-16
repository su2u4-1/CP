#include <algorithm>
#include <iostream>
using namespace std;

int search(int c[], int n, int t) {
    int ans = n, step = n;
    while (step) {
        if (ans - step >= 0 && c[ans - step] > t)
            ans -= step;
        else
            step /= 2;
    }
    return ans;
}

int main() {
    int N, c[200005]{0}, t, s = 1, i, j;
    cin >> N >> t;
    c[0] = t;
    for (i = 1; i < N; ++i) {
        cin >> t;
        j = search(c, s, t);
        c[j] = t;
        if (j == s)
            ++s;
    }
    cout << s << "\n";
    return 0;
}

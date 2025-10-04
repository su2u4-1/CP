#include <climits>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int c = 1; c <= N; c++) {
        int n, t, mx = INT_MIN, p = -1, s = -1, e = -1, ns = 0;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            cin >> t;
            p = max(p + t, t);
            if (p < 0)
                ns = i + 1;
            else if (p > mx || (p == mx && (i - ns > e - s))) {
                mx = p;
                s = ns;
                e = i;
            }
        }
        if (mx > 0)
            cout << "The nicest part of route " << c << " is between stops " << s + 1 << " and " << e + 2 << endl;
        else
            cout << "Route " << c << " has no nice parts" << endl;
    }
    return 0;
}

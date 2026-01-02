#include <iostream>
using namespace std;

int a, b, c, d, l;

int f(int x) {
    return x * x * a + x * b + c;
}

int main() {
    while (cin >> a >> b >> c >> d >> l, a || b || c || d || l) {
        int ans = 0;
        for (int i = 0; i <= l; i++)
            if (!(f(i) % d)) ++ans;
        cout << ans << '\n';
    }
    return 0;
}

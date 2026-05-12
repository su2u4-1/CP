#include <iostream>
#include <cmath>
using namespace std;

int f(int a) {
    if (a == 1) return 1;
    return f(a/2) + 1;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, a, b, t;
        cin >> n >> a >> b;
        t = pow(2, n) - 1;
        a = pow(2, n - f(a) + 1) - 2;
        b = pow(2, n - f(b) + 1) - 2;
        t -= min(a, b);
        cout << t << endl;
    }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

bool t[20];

void f(int n, int s) {
    t[s - 1] = n % 2;
    if (s == 1) return;
    f(n/2, s - 1);
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int d, n, a;
        cin >> d >> n;
        f(n - 1, d);
        a = 1;
        for (int i = d - 1; i > 0; --i) {
            a *= 2;
            if (t[i])
                a += 1;
        }
        cout << a << endl;
    }
    return 0;
}

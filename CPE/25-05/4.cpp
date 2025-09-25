#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
void f() {
    bool p[1000001]{false};
    for (int i = 2; i * i <= 1000000; ++i)
        if (!p[i])
            for (int j = i * i; j <= 1000000; j += i)
                p[j] = true;
    for (int i = 2; i <= 1000000; ++i)
        if (!p[i])
            prime.push_back(i);
}

bool find(int t) {
    int l = 0, r = prime.size() - 1, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (prime[m] == t)
            return true;
        else if (prime[m] > t)
            r = m - 1;
        else if (prime[m] < t)
            l = m + 1;
    }
    return false;
}

int main() {
    f();
    int n;
    bool flag = true;
    while (cin >> n, n) {
        for (int i = 0; i < prime.size(); ++i) {
            int t = n - prime[i];
            if (find(t)) {
                cout << n << " = " << prime[i] << " + " << t << "\n";
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}

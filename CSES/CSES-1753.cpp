#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    long long p = 56637, q = 1e9 + 7, bhash = 0, ahash = 0;
    int as = a.size(), bs = b.size(), ans = 0;
    if (as < bs) {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> pow(bs + 1, 0);
    pow[0] = 1;
    for (int i = 1; i <= bs; ++i)
        pow[i] = (pow[i - 1] * p) % q;
    for (int i = 0; i < bs; ++i) {
        ahash = (ahash + ((a[i] - 'a' + 1) * pow[bs - i - 1]) % q) % q;
        bhash = (bhash + ((b[i] - 'a' + 1) * pow[bs - i - 1]) % q) % q;
    }
    if (bhash == ahash)
        ++ans;
    for (int i = 0; i < as - bs; ++i) {
        long long removed = (a[i] - 'a' + 1) * pow[bs - 1] % q;
        ahash = (ahash - removed + q) % q;
        ahash = (ahash * p) % q;
        ahash = (ahash + (a[i + bs] - 'a' + 1)) % q;
        if (ahash == bhash)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}

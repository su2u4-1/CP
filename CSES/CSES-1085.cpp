#include <climits>
#include <iostream>
using namespace std;

#define ll long long
ll N, K, D[200005];

bool f(ll s) {
    ll count = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        if (sum + D[i] > s) {
            sum = D[i];
            count++;
        } else
            sum += D[i];
    }
    if (sum > 0)
        count++;
    return count <= K;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> D[i];
    ll l = INT_MIN, r = 0;
    for (int i = 0; i < N; i++) {
        l = max(l, D[i]);
        r += D[i];
    }
    ll ans = l - 1, step = r - l;
    while (step > 0)
        if (!f(ans + step))
            ans += step;
        else
            step /= 2;
    cout << ans + 1 << endl;
    return 0;
}

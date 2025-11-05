#include <iostream>
using namespace std;

int N, K, D[605];

bool f(int s) {
    int count = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        if (sum + D[i] > s) {
            sum = 0;
            count++;
        }
        sum += D[i];
    }
    if (sum > 0)
        count++;
    return count <= K;
}

int main() {
    while (cin >> N >> K) {
        N++, K++;
        int l = -1, r = 0;
        for (int i = 0; i < N; i++) {
            cin >> D[i];
            l = max(l, D[i]);
            r += D[i];
        }
        int ans = l - 1, step = r - l;
        while (step > 0)
            if (f(ans + step))
                step /= 2;
            else
                ans += step;
        cout << ans + 1 << endl;
    }
    return 0;
}

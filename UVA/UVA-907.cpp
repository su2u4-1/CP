#include <iostream>
using namespace std;

int N, K, D[605];

bool f(int s) {
    int count = 0, sum = 0;
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
    while (cin >> N >> K) {
        N++, K++;
        for (int i = 0; i < N; i++)
            cin >> D[i];
        int l = -1, r = 0;
        for (int i = 0; i < N; i++) {
            l = max(l, D[i]);
            r += D[i];
        }
        int ans = l - 1, step = r - l;
        while (step > 0)
            if (!f(ans + step))
                ans += step;
            else
                step /= 2;
        cout << ans + 1 << endl;
    }
    return 0;
}

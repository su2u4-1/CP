#include <cstring>
#include <iostream>
using namespace std;

int lo[27][27][352];
int f(int L, int S, int l, int s) {
    if (lo[L][l][s] != -1)
        return lo[L][l][s];
    if (L == 0 || s > S || l > 26)
        return lo[L][l][s] = 0;
    int n = 0;
    for (int i = l; i < 27; i++) {
        if (s + i == S && L == 1)
            return lo[L][l][s + i] = 1;
        else if (s + i < S && L > 1)
            n += f(L - 1, S, i + 1, s + i);
    }
    return lo[L][l][s] = n;
}

int main() {
    int L, S, N = 0;
    cin >> L >> S;
    while (L != 0 && S != 0) {
        N++;
        if (S > 351 || L > 26)
            cout << "Case " << N << ": 0" << endl;
        else {
            memset(lo, -1, sizeof(lo));
            int n = f(L, S, 1, 0);
            cout << "Case " << N << ": " << n << endl;
        }
        cin >> L >> S;
    }
}

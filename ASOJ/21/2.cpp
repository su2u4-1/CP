#include <cmath>
#include <iostream>
using namespace std;

void ten_to_k(int a, int A[], int K) {
    for (int k = 31; k >= 0; --k) {
        int t = pow(K, k);
        A[k] = a / t;
        a %= t;
    }
}

int k_to_ten(int A[], int K) {
    int t = 0;
    for (int k = 0; k < 32; ++k)
        t += A[k] * pow(K, k);
    return t;
}

int main() {
    int N, M, K, e[105][105][32], t;
    char c;
    cin >> N >> M >> K;
    for (int j = 1; j <= M; ++j) {
        cin >> t;
        ten_to_k(t, e[0][j], K);
    }
    for (int i = 1; i <= N; ++i) {
        cin >> t;
        ten_to_k(t, e[i][0], K);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> c;
            if (c == '&') {
                for (int k = 0; k < 32; ++k)
                    e[i][j][k] = min(e[i - 1][j][k], e[i][j - 1][k]);
            } else if (c == '|') {
                for (int k = 0; k < 32; ++k)
                    e[i][j][k] = max(e[i - 1][j][k], e[i][j - 1][k]);
            } else if (c == '^') {
                for (int k = 0; k < 32; ++k)
                    e[i][j][k] = (e[i - 1][j][k] + e[i][j - 1][k]) % K;
            }
            if (j < M)
                cout << k_to_ten(e[i][j], K) << " ";
            else
                cout << k_to_ten(e[i][j], K) << endl;
        }
    }
    return 0;
}

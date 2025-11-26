#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N, S, W[101][101], a, b, w;
    float s;
    while (cin >> N >> S) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                W[i][j] = 1e9;
        for (int i = 0; i < S; ++i) {
            cin >> a >> b >> w;
            W[a][b] = W[b][a] = w;
        }
        cin >> a >> b >> w;
        s = min(w, min(a, b));
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
        int mx = -1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j)
                    mx = max(mx, W[i][j]);
        cout << (int)ceil((float)mx / s) << endl;
    }
    return 0;
}

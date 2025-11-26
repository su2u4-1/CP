#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n, m;  // max: 22, 231
    string names[23];
    int W[23][23], N = 0;
    while (cin >> n >> m, n || m) {
        for (int i = 1; i <= n; ++i) {
            cin >> names[i];
            for (int j = 1; j <= n; ++j)
                W[i][j] = 1e9;
        }
        int a, b, w;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> w;
            W[a][b] = W[b][a] = w;
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
        int mi = INT_MAX, index = 0;
        for (int i = 1; i <= n; ++i) {
            W[i][i] = 0;
            for (int j = 1; j <= n; ++j)
                if (i != j)
                    W[i][i] += W[j][i];
            if (W[i][i] < mi) {
                mi = W[i][i];
                index = i;
            }
        }
        cout << "Case #" << ++N << " : " << names[index] << endl;
    }
    return 0;
}

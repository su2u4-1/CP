#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, n;
    vector<int> h, w, lis;
    cin >> N;
    for (int C = 1; C <= N; ++C) {
        int in, de;
        cin >> n;
        h.resize(n);
        w.resize(n);
        lis.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> h[i];
        for (int i = 0; i < n; ++i)
            cin >> w[i];
        in = lis[0] = w[0];
        for (int i = 1; i < n; ++i) {
            lis[i] = w[i];
            for (int j = 0; j < i; ++j)
                if (h[i] > h[j])
                    lis[i] = max(lis[i], lis[j] + w[i]);
            in = max(in, lis[i]);
        }
        de = lis[0] = w[0];
        for (int i = 1; i < n; ++i) {
            lis[i] = w[i];
            for (int j = 0; j < i; ++j)
                if (h[i] < h[j])
                    lis[i] = max(lis[i], lis[j] + w[i]);
            de = max(de, lis[i]);
        }
        if (in >= de)
            cout << "Case " << C << ". Increasing (" << in << "). Decreasing (" << de << ").\n";
        else
            cout << "Case " << C << ". Decreasing (" << de << "). Increasing (" << in << ").\n";
    }
    return 0;
}

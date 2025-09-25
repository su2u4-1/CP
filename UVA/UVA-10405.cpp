#include <iostream>
using namespace std;

int lcs[1005];

int main() {
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        int n = a.size(), m = b.size();
        for (int i = 0; i <= m; ++i)
            lcs[i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j > 0; --j)
                if (a[i - 1] == b[j - 1])
                    lcs[j] = lcs[j - 1] + 1;
            for (int j = 1; j <= m; ++j)
                if (a[i - 1] != b[j - 1])
                    lcs[j] = max(lcs[j], lcs[j - 1]);
        }
        cout << lcs[m] << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool f = false;
    int n = 0, p = -1, C = 1;
    vector<int> a;
    cin >> n;
    for (; n != -1 || p != -1;) {
        a.push_back(n);
        if (n == -1) {
            a.pop_back();
            vector<int> lis;
            lis.resize(a.size());
            int mx = lis[0] = 1;
            for (int i = 1; i < a.size(); i++) {
                lis[i] = 1;
                for (int j = 0; j < i; j++)
                    if (a[j] > a[i])
                        lis[i] = max(lis[i], lis[j] + 1);
                mx = max(mx, lis[i]);
            }
            if (f)
                cout << endl;
            f = true;
            cout << "Test #" << C << ":\n  maximum possible interceptions: " << mx << "\n";
            a.clear();
            C++;
        }
        p = n;
        cin >> n;
    }
    return 0;
}

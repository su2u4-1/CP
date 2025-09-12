// https://vjudge.net/problem/UVA-12160
// WA

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int L, U, R, I = 1;
    cin >> L >> U >> R;
    while (L != 0 || U != 0 || R != 0) {
        int f[10000];
        for (int i = 0; i < 10000; i++)
            f[i] = -1;
        f[L] = 0;
        int rv[R];
        for (int i = 0; i < R; i++)
            cin >> rv[i];

        queue<int> q;
        q.push(L);
        bool flag = true;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            if (n == U) {
                cout << "Case " << I << ": " << f[U] << endl;
                flag = false;
                break;
            }
            for (int i : rv) {
                int v = (n + i) % 10000;
                if (f[v] == -1 || f[v] > f[n] + 1) {
                    f[v] = f[n] + 1;
                    q.push(v);
                }
            }
        }
        if (flag)
            cout << "Case " << I << ": Permanently Locked\n";
        I++;
        cin >> L >> U >> R;
    }
    return 0;
}

#include <iostream>
using namespace std;

bool m[105];
bool c[105];
int main() {
    int N, n, ans;
    cin >> N;
    for (int case_ = 1; case_ <= N; ++case_) {
        ans = 0;
        string str;
        cin >> n >> str;
        for (int i = 0; i < n; ++i) {
            m[i] = (str[i] == '.');
            c[i] = false;
        }
        for (int i = 0; i < n; ++i) {
            if (m[i] && !c[i]) {
                if (!c[i + 1]) {
                    c[i] = true;
                    c[i + 1] = true;
                    c[i + 2] = true;
                    ++ans;
                } else if ((i >= 1 && c[i - 1]) || (i == 0 && (!m[i+1] || n<2) && (!m[i+2] || n<3))) {
                    c[i] = true;
                    c[i - 1] = true;
                    c[i + 1] = true;
                    ++ans;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (m[i] && !c[i]) {
                c[i] = true;
                c[i - 1] = true;
                c[i + 1] = true;
                ++ans;
            }
        }
        cout << "Case " << case_ << ": " << ans << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int N = 0, n, arr[105];
    bool f[20005], flag;
    while (cin >> n) {
        ++N;
        flag = true;
        for (int i = 0; i < 20005; ++i)
            f[i] = false;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] < 1 || i > 0 && arr[i - 1] >= arr[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    if (f[arr[i] + arr[j]]) {
                        flag = false;
                        break;
                    }
                    f[arr[i] + arr[j]] = true;
                }
                if (!flag)
                    break;
            }
        }
        cout << "Case #" << N << ": It is" << (flag ? " " : " not ") << "a B2-Sequence.\n\n";
    }
}

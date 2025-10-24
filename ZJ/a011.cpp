#include <iostream>
using namespace std;

int main() {
    string a;
    bool f;
    int ans;
    while (getline(cin, a)) {
        f = false;
        ans = 0;
        for (int i = 0; i < a.size(); i++) {
            if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z')) {
                if (!f) {
                    ans++;
                    f = true;
                }
            } else
                f = false;
        }
        cout << ans << endl;
    }
    return 0;
}

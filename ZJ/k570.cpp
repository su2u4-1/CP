#include <iostream>
using namespace std;

int main() {
    int N, id, h, m, a, ans = 0;
    cin >> N;
    while (N--) {
        cin >> id >> h >> m >> a;
        m += h * 60;
        if ((id == 0 && (m >= 1080 || m == 0)) || (id == 1 && (m >= 600 || m == 0)))
            ans += a * 7 / 10;
        else if (id == 2 && ((600 <= m && m <= 1020) || m >= 1200 || m == 0))
            ans += a * 65 / 100;
        else if (id == 3 && (990 <= m && m <= 1350))
            ans += a * 6 / 10;
        else
            ans += a;
    }
    cout << ans << endl;
    return 0;
}

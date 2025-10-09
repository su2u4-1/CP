#include <iostream>
using namespace std;

int main() {
    int n, mx = -1, t;
    cin >> n;
    while (n--) {
        cin >> t;
        mx = max(mx, t);
    }
    cout << mx << endl;
    return 0;
}

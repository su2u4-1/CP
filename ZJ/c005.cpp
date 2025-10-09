#include <iostream>
using namespace std;

int main() {
    long long N, n, a, b, c, s;
    cin >> N;
    while (N--) {
        s = 0;
        cin >> n;
        while (n--) {
            cin >> a >> b >> c;
            s += a * c;
        }
        cout << s << endl;
    }
}

#include <iostream>
using namespace std;

int main() {
    int N, a, b, s, c = 0;
    cin >> N;
    while (N--) {
        s = 0;
        cin >> a >> b;
        if (a % 2 == 0)
            ++a;
        if (b % 2 == 0)
            --b;
        for (int i = a; i <= b; i += 2)
            s += i;
        cout << "Case " << ++c << ": " << s << endl;
    }
    return 0;
}

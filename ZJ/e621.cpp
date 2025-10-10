#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    bool f;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        f = true;
        for (int j = a + 1; j < b; ++j)
            if (j % c) {
                cout << j << " ";
                f = false;
            }
        cout << (f ? "No free parking spaces.\n" : "\n");
    }
    return 0;
}

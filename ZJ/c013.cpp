#include <iostream>
using namespace std;

int main() {
    int N, f, a;
    bool s = false;
    cin >> N;
    while (N--) {
        cin >> a >> f;
        while (f--) {
            if (s)
                cout << endl;
            s = true;
            for (int i = 1; i <= a; ++i) {
                for (int j = 0; j < i; ++j)
                    cout << i;
                cout << endl;
            }
            for (int i = a - 1; i >= 1; --i) {
                for (int j = 0; j < i; ++j)
                    cout << i;
                cout << endl;
            }
        }
    }
    return 0;
}

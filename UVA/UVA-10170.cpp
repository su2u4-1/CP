#include <iostream>
using namespace std;

int main() {
    long long s, d, r;
    while (cin >> s >> d) {
        for (r = s; r < d; r += (++s));
        cout << s << endl;
    }
    return 0;
}

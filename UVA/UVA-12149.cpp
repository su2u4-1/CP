#include <iostream>
using namespace std;

int main() {
    int n, s[101]{0};
    for (int i = 1; i <= 100; ++i)
        s[i] = s[i - 1] + i * i;
    while (cin >> n, n)
        cout << s[n] << endl;
    return 0;
}

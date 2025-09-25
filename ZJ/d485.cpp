#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << abs(a - b) / 2 + (a != b || a % 2 == 0) << endl;
    return 0;
}

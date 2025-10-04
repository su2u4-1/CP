#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a <= 2500)
        cout << "1 " << a / 25 + (a % 25 ? 1 : 0) << " " << (a % 25 ? a % 25 : 25) << endl;
    else if (a <= 7500)
        cout << "2 " << (a - 2500) / 50 + (a % 50 ? 1 : 0) << " " << (a % 50 ? a % 50 : 50) << endl;
    else
        cout << "3 " << (a - 7500) / 25 + (a % 25 ? 1 : 0) << " " << (a % 25 ? a % 25 : 25) << endl;
    return 0;
}

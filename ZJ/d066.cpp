#include <iostream>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    m += h * 60;
    if (450 <= m && m < 1020)
        cout << "At School" << endl;
    else
        cout << "Off School" << endl;

    return 0;
}

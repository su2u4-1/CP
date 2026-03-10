#include <iostream>
using namespace std;

int main() {
    int N, s;
    while(cin >> N, N) {
        s = 0;
        for (int i = 1; i <= N; ++i)
            s += i * i;
        cout << s << endl;
    }
    return 0;
}

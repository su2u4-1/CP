#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            q.push(i);
        cout << "Discarded cards:";
        bool f = false;
        while (q.size() > 1) {
            if (f) cout << ",";
            cout << " " << q.front();
            f = true;
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << "\nRemaining card: " << q.front() << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        vector<queue<char>> v;
        v.push_back(queue<char>());
        int pos = 0;
        for (char c: str) {
            if (c == '[') {
                pos = v.size();
                v.push_back(queue<char>());
            } else if (c == ']') {
                pos = 0;
            } else {
                v[pos].push(c);
            }
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            for (; !v[i].empty(); v[i].pop()) {
                cout << v[i].front();
            }
        }
        cout << endl;
    }
    return 0;
}

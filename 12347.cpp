#include <iostream>
#include <cstring>
using namespace std;

int tree[10005];

int append(int n, int c) {
    if (tree[c] == -1) {
        tree[c] = n;
        return c;
    } else if (n < tree[c])
        return append(n, c*2);
    else
        return append(n, c*2+1);
}

void f(int n) {
    if (tree[n*2] > -1) f(n*2);
    if (tree[n*2+1] > -1) f(n*2+1);
    cout << tree[n] << endl;
}

int main() {
    int n, c = 0, t = -1;
    memset(tree, -1, 10005);
    while (cin >> n) {
        c = append(n, 1);
        if (c > t) t = c;
    }
    f(1);
    return 0;
}

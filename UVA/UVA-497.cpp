#include <iostream>
#include <vector>
using namespace std;

vector<int> n, p, l;

void print(int index) {
    if (p[index] > -1)
        print(p[index]);
    cout << n[index] << endl;
}

int main() {
    int N, a;
    string str;
    getline(cin, str);
    N = stoi(str);
    getline(cin, str);
    while (N--) {
        n.clear();
        while (getline(cin, str)) {
            if (str == "")
                break;
            n.push_back(stoi(str));
        }
        l = vector<int>(n.size(), -1);
        p = vector<int>(n.size(), -1);
        l[0] = 1;
        a = 0;
        for (int i = 1; i < n.size(); ++i) {
            l[i] = 1;
            for (int j = 0; j < i; ++j)
                if (n[j] < n[i] && l[i] < l[j] + 1) {
                    l[i] = l[j] + 1;
                    p[i] = j;
                }
            if (l[a] < l[i])
                a = i;
        }
        cout << "Max hits: " << l[a] << endl;
        print(a);
        if (N)
            cout << endl;
    }
    return 0;
}

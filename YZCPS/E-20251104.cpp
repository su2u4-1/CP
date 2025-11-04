#include <cstring>
#include <iostream>
using namespace std;

int trie[500050][27], trie_index = 0;

void insert(const string& s) {
    int n = 0;
    for (char c : s) {
        int ic = c - 'a';
        if (trie[n][ic] == 0)
            trie[n][ic] = ++trie_index;
        n = trie[n][ic];
    }
    trie[n][26] = 1;
}

int exist(const string& s) {
    int n = 0;
    for (char c : s) {
        int ic = c - 'a';
        if (trie[n][ic] == 0)
            return -1;
        n = trie[n][ic];
    }
    if (trie[n][26] == 1)
        return trie[n][26]++;
    else if (trie[n][26] > 1)
        return 0;
    return -1;
}

int main() {
    int n, m;
    string s;
    cin >> n;
    memset(trie, 0, sizeof(trie));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        insert(s);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        switch (exist(s)) {
            case -1:
                cout << "WRONG\n";
                break;
            case 0:
                cout << "REPEAT\n";
                break;
            case 1:
                cout << "OK\n";
                break;
        }
    }
    return 0;
}

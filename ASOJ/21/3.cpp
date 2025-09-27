#include <iostream>
using namespace std;

int N, ans;
bool check(char S[]) {
    char p = '-', pp = '-';
    for (int i = 0; i < N; ++i) {
        if (p == '0' && pp == '0' && S[i] == '7')
            return true;
        pp = p;
        p = S[i];
    }
    return false;
}

void DFS(char S[]) {
    for (int i = 0; i < N; ++i)
        if (S[i] == '*') {
            for (char c = '0'; c <= '9'; ++c) {
                S[i] = c;
                DFS(S);
            }
            S[i] = '*';
            return;
        }
    if (check(S))
        ans = (ans + 1) % 1000000007;
}

int main() {
    char S[500005];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    DFS(S);
    cout << ans << endl;
    return 0;
}

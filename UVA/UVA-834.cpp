#include <iostream>
#include <vector>
using namespace std;

vector<int> f(int a, int b) {
    vector<int> ans;
    while (b != 0) {
        ans.push_back(a / b);
        int r = a % b;
        a = b;
        b = r;
    }
    if (ans.size() >= 2 && ans.back() == 1) {
        ans.pop_back();
        ans.back() += 1;
    }
    return ans;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        vector<int> ans = f(a, b);
        cout << "[";
        cout << ans[0];
        cout << ";";
        for (size_t i = 1; i < ans.size(); ++i) {
            if (i > 1) cout << ",";
            cout << ans[i];
        }
        cout << "]\n";
    }
    return 0;
}

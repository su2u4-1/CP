#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int d, f, t, s, c;
    while (cin >> d >> f, d != 0 || f != 0) {
        if (d > f) {
            cout << "Loowater is doomed!\n";
            continue;
        }
        s = 0, c = 0;
        vector<int> dragons;
        vector<int> knights;
        for (int i = 0; i < d; ++i) {
            cin >> t;
            dragons.push_back(t);
        }
        sort(dragons.begin(), dragons.end());
        for (int i = 0; i < f; ++i) {
            cin >> t;
            knights.push_back(t);
        }
        sort(knights.begin(), knights.end());
        for (int i = 0; i < d; ++i) {
            auto result = lower_bound(knights.begin(), knights.end(), dragons[i]);
            if (result != knights.end() && *result >= dragons[i]) {
                s += *result;
                ++c;
                knights.erase(result);
            }
        }
        if (c < d) cout << "Loowater is doomed!\n";
        else cout << s << "\n";
    }
    return 0;
}

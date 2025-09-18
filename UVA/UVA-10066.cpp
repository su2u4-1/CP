#include <iostream>
using namespace std;

int main() {
    int N1, N2, n = 0;
    cin >> N1 >> N2;
    int T1[105], T2[105];
    int LCS[105];
    while (N1 != 0 && N2 != 0) {
        n++;
        for (int i = 0; i < N1; i++)
            cin >> T1[i];
        for (int i = 0; i < N2; i++)
            cin >> T2[i];
        for (int i = 0; i <= max(N1, N2); i++)
            LCS[i] = 0;
        for (int i = 1; i <= N1; i++) {
            for (int j = N2; j >= 1; j--)
                if (T1[i - 1] == T2[j - 1])
                    LCS[j] = LCS[j - 1] + 1;
            for (int j = 1; j <= N2; j++)
                LCS[j] = max(LCS[j], LCS[j - 1]);
        }
        cout << "Twin Towers #" << n << "\nNumber of Tiles : " << LCS[N2] << "\n\n";
        cin >> N1 >> N2;
    }
}

#include <iostream>
using namespace std;

int arr[42]{113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331};
int main() {
    int n, m;
    while (cin >> n, n > -1) {
        cin >> m;
        int count = 0;
        for (int i = 0; i < 42; ++i)
            if (arr[i] >= n && arr[i] <= m)
                count++;
        if (count == 0)
            cout << "No Circular Primes.\n";
        else if (count == 1)
            cout << "1 Circular Prime.\n";
        else
            cout << count << " Circular Primes.\n";
    }
    return 0;
}

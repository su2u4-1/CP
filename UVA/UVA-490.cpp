#include <iostream>
#include <string>
using namespace std;

int main() {
    string input[101];
    int index = 0;
    size_t max_length = 0;
    while (getline(cin, input[index++])) {
        max_length = max(max_length, input[index - 1].size());
    }
    --index;
    if (input[index] == "\n" || input[index] == "")
        --index;
    for (int j = 0; j < max_length; ++j) {
        for (int i = index; i >= 0; --i) {
            if (j < input[i].size()) {
                cout << input[i][j];
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}

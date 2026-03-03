#include <iostream>
#include <string>
using namespace std;

int main() {
    string in;
    bool in_string = false;
    while (getline(cin, in)) {
        for (char c : in) {
            if (c == '"') {
                if (in_string) {
                    in_string = false;
                    cout << "''";
                } else {
                    in_string = true;
                    cout << "``";
                }
            } else
                cout << c;
        }
        cout << "\n";
    }
    return 0;
}

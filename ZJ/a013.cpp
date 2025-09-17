#include <iostream>
using namespace std;

int main() {
    string str;
    while (getline(cin, str), str != "#") {
        int a = 0, b = 0;
        int* n = &a;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ')
                n = &b;
            else if (str[i] == 'M')
                *n += 1000;
            else if (str[i] == 'D')
                *n += 500;
            else if (str[i] == 'C') {
                if (i + 1 < str.size() && str[i + 1] == 'M')
                    *n += 900, i++;
                else if (i + 1 < str.size() && str[i + 1] == 'D')
                    *n += 400, i++;
                else
                    *n += 100;
            } else if (str[i] == 'L')
                *n += 50;
            else if (str[i] == 'X') {
                if (i + 1 < str.size() && str[i + 1] == 'C')
                    *n += 90, i++;
                else if (i + 1 < str.size() && str[i + 1] == 'L')
                    *n += 40, i++;
                else
                    *n += 10;
            } else if (str[i] == 'V')
                *n += 5;
            else if (str[i] == 'I') {
                if (i + 1 < str.size() && str[i + 1] == 'X')
                    *n += 9, i++;
                else if (i + 1 < str.size() && str[i + 1] == 'V')
                    *n += 4, i++;
                else
                    *n += 1;
            }
        }
        a = abs(a - b);
        if (a == 0)
            cout << "ZERO" << endl;
        else {
            string res;
            while (a >= 1000)
                res += 'M', a -= 1000;
            if (a >= 900)
                res += "CM", a -= 900;
            if (a >= 500)
                res += 'D', a -= 500;
            if (a >= 400)
                res += "CD", a -= 400;
            while (a >= 100)
                res += 'C', a -= 100;
            if (a >= 90)
                res += "XC", a -= 90;
            if (a >= 50)
                res += 'L', a -= 50;
            if (a >= 40)
                res += "XL", a -= 40;
            while (a >= 10)
                res += 'X', a -= 10;
            if (a == 9)
                res += "IX", a -= 9;
            if (a >= 5)
                res += 'V', a -= 5;
            if (a == 4)
                res += "IV", a -= 4;
            while (a >= 1)
                res += 'I', a -= 1;
            cout << res << endl;
        }
    }
    return 0;
}

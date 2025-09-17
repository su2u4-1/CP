#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        vector<string> tokens;
        stack<string> operators;
        stringstream ss(str);
        string s;
        while (ss >> s) {
            if (s == "(") {
                operators.push(s);
            } else if (s == ")") {
                while (!operators.empty() && operators.top() != "(") {
                    tokens.push_back(operators.top());
                    operators.pop();
                }
                if (!operators.empty() && operators.top() == "(")
                    operators.pop();
            } else if (s == "+" || s == "-") {
                while (!operators.empty() && operators.top() != "(") {
                    tokens.push_back(operators.top());
                    operators.pop();
                }
                operators.push(s);
            } else if (s == "*" || s == "/" || s == "%") {
                while (!operators.empty() && (operators.top() == "*" || operators.top() == "/" || operators.top() == "%")) {
                    tokens.push_back(operators.top());
                    operators.pop();
                }
                operators.push(s);
            } else
                tokens.push_back(s);
        }
        while (!operators.empty()) {
            tokens.push_back(operators.top());
            operators.pop();
        }
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
                int b = stoi(operators.top());
                operators.pop();
                int a = stoi(operators.top());
                operators.pop();
                if (token == "+")
                    operators.push(to_string(a + b));
                else if (token == "-")
                    operators.push(to_string(a - b));
                else if (token == "*")
                    operators.push(to_string(a * b));
                else if (token == "/")
                    operators.push(to_string(a / b));
                else if (token == "%")
                    operators.push(to_string(a % b));
            } else
                operators.push(token);
        }
        cout << operators.top() << endl;
    }
    return 0;
}

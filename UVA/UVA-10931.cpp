#include <iostream>
using namespace std;

void displayBinary(int number) {
    if (number <= 1) {
        cout << number % 2;
        return;
    }
    displayBinary(number / 2);
    cout << number % 2;
}

int sumBits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 2;
        number /= 2;
    }
    return sum;
}

int main() {
    int number;
    while (cin >> number, number > 0) {
        cout << "The parity of ";
        displayBinary(number);
        cout << " is " << sumBits(number) << " (mod 2).\n";
    }
    return 0;
}

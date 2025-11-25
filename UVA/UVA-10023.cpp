#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

const int arraySize = 1010;

void compSquare(long long int* hugeInt, long long int* square, int hugeIntSize, int& squareSize) {
    for (int i = 0; i < squareSize; ++i)
        square[i] = 0;
    for (int i = 0; i < hugeIntSize; ++i)
        for (int j = 0; j < hugeIntSize; ++j)
            square[i + j] += hugeInt[i] * hugeInt[j];
    for (int i = 0; i < squareSize - 1; ++i)
        if (square[i] > 9999) {
            square[i + 1] += square[i] / 10000;
            square[i] = square[i] % 10000;
        }
}

bool eq(long long int* hugeInt1, long long int* hugeInt2, int size1, int size2) {
    if (size1 != size2)
        return false;
    for (int i = size1 - 1; i >= 0; i--)
        if (hugeInt1[i] != hugeInt2[i])
            return false;
    return true;
}

bool le(long long int* hugeInt1, long long int* hugeInt2, int size1, int size2) {
    if (size1 != size2)
        return size1 < size2;
    for (int i = size1 - 1; i >= 0; i--)
        if (hugeInt1[i] != hugeInt2[i])
            return hugeInt1[i] < hugeInt2[i];
    return false;
}

void compSquareRoot(long long int* hugeInt, long long int* squareRoot, int hugeIntSize, int sqrtSize) {
    int squareSize = hugeIntSize;
    long long int* square = new long long int[squareSize]();

    for (int i = sqrtSize - 1; i >= 0; --i) {
        int l = 0, r = 9999;
        while (l <= r) {
            squareRoot[i] = (l + r) / 2;
            compSquare(squareRoot, square, sqrtSize, squareSize);
            if (eq(square, hugeInt, squareSize, hugeIntSize)) {
                delete[] square;
                return;
            } else if (le(square, hugeInt, squareSize, hugeIntSize))
                l = squareRoot[i] + 1;
            else
                r = squareRoot[i] - 1;
        }
        if (le(hugeInt, square, hugeIntSize, squareSize))
            --squareRoot[i];
    }

    delete[] square;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        char str[arraySize] = {};
        cin >> str;

        size_t numDigits = strlen(str);
        if (numDigits < 10)
            cout << sqrt(atoi(str)) << endl;
        else {
            int* digits = new int[numDigits + 3]();
            for (size_t j = 0; j < numDigits; ++j)
                digits[j] = static_cast<int>(str[numDigits - 1 - j]) - '0';

            size_t last = (numDigits - 1) / 4;
            size_t hugeIntSize = last + 1;
            long long int* hugeInt = new long long int[hugeIntSize]();
            for (size_t j = 0; j <= last; j++)
                hugeInt[j] = digits[4 * j] + digits[4 * j + 1] * 10 + digits[4 * j + 2] * 100 + digits[4 * j + 3] * 1000;

            size_t sqrtSize = (hugeIntSize + 1) / 2;
            long long int* squareRoot = new long long int[sqrtSize]();

            compSquareRoot(hugeInt, squareRoot, hugeIntSize, sqrtSize);

            cout << squareRoot[sqrtSize - 1];
            for (int j = sqrtSize - 2; j >= 0; j--)
                cout << setw(4) << setfill('0') << squareRoot[j];
            cout << endl;

            delete[] squareRoot;
            delete[] hugeInt;
            delete[] digits;
        }
        if (N > 0)
            cout << endl;
    }
    return 0;
}

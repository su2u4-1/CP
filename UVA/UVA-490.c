#include <stdio.h>

int main(void) {
    int c = getchar();
    int i1 = 0, i2 = 0, max = 0;
    int length[101];
    char input[101][101];
    while (1) {
        if (c == '\n' || c == EOF) {
            input[i1][i2] = '\0';
            length[i1] = i2;
            if (i2 > max) max = i2;
            i2 = 0;
            ++i1;
            if (c == EOF) break;
        } else
            input[i1][i2++] = c;
        c = getchar();
    }
    for (int j = 0; j < max; ++j) {
        for (int i = i1; i >= 0; --i) {
            if (j < length[i]) {
                putchar(input[i][j]);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}

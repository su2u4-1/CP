#include <stdio.h>

int main(void) {
    int c = getchar();
    char in_string = 0;
    while (c != EOF) {
        if (c == '"') {
            if (in_string) {
                in_string = 0;
                putchar('`');
                putchar('`');
            } else {
                in_string = 1;
                putchar('\'');
                putchar('\'');
            }
        } else
            putchar(c);
        c = getchar();
    }
    return 0;
}

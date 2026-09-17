#include <stdio.h>

int main(void) {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
        printf("%d\n", m + (m != n));
}

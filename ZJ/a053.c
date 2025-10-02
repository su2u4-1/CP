#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n > 40)
        printf("%d", 100);
    else if (n > 20)
        printf("%d", 10 * 6 + 10 * 2 + (n - 20) * 1);
    else if (n > 10)
        printf("%d", 10 * 6 + (n - 10) * 2);
    else
        printf("%d", n * 6);
    return 0;
}

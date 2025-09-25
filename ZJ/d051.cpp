#include <stdio.h>

int main() {
    double n;
    scanf("%lf", &n);
    printf("%.3f", (n - 32.0) * 5.0 / 9.0);
    return 0;
}

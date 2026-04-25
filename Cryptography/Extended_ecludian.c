#include <stdio.h>

// Extended Euclidean Algorithm with step display
int extendedEuclid(int a, int b, int *x, int *y) {
    printf("Computing gcd(%d, %d)\n", a, b);

    if (b == 0) {
        *x = 1;
        *y = 0;
        printf("Base Case: gcd(%d, %d) = %d\n", a, b, a);
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclid(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    printf("Back Step: gcd(%d, %d) = %d\n", a, b, gcd);
    printf("x = %d, y = %d\n", *x, *y);
    printf("Equation: %d(%d) + %d(%d) = %d\n", a, *x, b, *y, gcd);
    printf("---------------------------------\n");

    return gcd;
}

int main() {
    int a, m;
    int x, y;

    printf("Enter number (a): ");
    scanf("%d", &a);

    printf("Enter modulo (m): ");
    scanf("%d", &m);

    int gcd = extendedEuclid(a, m, &x, &y);

    if (gcd != 1) {
        printf("Multiplicative inverse does not exist (gcd != 1).\n");
    } else {
        int inverse = (x % m + m) % m;
        printf("Multiplicative inverse of %d under modulo %d is: %d\n", a, m, inverse);
    }

    return 0;
}
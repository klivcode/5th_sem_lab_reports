// primitive root
#include <stdio.h>

// Function to calculate gcd
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n, g;
    printf("Enter n (preferably prime): ");
    scanf("%d", &n);

    printf("Enter g: ");
    scanf("%d", &g);

    // Check if g and n are coprime
    if (gcd(g, n) != 1) {
        printf("%d is NOT a primitive root of %d (not coprime)\n", g, n);
        return 0;
    }

    int used[100] = {0}; // track generated numbers
    int flag = 1;

    printf("\nCalculating powers of %d modulo %d:\n\n", g, n);

    int result = 1;
    for (int i = 1; i <= n - 1; i++) {
        result = (result * g) % n;
        printf("Step %2d: %d^%d mod %d = %d\n", i, g, i, n, result);

        if (used[result] == 1) flag = 0; // repeated value
        used[result] = 1;
    }

    // Check if all numbers from 1 to n-1 appear
    for (int i = 1; i <= n - 1; i++) {
        if (used[i] == 0) flag = 0;
    }

    if (flag)
        printf("\nResult: %d IS a primitive root of %d\n", g, n);
    else
        printf("\nResult: %d is NOT a primitive root of %d\n", g, n);

    return 0;
}

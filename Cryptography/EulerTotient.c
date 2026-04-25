/// euler 
#include <stdio.h>

int main() {
    int n, temp, i, phi;

    // Take input from user
    printf("Enter value of n: ");
    scanf("%d", &n);

    // Initialize
    temp = n;
    phi = n;

    printf("\nStep 1: Start with n = %d\n", n);
    printf("Initial phi(n) = %d\n\n", phi);

    // Check for prime factors up to sqrt(n)
    for (i = 2; i * i <= temp; i++) {
        if (temp % i == 0) { // i is a prime factor

            printf("Prime factor found: %d\n", i);

            // Divide temp completely by this prime
            while (temp % i == 0) {
                printf("Dividing %d by %d\n", temp, i);
                temp = temp / i;
            }

            // Apply Euler's formula
            printf("Applying formula: phi(n) = phi(n) - phi(n)/%d\n", i);
            phi = phi - (phi / i);

            printf("Updated phi(n) = %d\n\n", phi);
        }
    }

    // If remaining temp is prime
    if (temp > 1) {
        printf("Prime factor found: %d\n", temp);
        printf("Applying formula: phi(n) = phi(n) - phi(n)/%d\n", temp);
        phi = phi - (phi / temp);
        printf("Updated phi(n) = %d\n\n", phi);
    }

    // Final result
    printf("Final Result: phi(%d) = %d\n", n, phi);

    return 0;
}

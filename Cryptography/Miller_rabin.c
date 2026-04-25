#include <stdio.h>

// Fast modular exponentiation
long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    long long m, k = 0;
    long long a = 2;   // Fixed base
    long long T;

    printf("Enter value of n: ");
    scanf("%lld", &n);

    if (n < 2) {
        printf("Composite (n < 2)\n");
        return 0;
    }

    if (n == 2 || n == 3) {
        printf("Prime\n");
        return 0;
    }

    if (n % 2 == 0) {
        printf("Composite (Even number)\n");
        return 0;
    }

    // Step 1: Write n-1 = m * 2^k
    m = n - 1;

    while (m % 2 == 0) {
        m /= 2;
        k++;
    }

    printf("\nStep 1: Decompose n-1\n");
    printf("%lld - 1 = %lld * 2^%lld\n", n, m, k);

    // Step 2: Compute T1 = a^m mod n
    printf("\nStep 2: Compute T1 = a^m mod n\n");
    printf("Using a = %lld\n", a);

    T = modPower(a, m, n);
    printf("T1 = %lld^%lld mod %lld = %lld\n", a, m, n, T);

    if (T == 1 || T == n - 1) {
        printf("\nResult: Probably Prime\n");
        return 0;
    }

    // Step 3: If k > 1, compute Ti = Ti-1^2 mod n
    printf("\nStep 3: Compute successive squares\n");

    for (long long i = 1; i < k; i++) {
        T = (T * T) % n;
        printf("T%lld = (previous T)^2 mod %lld = %lld\n", i + 1, n, T);

        if (T == n - 1) {
            printf("\nResult: Probably Prime\n");
            return 0;
        }

        if (T == 1) {
            printf("\nResult: Composite\n");
            return 0;
        }
    }

    printf("\nResult: Composite\n");
    return 0;
}

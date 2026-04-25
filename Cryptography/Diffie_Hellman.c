#include <stdio.h>

// Simple function to calculate (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

int main() {
    long long p, g, Xa, Xb;
    long long Ya, Yb, Ka, Kb;

    printf("Enter prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root (g): ");
    scanf("%lld", &g);

    printf("Enter Alice Secret Key (Xa): ");
    scanf("%lld", &Xa);

    printf("Enter Bob Secret Key (Xb): ");
    scanf("%lld", &Xb);

    // Step 1: Public Keys
    Ya = power(g, Xa, p);
    Yb = power(g, Xb, p);

    printf("\n--- Public Keys ---\n");
    printf("Alice Public Key (Ya) = g^Xa mod p = %lld\n", Ya);
    printf("Bob Public Key (Yb) = g^Xb mod p = %lld\n", Yb);

    // Step 2: Shared Secret Keys
    Ka = power(Yb, Xa, p);
    Kb = power(Ya, Xb, p);

    printf("\n--- Shared Secret Key Calculation ---\n");
    printf("Alice Key (Ka) = Yb^Xa mod p = %lld\n", Ka);
    printf("Bob Key (Kb) = Ya^Xb mod p = %lld\n", Kb);

    if (Ka == Kb)
        printf("\nShared Secret Key = %lld\n", Ka);
    else
        printf("\nKeys do not match!\n");

    return 0;
}
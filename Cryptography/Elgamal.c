
// elgam
#include <stdio.h>

// Function for modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

// Function to find modular inverse (brute force)
long long modInverse(long long a, long long p) {
    a = a % p;
    for (long long i = 1; i < p; i++) {
        if ((a * i) % p == 1)
            return i;
    }
    return -1;
}

int main() {
    long long p, g, Xa, Ya;
    long long M, r;
    long long K, C1, C2, decrypted;

    printf("Enter prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root (g): ");
    scanf("%lld", &g);

    printf("Enter Private Key Xa (Xa < p-1): ");
    scanf("%lld", &Xa);

    // Key Generation
    Ya = power(g, Xa, p);

    printf("\n--- Key Generation ---\n");
    printf("Ya = g^Xa mod p = %lld\n", Ya);
    printf("Public Key (PU) = {%lld, %lld, %lld}\n", p, g, Ya);
    printf("Private Key = {%lld}\n", Xa);

    // Encryption
    printf("\nEnter Plaintext M (M < p): ");
    scanf("%lld", &M);

    printf("Enter Random Integer r (r < p): ");
    scanf("%lld", &r);

    K = power(Ya, r, p);
    C1 = power(g, r, p);
    C2 = (K * M) % p;

    printf("\n--- Encryption ---\n");
    printf("K = Ya^r mod p = %lld\n", K);
    printf("C1 = g^r mod p = %lld\n", C1);
    printf("C2 = K*M mod p = %lld\n", C2);
    printf("Ciphertext (C1, C2) = (%lld, %lld)\n", C1, C2);

    // Decryption
    printf("\n--- Decryption ---\n");

    K = power(C1, Xa, p);
    long long K_inv = modInverse(K, p);

    decrypted = (C2 * K_inv) % p;
    if (decrypted < 0)
        decrypted += p;

    printf("K = C1^Xa mod p = %lld\n", K);
    printf("K^-1 (Inver of K )= %lld\n", K_inv);
    printf("Decrypted Message M(K^-1 mod p)= %lld\n", decrypted);

    return 0;
}


//RSA

#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

int main() {
    int p, q, n, phi, e, d;
    char message[100];

    printf("Enter prime number p: ");
    scanf("%d", &p);
    printf("Enter prime number q: ");
    scanf("%d", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("\nn = %d", n);
    printf("\nphi(n) = %d\n", phi);

    printf("\nEnter value of e (1 < e < %d and gcd(e, %d) = 1): ", phi, phi);
    scanf("%d", &e);

    if (gcd(e, phi) != 1) {
        printf("Invalid e! Must be co-prime with phi(n).\n");
        return 0;
    }

    d = modInverse(e, phi);

    printf("\nPublic Key (PU) = {%d, %d}", e, n);
    printf("\nPrivate Key (PR) = {%d, %d}\n", d, n);

    getchar();

    printf("\nEnter TEXT message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("\nEncryption Process (C = M^e mod n):\n");
    long long encrypted[100];
    int len = strlen(message);

    for (int i = 0; i < len; i++) {
        int ascii = (int)message[i];
        encrypted[i] = power(ascii, e, n);
        printf("'%c' -> ASCII %d -> Cipher %lld\n", message[i], ascii, encrypted[i]);
    }

    printf("\nDecryption Process (M = C^d mod n):\n");
    for (int i = 0; i < len; i++) {
        long long decrypted = power(encrypted[i], d, n);
        printf("Cipher %lld -> ASCII %lld -> '%c'\n", encrypted[i], decrypted, (char)decrypted);
    }

    return 0;
}



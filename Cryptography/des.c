#include <stdio.h>

// Permutation tables
int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P8[8]  = {6, 3, 7, 4, 8, 5, 10, 9};

// Left shift function
void leftShift(int key[], int shifts) {
    int temp;
    while (shifts--) {
        temp = key[0];
        for (int i = 0; i < 4; i++)
            key[i] = key[i + 1];
        key[4] = temp;
    }
}

// Permutation function
void permute(int input[], int output[], int perm[], int size) {
    for (int i = 0; i < size; i++)
        output[i] = input[perm[i] - 1];
}

int main() {
    int key[10], p10[10], left[5], right[5];
    int k1[8], k2[8], combined[10];

    printf("Enter 10-bit key (space separated):\n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &key[i]);

    // Apply P10
    permute(key, p10, P10, 10);

    // Split into halves
    for (int i = 0; i < 5; i++) {
        left[i]  = p10[i];
        right[i] = p10[i + 5];
    }

    // Left shift by 1
    leftShift(left, 1);
    leftShift(right, 1);

    // Combine halves
    for (int i = 0; i < 5; i++) {
        combined[i]     = left[i];
        combined[i + 5] = right[i];
    }

    // Generate K1
    permute(combined, k1, P8, 8);

    // Left shift by 2
    leftShift(left, 2);
    leftShift(right, 2);

    // Combine again
    for (int i = 0; i < 5; i++) {
        combined[i]     = left[i];
        combined[i + 5] = right[i];
    }

    // Generate K2
    permute(combined, k2, P8, 8);

    // Output keys
    printf("Subkey K1: ");
    for (int i = 0; i < 8; i++)
        printf("%d", k1[i]);

    printf("\nSubkey K2: ");
    for (int i = 0; i < 8; i++)
        printf("%d", k2[i]);

    return 0;
}

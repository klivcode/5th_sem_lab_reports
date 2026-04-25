
//RAIL FENCE

#include <stdio.h>
#include <string.h>

// Function to display rails for the message
void displayRails(char *text, int key) {
    int len = strlen(text);
    char rail[key][len];

    // Initialize the rails with spaces
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = ' ';

    int row = 0;
    int down = 1; // direction flag

    // Fill the rails
    for (int col = 0; col < len; col++) {
        rail[row][col] = text[col];

        if (row == 0)
            down = 1;
        else if (row == key - 1)
            down = 0;

        if (down)
            row++;
        else
            row--;
    }

    // Print the rails
    printf("\nRails representation:\n");
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++)
            printf("%c ", rail[i][j]);
        printf("\n");
    }
}

// Function to encrypt using Rail-Fence Cipher
void encryptRailFence(char *text, int key, char *cipher) {
    int len = strlen(text);
    int k = 0;

    for (int row = 0; row < key; row++) {
        int down = 1;
        for (int col = 0; col < len;) {
            if (row == 0 || row == key - 1) {
                if (col + row < len)
                    cipher[k++] = text[col + row];
                col += 2 * (key - 1);
            } else {
                if (col + row < len)
                    cipher[k++] = text[col + row];
                col += 2 * (key - row - 1);
                if (col < len) {
                    if (col + row < len)
                        cipher[k++] = text[col + row];
                    col += 2 * row;
                }
            }
        }
    }
    cipher[k] = '\0';
}

// Function to decrypt using Rail-Fence Cipher
void decryptRailFence(char *cipher, int key, char *text) {
    int len = strlen(cipher);
    char result[len + 1];
    int k = 0;

    for (int row = 0; row < key; row++) {
        int col = 0;
        while (col < len) {
            if (row == 0 || row == key - 1) {
                if (col + row < len) {
                    result[col + row] = cipher[k++];
                }
                col += 2 * (key - 1);
            } else {
                if (col + row < len) {
                    result[col + row] = cipher[k++];
                }
                col += 2 * (key - row - 1);
                if (col < len) {
                    if (col + row < len) {
                        result[col + row] = cipher[k++];
                    }
                    col += 2 * row;
                }
            }
        }
    }
    result[len] = '\0';
    strcpy(text, result);
}

int main() {
    char message[1000], cipher[1000], decrypted[1000];
    int key;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove newline

    printf("Enter the number of rails: ");
    scanf("%d", &key);

    displayRails(message, key);

    encryptRailFence(message, key, cipher);
    printf("\nEncrypted message: %s\n", cipher);

    decryptRailFence(cipher, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}








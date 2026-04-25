

////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

/* Create key matrix */
void createMatrix(char key[]) {
    int used[26] = {0};
    int i, k = 0;
    // FILL THE KEY
    for (i = 0; key[i]; i++) {
        if (key[i] == 'J') key[i] = 'I';
        if (!used[key[i] - 'A']) {
            matrix[k / 5][k % 5] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }
    // FILL REMAINING 
    for (i = 0; i < 26; i++) {
        if (i + 'A' == 'J') continue;
        if (!used[i]) {
            matrix[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

/* Print matrix */
void printMatrix() {
    int i, j;
    printf("\nPlayfair Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

/* Find character position */
void findPos(char c, int *row, int *col) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
            }
}

/* Prepare plaintext */
void prepareText(char text[]) {
    char temp[100];
    int i, j = 0;

    for (i = 0; text[i]; i++)
        if (isalpha(text[i]))
            temp[j++] = toupper(text[i] == 'J' ? 'I' : text[i]);
    temp[j] = '\0';

    j = 0;
    for (i = 0; temp[i]; i++) {
        text[j++] = temp[i];
        if (temp[i] == temp[i + 1])
            text[j++] = 'X';
    }

    if (j % 2 != 0)
        text[j++] = 'X';
    text[j] = '\0';
}

/* Encrypt */
void encrypt(char text[]) {
    int r1, c1, r2, c2;

    for (int i = 0; text[i]; i += 2) {
        findPos(text[i], &r1, &c1);
        findPos(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            text[i] = matrix[r1][(c1 + 1) % 5];
            text[i + 1] = matrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            text[i] = matrix[(r1 + 1) % 5][c1];
            text[i + 1] = matrix[(r2 + 1) % 5][c2];
        } else {
            text[i] = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

/* Decrypt */
void decrypt(char text[]) {
    int r1, c1, r2, c2;

    for (int i = 0; text[i]; i += 2) {
        findPos(text[i], &r1, &c1);
        findPos(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            text[i] = matrix[r1][(c1 + 4) % 5];
            text[i + 1] = matrix[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            text[i] = matrix[(r1 + 4) % 5][c1];
            text[i + 1] = matrix[(r2 + 4) % 5][c2];
        } else {
            text[i] = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

/* Optional: remove filler X */
void removeX(char text[]) {
    char temp[100];
    int i, j = 0;
    int len = strlen(text);

    for (i = 0; i < len; i++) {

        /* Remove X between repeated letters */
        if (i > 0 && i < len - 1 &&
            text[i] == 'X' &&
            text[i - 1] == text[i + 1]) {
            continue;
        }

        /* Remove padding X at end */
        if (i == len - 1 && text[i] == 'X') {
            continue;
        }

        temp[j++] = text[i];
    }

    temp[j] = '\0';
    strcpy(text, temp);
}


int main() {
    char text[100], prepared[100], encrypted[100], decrypted[100];
    char encKey[50], decKey[50];
    int choice;

    printf("Enter key for encryption: ");
    scanf("%s", encKey);
    for (int i = 0; encKey[i]; i++)
        encKey[i] = toupper(encKey[i]);

    createMatrix(encKey);
    printMatrix();

    printf("Enter message: ");
    scanf(" %[^\n]", text);

    strcpy(prepared, text);
    prepareText(prepared);

    do {
        printf("\n1. Encrypt\n2. Decrypt\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            strcpy(encrypted, prepared);
            encrypt(encrypted);
            printf("Encrypted Text: %s\n", encrypted);
        }
        else if (choice == 2) {
            printf("Enter key for decryption: ");
            scanf("%s", decKey);
            for (int i = 0; decKey[i]; i++)
                decKey[i] = toupper(decKey[i]);

            createMatrix(decKey);
            printMatrix();

            strcpy(decrypted, encrypted);
            decrypt(decrypted);
            removeX(decrypted);   // optional
            printf("Decrypted Text: %s\n", decrypted);
        }
    } while (choice != 3);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(const char text[], char encrypted[], int key)
{
    key %= 26;
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (isupper(ch))
            encrypted[i] = (ch - 'A' + key) % 26 + 'A';
        else if (islower(ch))
            encrypted[i] = (ch - 'a' + key) % 26 + 'a';
        else
            encrypted[i] = ch;
    }
    encrypted[i] = '\0';   // FIX: null termination
}

void decrypt(const char encrypted[], char decrypted[], int key)
{
    key %= 26;
    int i;

    for (i = 0; encrypted[i] != '\0'; i++)
    {
        char ch = encrypted[i];

        if (isupper(ch))
            decrypted[i] = (ch - 'A' - key + 26) % 26 + 'A';
        else if (islower(ch))
            decrypted[i] = (ch - 'a' - key + 26) % 26 + 'a';
        else
            decrypted[i] = ch;
    }
    decrypted[i] = '\0';   // FIX: null termination
}

int main()
{
    char message[100];
    char encrypted[100] = "";   // FIX: initialization
    char decrypted[100];
    int key, choice;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    do
    {
        printf("\n1. Encrypt\n2. Decrypt\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter key for encryption: ");
            scanf("%d", &key);

            encrypt(message, encrypted, key);
            printf("Original Message : %s\n", message);
            printf("Encrypted Message: %s\n", encrypted);
        }
        else if (choice == 2)
        {
            printf("Enter key for decryption: ");
            scanf("%d", &key);

            decrypt(encrypted, decrypted, key);
            printf("Encrypted Message: %s\n", encrypted);
            printf("Decrypted Message: %s\n", decrypted);
        }
        else if (choice == 3)
        {
            printf("Exiting program...\n");
        }
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}

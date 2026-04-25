#include <stdio.h>
#include <string.h>

int main() {
    char msg[17];
    unsigned char state[4][4];
    int i, j, k = 0;

    printf("Enter a message (max 16 characters): ");
    scanf("%16s", msg);

    // Pad with 'X' if message < 16 chars
    for (i = strlen(msg); i < 16; i++)
        msg[i] = 'X';
    msg[16] = '\0';

    // Fill state array column-wise (AES style)
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            state[i][j] = msg[k++];
        }
    }

    // Display state array in HEX
    printf("\nState Array (Hex Format):\n\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%02X ", state[i][j]);   // Print hex value
        }
        printf("\n");
    }

    return 0;
}

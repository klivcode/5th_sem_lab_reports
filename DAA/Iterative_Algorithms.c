/*
LAB 1
Title: Iterative algorithms Implementation
Objective:
To implement GCD using Itertion
To Implement Fibonacci series usign Iteration
To implement Factorial series using Iteration
To implement Linear Search using Iteration

THEORY:
Name:
    - Algorithm
    - Trace
    - Time & Space Complexity
*/

#include <stdio.h>
#define size 5

int arr[size];


int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void fibonacci(int n) {
    int a = 0, b = 1, c;
    printf("Fibonacci Series:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}


int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


int linearSearch(int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int choice, a, b, n, key, result;

    printf("Enter the %d numbers of the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu Driven Program");
        printf("\n1. GCD");
        printf("\n2. Fibonacci Series");
        printf("\n3. Factorial");
        printf("\n4. Linear Search");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("GCD = %d\n", gcd(a, b));
                break;

            case 2:
                printf("Enter number of terms: ");
                scanf("%d", &n);
                fibonacci(n);
                break;

            case 3:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial = %d\n", factorial(n));
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = linearSearch(key);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else
                    printf("Element not found\n");
                break;

            case 5:
                printf("Exiting the program\n");
                break;

            default:
                printf("Exception Choice OutOfBounds\n");
        }

    } while (choice != 5);

    return 0;
}

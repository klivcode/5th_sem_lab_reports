
// fermat 
#include <stdio.h>

// Function to calculate (a^b) % mod using modular exponentiation
long long modPower(long long a, long long b, long long mod)
{
    long long result = 1;
    a = a % mod;

    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % mod;

        a = (a * a) % mod;
        b = b / 2;
    }
    return result;
}

int main()
{
    int n, a;
    char choice = 'y';

    // while loop to repeat the test
    while (choice == 'y' || choice == 'Y')
    {
        printf("Enter a number (n): ");
        scanf("%d", &n);

        if (n <= 1)
        {
            printf("Not a prime number\n");
        }
        else
        {
            printf("Enter the value of a (1 < a < %d): ", n-1);
            scanf("%d", &a);

            if (a <= 1 || a >= n)
            {
                printf("Invalid value of a\n");
            }
            else
            {
                if (modPower(a, n - 1, n) == 1)
                    printf("%d is probably a prime number (Fermat Test)\n", n);
                else
                    printf("%d is a composite number\n", n);
            }
        }

        printf("\nDo you want to test another number? (y/n): ");
        scanf(" %c", &choice);   // space before %c is important
        printf("\n");
    }

    return 0;
}

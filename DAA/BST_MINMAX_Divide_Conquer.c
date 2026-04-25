
#include <stdio.h>
#include<math.h>

int arr[100], n;
int min, max;

int BinarySearch(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = floor((left + right) / 2);

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return BinarySearch(arr, left, mid - 1, key);
        else
            return BinarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

void MinMax(int left, int right)
{
    int mid, min1, max1;

    if (left == right)
    {
        min = max = arr[left];
    }
    else if (left == right - 1)
    {
        if (arr[left] < arr[right])
        {
            min = arr[left];
            max = arr[right];
        }
        else
        {
            min = arr[right];
            max = arr[left];
        }
    }
    else
    {
        mid = floor((left + right) / 2);

        MinMax(left, mid);
        min1 = min;
        max1 = max;

        MinMax(mid + 1, right);

        if (max > max1) max = max;
        else max = max1;

        if (min < min1) min = min;
        else min = min1;
    }
}

/* Main Menu */
int main()
{
    int choice, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements in ascending order:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Binary Search\n");
        printf("2. Find Min & Max\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to search: ");
            scanf("%d", &key);

            result = BinarySearch(arr, 0, n - 1, key);

            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found\n");
            break;

        case 2:
            MinMax(0, n - 1);
            printf("Minimum = %d\n", min);
            printf("Maximum = %d\n", max);
            break;

        case 3:
            printf("Program exited.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}



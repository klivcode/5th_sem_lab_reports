

/*
10/07
lab 5
Title: Selection Problem using divide and conquer 
Objective:
- to implement selection problem 

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int*a,int*b)
{
    int temp=*a;
    *a=*b;
    *b = temp;
}


// int partition(int arr[], int low, int high)
// {
//     int pivot= arr[high];
//     int i = low-1;
//     for(int j=low; j<high; j++)
//     {
//         if(arr[j]<=pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i+1], &arr[high]);
//     return i+1;
// }

int randomized_partition(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]); 

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


int quick_select(int arr[], int low, int high, int k)
{
    if(low<=high)
    {
        int pivotIndex=randomized_partition(arr, low, high);

        if(pivotIndex==k)
            return arr[pivotIndex];
        
        if(pivotIndex > k) return quick_select(arr, low, pivotIndex-1, k);

        return quick_select(arr, pivotIndex+1, high, k);
    }
    return -1;
}



 int main()
 {
    int arr[]={10,3,5,8,9,7,8,55,88,7,25,86,32,14,11,6,4,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k =5; //k-th smallest element


     int result = quick_select(arr, 0,n-1,k);

     if(result!=-1)
     {
        printf("%d -th smallest element is : %d\n", k+1, result);

     }else printf("Invalid Input\n");

     return 0;
 }




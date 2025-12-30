
// Iterative Sorting Algorithms: Bubble Sort, Selection Sort, Insertion Sort

#include<stdio.h>
int i,j;

void swap(int*a, int*b)
{
  int temp;
  temp= *a;
  *a=*b;
  *b= temp;
}
void insertElement(int arr[],int *n)
{

  printf("Enter the size of the array\n");
  scanf("%d",n);
  printf("Enter the elements in the array\n");
  for(int i =0; i<*n;i++)
  {
    scanf("%d",&arr[i]);
  }
  
}

void display(int arr[], int n)
{
   for(i=0;i<n;i++)
   {
    printf("%d\t",arr[i]);
   }
   printf("\n");
}

void bubblesort(int arr[], int n)
{
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(&arr[j],&arr[j+1]);
      }
    }
  }
}

void selectionsort(int arr[], int n)
{
  for(i=0;i<n-1;i++)
  {
    int min_idx=i;
    for(j=i+1; j<n; j++)
    {
      if(arr[j]<arr[min_idx])
      {
        min_idx=j;
      }
    
    }
    swap(&arr[i],&arr[min_idx]);
  }
}

void insertionsort(int arr[], int n)
{
  for(i=1; i<n;i++)
  {
    int key=arr[i];
    int j=i-1;
    for(;j>=0 && arr[j]>key;)
    {
      arr[j+1]=arr[j];
      j=j-1;
    }
    arr[j+1]=key;
  }
}


int main() {
    int arr[100], n;
    int choice;
    
    insertElement(arr, &n);

    do {
        
        printf("\nChoose an option:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                bubblesort(arr, n);
                printf("Array after Bubble Sort: \n");
                display(arr, n);
                break;
            case 2:
                selectionsort(arr, n);
                printf("Array after Selection Sort: \n");
                display(arr, n);
                break;
            case 3:
                insertionsort(arr, n);
                printf("Array after Insertion Sort: \n");
                display(arr, n);
                break;
            case 4:
                display(arr, n);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! \n");
        }
    } while(choice != 5);

    return 0;
}


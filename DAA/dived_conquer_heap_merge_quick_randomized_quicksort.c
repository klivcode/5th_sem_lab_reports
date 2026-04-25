
// 09/23
/*
Obejctive:
     to implement Quick sort with partition an analyze it's complexity
     to implement Heap sort and analyze it's complexity
     to implement Merge Sort and analyze it complexity
     to implement Randomuized quick sort and analayze its complexity
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* Function Declarations */
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int q, int r);
void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void swap(int *a, int *b);
int RandomizedPartition(int arr[], int l, int r);
void RandoizedQuickSort(int arr[], int l, int r);
void HeapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void display(int arr[], int n);

/* Merge Sort */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int q = (l + r) / 2;
        mergeSort(arr, l, q);
        mergeSort(arr, q + 1, r);
        merge(arr, l, q, r);
    }
}

void merge(int arr[], int l, int q, int r){
    int i = l, j = q + 1, k = l;
    int temp[1000];

    while (i <= q && j <= r){
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= q)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for(i = l; i <= r; i++)
        arr[i] = temp[i];
}

/* Quick Sort */
void quickSort(int arr[], int l, int r){
    int q;
    if(l < r){
        q = partition(arr, l, r);
        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int partition(int arr[], int l, int r){
    int x = arr[r];
    int i = l - 1;
    int j;

    for(j = l; j < r; j++){
        if(arr[j] <= x){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Randomized Quick Sort */
int RandomizedPartition(int arr[], int l, int r){
    int i = l + rand() % (r - l + 1);
    swap(&arr[i], &arr[r]);
    return partition(arr, l, r);
}

void RandoizedQuickSort(int arr[], int l, int r){
    int q;
    if(l < r){
        q = RandomizedPartition(arr, l, r);
        RandoizedQuickSort(arr, l, q - 1);
        RandoizedQuickSort(arr, q + 1, r);
    }
}

/* Heap Sort */
void HeapSort(int arr[], int n){
    int i;
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(i = n - 1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;

    if(r < n && arr[r] > arr[largest])
        largest = r;

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

/* Display */
void display(int arr[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
int main(){
    int arr[100], n, choice, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while(1){
        printf("\n---- SORTING MENU ----\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Randomized Quick Sort\n");
        printf("4. Heap Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 0)
            break;

        switch(choice){
            case 1:
                mergeSort(arr, 0, n - 1);
                break;
            case 2:
                quickSort(arr, 0, n - 1);
                break;
            case 3:
                RandoizedQuickSort(arr, 0, n - 1);
                break;
            case 4:
                HeapSort(arr, n);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printf("\nSorted array:\n");
        display(arr, n);
        printf("\n");
    }

    return 0;
}

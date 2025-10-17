#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {  // low = 2, high = 4;
    int pivot = arr[high]; // pivot = 22;
    int i = (low - 1); // i = 1;
    for (int j = low; j <= high - 1; j++) { // j = 4  <= 3;

        if (arr[j] <= pivot) {
            i++; // i = 2;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
}

// {5, 34, 25, 12, 22, 11, 90, 64} 1st sort 
// {5, 34, 25, 12, 22, 11, 64, 90} 2nd sort
// {5, 11, 12, 22, 25, 34, 64, 90} 3rd step
// {5, 11, 12, 22, 25, 34, 64, 90} 4th step final answer 

void quickSort(int arr[], int low, int high) { // low = 2, high = 4;
    if (low < high) {
        int pi = partition(arr, low, high); // low = 2, high = 4, pi = 3 
        // smaller than 5 elements
        quickSort(arr, low, pi - 1); // low = 2, high = 2;
        // greater than 5 elements
        quickSort(arr, pi + 1, high); // low = 4, high = 4;
    }
}



int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); // 8;

    printf("Unsorted array: \n"); 
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); // {64, 34, 25, 12, 22, 11, 90, 5}

    quickSort(arr, 0, n - 1); // completed 

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++){ 
        printf("%d ", arr[i]);
    }
    printf("\n"); // {5, 11, 12, 22, 25, 34, 64, 90}
    return 0;
}
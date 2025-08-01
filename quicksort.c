#include <stdio.h>
#include <stdlib.h>
// Function to print a part of the array
void printArray(int arr[], int start, int end) {
for (int i = start; i <= end; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Partition function for Quick Sort
int partition(int arr[], int low, int high, int* pass) {
int pivot = arr[high];
int i = low - 1, temp;
for (int j = low; j < high; j++) {
if (arr[j] < pivot) {
i++;
// Swap arr[i] and arr[j]
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
// Swap arr[i+1] and arr[high]
temp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = temp;
// Print current pass
printf("Pass: ");
printArray(arr, low, high);
(*pass)++;
return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high, int* pass) {
    if (low < high) {
        int pi = partition(arr, low, high, pass);
        quickSort(arr, low, pi - 1, pass);
        quickSort(arr, pi + 1, high, pass);
    }
}

int main() {
    int n, i, pass = 1;

    printf("number of elements: ");
    scanf("%d", &n);

    int arr[n]; // VLA: valid in C99+

    printf("elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1, &pass);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

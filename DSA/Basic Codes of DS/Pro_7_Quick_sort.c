// Quick Sort Implementation in C
// This program sorts an array using the Quick Sort algorithm.
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int PARTITION(int A[], int p, int r) {
    int pivot = A[r];   // Pivot element
    int i = p - 1;      // Place for swapping

    for (int j = p; j < r; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);   // Place pivot in correct position
    return i + 1;
}

// QuickSort function
void QUICKSORT(int A[], int p, int r) {
    if (p < r) {
        int q = PARTITION(A, p, r);
        QUICKSORT(A, p, q - 1);
        QUICKSORT(A, q + 1, r);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    QUICKSORT(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Merge Sort Implementation in C
// This program sorts an array using the Merge Sort algorithm.
#include <stdio.h>
#include <string.h>   // for memcpy

// Merge function
void merge(int* A, int l, int mid, int u) {
    int B[u - l];  // Temporary array
    int i = l;     // Pointer for left subarray
    int j = mid;   // Pointer for right subarray
    int k = 0;

    // Merge two sorted halves
    while (i < mid && j < u) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i < mid) {
        B[k++] = A[i++];
    }

    // Copy remaining elements from right subarray
    while (j < u) {
        B[k++] = A[j++];
    }

    // Copy merged array back into original
    memcpy(A + l, B, (u - l) * sizeof(int));
}

// MergeSort function
void mergeSort(int* A, int l, int u) {
    if (u <= l + 1) return;   // Base case: 0 or 1 element
    int mid = (l + u) / 2;

    // Recursively sort both halves
    mergeSort(A, l, mid);
    mergeSort(A, mid, u);

    // Merge the two halves
    merge(A, l, mid, u);
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

    mergeSort(arr, 0, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

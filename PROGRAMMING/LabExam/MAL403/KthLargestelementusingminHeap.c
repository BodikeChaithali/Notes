#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int kthLargest(int arr[], int n, int k) {
    int heap[k];

    // Insert first k elements
    for (int i = 0; i < k; i++)
        heap[i] = arr[i];

    // Build min heap
    for (int i = k/2 - 1; i >= 0; i--)
        heapify(heap, k, i);

    // Process remaining elements
    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            heapify(heap, k, 0);
        }
    }

    return heap[0]; // root is kth largest
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int result = kthLargest(arr, n, k);
    printf("%dth Largest Element: %d\n", k, result);

    return 0;
}

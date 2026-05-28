#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int arr[], int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && arr[parent] < arr[index]) {
        swap(&arr[parent], &arr[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(int arr[], int *n, int key) {
    arr[*n] = key;
    (*n)++;
    heapifyUp(arr, *n - 1);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[20]; 
    int n = 0;

    int input[] = {42, 15, 27, 33, 18, 10, 5};
    int size = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < size; i++) {
        insert(arr, &n, input[i]);
        printf("Heap after inserting %d: ", input[i]);
        printHeap(arr, n);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* -------- MAX HEAPIFY (DOWN) -------- */
void maxHeapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

/* -------- UP HEAPIFY (BUBBLE UP in MAX HEAP) -------- */
void upHeapify(int *arr, int i) {
    if (i == 0) return;

    int parent = (i - 1) / 2;

    if (arr[i] > arr[parent]) {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;

        upHeapify(arr, parent);
    }
}

/* -------- BUILD MAX HEAP -------- */
void buildheap(int *arr, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

/* -------- EXTRACT MAX -------- */
int extractMax(int *arr, int *n) {
    int maxVal = arr[0];

    arr[0] = arr[*n - 1];
    (*n)--;

    maxHeapify(arr, *n, 0);
    return maxVal;
}

/* -------- INSERT INTO MAX HEAP -------- */
void insertHeap(int *arr, int *n, int val) {
    arr[*n] = val;
    (*n)++;
    upHeapify(arr, *n - 1);
}

/* -------- SOLUTION FUNCTION -------- */
int minStoneSum(int* piles, int pilesSize, int k) {
    buildheap(piles, pilesSize);

    while (k--) {
        int maxVal = extractMax(piles, &pilesSize);
        int reduced = maxVal - maxVal/2;   // floor(maxVal / 2)

        insertHeap(piles, &pilesSize, reduced);
    }

    long long sum = 0;
    for (int i = 0; i < pilesSize; i++)
        sum += piles[i];

    return (int)sum;
}

/* -------- MAIN FUNCTION -------- */
int main() {
    int n, k;

    printf("Enter number of piles: ");
    scanf("%d", &n);

    int *piles = (int*)malloc(sizeof(int) * (n + 100)); // extra room for inserts

    printf("Enter %d pile values:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &piles[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    int result = minStoneSum(piles, n, k);

    printf("Minimum stones left = %d\n", result);

    free(piles);
    return 0;
}

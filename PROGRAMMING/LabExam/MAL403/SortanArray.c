#include <stdio.h>
#include <stdlib.h>

/* ---------------- Merge Function ---------------- */
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

/* ---------------- Merge Sort ---------------- */
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* ---------------- API Function ---------------- */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
        result[i] = nums[i];

    mergeSort(result, 0, numsSize - 1);

    *returnSize = numsSize;
    return result;
}

/* ---------------- MAIN FUNCTION (TESTING) ---------------- */
int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int returnSize;
    int* sorted = sortArray(arr, n, &returnSize);

    printf("Sorted array: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    free(sorted);
    return 0;
}

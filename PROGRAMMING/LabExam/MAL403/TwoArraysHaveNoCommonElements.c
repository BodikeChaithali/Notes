#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

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
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int noCommon(int A[], int n, int B[], int m) {
    mergeSort(A, 0, n - 1);
    mergeSort(B, 0, m - 1);

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] == B[j])
            return 0;
        else if (A[i] < B[j])
            i++;
        else
            j++;
    }
    return 1;
}

int main() {
    int A[] = {5, 12, 21, 7};
    int B[] = {14, 1, 9, 22};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    if (noCommon(A, n, B, m))
        printf("No common elements\n");
    else
        printf("Common elements found\n");

    return 0;
}

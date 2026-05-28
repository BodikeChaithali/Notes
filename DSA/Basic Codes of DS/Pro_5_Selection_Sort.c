// Selection Sort Implementation in C
// This program sorts an array using the Selection Sort algorithm.
#include <stdio.h>

// Function to find the index of the minimum element
int MIN(int A[], int K, int N) 
{
    int MIN_VAL = A[K];
    int LOC = K;

    for (int J = K + 1; J < N; J++) 
    {
        if (A[J] < MIN_VAL) 
        {
            MIN_VAL = A[J];
            LOC = J;
        }
    }
    return LOC;
}

// Selection sort function
void SELECTION(int A[], int N) 
{
    for (int K = 0; K < N - 1; K++) 
    {
        int LOC = MIN(A, K, N);

        // Swap A[K] and A[LOC]
        int temp = A[K];
        A[K] = A[LOC];
        A[LOC] = temp;
    }
}

int main() 
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    SELECTION(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Insertion Sort in C
// This program sorts an array using the Insertion Sort algorithm.
#include <stdio.h>

void INSERTION(int A[], int N) 
{
    for (int K = 1; K < N; K++)   // Start with the 2nd element
    {
        int TEMP = A[K];
        int PTR = K;

        // Shift elements to the right while TEMP is smaller
        while (PTR > 0 && TEMP < A[PTR - 1]) 
        {
            A[PTR] = A[PTR - 1];   // Shift larger elements one step right
            PTR = PTR - 1;
        }

        A[PTR] = TEMP;   // Insert TEMP in correct position
    }
}

int main() 
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    INSERTION(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

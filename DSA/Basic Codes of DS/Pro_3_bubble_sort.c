// Bubble Sort Implementation in C
// This program sorts an array using the Bubble Sort algorithm.
#include <stdio.h>

void bubble_sort(int x[], int size) 
{
    int i, j, t;

    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            if (x[j] > x[j + 1]) 
            {
                // swap x[j] and x[j+1]
                t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
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

    bubble_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

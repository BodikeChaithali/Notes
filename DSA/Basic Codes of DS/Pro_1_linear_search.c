// Linear Search Implementation in C

#include <stdio.h>

void LINEAR(int DATA[], int N, int ITEM, int *LOC) 
{
    // Step 1: Insert ITEM at the end (sentinel)
    DATA[N] = ITEM;

    // Step 2: Initialize counter
    *LOC = 0;
    int i = 0;

    // Step 3: Search until ITEM is found
    while (DATA[i] != ITEM) {
        i++;
    }

    // Step 4: Successful?
    if (i == N) {
        *LOC = 0;   // Not found
    } else {
        *LOC = i + 1; // Found (position, 1-based)
    }
}

int main() 
{
    int n, i, item, loc;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n + 1];  // +1 for sentinel
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter item to search: ");
    scanf("%d", &item);

    LINEAR(arr, n, item, &loc);

    if (loc != 0) {
        printf("Element %d found at position %d (index %d).\n", item, loc, loc - 1);
    } else {
        printf("Element %d not found in the array.\n", item);
    }

    return 0;
}

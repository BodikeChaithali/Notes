// Binary Search Implementation in C
// This program performs a binary search on a sorted array of integers.
#include <stdio.h>

void BINARY(int DATA[], int LB, int UB, int Key, int *LOC) 
{
    int BEG = LB;
    int END = UB;
    int MID = (BEG + END) / 2;

    while (BEG <= END && DATA[MID] != Key) 
    {
        if (Key < DATA[MID]) 
        {
            END = MID - 1;
        } 
        else 
        {
            BEG = MID + 1;
        }
        MID = (BEG + END) / 2; // Update MID
    }

    if (BEG <= END && DATA[MID] == Key) 
    {
        *LOC = MID; // Found
    } 
    else 
    {
        *LOC = 0;   // Not found
    }
}

int main() 
{
    int n, i, key, loc;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    BINARY(arr, 0, n - 1, key, &loc);

    if (loc != 0) 
    {
        printf("Element %d found at position %d (index %d).\n", key, loc + 1, loc);
    } 
    else 
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
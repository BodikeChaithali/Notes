#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*
   Find 132 Pattern
   Pattern: nums[i] < nums[k] < nums[j] where i < j < k
*/

bool find132pattern(int* nums, int numsSize) {
    if (numsSize < 3) return false;

    int s[numsSize], top = -1;
    int third = INT_MIN;  // holds nums[k]

    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] < third)
            return true;

        // While stack top < nums[i], pop and assign to third
        while (top >= 0 && s[top] < nums[i])
            third = s[top--];

        s[++top] = nums[i];   // push to stack
    }
    return false;
}

/* MAIN FUNCTION TO TEST */
int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (find132pattern(arr, n))
        printf("132 pattern exists\n");
    else
        printf("132 pattern does not exist\n");

    return 0;
}

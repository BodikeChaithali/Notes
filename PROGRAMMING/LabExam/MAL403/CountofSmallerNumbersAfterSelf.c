#include <stdio.h>
#include <stdlib.h>

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* count = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int c = 0;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[i]) c++;
        }
        count[i] = c;
    }
    *returnSize = numsSize;
    return count;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int returnSize;
    int* result = countSmaller(nums, n, &returnSize);

    printf("Count of smaller elements to the right:\n");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(nums);
    free(result);
    return 0;
}

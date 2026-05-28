#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int st = 0, mid = 0, end = numsSize - 1;
    while (mid <= end) {
        if (nums[mid] == 0) {
            swap(&nums[st], &nums[mid]);
            st++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            swap(&nums[mid], &nums[end]);
            end--;
        }
    }
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Before: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    sortColors(nums, size);

    printf("After : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

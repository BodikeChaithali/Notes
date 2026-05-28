#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *nums, int size, int target, int findFirst) {
    int st = 0, end = size - 1, ans = -1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target) {
            ans = mid;
            if (findFirst) end = mid - 1;
            else st = mid + 1;
        }
        else if (nums[mid] > target) end = mid - 1;
        else st = mid + 1;
    }
    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1] = -1;
    ans[0] = BinarySearch(nums, numsSize, target, 1);
    if (ans[0] == -1) return ans;
    ans[1] = BinarySearch(nums, numsSize, target, 0);
    return ans;
}

int main() {
    int nums[] = {5,7,7,8,8,10};
    int target = 8;
    int returnSize;
    int *result = searchRange(nums, 6, target, &returnSize);
    printf("First and Last Position of %d: [%d, %d]\n", target, result[0], result[1]);
    free(result);
    return 0;
}

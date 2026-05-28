#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} HashNode;

int hashFunction(int key, int size) {
    int hash = key % size;
    return hash < 0 ? hash + size : hash;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    HashNode *hash = (HashNode*)calloc(numsSize, sizeof(HashNode));

    for(int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int hashIndex = hashFunction(complement, numsSize);

        while(hash[hashIndex].value != 0 || hash[hashIndex].index != 0) {
            if(hash[hashIndex].value == complement) {
                int *ans = (int *)malloc(sizeof(int)*2);
                ans[0] = hash[hashIndex].index;
                ans[1] = i;
                free(hash);
                return ans;
            }
            hashIndex = (hashIndex + 1) % numsSize;
        }

        hashIndex = hashFunction(nums[i], numsSize);
        while(hash[hashIndex].value != 0 || hash[hashIndex].index != 0)
            hashIndex = (hashIndex + 1) % numsSize;

        hash[hashIndex].value = nums[i];
        hash[hashIndex].index = i;
    }

    free(hash);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *ans = twoSum(nums, 4, target, &returnSize);

    if(ans != NULL)
        printf("[%d, %d]\n", ans[0], ans[1]);

    free(ans);
    return 0;
}

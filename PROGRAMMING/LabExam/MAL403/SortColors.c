#include <stdio.h>

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sortColors(int* nums, int numsSize) {
    int st=0, mid=0, end=numsSize-1;
    while(mid<=end) {
        if(nums[mid]==0) {
            swap(&nums[st],&nums[mid]);
            st++;
            mid++;
        }
        else if(nums[mid]==1) {
            mid++;
        }
        else {
            swap(&nums[mid],&nums[end]);
            end--;
        }
    }
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    sortColors(nums, numsSize);

    for(int i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);
    
    return 0;
}

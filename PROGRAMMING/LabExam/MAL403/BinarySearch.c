#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *arr, int n, int key) {
    int st=0,end=n-1;
    while(st<=end) {
        int mid=st+(end-st)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) end=mid-1;
        else st=mid+1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int key;
    scanf("%d",&key);
    int result = binarySearch(arr, n, key);
    printf("%d\n", result);
    free(arr);
    return 0;
}
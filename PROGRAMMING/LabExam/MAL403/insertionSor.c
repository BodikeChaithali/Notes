#include<stdio.h>
#include<stdlib.h>
void InsertionSort(int *arr, int n) {
    for(int i = 1; i <=n; i++) {
        int temp=arr[i];
        int ptr=i;
        while(ptr>0 && temp<arr[ptr-1]) {
            arr[ptr]=arr[ptr-1];
            ptr--;
        }
        arr[ptr]=temp;
        }
}

int main() {
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    InsertionSort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    free(arr);
    return 0;
}
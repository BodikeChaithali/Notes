#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void BubbleSort(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    BubbleSort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    free(arr);
    return 0;
}
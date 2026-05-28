#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        int mI=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[mI]) mI=j;
        }
        if(mI!=i) swap(&arr[i],&arr[mI]);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    SelectionSort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    free(arr);
    return 0;
}
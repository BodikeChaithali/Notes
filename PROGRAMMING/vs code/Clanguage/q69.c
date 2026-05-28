#include<stdio.h>
void main () {
    int n;
    printf("Enter the size of the array:");scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    for(int i=0;i<n/2;i++) {
        int t=arr[i];
        arr[i]=arr[n-i-1]; arr[n-i-1]=t;
    }
    printf("Array elements after reversing:");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
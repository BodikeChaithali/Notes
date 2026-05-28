#include<stdio.h>

void main () {
    int n;
    printf("Enter the array size:");scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    printf("Input array elements:\n");
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]>arr[j]) {int t=arr[i]; arr[i]=arr[j];arr[j]=t;} 
        }
    }
    printf("Sorted array elements in Ascending order:\n");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
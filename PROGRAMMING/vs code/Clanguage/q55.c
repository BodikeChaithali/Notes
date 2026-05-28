#include<stdio.h>

void main () {
    //bubble sort array
    int n,t;
    printf("Enter n value: ");scanf("%d",&n);
    int arr[n];
    printf("Input Arrays:\n");
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;}
        }
    }
    printf("Sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
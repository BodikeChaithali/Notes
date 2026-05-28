#include<stdio.h>

void main () {
    //selection sort array
    int n,t;
    printf("Enter n value: ");scanf("%d",&n);
    int arr[n];
    printf("Input the array:\n");
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]<arr[j]) {t=arr[i];arr[i]=arr[j]; arr[j]=t;}
        }
    }
    printf("Decreasing order:\n");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
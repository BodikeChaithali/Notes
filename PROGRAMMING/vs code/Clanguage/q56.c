#include<stdio.h>

void main () {
    int n;
    printf("Enter n value:");scanf("%d",&n);
    int arr[n],t;
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
        if(arr[i]%2==0) printf("%d ",arr[i]);
    }
    for(int i=n-1;i>=0;i--) {
        if(arr[i]%2!=0) printf("%d ",arr[i]);
    }
    printf("\n");
}
#include<stdio.h>

void main () {
    int n,max,min;
    printf("Enter n value: ");scanf("%d",&n);
    printf("Enter the inputs:\n");
    int arr[n];
    printf("Element-0:");scanf("%d",&arr[0]);
    max=arr[0];min=arr[0];
    for(int i=1;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
        if(arr[i]<min) min=arr[i];
        if(arr[i]>max) max=arr[i];
    }
    printf("The min and max values are:%d,%d\n",min,max);
}
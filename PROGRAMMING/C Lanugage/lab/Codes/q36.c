#include<stdio.h>

void main () {
    int n;printf("Enter the size of the array:");scanf("%d",&n);
    int arr[n];printf("Input the array elements:\n");
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    if(n==1) {printf("Peak element=%d\n",arr[0]);return;}
    if(arr[0]>=arr[1]) {printf("Peak element=%d\n",arr[0]);return;}
    if(arr[n-1]>=arr[n-2]) {printf("Peak element=%d\n",arr[n-1]);return;}
    for(int i=1;i<n-1;i++) {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {printf("Peak element=%d\n",arr[i]);return;}
    }
}
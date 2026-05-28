#include<stdio.h>

void main () {
    int n,arr[n],mean=0;
    printf("N=");scanf("%d",&n);
    printf("Input %d elements in array:\n",n);
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
        mean=mean+arr[i];
    }
    printf("Mean of all elements stored in the array : %.2f\n",(float)mean/n);
}
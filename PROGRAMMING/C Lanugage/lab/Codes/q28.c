#include<stdio.h>

void main () {
    int n,arr[n];
    printf("Input the number of elements to be stored in the array:");scanf("%d",&n);
    printf("Input %d elements in the array:\n",n);
    for(int i=0;i<n;i++){
        printf("Element-%d:",i);scanf("%d",&arr[i]);
        int j;
        for(j=0;j<=i;i++) {
            if(arr[i+1]==arr[j]) continue;
            else goto start; 
        }
        start:printf("%d ",arr[j]);
    }

}
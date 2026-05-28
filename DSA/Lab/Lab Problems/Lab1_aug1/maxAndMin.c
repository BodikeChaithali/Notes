#include<stdio.h>
#include<stdlib.h>

void findMinMax(int *arr,int n,int *min,int *max) {
    for(int i=1;i<n;i++) {
        if(arr[i]>*max) *max=arr[i];
        if(arr[i]<*min) *min=arr[i];
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int *arr=malloc(sizeof(int)*n);
    printf("Enter the values in the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int min,max;
    max=min=arr[0];
    findMinMax(arr,n,&min,&max);
    printf("Max: %d and Min: %d.\n",max,min);
    free(arr);
    return 0;
}
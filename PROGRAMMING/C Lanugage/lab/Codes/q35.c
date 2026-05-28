#include<stdio.h>

void main () {
    int n;
    printf("Enter size of the array:");scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++) {printf("Element-%d:",i);scanf("%d",&arr[i]);}
    printf("Original array: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    int m;printf("\nEnter the number of times to rotate the array: ");scanf("%d",&m);
    for(int i=0;i<m;i++) {
        int last=arr[n-1];
        for(int j=n-1;j>0;j--) arr[j]=arr[j-1];
        arr[0]=last;
    }
    printf("Array after rotating %d times: ",m);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
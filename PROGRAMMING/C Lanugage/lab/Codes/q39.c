#include<stdio.h>

void main () {
    int n;
    printf("Enter the size ofthe array: ");scanf("%d",&n);
    int arr[n];printf("Input the elements:\n");
    for(int i=0;i<n;i++) {printf("Element-%d:",i);scanf("%d",&arr[i]);}
    printf("The unique elements found in the array are:");
    for(int i=0;i<n;i++) {
        int c=0;
        for(int j=0;j<n;j++) {
            if(arr[i]==arr[j]) c++;
        }
        if(c==1) {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}
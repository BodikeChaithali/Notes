#include<stdio.h>
//removing duplicates
void main () {
    int n;
    printf("Enter the size ofthe array: ");scanf("%d",&n);
    int arr[n];printf("Input the elements:\n");
    for(int i=0;i<n;i++) {printf("Element-%d:",i);scanf("%d",&arr[i]);}
    printf("The elements after removing duplicates in the array are:");
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n; ) {
            if(arr[i]==arr[j]) {
                for(int k=j;k<n-1;k++) {
                    arr[k]=arr[k+1];
                }
                n--;
            }
            else j++;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
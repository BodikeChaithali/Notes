#include<stdio.h>

void main () {
    int n;
    printf("Enter the size of the array:");scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++) {printf("Element-%d:",i);scanf("%d",&arr[i]);}
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;) {
            if(arr[i]==arr[j]){
                for(int k=0;k<n-1;k++)
                arr[k]=arr[k+1];
                n--;
            }
            else j++;
        }
    }
    printf("After removing duplicates:");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
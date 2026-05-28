#include<stdio.h>

void main () {
    int n;
    printf("Enter n value:");scanf("%d",&n);
    int arr[n],t;
    printf("Input Arrays:\n");
    for(int i=0;i<n;i++) {
        printf("Element-%d:",i);scanf("%d",&arr[i]);
    }
    int newelement,position;
    printf("Enter new element and its position to be added:");
    scanf("%d %d",&newelement,&position);
    int i;
    for(i=n;i>=position;i--) arr[i]=arr[i-1];
    arr[i]=newelement;
    printf("New array!!\n");
    for(int j=0;j<=n;j++) {
        printf("%d ",arr[j]);
    }
    printf("\n");
}
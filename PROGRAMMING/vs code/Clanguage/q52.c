#include<stdio.h>

void main () {
    int n;
    printf("Enter n value: ");scanf("%d",&n);
    int arr[n],s,f=0;
    printf("Input the array:\n");
    for(int i=0;i<n;i++) {
        printf("Element-%d: ",i);scanf("%d",&arr[i]);
    }
    printf("Enter the value you have to search: ");scanf("%d",&s);
    for(int i=0;i<n;i++) {
        if(arr[i]==s) {
            f=1;
             printf("%d in %d cell.\n",s,i+1);
        }
    }
    if(f==0) printf("%d Value not found in given array!!\n",s);
}
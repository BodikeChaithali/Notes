#include<stdio.h>

void main () {
    int n,sum=0;
    printf("Enter any number:");scanf("%d",&n);
    printf("Factors of %d are:",n);
    for(int i=1;i<n;i++) {
        if(n%i==0) {
            printf("%d ",i);
            sum=sum+i;
        } 
    }
    if(sum==n) puts("\nPerfect");
    else puts("\nNot a Perfect");
}
#include<stdio.h>

void main () {
    int n;
    printf("n=");scanf("%d",&n);
    for(int i=1;i<=10;i++) {
        printf("%dX%d=%d\n",n,i,n*i);
    }
}
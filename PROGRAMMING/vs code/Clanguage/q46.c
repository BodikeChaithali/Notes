#include<stdio.h>
#include <stdlib.h>

void main () {
    int n;
    printf("Enter a number:");scanf("%d",&n);
    while(n>9) {
        int s=0;
        while(n!=0) {
            s=s+n%10;
            n/=10;
        }
        n=s;
    }
    printf("Generic code:%d\n",n);
    if(n==1) puts("Magic number");
    else puts("Not a magic number");
}
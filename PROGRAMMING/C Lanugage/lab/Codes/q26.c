#include<stdio.h>

void main () {
    int n,sum=0;
    printf("Input:");scanf("%d",&n);
    while(n!=0) {
        sum=sum+n%10;
        n/=10;
    }
    printf("Output:%d\n",sum);
}
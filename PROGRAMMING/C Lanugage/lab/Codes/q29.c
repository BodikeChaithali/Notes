#include<stdio.h>

void main () {
    int n,sum=0,c=1;
    printf("Enter the value of n: ");scanf("%d",&n);
    for(int i=1;c<=n;i++) {
        if(i%2==0) {sum=sum+i;c++;}
    }
    printf("Sum of first %d even numbers:%d\n",n,sum);
}
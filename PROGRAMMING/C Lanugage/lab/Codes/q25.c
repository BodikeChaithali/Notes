#include<stdio.h>

void main () {
    int n,sum=0,m;
    printf("Enter a number:");scanf("%d",&n);m=n;
    while(m!=0) {
        sum=sum+m%10;
        m/=10;
    }
    if(n%sum==0) printf("%d is a Harshad number\n",n);
    else printf("%d is not a Harshad number\n",n);
}
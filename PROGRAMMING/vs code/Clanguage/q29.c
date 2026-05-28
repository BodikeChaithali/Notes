#include<stdio.h>

void main () {
    int a,b,i=1,gcd;
    printf("enter a and b values:");scanf("%d%d",&a,&b);
    while(i<=a&&i<=b) {
        if(a%i==0&&b%i==0) gcd=i;
        i++;
    }
    printf("Gcd of a and b is %d\n",gcd);
}
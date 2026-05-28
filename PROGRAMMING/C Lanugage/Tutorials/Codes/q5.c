#include<stdio.h>

int digit_length(int a) {
    int length = 0;
    if(a==0) return 1;
    if(a<0) a=-a;
    while (a!=0)
    {
        length++;
        a=a/10;
    }
    return length;
    
}

void main() {
    int n;
    printf("Enter any number:");scanf("%d",&n);
    printf("The number of digits in %d is %d\n",n,digit_length(n));
}
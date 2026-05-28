#include<stdio.h>
//reversing the  no.
void main () {
    int n,r,a,reverse=0;
    printf("Enter an number:");scanf("%d",&n);a=n;
    while(n!=0) {
        r=n%10;
        reverse=reverse*10+r;
        n/=10;
    }
    printf("Reverse of %d is %d\n",a,reverse);
    if(reverse==a) puts("Palindrome");
    else puts("Not an palindrome");
}
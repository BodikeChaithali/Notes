#include<stdio.h>

void main () {
    int n,m,reverse=0;
    printf("Enter any number:");scanf("%d",&n);m=n;
    while (m!=0) 
    {
        reverse=reverse*10+m%10;
        m/=10;
    }
    printf("Reverse of %d is %d\n",n,reverse);
    if(reverse==n) {
        printf("Palindrome\n");
    }
    else{
        printf("Not a Palindrome\n");
    }
    
}
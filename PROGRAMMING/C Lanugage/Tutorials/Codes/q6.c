#include<stdio.h>

int palindrome(int a) {
    int b=a,reverse=0;
    if(a<0) return 0;
    while(a!=0) {
        reverse=reverse*10+(a%10);
        a=a/10;
    }
    if(reverse==b) return 1;
    else return 0;
}
void main () {
    int n;
    printf("Enter any number:");scanf("%d",&n);
    printf("IS palindrome? %d\n",palindrome(n));
}
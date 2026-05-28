#include<stdio.h>

void main () {
    int n;start:
    printf("Enter any number:");scanf("%d",&n);
    if(n<=0) {puts("Entered number is -ve or 0 please enter positive number");goto start;}
    else if(n==1) goto end;
    for(int i=2;i<n;i++) {
        if(n%i==0) goto end;
    }
    printf("%d is an prime number\n",n); return;
    end:printf("%d is not an prime number\n",n);
    /* 
    if()
    */
}
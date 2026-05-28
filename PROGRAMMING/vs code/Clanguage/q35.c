#include<stdio.h>

void main () {
    int n;
    printf("n=");scanf("%d",&n);
    printf("Last number is %d\n",n%10);
    while(n>9||n<-9) n=n/10;
    printf("First digit is %d\n",n);

}
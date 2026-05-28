#include<stdio.h>
//finding no.of digits in given no.
void main () {

    long n;int c=0;long a;
    printf("n=");scanf("%ld",&n);a=n;
    do {
        c++;
        n=n/10;
    }while(n!=0);
    printf("no.of digits in %ld = %d\n",a,c);
}
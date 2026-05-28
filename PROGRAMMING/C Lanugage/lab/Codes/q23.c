#include<stdio.h>

void main () {
    int n,binary=0,p=1;
    printf("Enter a decimal number: ");scanf("%d",& n);
    if(n==0) binary=0;
    for(int i=1;n>0;n/=2) {
        int r=n%2;
        binary=binary+r*p;
        p=p*10;
    }
    printf("Binary equivalent: %d\n",binary);
    
}
#include<stdio.h>

void main () {
    int n,l,s;
    printf("Enter a number: ");scanf("%d",&n);
    l=s=n%10;
    n/=10;
    for(int i=0;n!=0;n/=10) {
        if((n%10)>l) l=n%10;
        if((n%10)<s) s=n%10;
    }
    printf("Smallest digit:%d,Largest digit:%d\n",s,l);
}
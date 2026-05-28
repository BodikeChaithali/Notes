#include<stdio.h>

void main () {
    int n,r,max=-9,min=9;
    printf("n=");scanf("%d",&n);
    do {
        r=n%10;
        if(min>r)min=r;
        if(max<r)max=r;
        n=n/10;
    }while(n!=0);
    printf("min=%d,max=%d\n",min,max);
}
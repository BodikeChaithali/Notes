#include<stdio.h>

void main() {
    int n,e=0,o=0,r,z=0,a;
    printf("n=");scanf("%d",&n);a=n;
    do {
        r=n%10;
        if(r==0)z++;
        else if(r%2==0) e++;
        else o++;
        n/=10;
    }while(n!=0);
    printf("no.of even,odd and zeros in %d are %d,%d and %d\n",a,e,o,z);
}
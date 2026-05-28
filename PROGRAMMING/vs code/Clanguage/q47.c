#include<stdio.h>

void main () {
    int n,m,s=0;
    printf("Enter any number:");scanf("%d",&n);m=n;
    while(m!=0) {
        int f,r=m%10;
        for(f=1;r>1;r--) {
            f=f*r;
        }
        printf("%d!+",m%10);
        s=s+f;
        m/=10;
    }
    printf("\b=%d\n",s);
    if(n==s) puts("Strong number");
    else puts("Not a Strong number");
}
#include<stdio.h>

void main () {
    int n,f1=0,f2=1,f3;
    printf("Enter any number:");scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        if(i<n) printf("%d,",f1);
        else printf("%d\n",f1);
        f3=f1+f2;
        f1=f2;f2=f3;
    }
}
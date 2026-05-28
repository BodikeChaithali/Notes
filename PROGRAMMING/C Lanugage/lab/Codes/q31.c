#include<stdio.h>

void main () {
    int n,m,sum=0;
    printf("Enter a number:");scanf("%d",&n);m=n;
    while(m!=0){
        int p=1;
        for(int j=m%10;j>0;j--) {
            p=p*j;
        }
        sum=sum+p;
        m=m/10;
    }
    printf("Sum=%d\n",sum);
    if(n==sum) printf("strong number.\n");
    else printf("Not an strong number.\n");
}
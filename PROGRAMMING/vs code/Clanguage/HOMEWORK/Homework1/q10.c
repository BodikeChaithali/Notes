#include<stdio.h>

int main () {
    int n,sum=0;
    printf("Enter any number:");scanf("%d",&n);
    for(int i=2;i<n;i++) {
        for(int j=2;j<i;j++) {
            if(i%j==0) goto start;
        }
        if(sum+i<=n) sum=sum+i;
        start:
    }
    printf("Sum of prime numbers=%d\n",sum);
    if(sum==n) puts("True");
    else puts("False");
    return 0;
}
#include<stdio.h>

void main () {
    int n,a;
    printf("Enter a number:");scanf("%d",&n);a=n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if(a==0) return;
            printf("%d ",a--);
        }
        printf("\n");
    }
}
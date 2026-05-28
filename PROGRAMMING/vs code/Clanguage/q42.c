#include<stdio.h>

void main () {
    int n;
    printf("Enter any number:");scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if((i+j)%2==0) printf("$ ");
            else printf("* ");
        }
        printf("\n");
    }
}
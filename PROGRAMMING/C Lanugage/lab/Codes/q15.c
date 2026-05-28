#include<stdio.h>

void main () {
    int n;
    printf("Enter no.of rows:");scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int f1=0,f2=1,f3;
        for(int j=1;j<=i;j++) {
            printf("%d ",f1);
            f3=f1+f2;f1=f2;f2=f3;
        }
        printf("\n");
    }
}
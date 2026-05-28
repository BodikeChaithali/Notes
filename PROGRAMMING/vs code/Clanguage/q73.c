#include<stdio.h>

void main () {
    int n,a1=1,a2=2;
    printf("Enter the no.of row do you want: ");scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if(i%2!=0) {
                printf("%d ",a1);
                a1=a1+2;
            }
            else {
                printf("%d ",a2);
                a2=a2+2;
            } 
        }         

        printf("\n");
    }
}
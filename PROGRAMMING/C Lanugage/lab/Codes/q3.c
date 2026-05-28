#include<stdio.h>

void main () {
    int n;
    printf("Enter any number:");scanf("%d",&n);
    for(int i=n;i>=1;i--) {
        int j=i;
        while(j>=1) {
            printf("%d ",j);
            j--;
        }
        printf("\n");
    }
}
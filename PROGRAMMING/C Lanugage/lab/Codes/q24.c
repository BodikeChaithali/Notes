#include<stdio.h>

void main () {
    int n;
    printf("Enter a number: ");scanf("%d",&n);
    printf("Factors are:\n");
    for(int f=2;f<n;f++) {
        if(n%f==0) {
            for(int j=2;j<f;j++) {
                if(f%j==0) goto start;
            }
            printf("%d ",f);
        }
        start:
    }
    printf("\n");
}
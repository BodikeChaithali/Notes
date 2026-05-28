#include<stdio.h>

void main () {
    int nr,nc;
    printf("Enter no.of rows and columns:");scanf("%d %d",&nr,&nc);
    for(int i=1;i<=nr;i++) {
        for(int j=1;j<=nc;j++) {
            if(j%2!=0) printf("%c",64+j);
            else printf("%c",96+j);
        }
        printf("\n");
    }
}
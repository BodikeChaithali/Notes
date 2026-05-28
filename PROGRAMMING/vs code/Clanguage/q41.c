#include<stdio.h>

void main () {
    int nr,nc;
    printf("Enter no.of rows and columns:");scanf("%d %d",&nr,&nc);
    for(int i=1;i<=nr;i++) {
        for(int j=1;j<=nc;j++) {
            if(j==i) printf("1 ");
            else if(j<i) printf("2 ");
            else printf("0 ");
        }
        printf("\n");
    }
}
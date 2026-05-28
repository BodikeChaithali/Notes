#include<stdio.h>

void main () {
    int nr,nc;
    printf("Enter no.of rows and columns:");scanf("%d %d",&nr,&nc);
    for(int i=1;i<=nr;i++) {
        for(int j=1;j<=nc;j++) {
            if(i%2!=0) 
                printf("%c",96+j);
            else printf("%c",97+nc-j);
        }
            printf("\n");
        }
}
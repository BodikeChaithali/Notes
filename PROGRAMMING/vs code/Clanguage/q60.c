#include<stdio.h>

void main () {
    int nr,nc;
    printf("Enter number of rows and columns:");scanf("%d %d",&nr,&nc);
    int a[nr][nc];
    for(int i=0;i<nr;i++) {
        for(int j=0;j<nc;j++) {
            printf("arr[%d][%d]:",i,j);scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<nr;i++) {
        for(int j=0;j<nc;j++) {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    puts("Transpose of Given matrix!");
    for(int i=0;i<nc;i++) {
        for(int j=0;j<nr;j++) {
            printf("%4d",a[j][i]);
        }
        printf("\n");
    }
}
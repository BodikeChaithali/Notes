#include<stdio.h>

void main () {
    int nr,nc;
    printf("Enter number of rows and columns:");scanf("%d %d",&nr,&nc);
    int a[nr][nc],z,e,o;
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
    printf("     \tEven\tOdd\tZero\n");
    printf("-------------------------------\n");
    for(int i=0;i<nr;i++) {
        z=o=e=0;
        for(int j=0;j<nc;j++) {
            if(a[i][j]==0) z++;
            else if(a[i][j]%2==0) e++;
            else o++;
        }
        printf("%d-row\t%2d\t%2d\t%2d\n",i+1,e,o,z);
    }
}
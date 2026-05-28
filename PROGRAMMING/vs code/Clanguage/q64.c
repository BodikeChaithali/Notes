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
    for(int i=0;i<nc;i++) {
        z=o=e=0;
        for(int j=0;j<nr;j++) {
            if(a[j][i]==0) z++;
            else if(a[j][i]%2==0) e++;
            else o++;
        }
        printf("%d-col\t%2d\t%2d\t%2d\n",i+1,e,o,z);
    }
}
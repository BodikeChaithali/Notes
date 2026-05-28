#include<stdio.h>

int main () {
    // 1st matix cols and 2nd matrix rows should be same.
    int nr1,nc1,nr2,nc2;
    printf("Enter the no.of the rows and the columns of the 1st matrix:");
    scanf("%d%d",&nr1,&nc1);
    int arr1[nr1][nc1];
    printf("Enter the 1st matrix elements:\n");
    for(int i=0;i<nr1;i++) {
        for(int j=0;j<nc1;j++) {
            printf("Element-[%d][%d]:",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter the no.of the rows and the columns of the 1st matrix:");
    scanf("%d%d",&nr2,&nc2);
    int arr2[nr2][nc2];
    printf("Enter the 2nd matrix elements:\n");
    for(int i=0;i<nr2;i++) {
        for(int j=0;j<nc2;j++) {
            printf("Element-[%d][%d]:",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    if(nc1!=nr2) main();
    for(int i=0;i<nr1;i++) {
        for(int j=0;j<nc2;j++) {
            int long s=0;
            for(int k=0;k<nc1;k++) {
                s=s+arr1[i][k]*arr2[k][j];
            }
            printf("%-4ld",s);
        }
        printf("\n");
    }
    return 0;
}
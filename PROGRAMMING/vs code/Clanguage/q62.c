#include<stdio.h>

void main (){
    int nr,nc;start:
    printf("Enter no.of rows and columns:");scanf("%d %d",&nr,&nc);
    if(nr!=nc) {printf("For calculation of trace we need same no.of rows and columns.\n");goto start;}
    int arr[nr][nc],sum=0;
    for(int i=0;i<nr;i++) {
        for(int j=0;j<nc;j++) {
            printf("arr[%d][%d]:",i,j);scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<nr;i++) {
        for(int j=0;j<nc;j++) {
            printf("%3d",arr[i][j]);
            if((i+j)==(nr-1)) sum=sum+arr[i][j];
        }
        printf("\n");
    }
    printf("Trace of right diagonal element=%d\n",sum);
}
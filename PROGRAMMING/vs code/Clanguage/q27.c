#include<stdio.h>

void main () {
    int n,i=1,sum=0;
    printf("n=");scanf("%d",&n);
    while(i<=n){
        sum=sum+i;
        i++;
    }
    printf("sum=%d and mean=%.2f \n",sum,(float)sum/n);
}
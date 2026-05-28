#include<stdio.h>

int main () {
    //using %(module) operator
    int start,end,sum=0;
    printf("Enter starting number and ending number:");
    scanf("%d%d",&start,&end);
    for(int i=start;i<=end;i++) {
        if(i%17==0) sum=sum+i;
    }
    printf("Sum=%d\n",sum);sum=0;
    //without using % operator
    for(int i=102;i<=999;i=i+17) sum=sum+i;
    printf("Sum=%d\n",sum);
    return 0;
}
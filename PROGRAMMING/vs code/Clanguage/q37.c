#include<stdio.h>
#include<math.h>

void main () {
    int n,m,sum=0;
    printf("Enter a number:");scanf("%d",&n);m=n;
    for(int c=0;m!=0;c++) {
        m=m/10;
        sum=sum+pow(m%10,c);
    }
    printf("sum=%d\n",sum);
    if(n==sum) puts("Armstrong");
    else puts("Not An Armstrong");
}
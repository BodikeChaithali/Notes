#include<stdio.h>
#include<math.h>
//gcc q30.c -o q30 -lm    ./q30
void main () {
    int n,m,c=0,sum=0;
    printf("Enter a number:");scanf("%d",&n);m=n;
    while(m!=0) {
        c++;
        m/=10;
    }
    m=n;
    while(m!=0) {
        sum=sum+pow(m%10,c);
        m=m/10;
    }
    printf("Sum=%d\n",sum);
    if(n==sum) printf("Armstrong number.\n");
    else printf("Not an Armstrong number.\n");
}
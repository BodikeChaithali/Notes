#include<stdio.h>

void main () {
    int n;float fine;
    printf("No.of days the member is overdue-");scanf("%d",&n);
    if(n<=5) fine=n*0.50;
    else if(n<=10&&n>=6) fine=5*0.50+(n-5)*1.00;
    else if(n>10&&n<=30) fine=5*0.50+5*1.00+(n-10)*5.00;
    else {
        printf("your's membership is revoked.\n"); 
        return ;
    }
    printf("The penalty charged is %.2f Rs.\n",fine);
}
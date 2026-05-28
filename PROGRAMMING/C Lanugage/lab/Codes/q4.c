#include<stdio.h>

void main () {
    int t; float p,r,si;
    printf("Enter time , principle and rate of interest:");
    scanf("%d %f %f",&t,&p,&r);
    si=t*p*r/100;
    printf("Simple interest=%.2f\n",si);
    //swaping numbers
    int a,b;
    printf("Enter the values:");scanf("%d %d",&a,&b);
    printf("a & b before swap = %d & %d\n",a,b);
    a=a^b;b=a^b;a=a^b;//int c=b;b=a;a=c;
    printf("a & b after swap = %d & %d\n",a,b);
}
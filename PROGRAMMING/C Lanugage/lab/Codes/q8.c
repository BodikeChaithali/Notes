#include<stdio.h>

void main () {
    int num1,num2;
    printf("Enter two three digit numbers:");scanf("%3d %3d",&num1,&num2);
    int h1=num1/100,m1=(num1/10)%10,u1=num1%10;
    int h2=num2/100,m2=(num2/10)%10,u2=num2%10;
    printf("Numbers after swaping middle digits:\n");
    printf("%3d and %3d\n",h1*100+m2*10+u1,h2*100+m1*10+u2);
}
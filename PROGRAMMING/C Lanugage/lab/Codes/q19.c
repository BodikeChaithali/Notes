#include<stdio.h>

void main () {
    int n1,n2,gcd,lcm;
    printf("Enter two numbers:");scanf("%d %d",&n1,&n2);
    for(int i=1;n1>n2?i<n2:i<n1;i++) {
        if(n1%i==0&&n2%i==0)  {
            gcd=i;
        }
    }
    for(int i=n1>n2?n1:n2;1;i++) {
        if(i%n1==0&&i%n2==0)  {
            lcm=i;break;
        }
    }
    printf("GCD:%d\n",gcd);
    printf("LCM:%d\n",lcm);
}
#include<stdio.h>

void main () {
    int a,b,max;//lcm=a*b/gcd
    printf("Enter a and b values:");scanf("%d%d",&a,&b);
    max=a>b?a:b;
    while(1) {
        if(max%a==0&&max%b==0) {
            printf("LCM=%d\n",max);break;
        }
        else
        max++;
    }
}
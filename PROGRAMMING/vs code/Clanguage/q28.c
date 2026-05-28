#include<stdio.h>

void main () {
    int p,b;long int power=1;
    printf("power and base:");scanf("%d %d",&p,&b);
    int a=p;
    if(p<0) p=-p;
    while(p>=1) {
        power=power*b;
        p--;
    }
    if(a<0) printf("%d^%d=%.2f\n",b,a,1.0/power);
    else
    printf("%d^%d=%ld\n",b,a,power);

}
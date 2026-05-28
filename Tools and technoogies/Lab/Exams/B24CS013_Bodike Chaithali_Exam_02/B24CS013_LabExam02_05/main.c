#include<stdio.h>
#include"math_utils.h"

int main() {
int n;
printf("Enter any number: ");
scanf("%d",&n);
fib(n);
printf("\n%d!=%d\n",n,fact(n));
return 0;
}

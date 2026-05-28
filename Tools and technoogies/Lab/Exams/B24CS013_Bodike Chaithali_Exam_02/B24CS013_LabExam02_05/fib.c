#include"math_utils.h"

int fib(int n) {
int f1=0,f2=1,f3=f1+f2,i=0;
while(i<n) {
printf("%d ",f1);
f1=f2;
f2=f3;
f3=f1+f2;
i++;
}
return 0;
}

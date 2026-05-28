#include"math_utils.h"

int fact(int n) {
int m=1;
while(n!=0) {
m=m*n;
n--;
}
return m;
}

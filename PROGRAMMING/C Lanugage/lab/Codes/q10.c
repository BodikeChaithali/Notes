#include <stdio.h>

void main() {
    /*
    int n, first = 0, second = 1, next;
    printf("Enter a number: ");scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d,", next);
    }
    printf("\n");
    */
   int n,f1=0,f2=1,f3;
   printf("Enter any number:");scanf("%d",&n);
    printf("Fibonacci Series: ");
   for(int i=1;i<=n;i++) {
    if(i<n)printf("%d,",f1);
    else printf("%d\n",f1);
    f3=f1+f2;
    f1=f2;
    f2=f3;
   }
}

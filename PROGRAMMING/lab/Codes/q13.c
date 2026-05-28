#include<stdio.h>
#include<math.h>

void main () {
    int a,b,c;
    printf("Enter the co-efficients of an quadratic eqation:");
    scanf("%d %d %d",&a,&b,&c);
    float D=b*b-4*a*c;
    if(D>0) {
        puts("The equation has distinct real roots.\n Roots are:");
        printf("%.3f,%.3f\n",(float)(-b+sqrt(D))/2*a,(float)(-b+sqrt(D))/2*a);
    }
    else if(D=0) {
        puts("The equation has exactly one real root(a repeated root).\n Roots are:");
        printf("%.3f,%.3f\n",(float)(-b)/2*a,(float)(-b)/2*a);
    }
    else {
        puts("The equation has no real roots,but two complex roots,\n Roots are:");
        printf("%.2f-i%.3f,%.2f-i%.3f",(float)(-b)/2*a,(float)(sqrt(-D))/2*a,(float)(-b)/2*a,(float)(sqrt(-D))/2*a);
    }
}
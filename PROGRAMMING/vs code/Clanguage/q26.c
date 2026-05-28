#include<stdio.h>

void main () {
    int a=10;
    printf("a=%d\n",a++);//a=a++ 1st a so a=a is printed then incremented to 11 finally a=11
    printf("a=%d\n",++a);//a=++a 1st a is 11 then incremented to 12 then printed
    //if in place of a replaced with 10[printf("a=%d",10++)] then it shows error because it is constant(never changed)
    /* int a=4,b=2,c;
    c= (a++ + ++b)++;
    printf("a=%d,b=%d,c=%d\n",a,b,c);
    R:c=(4++ + ++2)++=(4 + 3)++=7++(constant)-->Error*/
    a=2;
    printf("%d %d %d %d %d\n",++a,a++,a--,a++,++a);
    printf("%d %d %d %d %d\n", ++a,a*10,a=10,a--,++a);
    //in printf execution order is right to left
    //5   4    3    4    3
    //++a a++ a-- a++ ++a
    //5   3    4   3   3
}
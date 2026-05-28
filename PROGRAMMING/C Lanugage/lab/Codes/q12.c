#include<stdio.h>

void main () {
    int a,b,c,d,nearest1,nearest2;
    printf("Enter any four numbers:");scanf("%d %d %d %d",&a,&b,&c,&d);
    int e=d-a,f=d-b,g=d-c;
    if(e<0)  e=-e;
    if(f<0)  f=-f;
    if(g<0)  g=-g;
    printf("%d-%d=%d\n",d,a,e);
    printf("%d-%d=%d\n",d,b,f);
    printf("%d-%d=%d\n",d,c,g);
    if(d-a>=d-b && d-a>=d-c) {
            nearest1=b;nearest2=c;
    }
    else if(d-a<=d-b && d-a<=d-c) {
        nearest1=a;
        if(d-b>=d-c) nearest2=c;
        else nearest2=b;
    }
    else if(d-a<=d-b && d-a>=d-c) {
        nearest1=a;nearest2=c;
    }
    printf("two nearest numbers are %d and %d\n",nearest1,nearest2);
}
#include<stdio.h>

int main () {
    int c=0,a,b;
    printf("Enter the start and end value:");scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++) {
        for(int j=i;j<=b;j++) 
        {
            if(j%i==0) c++;
        }
    }
    printf("%d\n",c);
    return 0;
}
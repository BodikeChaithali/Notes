#include<stdio.h>

void main () {
    int n,m,c=0;
    printf("Enter any number:"); scanf("%d",&n);m=n;
    printf("Palindrome number are: ");
    for(int i=1;i<=m;i++) {
        int rev=0;
        for(int j=i;j!=0;j/=10) {
            rev=rev*10+(j%10);
        }
        if(i==rev) {
            printf("%d ",i);
            c++;
        }
    }
    printf("\nNumber of palindomes=%d\n",c);
}
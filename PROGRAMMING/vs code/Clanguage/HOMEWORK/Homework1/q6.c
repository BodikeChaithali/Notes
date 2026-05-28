#include<stdio.h>

int main () {
    int n,c=0;
    printf("No.of rows do you want to print:");scanf("%d",&n);
    for(int i=2;c<n*n;i++) {
        for(int j=2;j<i;j++) 
        {
            if(i%j==0) goto start;
        }   
        if(c%n==0) printf("\n");
        printf("%-4d",i);
        c++;
        start:
    }
    printf("\n");
    return 0;
}
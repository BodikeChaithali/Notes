#include<stdio.h>

int main () {
    int n,rev=0;
    printf("Enter the n digit number: ");scanf("%d",&n);
    if(n%10==0) printf("Error: Ending with zero.\n");
    else {
        while (n!=0)
        {
            rev=rev*10+(n%10);
            n/=10;
        }
        printf("Revered number: %d\n",rev);
        
    }
    return 0;
}
#include<stdio.h>

int main () {
    int n=5;
    for(int i=1;i<=n;i++) {
        for(int j=1,c=i;j<2*n-1;j++) {
            if(j>i && j<=2*n-2*i) {
                printf(" ");
            }
            else printf("%d",c);
            }
            printf("\n");
        }
    return 0;
}

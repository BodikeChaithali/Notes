#include<stdio.h>

int main () {
    int n;
    printf("n=");scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) printf(" ");
        for(int k=0;k<=i;k++) printf("#");
        for(int j=0;j<4*(n-i-1);j++) printf(" ");
        for(int k=0;k<=i;k++) printf("#");
        printf("\n");
    }
    for(int i=0;i<n;i++) {
        
        for(int j=n-1;j>i;j--) printf(" ");
        for(int k=n-i;k>0;k--) printf("#");
        for(int j=0;j<4*i;j++) printf(" ");
        for(int k=n-i;k>0;k--) printf("#");
        printf("\n");
    }
    return 0;
}
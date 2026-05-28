#include<stdio.h>

int main () {
    int n,c=0;
    printf("n=");scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int f=0;
        for(int j=0;j*j<=i;j++) {
            for(int k=0;k*k<=i;k++) {
                if((j*j+k*k) == i) {
                f=1;
                break;
                }
            }
            if(f) break;
        }
        if(f)  c++;
    }
    printf("%d\n",c);
    return 0;
}
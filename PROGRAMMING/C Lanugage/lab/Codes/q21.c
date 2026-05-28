#include<stdio.h>

void main () {
    int n,tn;
    printf("Enter the number of terms ");scanf("%d",&n);
    for(int i=0;i<n;i++) {
        tn=i*(i+1)/2;
        if(i<n-1) printf("%d,",tn);
        else printf("%d\n",tn);
    }
}
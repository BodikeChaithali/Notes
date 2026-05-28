#include<stdio.h>

int fibseries(int n) {
    if(n==0)
    return 0;
    else if(n==1) 
    return 1;
    else
    return fibseries(n-1)+fibseries(n-2);
}
int main() {
    int n;
    printf("n=");
    scanf("%d",&n);
    printf("The fibbonacci series is :\n");
    for(int i=0;i<n;i++) {
        int result = fibseries(i);
        printf("%d  ",result);
    }
    printf("\n");
    return 0;
}
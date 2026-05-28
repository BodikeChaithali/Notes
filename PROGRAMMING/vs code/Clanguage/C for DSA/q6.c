#include<stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i=n;i>0;i--) {
        for(int j=1;j<=n;j++) printf("%d ",j);
    printf("\n");n--;
    }
    return 0;
}
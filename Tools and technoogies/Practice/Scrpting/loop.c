#include<stdio.h>

int main() {
    int n=5,c=0;
    for(int i = 1;i<=5;i++) {
        for(int j=1;j<=10;j++) {
            if(j<=i || j>10-i) {
                if(j<=5) 
                    printf("%d ",++c);
                else 
                    printf("%d ",c--);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    c=0;
    for(int i = 4;i>0;i--) {
        for(int j=1;j<=10;j++) {
            if(j<=i || j>10-i) 
            {
            if(j<=5) 
                    printf("%d ",++c);
                else 
                    printf("%d ",c--);
            }
            else  
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
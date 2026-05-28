#include<stdio.h> 

int main () {
    int arr[2][10];
    for(int i=0;i<2;i++) {
        for(int j=0;j<10;j++){
            printf("%d\t",(2+i)*(j+1));
        }
        printf("\n");
    }

    return 0;
}
#include<stdio.h>

int main () {
    int n;n:
    printf("Enter the amount:");scanf("%d",&n);
    int arr[8]={500,100,50,20,10,5,2,1};
    if(n<0) {puts("Enter positive amount:"); goto n;}
    printf("Total number of notes:\n");
    for(int i=0;i<8;i++) {
        if(n%arr[i]>=0) {
            printf("%d:%d\n",arr[i],n/arr[i]);
            n=n%arr[i];
        }
    }
    return 0;
}
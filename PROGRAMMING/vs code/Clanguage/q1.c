#include<stdio.h>
int countodd(int arr[],int n) {
    int count=0;
    for(int i=0;i<n;i++) {
        if(arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}
int main () {
    int n;
    printf("Enter n value ");
    scanf("%d",&n);int arr[n];
    for(int i=0;i<n;i++) {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    int result = countodd(arr,n);
    printf("no.of odd numbers=%d\n",result);
    return 0;
}
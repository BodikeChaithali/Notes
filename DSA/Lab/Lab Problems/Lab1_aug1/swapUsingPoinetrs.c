#include<stdio.h>

void swap(int *num1,int *num2) {
    int temp=*num1;
    *num1=*num2;
    *num2=temp;
}

int main() {
    int a,b;
    printf("Enter the numbers(only 2): ");
    scanf("%d %d",&a,&b);
    printf("Before Swap 1st number is %d and 2nd number is %d.\n",a,b);
    swap(&a,&b);
    printf("After Swap 1st number is %d and 2nd number is %d.\n",a,b);
    return 0;
}
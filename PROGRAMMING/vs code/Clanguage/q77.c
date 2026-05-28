#include<stdio.h>
#include<stdlib.h>

int main() {
    int n,a=1;
    printf("How many elements do you want to include in an operation? ");
    scanf("%d",&n);
    int *arr;
    arr=(int *)malloc(n*sizeof(int));
    printf("\t\t\tC B %% /\n\t\t\t");
    for(int i=1;i<=3;i++) {
        for(int j=0;j<3;j++) {
            printf("%d ",a++);
        }
        if(i==1) printf("X \n\t\t\t");
        else if(i==2) printf("- \n\t\t\t");
        else printf("+ \n");
    }
    printf("\t\t\tE 0 . =\n");
    printf("Enter numbers to be operated:");
    for(int i=0;i<n;i++) {
        scanf("%d",arr+i);
    }
    
}
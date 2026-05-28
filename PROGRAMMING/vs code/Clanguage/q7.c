#include<stdio.h> 

int main () {
    FILE *fptr;
    fptr=fopen("test.txt","r");
    int n;
        fscanf(fptr,"%d",&n);
        printf("number = %d\n",n);
        fscanf(fptr,"%d",&n);
        printf("number = %d\n",n);
        fscanf(fptr,"%d",&n);
        printf("number = %d\n",n);
        fscanf(fptr,"%d",&n);
        printf("number = %d\n",n);
        fscanf(fptr,"%d",&n);
        printf("number = %d\n",n);

    return 0;
}
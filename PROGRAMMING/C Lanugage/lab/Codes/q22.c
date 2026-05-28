#include<stdio.h>

void main () {
    int n,max,min,i;
    printf("Size of the list - ");scanf("%d",&n);
    printf("Input the list(Enter positive numbers) -\n");
    scanf("%d",&i);
    max=min=i;
    for(int j=1;j<n;j++) {
        scanf("%d",&i);
        if(i>max) max=i;
        if(i<min) min=i; 
    }
    printf("The Maximum is %d.The minimun is %d.\n",max,min);
}
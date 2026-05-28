#include<stdio.h>

void main () {
    int year;
    printf("Enter an year:");scanf("%d",&year);
    if(year%4==0 && year%100!=0 || year%400==0)
    puts("Leap year");
    else puts("Common year");
    
}
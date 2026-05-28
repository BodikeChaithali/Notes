#include<stdio.h>

void main () {
    int age;
    printf("Enter the age(1-100):");
    scanf("%d",&age);
    if(age<1 || age>100) puts("Invalid age");
    else if(age<=12) puts("Child");
    else if(age<=18) puts("Teenager");
    else if(age<=59) puts("Adult");
    else puts("Senior citizens");

}
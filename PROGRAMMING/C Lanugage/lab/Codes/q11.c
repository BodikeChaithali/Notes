#include<stdio.h>

void main () {
    int age;char gender;
    printf("Enter the age and gender:");scanf("%d %c",&age,&gender);
    if(age>=18 && age<=60) {
        if(gender=='m'||gender=='M') puts("Male");
        else puts("Female");
        puts("too big");
    }
    else puts("too small");
}
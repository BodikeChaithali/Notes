#include<stdio.h>

int main () {
    float subMarks;
    printf("Enter the marks of the student: ");scanf("%f",&subMarks);
    if(subMarks>=86 && subMarks<=100) puts("A+");
    else if (subMarks>=71 && subMarks<=85) puts("A-");
    else if(subMarks>=56 && subMarks<=70) puts("B+");
    else if(subMarks>=41 && subMarks<=55) puts("B-");
    else if(subMarks>=26 && subMarks<=40) puts("C");
    else if(subMarks<=25) puts("F");
    else puts("You entered wrong data");
    return 0;
}
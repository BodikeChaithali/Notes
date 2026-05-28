#include<stdio.h>
#include<string.h> 

struct student
{
    int roll;
    char name[100];
    float cgpa;
};

int main () {
    struct student s1;
    s1.roll=13;
    s1.cgpa=9.2;
    strcpy(s1.name,"Chaithali");
    printf("student name=%s\nstudent roll.no=%d\nstudent cgpa=%f\n",s1.name,s1.roll,s1.cgpa);

    return 0;
}
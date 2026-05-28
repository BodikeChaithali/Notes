#include<stdio.h>

struct student {
    char name[100];
    int rollno;
    float marks;
};

int main () {
    int n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    struct student s[n];
    for(int i=0;i<n;i++) {
        printf("Enter detalis for student %d:\n",i+1);
        printf("Name:");
        scanf("%s",s[i].name);
        printf("Roll Number:");
        scanf("%d",&s[i].rollno);
        printf("Marks:");
        scanf("%f",&s[i].marks);
    }
    printf("%-20s %-10s %-20s\n","Name","RollNumber","Marks");
    for(int i=0;i<n;i++) {
        printf("%-20s %-10d %-20.2f\n",s[i].name,s[i].rollno,s[i].marks);
    }

    return 0;
}

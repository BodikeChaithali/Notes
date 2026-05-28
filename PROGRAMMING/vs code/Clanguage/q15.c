#include<stdio.h>

struct student
{
    char Name[100];
    int RollNumber;
};

int main () {
    int n;
    printf("Enter number of students record to insert:");
    scanf("%d",&n);
    struct student s[n];
    for(int i=0;i<n;i++) {
        printf("Enter name for student %d:",i+1);
        scanf("%s", s[i].Name);
        printf("Enter roll number for student %d:",i+1);
        scanf("%d",&s[i].RollNumber);
    }
    printf("sorted list of students based on roll number:\n");
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++){
            if(s[j].RollNumber>s[j+1].RollNumber){
            struct student temp =s[j];
            s[j]=s[j+1];
            s[j+1]=s[j];
            }
        }
    }
    for(int i=0;i<n;i++) {
        printf("Name:%s,Roll Number:%d\n",s[i].Name,s[i].RollNumber);
    }

    return 0;
}

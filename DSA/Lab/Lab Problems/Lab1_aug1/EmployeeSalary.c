#include<stdio.h>
#include<stdlib.h>

struct employeeDetails {
    int ID;
    char name[10];
    char department[30];
    float salary;
};

int main() {
    int n;
    printf("Enter the numbwe of employees: ");
    scanf("%d",&n);
    struct employeeDetails *e;
    e=(struct employeeDetails *)malloc(sizeof(struct employeeDetails)*n);
    printf("Enter the information of %d employees:\n",n);
    float salary=0;
    for(int i=0;i<n;i++) {
        printf("ID: ");
        scanf("%d",&e[i].ID);
        printf("Name: ");
        scanf(" %[^\n]",e[i].name);
        printf("Department: ");
        scanf(" %[^\n]",e[i].department);
        printf("Salary: ");
        scanf("%f",&e[i].salary);
        salary+=e[i].salary;
    } 
    float avg=salary/(float)n;
    printf("Average Salary: %.2f\n",avg);
    printf("Employees Who's salary is greater than avg salary with there name:\n");
    for(int i=0;i<n;i++) {
        if(e[i].salary>avg) printf("Name: %s => Salary: %.2f\n",e[i].name,e[i].salary);
    }
    free(e);
    return 0;
}
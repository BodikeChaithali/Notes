#include<stdio.h>
#include<stdlib.h>

struct employee {
	int ID;
	char Name[20];
	char Dept[20];
	float salary;
};

int main () {
	int n;
	float sum=0;
	printf("Enter no.of the employees:");
	scanf("%d",&n);
	struct employee *e;
	e=(struct employee*)malloc(n*sizeof(struct employee));
	printf("Input for %d employees:\n",n);
	for(int i=0;i<n;i++) {
		printf("Input %d employee details:\n",i+1);
		printf("ID:");scanf("%d",&e[i].ID);
		printf("Name:");scanf(" %[^\n]",e[i].Name);
		printf("Department:");scanf(" %[^\n]",e[i].Dept);
		printf("Salary:");scanf("%f",&e[i].salary);
		sum=sum+e[i].salary;
	}
	float avg=sum/n;
	printf("Average salary is %.2f\n",avg);
	printf("Employees earning salary above average are:\n");
	for(int i=0;i<n;i++) {
		if(e[i].salary>avg) printf("salary of %s is %.2f\n",e[i].Name,e[i].salary);
	}
	free(e);
	return 0;
}

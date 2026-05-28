#include<stdio.h>
#include<stdlib.h>

struct student {
        char Name[20];
        float marks[3];
        float total;
};

int main () {
        int n;
        printf("Enter no.of the students:");
        scanf("%d",&n);
        struct student *s;
        s=(struct student*)malloc(n*sizeof(struct student));
        printf("Input for %d students:\n",n);
        for(int i=0;i<n;i++) {
                printf("Name:");scanf(" %[^\n]",s[i].Name);
                printf("Marks for student %d:\n",i+1);
		s[i].total=0;
		for(int j=0;j<3;j++) {
			printf("Enter marks of sub %d:",j+1);
			scanf(" %f",&s[i].marks[j]);
			s[i].total+=s[i].marks[j];
		}
        }
        printf("Total and average for each student:\n");
	printf("%-20s %-10s %-10s\n","Name","Total","Average");
	puts("----------------------------------------------------------");
        for(int i=0;i<n;i++) {
                printf("%-20s %-10.2f %-10.2f\n",s[i].Name,s[i].total,(s[i].total)/3);
        }
        free(s);
        return 0;
}


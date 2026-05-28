#include<stdio.h>

void main () {
    struct vechile {
        char company[30],model[30],registration[30];
    }v,*p;
    p=&v;
    printf("Enter the company name:");gets(v.company);
    printf("Enter the model name:");gets(v.model);
    printf("Enter the registration number:");gets(v.registration);
    printf("%s %s registraion no %s\n",v.company,v.model,v.registration);
    printf("Enter the company name:");gets(p->company);
    printf("Enter the model name:");gets(p->model);
    printf("Enter the registration number:");gets(p->registration);
    printf("%s %s registraion no %s\n",p->company,p->model,p->registration);
}
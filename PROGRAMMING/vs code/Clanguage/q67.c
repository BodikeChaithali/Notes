#include<stdio.h>

void main () {
    //flushall();
    struct student {
        int id,sub[6];
        char name[30];
    }s;
    int i,tot=0,p=1;
    float avg;
    printf("Enter student id:");scanf("%d",&s.id);
    printf("Enter student name:");scanf("%s",s.name);
    printf("Enter subject marks:\n");
    for(int i=0;i<6;i++) {
        scanf("%d",&s.sub[i]);tot+=s.sub[i];
        if(s.sub[i]<35) p=0;
    }avg=tot/6.0;
    printf("%s id=%d,total=%d,avg=%.2f and got %s\n",s.name,s.id,tot,avg,p==1?"Passed":"Failed");
}
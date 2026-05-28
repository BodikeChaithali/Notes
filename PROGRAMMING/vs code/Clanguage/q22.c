#include<stdio.h>
#include<string.h>

void main () {
    char user[20],pass[20],cap[20];
    printf("Enter user name:");scanf("%s",user);
    if(strcmp(user,"Chaithali02")==0) {
        printf("Enter user password:");scanf("%s",pass);
        if(strcmp(pass,"chaithu@54321")==0) {
            printf("Enter user captcha code:");scanf("%s",cap);
            if(strcmp(cap,"HYD")==0) puts("Welcome to IRCTC");
            else puts("Invalid Captcha");
        }
        else puts("Invalid password");
    }
    else puts("Invalid user name");
}
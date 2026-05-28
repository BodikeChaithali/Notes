#include<stdio.h>
//Atm pin validation
void main () {
    int pin,count=0;
    start:
    printf("Enter the pin of your card:");
    scanf(" %4d",&pin);
    if(pin==6818) {
        printf("Welcome to your account\n");
    }
    else{
        count++;
        if(count==3){
            printf("Your card is BLOCKED try after 24hours\n");}
        else {
            printf("INVALID PIN\n");goto start;
        }
    }
}
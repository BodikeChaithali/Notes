#include<stdio.h>

void main () {
    int customer_id;char name[100];int units;float amount;
    printf("Customer IDNO :");scanf("%d",&customer_id);
    printf("Customer Name :");scanf("%s",name);
    printf("units Consumed :");scanf("%d",&units);
    if(units<=199) amount=units*1.20;
    else if(units>=200&&units<400) amount=units*1.50;
    else if(units>=400&&units<600) amount=units*1.80;
    else amount=units*2.00;
    if(amount<100) amount=100;
    else amount=amount;
    printf("Amount Charges : %.2f\n",amount);
    if(amount>400) {
        printf("Surcharge Amount:%.2f\n",0.15*amount);
        printf("Net Amount paid by the Customer :%.2f\n",amount+amount*0.15);
    }
}
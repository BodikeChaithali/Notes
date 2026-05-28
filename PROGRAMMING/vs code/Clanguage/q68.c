#include<stdio.h>
 
struct dmart {
    char item[20];
    float qty,price;
}d[100];
void main () {
    int i=0,c=1;
    float amt=0,tot=0,gst,net; char ch;
    while(1) {
        printf("Enter product name:");scanf(" %[^\n]",d[i].item);
        printf("Enter Quantity:");scanf("%f",&d[i].qty);
        printf("Enter each item price:");scanf("%f",&d[i].price);
        printf("Do you want to continue [y/n]:");scanf(" %c",&ch);
        if(ch=='y'|| ch=='Y') {i++;c++;}
        else break;
    }
    puts("********************************************************************************");
    puts("\t\t\t\tD-MART AVENU PVT LTD");
    puts("\t\t\t\tSANATH NAGAR");
    puts("********************************************************************************");
    printf("%-20s\t%8s\t%8s\t%8s\n","ITEMS","QTY","PRICE","AMOUNT");
    puts("********************************************************************************");
    for(int i=0;i<c;i++) {
        amt=d[i].qty*d[i].price;
        tot=tot+amt;
        printf("%-20s\t%8.2f\t%8.2f\t%8.2f\n",d[i].item,d[i].qty,d[i].price,amt);
    }
    puts("********************************************************************************");
    printf("\t\t\t\tTotal:%.2f\n",tot);
    gst=tot*0.05;
    net=tot+gst;
    printf("\t\t\t\tGST : %.2f\n",gst);
    printf("\t\t\t\tNet : %.2f\n",net);
    puts("***************************Thank you - Visit Again******************************");
}
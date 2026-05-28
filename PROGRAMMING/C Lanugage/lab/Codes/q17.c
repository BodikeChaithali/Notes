#include<stdio.h>

void main () {
    int n;
    puts("1.Calculate the area and perimeter of a rectangle");
    puts("2.Calculate the area and circumference of a circle");
    puts("3.Calculate the area triangle");
    puts("Enter any button on the keyboard to exit");
    start:
    printf("Enter your choice(1/2/3)-");scanf("%d",&n);
    switch(n) {
        case 1: {
            float l,w;
            printf("Enter the length of the rectangle-");scanf("%f",&l);
            printf("Enter the width of the rectangle-");scanf("%f",&w);
            printf("Area of the rectangle:%.2f square units\n",l*w);
            printf("Perimeter of the rectangle:%.2f square units\n",2*(l+w));
            goto start;
        }
        case 2: {
            float r;
            printf("Enter the radius of the circle-");scanf("%f",&r);
            printf("Area of the circle:%.2f square units\n",3.14*r*r);
            printf("Circumference of the cirle:%.2f units\n",2*3.14*r);
            goto start;
        }
        case 3: {
            float b,h,l;
            printf("Enter the base of the triangle-");scanf("%f",&b);
            printf("Enter the height of the triangle-");scanf("%f",&h);
            printf("Enter the another side of the triangle-");scanf("%f",&l);
            printf("Area of the triangle:%.2f square units\n",0.5*b*h);
            printf("Perimeter of the triangle:%.2f units\n",b+h+l);
            goto start;
        }
        default: return ;
    }
}
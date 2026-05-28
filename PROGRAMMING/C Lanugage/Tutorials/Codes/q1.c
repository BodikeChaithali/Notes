#include<stdio.h>

void main () {
    float a,b;
    printf("Enter a and b values:");scanf("%f %f",&a,&b);
    printf("sum=%f\t divide=%.2f\n",a+b,(float)a/b);
    char f[10],l[10],h[10];
    printf("Enter your first name:");scanf("%s",f);
    printf("Enter your last name:");scanf(" %s",l);
    printf("Enter your favorite hobby:");scanf(" %s",h);
    printf("Hello, %s %s! It's great that you enjoying %s.\n",f,l,h);
    char ch;
    printf("Enter a character:");scanf(" %c",&ch);
    printf("ASCII value of %c is %d.\n",ch,ch);
    char lc;
    printf("Enter a lowercase character:");scanf(" %c",&lc);
    if(lc>='a'&&lc<='z') {
        printf("uppercase of %c is %c\n",lc,lc-32);
    }
    else puts("Entered character is not an lowecase\n");
    char ch1,ch2;
    printf("Enter two characters:");scanf(" %c %c",&ch1,&ch2);
    printf("Difference in ASCII values of %c and %c is %d\n",ch1,ch2,ch1-ch2);
}
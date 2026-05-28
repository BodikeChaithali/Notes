#include<stdio.h>
#include<ctype.h>

void main () {
    char ch;
    printf("Enter any character:");
    scanf("%c",&ch);
    if( islower(ch)) ch=toupper(ch);
    else ch=tolower(ch);
    printf("char=%c\n",ch);

}
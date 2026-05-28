#include<stdio.h>
#include<ctype.h>

void main () {
    char ch;
    printf("Enter any character:");
    ch=getchar();
    if( islower(ch)) puts("lower case");
    else if( isupper(ch)) puts("Upper case");
    else if( isdigit(ch)) puts("Number");
    else if( isspace(ch)) puts("Space");
    else puts("Special char");
}
#include<stdio.h>

void main () {
    char ch;
    printf("Enter any character:");
    scanf("%c",&ch);//ASCII values
    if(ch>='a' && ch<='z') puts("lower case");//lower case from 97 to 122
    else if(ch>='A'&&ch<='Z') puts("Upper case");//upper case from 65 to 90
    else if(ch>='0'&&ch<='9') puts("Number");//number from 48 to 57
    else if(ch==' ') puts("Space");//space 32
    else puts("Special char");
}
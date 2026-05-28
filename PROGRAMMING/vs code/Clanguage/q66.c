#include<stdio.h>
#include<string.h>

void main () {
    char ch[100];
    printf("Enter any string:");scanf("%[^\n]",ch);
    char r=strrev(ch);
    if(strcmp(ch,r)==0) puts("Palindrome");
    else puts("Not a Palindrome");
}
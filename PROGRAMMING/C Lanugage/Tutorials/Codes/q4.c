#include<stdio.h>

void main () {
    char ch;
    printf("Enter any character:");scanf(" %c",&ch);
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') {
        puts("character is an Alphabet");
    }
    else if(ch>='0' && ch<='9') {
        puts("Character is an digit");
    } 
    else 
    puts("Neither Alphabet nor digit it is an special character");

}
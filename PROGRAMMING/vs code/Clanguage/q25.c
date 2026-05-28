#include<stdio.h>
#include<ctype.h>

void main () {
    char ch;
    printf("Enter a character:");scanf("%c",&ch);
    switch(ch=tolower(ch)) {
        case ('a'||'e'||'i'||'o'||'u'): //case 'a': case 'e': case 'i': case 'o': case'u':
        puts("Vowel");break;
        default: puts("Consonant");
    }
}
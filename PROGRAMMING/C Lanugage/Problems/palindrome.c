#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool is_palindrome(char *str) {
    for(int i=0;i<strlen(str)/2;i++) {
        if(str[i]!=str[strlen(str)-i-1]) {
            return false;
        }
    }
    return true;
}
void reverse_string(char *str, char *rev) {
    int len = strlen(str);
    for(int i=0;i<len;i++) {
        rev[i] = str[len-i-1];
    }
    rev[len] = '\0';
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    
    if(is_palindrome(str)) 
        printf("%s is a palindrome.\n", str);
    else 
        printf("%s is not a palindrome.\n", str);
    
    return 0;
}
#include<stdio.h>

extern char msg[];
extern void change_msg();

int main() {
    change_msg();
    printf("%s\n", msg);
    return 0;
}
#include<stdio.h>
#include<string.h>

void main () {
    char ch[100];
    printf("Enter any string: ");getc(ch);
    char a[256]={0};
    for(int i=0;ch[i]='\0';i++) {
        int n=ch[i];
        a[i]++;
    }
    for(int i=0;i<256;i++) {
        if(a[i]!=0) printf("%c found %d times\n",i,a[i]);
    }
}
#include<stdio.h>
#include<string.h>

int main () {
    char ch[100];
    // gets(ch);
    printf("Name=");fgets(ch,sizeof(ch),stdin);char ch1[100];strcpy(ch1,ch);
    // scanf(" %[^\n]",ch);
    if (ch[strlen(ch) - 1] == '\n') {
        ch[strlen(ch) - 1] = '\0';
    }
    printf("Your name is %s\n",ch);
    printf("Length=%ld\n",strlen(ch));
    // printf("Reverse=%s",strrev) strrev is not available in this compiler
    // Remove trailing newline if present
    if (ch[strlen(ch) - 1] == '\n') {
        ch[strlen(ch) - 1] = '\0';
    }
    int i, len = strlen(ch);
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = ch[i];
        ch[i] = ch[len - i - 1];
        ch[len - i - 1] = temp;
    }
    /* Remove newline if any
    ch[strcspn(ch, "\n")] =0;
    */
    printf("Reverse=%s\n",ch);
    if (ch1[strlen(ch1) - 1] == '\n') {
        ch1[strlen(ch1) - 1] = '\0';
    }
    for(int i=0;ch1[i]!='\0';i++) puts(ch1+i);
    return 0;
}
#include<stdio.h> 

int main () {
    FILE *fptr;
    fptr=fopen("index.txt","r");
    if(fptr == NULL) {
        printf("Error in opening file.\n");
        return 1;
    }
    char ch;
    int lines=0;
    while((ch =fgetc(fptr) )!=  EOF) {
        putchar(ch);
        if(ch == '\n') {
            lines++;
        }

    }
    fclose(fptr);
    printf("No.of lines = %d\n",lines);


    return 0;
}
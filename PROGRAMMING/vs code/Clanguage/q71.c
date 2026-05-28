#include<stdio.h>

void main() {
    FILE *fp;
    fp=fopen("q71.txt","a");
    if(fp==NULL) {puts("Error in opening file."); return;}
    char ch;
    puts("Enter the information");
    while((ch=getchar())!=EOF) fputc(ch,fp);//eof ctrl+d
    fclose(fp);
    puts("File 'q71.txt' created successfully.");
}
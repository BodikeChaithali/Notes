#include<stdio.h> 

void mergefiles(FILE *file1,FILE *file2,FILE *mergedfile) {
    char ch;
    while((ch = fgetc(file1)) !=EOF) {
        fputc(ch,mergedfile);
    }
     while((ch = fgetc(file2)) !=EOF) {
        fputc(ch,mergedfile);
    }
}

int main () {
    FILE *file1;
    FILE *file2;
    FILE *mergedfile;
    file1=fopen("index.txt","r");
    file2=fopen("passwords.txt","r");
    mergedfile=fopen("output.txt","w");
    if(file1 == NULL||file2 == NULL||mergedfile == NULL) {
        printf("Error in opening files.\n");
        return 1;
    }
    mergefiles(file1,file2,mergedfile);
    fclose(file1);
    fclose(file2);
    fclose(mergedfile);
    printf("Files are merged.\n");

    return 0;
}
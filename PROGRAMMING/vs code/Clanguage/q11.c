#include<stdio.h> 

int main () {
    FILE *fptr=fopen("index.txt","a");
    if(fptr == NULL ){
        printf("Error in opening the file.\n");
        return 1;
    }
    fprintf(fptr,"\nThis is appended text.\n");
    fclose(fptr);
    printf("The appended is added successfully.\n");

    return 0;

}
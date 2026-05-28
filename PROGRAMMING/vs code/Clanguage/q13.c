#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    if (fseek(file, -10, SEEK_END) != 0) {
        printf("Error seeking in file.\n");
        fclose(file);
        return 1;
    }
    char ch;
    while (fscanf(file, "%c", &ch) == 1) {
        fprintf(stdout, "%c", ch);
    }
    fclose(file);
    printf("\n");
    
    return 0;
}
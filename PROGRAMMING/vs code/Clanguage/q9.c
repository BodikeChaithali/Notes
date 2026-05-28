#include <stdio.h>

void insertWordAfterHelp(char *filename, char *newWord) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char ch;
    int state = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (state == 0 && ch == 'h') {
            state = 1;
        } else if (state == 1 && ch == 'e') {
            state = 2;
        } else if (state == 2 && ch == 'l') {
            state = 3;
        } else if (state == 3 && ch == 'p') {
            state = 4;
        } else {
            state = 0;
        }

        fputc(ch, tempFile);

        if (state == 4) {
            fputc(' ', tempFile);
            for (int i = 0; newWord[i] != '\0'; i++) {
                fputc(newWord[i], tempFile);
            }
            state = 0; 
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);

    printf("Word inserted successfully.\n");
}

int main() {
    char filename[100];
    char newWord[100];

    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("Enter the word to add after 'help': ");
    scanf("%s", newWord);

    insertWordAfterHelp(filename, newWord);

    return 0;
}

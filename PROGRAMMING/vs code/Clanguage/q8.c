#include <stdio.h>
int main() {
FILE *file = fopen("index.txt", "a");
if (file == NULL) {
printf("Error opening file!\n");
return 1;
}
fprintf(file, "\nThis is appended text.");
fclose(file);
printf("Text appended successfully.\n");
return 0;
}
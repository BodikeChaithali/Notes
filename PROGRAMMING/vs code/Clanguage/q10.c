#include <stdio.h>
int main() {
FILE *file = fopen("index.txt", "r");
if (file == NULL) {
printf("Error opening file!\n");
return 1;
}
char ch;
int lines = 0;
while ((ch = fgetc(file)) != EOF) {
if (ch == '\n') {
lines++;
}
}
fclose(file);
printf("Number of lines: %d\n", lines);
return 0;
}
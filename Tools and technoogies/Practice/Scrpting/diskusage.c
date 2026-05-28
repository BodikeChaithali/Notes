#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");  // open in binary mode
    if (fp == NULL) {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    long long bytes = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        bytes++;
    }

    fclose(fp);

    long long kb = bytes / 1024;  // integer division
    printf("%lld, %lld KB\n", bytes, kb);

    return 0;
}


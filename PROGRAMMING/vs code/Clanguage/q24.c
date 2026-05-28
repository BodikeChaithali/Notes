#include<stdio.h>

void main () {
    int n;
    printf("Enter weeday no(1-7):");
    scanf("%d",&n);
    switch(n) {
        case 1: puts("Sunday"); break;
        case 2: puts("Monday"); break;
        case 3: puts("Tuesday"); break;
        case 4: puts("Wednesday"); break;
        case 5: puts("Thusday"); break;
        case 6: puts("Friday"); break;
        case 7: puts("Satday"); break;
        default: puts("Invalid weeday");
    }
}
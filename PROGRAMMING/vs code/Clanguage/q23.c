#include<stdio.h>

void main () {
    int a;
    switch(a=*( "I Like""abcd" + 7))
    {
        case 97: puts("Janvi Kapoor"); break;
        case 98: puts("Rashmika Mandana"); break;
        case 99: puts("Kiara Advani"); break;
        default: puts("All");
    }
}
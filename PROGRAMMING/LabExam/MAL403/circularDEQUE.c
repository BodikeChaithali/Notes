#include <stdio.h>

#define SIZE 6

char deque[SIZE];
int left = 2;
int right = 4;

void printDeque() {
    printf("DEQUE: ");
    int i = left;
    while (1) {
        printf("%c ", deque[i]);
        if (i == right)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void insertRight(char x) {
    right = (right + 1) % SIZE;
    deque[right] = x;
}

void deleteRight() {
    right = (right - 1 + SIZE) % SIZE;
}

void insertLeft(char x) {
    left = (left - 1 + SIZE) % SIZE;
    deque[left] = x;
}

void deleteLeft() {
    left = (left + 1) % SIZE;
}

int main() {
    
    // Initial deque: _, _, A, C, D, _
    for(int i = 0; i < SIZE; i++)
        deque[i] = '-';
    deque[2] = 'A';
    deque[3] = 'C';
    deque[4] = 'D';

    printf("Initial ");
    printDeque();

    // (a) F added to the right
    insertRight('F');
    printf("(a) After adding F on right: ");
    printDeque();

    // (b) Two letters delete from right
    deleteRight();
    deleteRight();
    printf("(b) After deleting 2 on right: ");
    printDeque();

    // (c) K, L, M added to left
    insertLeft('K');
    insertLeft('L');
    insertLeft('M');
    printf("(c) After adding K, L, M on left: ");
    printDeque();

    // (d) One letter delete on left
    deleteLeft();
    printf("(d) After deleting 1 on left: ");
    printDeque();

    // (e) R added to left
    insertLeft('R');
    printf("(e) After adding R on left: ");
    printDeque();

    // (f) S added to right
    insertRight('S');
    printf("(f) After adding S on right: ");
    printDeque();

    // (g) T added to right
    insertRight('T');
    printf("(g) After adding T on right: ");
    printDeque();

    return 0;
}

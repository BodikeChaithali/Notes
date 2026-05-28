#include <stdio.h>

int countStudents(int students[], int n, int sandwiches[]) {
    int front = 0, back = n - 1;
    int sIndex = 0;
    int count = 0;

    while (count < n) {
        if (students[front] == sandwiches[sIndex]) {
            front = (front + 1) % n;
            sIndex++;
            count = 0;
        } else {
            back = (back + 1) % n;
            students[back] = students[front];
            front = (front + 1) % n;
            count++;
        }
    }
    return n - sIndex;
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;

    printf("Output: %d\n", countStudents(students, n, sandwiches));
    return 0;
}

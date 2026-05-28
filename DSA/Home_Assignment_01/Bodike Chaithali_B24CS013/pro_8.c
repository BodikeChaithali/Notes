#include <stdio.h>

#define MAX 10000

int countStudents(int students[], int n, int sandwiches[], int m) {
    int front = 0, rear = n - 1, sandwichIndex = 0, rotations = 0;

    while (front <= rear && sandwichIndex < m) {
        if (students[front] == sandwiches[sandwichIndex]) {
            front++;
            sandwichIndex++;
            rotations = 0;
        } else {
            rear++;
            students[rear] = students[front];
            front++;
            rotations++;
            if (rotations > rear - front + 1) break;
        }
    }
    return rear - front + 1;
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    int students[MAX], sandwiches[MAX];
    printf("Enter students array (0/1):\n");
    for (int i = 0; i < n; i++) scanf("%d", &students[i]);

    printf("Enter sandwiches array (0/1):\n");
    for (int i = 0; i < n; i++) scanf("%d", &sandwiches[i]);

    int result = countStudents(students, n, sandwiches, n);
    printf("Number of students unable to eat lunch = %d\n", result);

    return 0;
}
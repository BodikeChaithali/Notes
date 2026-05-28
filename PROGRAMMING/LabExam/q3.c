#include <stdio.h>

char board[205][205];

// Write your logic inside this function
void solveTestcase(int m, int n) {
    // TODO: write your code here
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int m, n;
        scanf("%d %d", &m, &n);

        for (int i = 0; i < m; i++) {
            scanf("%s", board[i]);
        }

        solveTestcase(m, n);

        // Print modified board
        for (int i = 0; i < m; i++) {
            printf("%s\n", board[i]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    if (n == 1) return 1;

    int in[n + 1], out[n + 1];

    for (int i = 0; i <= n; i++) {
        in[i] = 0;
        out[i] = 0;
    }

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];

        out[a]++;
        in[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (out[i] == 0 && in[i] == n - 1)
            return i;
    }

    return -1;
}

int main() {
    int n, trustSize;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter number of trust pairs: ");
    scanf("%d", &trustSize);

    int* trustColSize = (int*)malloc(sizeof(int) * trustSize);

    // Allocate trust matrix
    int** trust = (int**)malloc(sizeof(int*) * trustSize);
    for (int i = 0; i < trustSize; i++) {
        trust[i] = (int*)malloc(sizeof(int) * 2);
        trustColSize[i] = 2;
    }

    printf("Enter trust pairs (a b):\n");
    for (int i = 0; i < trustSize; i++) {
        scanf("%d %d", &trust[i][0], &trust[i][1]);
    }

    int judge = findJudge(n, trust, trustSize, trustColSize);
    printf("Town Judge = %d\n", judge);

    // Free memory
    for (int i = 0; i < trustSize; i++)
        free(trust[i]);
    free(trust);
    free(trustColSize);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int *indegree = (int*)calloc(numCourses, sizeof(int));
    int *adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        indegree[a]++;
        adjSize[b]++;
    }

    int **adj = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][adjSize[b]++] = a;
    }

    int *queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int course = queue[front++];
        count++;

        for (int i = 0; i < adjSize[course]; i++) {
            int next = adj[course][i];
            indegree[next]--;
            if (indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    for (int i = 0; i < numCourses; i++)
        free(adj[i]);
    free(adj);
    free(adjSize);
    free(indegree);
    free(queue);

    return count == numCourses;
}

int main() {
    int numCourses = 2;

    int prerequisitesSize = 1;
    int* prerequisitesColSize = (int*)malloc(sizeof(int) * prerequisitesSize);

    int** prerequisites = (int**)malloc(sizeof(int*) * prerequisitesSize);
    prerequisites[0] = (int*)malloc(sizeof(int) * 2);
    prerequisites[0][0] = 1;
    prerequisites[0][1] = 0;
    prerequisitesColSize[0] = 2;

    bool result = canFinish(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);
    printf("Can finish: %s\n", result ? "true" : "false");

    for (int i = 0; i < prerequisitesSize; i++)
        free(prerequisites[i]);
    free(prerequisites);
    free(prerequisitesColSize);

    return 0;
}

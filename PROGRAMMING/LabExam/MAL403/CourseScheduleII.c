#include <stdio.h>
#include <stdlib.h>

/*
 * Return a valid topological order of courses,
 * or empty array if cycle exists.
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize, int* returnSize) 
{
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

    int *queue = (int*)malloc(sizeof(int) * numCourses);
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int *order = (int*)malloc(sizeof(int) * numCourses);
    int idx = 0;

    while (front < rear) {
        int course = queue[front++];
        order[idx++] = course;

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

    if (idx != numCourses) {
        *returnSize = 0;
        free(order);
        return NULL;
    }

    *returnSize = numCourses;
    return order;
}


/* ------------------------ MAIN FOR TESTING ------------------------ */

int main() {
    int numCourses, prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &prerequisitesSize);

    int **prerequisites = (int**)malloc(prerequisitesSize * sizeof(int*));
    int *prerequisitesColSize = (int*)malloc(prerequisitesSize * sizeof(int));

    printf("Enter prerequisites as 'a b' meaning b -> a:\n");
    for (int i = 0; i < prerequisitesSize; i++) {
        prerequisites[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
        prerequisitesColSize[i] = 2;
    }

    int returnSize;
    int *order = findOrder(numCourses, prerequisites, prerequisitesSize,
                           prerequisitesColSize, &returnSize);

    if (returnSize == 0) {
        printf("No valid course order (cycle detected).\n");
    } else {
        printf("Course order: ");
        for (int i = 0; i < returnSize; i++)
            printf("%d ", order[i]);
        printf("\n");
    }

    for (int i = 0; i < prerequisitesSize; i++)
        free(prerequisites[i]);
    free(prerequisites);
    free(prerequisitesColSize);
    free(order);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Graph {
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* node = createNode(dest);
    node->next = graph->adjLists[src];
    graph->adjLists[src] = node;

    // For undirected graph
    node = createNode(src);
    node->next = graph->adjLists[dest];
    graph->adjLists[dest] = node;
}

void BFS(struct Graph* graph, int start) {
    int *queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    graph->visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph->adjLists[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(queue);
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    BFS(graph, 0);

    return 0;
}

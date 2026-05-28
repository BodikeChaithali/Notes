#include <stdio.h>
#include <string.h>
#define MAX 10000

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void init(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int val) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = val;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}

int peek(Queue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

const char* predictPartyVictory(char *senate) {
    int n = strlen(senate);
    Queue qR, qD;
    init(&qR);
    init(&qD);

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R' || senate[i] == 'r')
            enqueue(&qR, i);
        else if (senate[i] == 'D' || senate[i] == 'd')
            enqueue(&qD, i);
    }

    while (!isEmpty(&qR) && !isEmpty(&qD)) {
        int rIndex = dequeue(&qR);
        int dIndex = dequeue(&qD);

        if (rIndex < dIndex)
            enqueue(&qR, rIndex + n);
        else                
            enqueue(&qD, dIndex + n);
    }

    if (isEmpty(&qD)) return "Radiant";
    else return "Dire";
}

int main() {
    char senate[MAX];
    printf("Enter senate string (R/D): ");
    scanf("%s", senate);
    printf("Winner: %s\n", predictPartyVictory(senate));

    return 0;
}
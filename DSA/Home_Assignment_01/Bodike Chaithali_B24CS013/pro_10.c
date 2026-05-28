#include <stdio.h>
#define MAX 10000

typedef struct {
    int data[MAX];
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
    q->data[++q->rear] = val;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}

int peek(Queue *q) {
    if (isEmpty(q)) return -1;
    return q->data[q->front];
}

typedef struct {
    Queue q;
} RecentCounter;

void initRecentCounter(RecentCounter *rc) {
    init(&rc->q);
}

int ping(RecentCounter *rc, int t) {
    enqueue(&rc->q, t);
    while (!isEmpty(&rc->q) && peek(&rc->q) < t - 3000) {
        dequeue(&rc->q);
    }
    return rc->q.rear - rc->q.front + 1;
}

int main() {
    RecentCounter rc;
    initRecentCounter(&rc);
    int n, t, times[1000];
    printf("Enter number of pings: ");
    scanf("%d", &n);
    printf("Enter times: ");
    for (int i = 0; i < n; i++) scanf("%d", &times[i]);
    for (int i = 0; i < n; i++) {
        printf("ping(%d)", times[i]);
        if (i < n - 1) printf(",");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d", ping(&rc, times[i]));
        if (i < n - 1) printf(",");
    }
    puts("");
    return 0;
}
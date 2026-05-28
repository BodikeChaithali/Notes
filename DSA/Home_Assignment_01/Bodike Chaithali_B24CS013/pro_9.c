#include <stdio.h>
#include <string.h>
#define MAX 1000

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

int firstUniqueChar(char *s) {
    int freq[256] = {0};
    Queue q;
    init(&q);
    for (int i = 0; s[i]; i++) {
        freq[(unsigned char)s[i]]++;
        enqueue(&q, i);
        while (!isEmpty(&q) && freq[(unsigned char)s[peek(&q)]] > 1) {
            dequeue(&q);
        }
    }
    if (isEmpty(&q)) return -1;
    return peek(&q);
}

int main() {
    char s[MAX];
    printf("Enter string: ");
    scanf("%s", s);
    int index = firstUniqueChar(s);
    printf("%d\n", index);
    return 0;
}
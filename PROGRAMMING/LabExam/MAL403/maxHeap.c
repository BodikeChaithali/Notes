#include <stdio.h>

#define MAX 50

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify down
void heapifyDown(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}

// Heapify up
void heapifyUp(int i) {
    int parent = (i - 1) / 2;
    while (i > 0 && heap[parent] < heap[i]) {
        swap(&heap[parent], &heap[i]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void insert(int key) {
    heap[size] = key;
    size++;
    heapifyUp(size - 1);
}

void deleteRoot() {
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

int height() {
    int h = 0, nodes = 1;
    while (nodes < size) {
        nodes = nodes * 2 + 1;
        h++;
    }
    return h;
}

int depth() { return height() - 1; }

void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int initial[] = {95, 85, 80, 70, 60, 55, 50, 40};
    size = 8;

    for(int i = 0; i < size; i++)
        heap[i] = initial[i];

    printf("Initial Heap: ");
    printHeap();

    insert(77);
    printf("After inserting 77: ");
    printHeap();

    insert(88);
    printf("After inserting 88: ");
    printHeap();

    deleteRoot();
    printf("After deleting root: ");
    printHeap();

    deleteRoot();
    printf("After deleting root again: ");
    printHeap();

    printf("\nHeight: %d\n", height());
    printf("Depth: %d\n", depth());

    return 0;
}

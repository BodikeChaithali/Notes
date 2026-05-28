#include <stdio.h>
#include <stdlib.h>

/* ---------- Definition for linked list ---------- */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* ---------- Min-Heap for ListNode pointers ---------- */
void heapSwap(struct ListNode **a, struct ListNode **b) {
    struct ListNode *t = *a;
    *a = *b;
    *b = t;
}

void heapUp(struct ListNode **heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent]->val > heap[idx]->val) {
            heapSwap(&heap[parent], &heap[idx]);
            idx = parent;
        } else break;
    }
}

void heapDown(struct ListNode **heap, int size, int idx) {
    while (1) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int smallest = idx;

        if (left < size && heap[left]->val < heap[smallest]->val)
            smallest = left;
        if (right < size && heap[right]->val < heap[smallest]->val)
            smallest = right;

        if (smallest != idx) {
            heapSwap(&heap[idx], &heap[smallest]);
            idx = smallest;
        } else break;
    }
}

void heapPush(struct ListNode **heap, int *size, struct ListNode *node) {
    heap[*size] = node;
    (*size)++;
    heapUp(heap, *size - 1);
}

struct ListNode* heapPop(struct ListNode **heap, int *size) {
    struct ListNode* top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapDown(heap, *size, 0);
    return top;
}

/* ---------- Merge K Sorted Lists ---------- */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct ListNode **heap = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    int heapSize = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i])
            heapPush(heap, &heapSize, lists[i]);
    }

    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (heapSize > 0) {
        struct ListNode *node = heapPop(heap, &heapSize);
        tail->next = node;
        tail = node;
        if (node->next)
            heapPush(heap, &heapSize, node->next);
    }

    free(heap);
    return dummy.next;
}

/* ---------- Helper: Create nodes ---------- */
struct ListNode* newNode(int val) {
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

/* ---------- Helper: Print list ---------- */
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

/* ---------- Example main() ---------- */
int main() {
    /* Example: lists = [[1,4,5],[1,3,4],[2,6]] */

    struct ListNode* l1 = newNode(1);
    l1->next = newNode(4);
    l1->next->next = newNode(5);

    struct ListNode* l2 = newNode(1);
    l2->next = newNode(3);
    l2->next->next = newNode(4);

    struct ListNode* l3 = newNode(2);
    l3->next = newNode(6);

    struct ListNode* lists[3] = {l1, l2, l3};

    struct ListNode* result = mergeKLists(lists, 3);

    printf("Merged sorted list:\n");
    printList(result);

    return 0;
}

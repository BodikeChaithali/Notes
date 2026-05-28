#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct ListNode *head = NULL, *tail = NULL;

    if (l1->val < l2->val) {
        head = tail = l1;
        l1 = l1->next;
    } else {
        head = tail = l2;
        l2 = l2->next;
    }

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }

    tail->next = l1 ? l1 : l2;
    return head;
}

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* mid = findMiddle(head);
    struct ListNode* right = mid->next;
    mid->next = NULL;

    struct ListNode* leftSorted = sortList(head);
    struct ListNode* rightSorted = sortList(right);

    return merge(leftSorted, rightSorted);
}

// Utility function to create new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Print list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Empty list\n");
        return 0;
    }

    struct ListNode *head = NULL, *tail = NULL;

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct ListNode* newNode = createNode(value);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original list: ");
    printList(head);

    head = sortList(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}

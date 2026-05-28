#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}

int main() {
    // Example: head = [3,2,0,-4], pos = 1 -> cycle created
    int arr[] = {3, 2, 0, -4};
    int pos = 1;
    int n = 4;
    
    struct ListNode *head = NULL, *temp = NULL, *cycleNode = NULL;

    // Create linked list
    for (int i = 0; i < n; i++) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;

        if (!head) {
            head = temp = node;
        } else {
            temp->next = node;
            temp = node;
        }

        if (i == pos)
            cycleNode = node;
    }

    // Create cycle: last node -> pos node
    temp->next = cycleNode;

    printf("Cycle Present? %s\n", hasCycle(head) ? "true" : "false");
    return 0;
}
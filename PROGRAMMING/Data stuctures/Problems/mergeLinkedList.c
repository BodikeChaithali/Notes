#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;
Node *mergeLinkedLists(Node *head1,Node *head2) {
    if(!head1) return head2;
    if(!head2) return head1;

    Node *head=NULL;
    Node *tail=NULL;
    if(head1->val<head2->val) {
        head=tail=head1;
        head1=head1->next;
    }
    else {
        head=tail=head2;
        head2=head2->next;
    }
    while(head1 && head2) {
        if(head1->val<head2->val){
            tail->next=head1;
            tail=head1;
            head1=head1->next;
        }
        else {
            tail->next=head2;
            tail=head2;
        }
    }
    tail->next=head1?head1:head2;
    return head;
}
Node *insertData(int data,Node *head) {
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->val=data;
    newNode->next=head;
    return newNode;
}
int main() {
    int n1,n2;
    printf("Enter no.of nodes in 1st linked list: ");
    scanf("%d",&n1);
    Node *head1=NULL;
    printf("Enter elements in sorted order:\n");
    for(int i=0;i<n1;i++) {
        int data;
        scanf("%d",&data);
        head1=insertData(data,head1);
    }
    printf("Enter no.of nodes in 2nd linked list: ");
    scanf("%d",&n2);
    Node *head2=NULL;
    printf("Enter elements in sorted order:\n");
    for(int i=0;i<n2;i++) {
        int data;
        scanf("%d",&data);
        head2=insertData(data,head2);
    }
    Node *mergedHead=mergeLinkedLists(head1,head2);
    printf("Merged Linked List:\n");
    Node *temp=mergedHead;
    while(temp) {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}
#include<stdio.h>
struct Node{
    int data;
    struct nNode *next;
};
struct Node *reverse(struct Node *head) {
    if(!head || head->next) return head;
    struct Node *prev=NULL;
    struct Node *curr=head;
    struct Node *next=NULL;
    while(curr) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

struct Node *create(int key) {

}
int sumOfReversedLinkedList(struct Node *head1,struct Node *head2) {
    if(head1==NULL && head2==NULL) return 0;
    int sum=0;
    struct Node *revHead1=reverse(head1);
    struct Node *revHead2=reverse(head2);
    struct Node *temp1=revHead1,*temp2=revHead2;
    
    while(temp1 && temp2) {
        int sum=temp1->data+temp2->data;

    }
}
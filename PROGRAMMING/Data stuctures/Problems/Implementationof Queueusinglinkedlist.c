#include<stdio.h>
#include<stdlib.h>  
struct Node {
    int data;
    struct Node* next;
} *front=NULL,*rear=NULL;
void enqueue(int x) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    if(front==NULL && rear==NULL) {
        front=rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}
void dequeue() {
    struct Node* temp;
    if(front==NULL) {
        printf("Empty\n");
        return;
    }
    if(front==rear) {
        free(front);
        front=rear=NULL;
    }
    else {
        temp=front;
        front=front->next;
        free(temp);
    }
}
void display() {
    struct Node* temp=front;
    if(front==NULL) {
        printf("Empty\n");
        return;
    }
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void peek() {
    if(front==NULL) {
        printf("Empty\n");
        return;
    }
    printf("%d\n",front->data);
}
int isEmpty() {
    if(front==NULL) return 1;
    return 0;
}
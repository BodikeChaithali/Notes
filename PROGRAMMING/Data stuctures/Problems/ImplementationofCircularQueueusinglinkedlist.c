#include<stdio.h>
#include<stdlib.h>  
struct Node {
    int data;
    struct Node* next;
}*rear=NULL,*front=NULL;
void enqueue(int value) {
    struct Node*newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=0;
    if(rear==0) {
        front=rear=newnode;
        rear->next=front;
    }
    else {
        rear->next=newnode;
        rear=newnode;
        newnode->next=front;
    }
}
void dequeue (){
    struct Node* temp=front;
    if(front==0) {
        printf("Underflow!!\n");
    }
    else if (front==rear) {
        front=rear=0;
        free(temp);
    }
    else {
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek() {
    if(front==0) printf("Empty!!\n");
    else printf("%d",front->data);
}
void display () {
    struct Node*temp=front;
    while(temp->next!=front) {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
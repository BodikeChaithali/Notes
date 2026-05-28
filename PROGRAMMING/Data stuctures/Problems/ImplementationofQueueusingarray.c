#include<stdio.h>

#define n 50
int queue[n],front=-1,rear=-1;
void enqueuec(int x) {
    if (rear==n-1) {
        printf("Overflow\n");
        return;
    }
    if (front==-1 && rear==-1) {
        front=rear=0;
        queue[rear]=x;
    }
    else {
        rear++;
        queue[rear]=x;
    }
}
void dequeue () {
    if(front==-1 && rear==-1) {
        printf("Empty\n");
        return;
    }
    if(front==rear) {
        front=rear=-1;
    }
    else {
        front++;
    }
}
void display() {
    if(front==-1 && rear==-1) {
        printf("Empty\n");
        return;
    }int i;
    for(i=front;i!=rear;i=(i+1)%n) {
        printf("%d ",queue[i]);
    }
    printf("%d\n",queue[i]);
} 
void peek() {
    if(front==-1 && rear==-1) {
        printf("Empty\n");
        return;
    }
    printf("%d\n",queue[front]);
}
int isempty() {
    if(front==-1 && rear==-1) return 1;
    return 0;
}
int isfull() {
    if(rear==n-1) return 1;
    return 0;
}
int main() {
    int choice,x;
    while(1) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.IsEmpty\n6.IsFull\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&x);
                enqueuec(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                if(isempty()) printf("Empty\n");
                else printf("Not Empty\n");
                break;
            case 6:
                if(isfull()) printf("Full\n");
                else printf("Not Full\n");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

#include<stdio.h>
#define n 10000
int s1[n],s2[n],top1=-1,top2=-1;
void push1(int x)  {
    if(top1==n-1) {
        printf("Overflow\n");
        return;
    }
    s1[++top1]=x;
}
int pop1() {
    if(top1==-1) {
        return -1;
    }
    return s1[top1--];
}
void push2(int x)  {
    if(top2==n-1) {
        printf("Overflow\n");
        return;
    }
    s2[++top2]=x;
}
int pop2() {
    if(top2==-1) {
        return -1;
    }
    return s2[top2--];
}
void enqueue(int x) {
    push1(x);
}
void dequeue() {
    if(top1==-1 && top2==-1) {
        printf("Empty\n");
        return;
    }
    if(top2==-1) {
        while(top1!=-1) {
            push2(pop1());
        }
    }
    pop2();
}
void display() {
    if(top1==-1 && top2==-1) {
        printf("Empty\n");
        return;
    }
    for(int i=top2;i>=0;i--) {
        printf("%d ",s2[i]);
    }
    for(int i=0;i<=top1;i++) {
        printf("%d ",s1[i]);
    }
    printf("\n");
}
void peek() {
    if(top1==-1 && top2==-1) {
        printf("Empty\n");
        return;
    }
    if(top2!=-1) {
        printf("%d\n",s2[top2]);
    }
    else {
        while(top1!=-1) {
            push2(pop1());
        }
        printf("%d\n",s2[top2]);
    }
}
int isempty() {
    if(top1==-1 && top2==-1) return 1;
    return 0;
}
int isfull() {
    if(top1==n-1) return 1;
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
                printf("Enter the element to be enqueued: ");
                scanf("%d",&x);
                enqueue(x);
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
                exit(0);
            default:
                printf("Invalid Input!!\n");
        }
    }
    return 0;
}
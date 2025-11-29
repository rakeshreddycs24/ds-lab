#include<stdio.h>
#define MAX 5
int CQ[MAX];
int front=-1;
int rear=-1;
void insertCQ(){
    int n;
    if(front==(rear+1)%MAX){
        printf("QUEUE OVERFLOW\n");
    }else{
        printf("Enter item to be inserted:");
        scanf("%d",&n);
        if(front==-1 && rear==-1){
            front = 0;
            rear = 0;
            CQ[rear]=n;
            printf("%d item inserted\n",n);
        }else{
            rear = (rear + 1) % MAX;
            CQ[rear]=n;
            printf("%d item inserted\n",n);
        }
    }
}
void deleteCQ(){
    if(front==-1 && rear==-1){
        printf("QUEUE UNDERFLOW\n");
    }else{
        int item = CQ[front];
        if(front==rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % MAX;
        }
        printf("deleted item:%d\n",item);
    }
}
void display(){
    if(front == -1 && rear == -1){
        printf("QUEUE IS EMPTY\n");
    }else{
        int i=front;
        while (1){
            printf("%d\n",CQ[i]);
            if(i==rear){
                break;
            }
            i = (i+1)%MAX;        
        }
    }
}
void main(){
    int c;
    while(1){
        printf("\nCHOOSE OPERATION\n1)INSERT\n2)DELETE\n3)DISPLAY\n4)EXIT\n\n");
        scanf("%d",&c);
        printf("\n");
        if(c==4){
            printf("THANK YOU!!");
            break;
        }
        switch(c){
            case 1:
                insertCQ();
                break;
            case 2:
                deleteCQ();
                break;
            case 3:
                display();
                break;
        }
    }
}

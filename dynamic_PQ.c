//dynamic priority queue in ascending order
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};

struct Node* front;
struct Node* rear;

void enqueue_pq();
void dequeue_pq();
void display_pq();

void enqueue_pq(){
    printf("Enter the element you want to add\n");
    int add;
    scanf("%d",&add);
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=add;
    ptr->nextaddress = NULL;
    if(front==NULL){
        ptr->nextaddress=NULL;
        front = ptr;
        rear = ptr;
        printf("Created the first node of the queue\n");
    }//created the first Node of queue
    if(add < front->data){
        ptr->nextaddress = front;
        front = ptr;
        return;//fake return to break out of the enqueue function
    }
    struct Node* temp = front;
    while(temp->nextaddress != NULL && add > (temp->nextaddress->data)){
        ptr->nextaddress = temp->nextaddress;
        temp->nextaddress = ptr;
    }//end of while
        if(ptr->nextaddress == NULL){
            rear = ptr;
        }//if ptr was added at the end  
    printf("Element added\n");
}//end of enqueue_pq

void dequeue_pq(){
    if(front==NULL){
        printf("Queue is already empty so can't dequeue\n");
        rear = NULL;
    }
    else{
        struct Node* ptr = front;
        printf("Removing element: %d\n",front->data);
        front=front->nextaddress;
        free(ptr);
    }
}//end of dequeue

void display_pq(){
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        struct Node* temp=front;
        while(temp!=NULL){
            printf("Element is: %d\n",temp->data);
            temp = temp->nextaddress;
        }
    }
}//end of print

void main(){
    int choice,ch;
    do{
        printf("Enter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to print the queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue_pq();
                    break;
            case 2: dequeue_pq();
                    break;
            case 3: display_pq();
                    break;
            default: printf("Invalid input, try again\n");
                    break;
        }//end of switch case
        printf("Enter 1 to continue, 0 to exit\n");
        scanf("%d",&ch);
    }while(ch>0);
}//end of main
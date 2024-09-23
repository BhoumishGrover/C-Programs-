//dynamic queue
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};

struct Node* front;
struct Node* rear;

void enque_queue(){
    printf("Enter value you want to add to the queue\n");
    int value;
    scanf("%d",&value);
    if(front==NULL){
        struct Node* ptr =(struct Node*)malloc(sizeof(struct Node));
        ptr->data=value;
        ptr->nextaddress=NULL;
        rear=ptr;
        front=ptr;
    }//created the first element of the queue
    else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        //temp=rear;
        temp->data=value;
        rear->nextaddress=temp;
        rear=temp;
        rear->nextaddress=NULL;
    }//added node at the end of the queue
}//end of enque

void deque_queue(){
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        struct Node* ptr;
        ptr=front;
        front=front->nextaddress;
        free(ptr);
    }
}//end of deque

void print_queue(struct Node* ptr){
    printf("Printing....\n");
    while(ptr!=NULL){
        printf("Element of node is: %d \n",ptr->data);
        ptr=ptr->nextaddress;
    }//end of while
}//end of traversal

void main(){
    int choice,ch;
    do{
        printf("Enter 1 to enque\nEnter 2 to deque\nEnter 3 to display queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enque_queue();
                    print_queue(front);
                    break;
            case 2: deque_queue();
                    print_queue(front);
                    break;
            case 3: print_queue(front);
                    break;
            default: printf("Invalid choice, try again \n");
                    break;
        }//end of switch case
        printf("Enter 0 to stop all operations, 1 to continue\n");    
        scanf("%d",&ch);
    }while(ch>0);//end of do while loop
}//end of main
//circular queue using linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};

struct Node* front;
struct Node* tail;

void enqueue_queue(int value);
void print_queue();
void deque_queue();

void enque_queue(int value){
    if(front==NULL && tail==NULL){//need to create the linked list
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data=value;
        front = ptr;
        ptr->nextaddress=front;
        tail = ptr;
    }
    else{//linked list already exists
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data=value;
        tail->nextaddress=ptr;
        tail = ptr;
        tail->nextaddress=front;
    }
}//end of enqueue

void print_queue(){
    if(front == NULL && tail == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Printing...\n");
        struct Node* ptr = front;
        while(ptr->nextaddress!=front){
            printf("The element is: %d\n",ptr->data);
            ptr = ptr->nextaddress;
        }
        printf("The element is: %d\n",tail->data);
    }
}//end of display

void deque_queue(){
    struct Node* temp;
    temp = front;
    if(front == NULL && tail== NULL){
        printf("Underflow, queue is empty\n");
    }
    else if(front == tail){
        front = NULL;
        tail = NULL;
        free(temp);
    }
    else{
        printf("Dequeueing %d\n",front->data);
        front = front->nextaddress;
        tail->nextaddress = front;
        free(temp);
    }
}//end of dequeue 

void main(){
    int choice,ch;
    do{
        printf("Enter 1 to enque\nEnter 2 to deque\nEnter 3 to display queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value you want to add\n");
                    int value;
                    scanf("%d",&value);
                    enque_queue(value);
                    print_queue();
                    break;
            case 2: deque_queue();
                    print_queue();
                    break;
            case 3: print_queue();
                    break;
            default: printf("Invalid choice, try again \n");
                    break;
        }//end of switch case
        printf("Enter 0 to stop all operations, 1 to continue\n");    
        scanf("%d",&ch);
    }while(ch>0);//end of do while loop
}//end of main
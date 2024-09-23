//static queue operations
#include <stdio.h>
#include <stdlib.h>

int size;
int rear = -1;
int front = -1;

void enque_queue(int queue[], int size){
    printf("Enter value you want to add to the queue\n");
    int value;
    scanf("%d",&value);
    if(front==-1){
        queue[0] = value;
        front=0;
        rear=0;
    }//first element of the queue
    else if(rear==size-1){
        printf("Queue is full, cannot insert value\n");
    }
    else{
        queue[rear+1]=value;
        rear=rear+1;
    }
}//end of enqueue

void deque_queue(int queue[], int size){
    if(rear==-1){
        printf("Queue is already empty\n");
    }
    else{
        front=front+1;
    }
}//end of deque

void display_queue(int queue[]){
    printf("Printing the entire queue\n");
    for(int i=front;i<=rear;i++){
        printf("%d, ",queue[i]);
    }
}//end of display_queue
    
void main(){
    printf("Enter the size of the queue\n");
    scanf("%d",&size);
    int queue[size];
    int choice,ch;
    do{
        printf("Enter 1 to enque\n 2 to deque\n 3 to display queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enque_queue(queue,size);
                    display_queue(queue);
                    break;
            case 2: deque_queue(queue,size);
                    display_queue(queue);
                    break;
            case 3: display_queue(queue);
                    break;
            default: printf("Invalid choice, try again \n");
                    break;
        }//end of switch case
        printf("Enter 0 to stop all operations, 1 to continue\n");   
        scanf("%d",&ch); 
    }while(ch>0);//end of do while loop
}//end of main
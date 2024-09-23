//circuclar queue using arrays
#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void enque_queue(int arr[],int size);
void deque_queue(int arr[],int size);
void print_queue(int arr[],int size);

void enque_queue(int arr[],int size){
    int value;
    printf("Enter value you want to add\n");
    scanf("%d",&value);
    if(((rear+1)%size) == front){
        printf("Queue is full, cannot add element\n");
    }
    else if(front == -1 && rear == -1){
        printf("added the first element\n");
        front = 0;
        rear = 0;
        arr[rear] = value;
    }
    else{
        rear = (rear+1)%size;
        arr[rear] = value;
        printf("Element added\n");
    }
}//end of enqueue_queue

void deque_queue(int arr[],int size){
    if(front == -1 && rear == -1){
        printf("Underflow, queue is already empty\n");
    }
    else if(front == rear){
        printf("dequeued element is: %d",arr[front]);
        front = rear = -1;
    }
    else{
        printf("dequeued element is: %d\n",arr[front]);
        front = (front+1)%size;
    }
}//end of dequeue

void print_queue(int arr[],int size){
    printf("Printing....\n");
    int i = front;
    if(front==-1 && rear ==-1){
        printf("Queue is empty\n");
    }
    else{
        while(i!=rear){
            printf("%d\n",arr[i]);
            i = (i+1)%size;
        }
        printf("%d\n",arr[rear]);
    }
}//end of print queue

int main(){
    printf("Enter size of queue\n");
    int size;
    scanf("%d",&size);
    int queue[size];
    int choice,ch;
    do{
        printf("Enter 1 to enque\nEnter 2 to deque\nEnter 3 to display queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enque_queue(queue,size);
                    print_queue(queue,size);
                    break;
            case 2: deque_queue(queue,size);
                    print_queue(queue,size);
                    break;
            case 3: print_queue(queue,size);
                    break;
            default: printf("Invalid choice, try again \n");
                    break;
        }//end of switch case
        printf("Enter 0 to stop all operations, 1 to continue\n");    
        scanf("%d",&ch);
    }while(ch>0);//end of do while loop
}//end of main
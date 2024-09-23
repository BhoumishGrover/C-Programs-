//Static priority queue in ascending order
#include <stdio.h>
#include <stdlib.h>

int front = -1;
int end = -1;

void enque(int queue[],int size){
    int value,temp;
    printf("Enter the value you want to add\n");
    scanf("%d",&value);
    if(front==-1){
        queue[0] = value;
        front = 0;
        end = 0;
        printf("Added the first element of the queue\n");
    }
    else if(end == (size-1)){
        printf("Can't add element, queue is full\n");
    }
    else if(value > queue[end]){
        end = end + 1;
        queue[end] = value;
    }
    else{
        //traverse the entire queue
        for(int i=front;i<=end;i++){
            if(queue[i]>value){
                for(int j=end;j>=i;j--){
                    queue[j+1] = queue[j];
                }//shifted all the elements from i, one index ahead
                queue[i] = value;//put the value in i
                end = end + 1;
                break;
            }
        } 
        printf("Element was added\n");
    }
}//end of enque

void dequeue(int queue[]){
    if(front>end || front==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Dequeing %d\n",queue[front]);
        front = front + 1;
    }
}//end of dequeue

void display_queue(int queue[]){
    printf("printing....\n");
    if(front > end){
        printf("Queue is empty\n");
        front = -1;
        end = -1;
    }
    else{
        for(int i=front;i<=end;i++){
            printf("%d\n",queue[i]);
        }
    }
}//end of print

void main(){
    int size;
    printf("Enter the size of queue\n");
    scanf("%d",&size);
    int queue[size];
    int choice,ch;
    do{
        printf("Enter 1 to enque\nEnter 2 to deque\nEnter 3 to display queue\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enque(queue,size);
                    display_queue(queue);
                    break;
            case 2: dequeue(queue);
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
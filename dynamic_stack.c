//push() pop() peek() using linked lists 
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};
//struct Node* top;

void push(struct Node** top,int value);
void pop(struct Node** top);
void printStack(struct Node* top);
void peek(struct Node* top);

void peek(struct Node* top){
    printf("The top most element of the stack is: %d\n",top->data);
}//end of peek

void push(struct Node** top,int value){//we need this double pointer here because we are updating top
                                        //in the function
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    if(*top == NULL){
        ptr->nextaddress = NULL;
        *top = ptr;
        printf("Stack was empty so created a stack\n");
    }//creating the first node
    else{
        ptr->nextaddress = *top;//storing the address of top most node in the new node (push)
        *top = ptr;//making the new node as the top
        printf("Element added\n");
    }
}//end of push

void pop(struct Node** top){
    struct Node* ptr = *top;
    if(*top==NULL){
        printf("Stack is empty, underflow\n");
    }
    else{
        *top = ptr->nextaddress;
        free(ptr);
        printf("Removed top most element\n");
    }
}//end of pop

void printStack(struct Node* top){
    struct Node* ptr = top;
    if(ptr==NULL){
        printf("Stack is empty\n");
    } 
    while(ptr!=NULL){
        printf("The element is: %d\n",ptr->data);
        ptr = ptr->nextaddress;
    }//end of while
}//end of print stack

void main(){
    int choice,value,ch;
    struct Node* top = NULL;
    do{
        printf("Enter 1 to add an element\nEnter 2 to delete an element\nEnter 3 to see top most element\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Adding an element to the stack\nEnter value you want to add\n");
                    scanf("%d",&value);
                    push(&top,value);
                    printStack(top);
                    break;
            case 2: printf("Removing an element from the stack\n");
                    pop(&top);
                    printStack(top);
                    break;
            case 3: peek(top);
                    break;
            default: printf("Invalid choice, try again\n");
                     break;
        }//end of switch case 
    printf("Enter 0 to exit and stop all operations, 1 to continue\n");
    scanf("%d",&ch);
    }while(ch>0);
}//end of main
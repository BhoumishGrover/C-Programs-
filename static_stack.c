//static stack
#include <stdio.h>
#include <stdlib.h>

int size;
int top = -1;

void push(int stack[], int *top, int size){
    if(*top == size - 1) {
        printf("Stack overflow\n");
    } 
    else{
        printf("Enter element to be added\n");
        int num;
        scanf("%d", &num);
        (*top)++;
        stack[*top] = num;
        printf("Element pushed and top increased by 1\n");
    }
}//end of push

void pop(int stack[], int *top) {
    if(*top == -1) {
        printf("Stack is already empty\n");
    } 
    else {
        printf("Popped element is: %d\n", stack[*top]);
        (*top)--;
    }
}//end of pop

void peek(int stack[], int top) {
    if(top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("The topmost element of the stack is: %d\n", stack[top]);
    }
}//end of peek

int main() {
    printf("Enter the size of the stack\n");
    scanf("%d", &size);
    int stack[size];
    int ch = 1;
    while(ch > 0) {
        printf("Enter\n 1 for push\n 2 for pop\n 3 for peek\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:push(stack, &top, size);
                   break;
            case 2:pop(stack, &top);
                   break;
            case 3:peek(stack, top);
                   break;
            default:printf("Please enter a valid choice\n");
                ch = 0;
                break;
        }//end of switch case
        printf("Enter 1 to continue, 0 to exit\n");
        scanf("%d", &ch);
    }//end of while 
    return 0;
}//end of main
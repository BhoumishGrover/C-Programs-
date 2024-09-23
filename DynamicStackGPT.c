#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextaddress;
};

void push(struct Node** top, int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    if (*top == NULL) {
        ptr->nextaddress = NULL;
        *top = ptr;
        printf("Stack was empty so created a stack\n");
    } else {
        ptr->nextaddress = *top;  // Store the address of the top node in the new node
        *top = ptr;               // Make the new node the top
        printf("Element added\n");
    }
}

void printStack(struct Node* top) {
    struct Node* ptr = top;
    while (ptr != NULL) {
        printf("The element is: %d\n", ptr->data);
        ptr = ptr->nextaddress;
    }
}

int main() {
    int choice, value, ch;
    struct Node* top = NULL;  // Initialize top to NULL

    do {
        printf("Enter 1 to push, 0 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Adding an element to the stack\nEnter value you want to add: ");
                scanf("%d", &value);
                push(&top, value);
                printStack(top);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Enter 0 to exit and stop all operations, 1 to continue: ");
        scanf("%d", &ch);
    } while (ch > 0);

    return 0;
}

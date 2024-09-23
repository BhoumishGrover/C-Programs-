#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextaddress;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue_pq();
void dequeue_pq();
void display_pq();

void enqueue_pq() {
    printf("Enter the element you want to add\n");
    int add;
    scanf("%d", &add);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = add;
    ptr->nextaddress = NULL;

    // If queue is empty
    if (front == NULL) {
        front = ptr;
        rear = ptr;
        printf("Created the first node of the queue\n");
        return;
    }

    // If the new node should be inserted before the front
    if (add < front->data) {
        ptr->nextaddress = front;
        front = ptr;
        printf("Element added at the front\n");
        return;
    }

    struct Node* temp = front;
    
    // Traverse the queue and find the correct position
    while (temp->nextaddress != NULL && temp->nextaddress->data < add) {
        temp = temp->nextaddress;
    }

    // Insert the new node
    ptr->nextaddress = temp->nextaddress;
    temp->nextaddress = ptr;

    // If the new node is inserted at the end
    if (ptr->nextaddress == NULL) {
        rear = ptr;
    }

    printf("Element added in the queue\n");
}

void dequeue_pq() {
    if (front == NULL) {
        printf("Queue is already empty, can't dequeue\n");
        return;
    }

    struct Node* ptr = front;
    printf("Removing element: %d\n", front->data);
    front = front->nextaddress;

    // If the queue becomes empty after dequeue
    if (front == NULL) {
        rear = NULL;
    }

    free(ptr);
}

void display_pq() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    while (temp != NULL) {
        printf("Element is: %d\n", temp->data);
        temp = temp->nextaddress;
    }
}

int main() {
    int choice, ch;
    do {
        printf("Enter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to print the queue\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue_pq();
                break;
            case 2:
                dequeue_pq();
                break;
            case 3:
                display_pq();
                break;
            default:
                printf("Invalid input, try again\n");
                break;
        }

        printf("Enter 1 to continue, 0 to exit\n");
        scanf("%d", &ch);
    } while (ch > 0);

    return 0;
}

//cicular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};

struct Node* head;

void insert_start();
void insert_end();
void insert_between();
void delete();
void display();

void insert_start(){
    printf("Enter value you want to add\n");
    int value;
    scanf("%d",&value);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->nextaddress = head;
    head = ptr;

    // if(head->nextaddress == NULL){
    //     head->nextaddress = head;
    // }//first node point towards itself

    struct Node* temp = head;
    while(temp->nextaddress != head){
        temp = temp->nextaddress;
    }//at end, temp points to the last node
    
    temp->nextaddress = head;
}//end of insert at start

void insert_end(){
    printf("Enter value you want to add\n");
    int value;
    scanf("%d",&value);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;

    struct Node* temp = head;
    while(temp->nextaddress != head){
        temp = temp->nextaddress;
    }//at end, temp points to the last node

    temp->nextaddress = ptr;
    ptr->nextaddress = head;
}//end of insert at end

void insert_between(){
    printf("Enter value you want to add\n");
    int value;
    scanf("%d",&value);

    printf("Enter value after which you want to add\n");
    int search;
    scanf("%d",&search);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;

    struct Node* temp = head;
    while(temp->nextaddress != head){
        if(temp->data == search){
            ptr->nextaddress = temp->nextaddress;
            temp->nextaddress = ptr;
            break
        }
    }
    if(temp->nextaddress == NULL){
        printf("couldn't find the value, pls try again\n");
    }
}//end of insert between

void delete(){
    printf("Enter value you want to delete\n");
    int value;
    scanf("%d",&value);

    while()
}

void main(){
    int choice,ch;
    do{
        printf("Enter 1 to add at START\nEnter 2 to adde at END\nEnter 3 to add BETWEEN nodes\nEnter 4 to delete\nEnter 5 to display list\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_start();
                    break;
            case 2: insert_end();
                    break;
            case 3: insert_between();
                    break;
            case 4: delete();
                    break;
            case 5: display();
                    break;
            default: printf("Invalid choice,try again\n");
                     break;
        }//end of switch
    }while(ch>0);
}//end of main
//program to reverse linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};

struct Node_reversed{
    int data_rev;
    struct Node_reversed* next;
};

struct Node* head;
struct Node_reversed* head_rev;

void linked_list_print(struct Node_reversed* ptr){
    printf("Printing....\n");
    while(ptr!=NULL){
        printf("Element of node is: %d \n",ptr->data_rev);
        ptr=ptr->next;
    }//end of while
}//end of print

void insert_at_beginning(int value){
    //printf("Enter value you want to add to the linked list ");
    struct Node_reversed* ptr=(struct Node_reversed*)malloc(sizeof(struct Node_reversed));
    ptr->data_rev=value;
    ptr->next=head_rev;
    head_rev=ptr;
}//end of insert at start

void list_reversal(){
    struct Node* p;
    p=head;
    while(p!=NULL){
        insert_at_beginning(p->data);
        p=p->nextaddress;
    }
}//end of reversal
int main(){
    struct Node* first;
    struct Node* second;
    struct Node* third;
    
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    first->data=10;
    first->nextaddress=second;
    
    second->data=20;
    second->nextaddress=third;
    
    third->data=30;
    third->nextaddress=NULL;
    
    head=first;//value of head = address of first node

    list_reversal();

    linked_list_print(head_rev);
    
    return 0;
}//end of main 
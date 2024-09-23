//all linked list operations
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};
struct Node* head;

void linked_list_traversal(struct Node* ptr){
    printf("Printing....\n");
    while(ptr!=NULL){
        printf("Element of node is: %d \n",ptr->data);
        ptr=ptr->nextaddress;
    }//end of while
}//end of traversal 

void insert_at_beginning(){
    printf("Enter value you want to add to the linked list ");
    int value;
    scanf("%d",&value);
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->nextaddress=head;
    head=ptr;
}//end of insert at start

void insert_between(){
    printf("Enter the value after which you want to add the node: ");
    int search;
    scanf("%d",&search);
    
    printf("Enter value you want to add to the linked list ");
    int value;
    scanf("%d",&value);
    
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    if(ptr==NULL)printf("Memory NOT allocated");
    
    struct Node* temp;//temperory variable to traverse the linked list and find the "search" element.
    temp=head;
    while(temp!=NULL){
        if(temp->data==search){
            printf("Found the search element, now inserting...\n");
            ptr->data=value;
            ptr->nextaddress=temp->nextaddress;
            temp->nextaddress=ptr;//storing the value of the new node in the nextaddress of the node with the "search" element.
            break;
        }
        temp=temp->nextaddress;
    }//end of while
    if(temp==NULL)printf("Element was not found, couldn't insert\n");
}//end of middle insert

void insert_at_end(){
    printf("Enter the vaule you want to add at the end ");
    int value;
    scanf("%d",&value);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL)printf("Memory not allocated");
    ptr->data=value;
    
    struct Node* temp;
    temp=head;
    if(temp==NULL)printf("couldn't create pointer");

    while(temp->nextaddress!=NULL){
        temp=temp->nextaddress;
    }//at the end of this loop, the temp pointer will reach the last node 
    temp->nextaddress=ptr;
    ptr->nextaddress=NULL;
    printf("Added the new Node at the end\n");
}//end of insert_at_end

void delete(int search_val){
    struct Node* temp;
    temp=head;
    int index=0;
    int count=0;
    //finding the index of the node that has to be deleted
    while(temp!=NULL){
        if(temp->data==search_val){
            printf("Index found\n");
            index = count;
        }
        count=count+1;
        temp=temp->nextaddress;
    }//end of index while

    count=0;//resetting counter variable
    temp=head;//resetting temp pointer to the start of linked list.

    if(index==0){
        printf("deleting the very first element\n");
                head=temp->nextaddress;
                free(temp);
    }//deleting first element
    else{
        while(count<index){
            if(count==(index-1)){
                struct Node* ptr = temp->nextaddress;
                temp->nextaddress = ptr->nextaddress;
                free(ptr);
                break;
            }
            count++;
            temp=temp->nextaddress;
        }//end of while
    }//middle element 
}//end of delete

void search(int search_val){
    struct Node* temp;
    temp=head;
    int index=0;
    int count=0;
    //finding the index of the node that has to be deleted
    while(temp!=NULL){
        if(temp->data==search_val){
            printf("Index found\n");
            index = count;
        }
        count=count+1;
        temp=temp->nextaddress;
    }//end of index while
    printf("The value %d is at index %d\n",search_val,index);
}//end of search


int main() {
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

    int choice,ch=0;
    do{
        printf("Enter 1 to print the list\nEnter 2 to add an element at the start\nEnter 3 to add an element in between 2 elements\nEnter 4 to add an element at the end\nEnter 5 to delete an element\nEnter 6 to get the index of an element\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Printing the list\n");
                linked_list_traversal(head);
                break;
            case 2:
                printf("adding an element at the start\n");
                insert_at_beginning();
                printf("The list after insertion at start is:\n");
                linked_list_traversal(head);
                break;
            case 3:
                printf("Adding an element between 2 elements\n");
                insert_between();
                printf("The list after insertion in between two nodes is:\n");
                linked_list_traversal(head);  
                break;
            case 4:
                printf("Adding an element at the end\n");
                insert_at_end();
                printf("The list after insertion at end is \n");
                linked_list_traversal(head);
                break;
            case 5:
                printf("Enter element you wanr to delete\n");
                int delete_val;
                scanf("%d",&delete_val);
                delete(delete_val);
                linked_list_traversal(head);
            case 6:
                printf("Which value's index do you need?\n");
                int src_val;
                scanf("%d",&src_val);
                search(src_val);
                linked_list_traversal(head);
            default:
                printf("Invalid input, try again\n");
                break;
        }//end of switch case
        printf("Enter 0 to stop all operations and exit, Enter 1 to continue\n");
        scanf("%d",&ch);
    }while(ch>0);//end of do while loop

    return 0;
}//end of main
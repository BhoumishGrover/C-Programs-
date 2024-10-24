//Circualar Doubly linked list operations
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* previous;
};
struct Node* head;

void linked_list_traversal(struct Node* ptr){
    printf("Printing....\n");
    while(ptr->next != head){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }//end of while
    printf("%d \n",ptr->data);
}//end of traversal 

void reverse_linked_list(struct Node* ptr){
    while(ptr->next!=head){
        ptr=ptr->next;
    }//end of while
    
    printf("Printing in reverse\n");
    while(ptr!=head){
        printf("%d ",ptr->data);
        ptr=ptr->previous;
    }
    printf("%d \n",ptr->data);
}//end of reverse printing

void insert_at_beginning(){
    printf("Enter value you want to add to the linked list ");
    int value;
    scanf("%d",&value);

    struct Node* temp = head;
    while(temp->next != head){
        temp=temp->next;
    }
    //end of this while, temp points to last element

    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=value;
    ptr->next=head;
    ptr->previous=temp;
    head->previous=ptr;
    head=ptr;
    temp->next=head;
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
            ptr->next=temp->next;
            temp->next->previous = ptr;
            temp->next=ptr;//storing the value of the new node in the next of the node with the "search" element.
            ptr->previous=temp;
            break;
        }
        temp=temp->next;
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

    while(temp->next!=head){
        temp=temp->next;
    }//at the end of this loop, the temp pointer will reach the last node 
    temp->next=ptr;
    ptr->next=head;
    ptr->previous=temp;
    printf("Added the new Node at the end\n");
}//end of insert_at_end

void delete(int search_val){
    struct Node* temp;
    temp=head;
    int index=0;
    int count=0;
    //finding the index of the node that has to be deleted
    while(temp->next != head){
        if(temp->data==search_val){
            printf("Index found\n");
            index = count;
        }
        count=count+1;
        temp=temp->next;
    }//end of index while
    if(temp->data == search_val){
        //value at last node
        printf("Index found \n");
        index = count;
    }

    count=0;//resetting counter variable
    temp=head;//resetting temp pointer to the start of linked list.

    struct Node* temp2 = head;
    while(temp2->next!=head){
        temp2=temp2->next;
    }//at the end of this loop, the temp pointer will reach the last node 

    if(index==0){
        printf("deleting the very first element\n");
                head=temp->next;
                free(temp);
                head->previous=temp2;//last element
    }//deleting first element
    else{
        while(count<index){
            if(count==(index-1)){
                struct Node* ptr = temp->next;
                temp->next = ptr->next;
                ptr->next->previous=temp;
                free(ptr);
                break;
            }
            count++;
            temp=temp->next;
        }//end of while
    }//middle element 
}//end of delete

void search(int search_val){
    struct Node* temp;
    temp=head;
    int index=0;
    int count=0;
    //finding the index of the node that has to be deleted
    while(temp->next != head){
        if(temp->data==search_val){
            printf("Index found\n");
            index = count;
        }
        count=count+1;
        temp=temp->next;
    }//end of index while
    if(temp->data == search_val){
        //value at last node
        printf("Index found \n");
        index = count;
    }
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
    first->next=second;
    first->previous=third;
    
    second->data=20;
    second->next=third;
    second->previous=first;
    
    third->data=30;
    third->next=first;
    third->previous=second;
    
    head=first;//value of head = address of first node

    int choice,ch=0;
    do{
        printf("Enter 1 to print the list\nEnter 2 to add an element at the start\nEnter 3 to add an element in between 2 elements\nEnter 4 to add an element at the end\nEnter 5 to delete an element\nEnter 6 to get the index of an element\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Printing the list\n");
                linked_list_traversal(head);
                reverse_linked_list(head);
                break;
            case 2:
                printf("adding an element at the start\n");
                insert_at_beginning();
                printf("The list after insertion at start is:\n");
                linked_list_traversal(head);
                reverse_linked_list(head);
                break;
            case 3:
                printf("Adding an element between 2 elements\n");
                insert_between();
                printf("The list after insertion in between two nodes is:\n");
                linked_list_traversal(head); 
                reverse_linked_list(head); 
                break;
            case 4:
                printf("Adding an element at the end\n");
                insert_at_end();
                printf("The list after insertion at end is \n");
                linked_list_traversal(head);
                reverse_linked_list(head);
                break;
            case 5:
                printf("Enter element you want to delete\n");
                int delete_val;
                scanf("%d",&delete_val);
                delete(delete_val);
                linked_list_traversal(head);
                reverse_linked_list(head);
                break;
            case 6:
                printf("Which value's index do you need?\n");
                int src_val;
                scanf("%d",&src_val);
                search(src_val);
                linked_list_traversal(head);
                reverse_linked_list(head);
                break;
            default:
                printf("Invalid input, try again\n");
                break;
        }//end of switch case
        printf("Enter 0 to stop all operations and exit, Enter 1 to continue\n");
        scanf("%d",&ch);
    }while(ch>0);//end of do while loop

    return 0;
}//end of main